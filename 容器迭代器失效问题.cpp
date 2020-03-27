#include<iostream>
#include<vector>
using namespace std;

/*
迭代器失效问题
1、迭代器为什么会失效？
a.当容器调用erase方法后，当前位置到容器末尾元素的所有迭代器全部失效
b.当容器调用insert方法后，当前位置到容器末尾元素的所有迭代器全部失效
c.insert来说，如果引起容器扩容。原来容器的所有迭代器就全部失效了，因为连内存都改变了
d.不同容器的迭代器是不能进行比较运算的
2、迭代器失效了过后，问题该怎么解决？
对插入/删除点的迭代器进行更新操作,去当前元素增加一个元素，或者将当前失效的迭代器删除，将新的iterator返回
*/
template <typename T>
struct Allocator
{
	T* allocate(size_t size)//只负责内存开辟
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//只负责内存释放
	{
		free(p);
	}
	void construct(T* p, const T& val)//已经开辟好的内存上，负责对象构造
	{
		new (p) T(val);//定位new，指定内存上构造val，T(val)拷贝构造
	}
	void destroy(T* p)//只负责对象析构
	{
		p->~T();//~T()代表了T类型的析构函数
	}
};

template <typename T, typename Alloc = Allocator<T>>
class vector//向量容器
{
public:
	vector(int size = 10)//构造
	{
		//_first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()//析构
	{
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);//把_first指针指向的数组的有效元素析构
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)//拷贝构造
	{
		int size = rhs._end - rhs._first;//空间大小
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;//有效元素
		for (int i = 0; i < len; ++i)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)//赋值运算符重载
	{
		if (this == &rhs)
		{
			return *this;
		}

		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destory(p);//把_first指针指向的数组的有效元素析构
		}
		_allocator.deallocate(_first);//释放堆上的数组内存

		int size = rhs._end - rhs._first;//空间大小
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;//有效元素
		for (int i = 0; i < len; ++i)
		{
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	void push_back(const T& val)//尾插
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		_allocator.construct(_last, val);//_last指针指向的内存构造一个值为val的对象
		_last++;
	}
	void pop_back()//尾删
	{
		if (empty()) return;
		//检查是否失效
		//如果是使用erase(it),检查范围改变verify(it._ptr, _last);
		//如果是使用insert(it),检查范围改变verify(it._ptr, _last);
		verify(_last - 1, _last);
		--_last;
		_allocator.destroy(_last);
	}
	T back()const//返回容器末尾元素值
	{
		return *(_last - 1);
	}
	bool full()const
	{
		return _last == _end;
	}
	bool empty()const
	{
		return _first == _last;
	}
	int size()const//返回容器中元素个数
	{
		return _last - _first;
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= size())
		{
			throw "OutOfRangeException";
		}
		return _first[index];
	}
	//迭代器一般实现成容器的嵌套类型
	class iterator
	{
	public:
		iterator(vector<T, Alloc>* pvec=null，T* ptr = nullptr)
			:_ptr(ptr), _pVec(pvec){}
		{
			Iterator_Base* itb =
				new Iterator_Base(this, _pVec->_head._next);
			_pVec->_head._next = itb;
		}
		bool operator!=(const iterator& it)const
		{
			//检查迭代器的有效性，如果为空，则代表该指针指向的容器是空的表示迭代器失效了。
			//还有两个不同对象的迭代器比较是没有意义的
			if (_pVec == nullptr || _pVec != it._pVec)
			{
				throw"ierator incompatable!";
				return false;
			}
			return _ptr != it._ptr;
		}
		void operator++()
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw"iterator invalid";
			}
			_ptr++;
		}
		T& operator*()
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw"iterator invalid";
			}
			return *_ptr;
		}
		const T& operator*()const
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw"iterator invalid";
			}
			return *_ptr;
		}
	private:
		T* _ptr;
		vector<T, Alloc>* _pVec;
		//让迭代器知道当前迭代器迭代的是哪个容器对象，所以给迭代器提供一个指向当前容器对象的指针
	};
	iterator begin()
	{
		return iterator(_first);
	}
	iterator end()
	{
		return iterator(_last);
	}
	void verify(T *first,T *last)
	{
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head._next;
		while (it != nullptr)
		{
			if (it->_cur->_ptr >= first&& it->_cur->_ptr <= last)
			{
				//迭代器失效，把itreator持有的容器指针置nullptr
				it->_cur->_pVec = nullptr;
				//删除当前迭代器节点，继续判断后面的迭代器节点是否失效
				pre->_next = it->_next;
				delete it;
				it = pre->_next;
			}
			else
			{
				pre = it;
				it = it->_next;
		}
	//自定义vector容器insert方法实现
	iterator insert(iterator it, const T &val)
	{
		//1.这里我们未考虑扩容
		//2.还未考虑it._ptr指针合法性，假设它合法
		verify(it._ptr - 1, _last);
		T *p = _last;
		while (p > it._ptr)
		{
			_allocator.construct(p, *(p-1));
			_allocator.destroy(p - 1);
			p--;
		}
		_allocator.construct(p, val);
		_last++;
		return iterator(this, p);
	}

	//自定义vector容器erase方法实现
	iterator erase(iterator it)
	{
		verify(it._ptr - 1, _last);
		T *p = it._ptr;
		while (p < _last-1)
		{
			_allocator.destroy(p);
			_allocator.construct(p, *(p+1));
			p++;
		}
		_allocator.destroy(p);
		_last--;
		return iterator(this, it._ptr);
	}

private:
	T* _first;//起始数组位置
	T* _last;//指向最后一个有效元素后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间配置器对象

	//容器迭代器失效增加代码，用链表记录用户获取的哪一个迭代器
	struct Iterator_Base
	{
		Iterator_Base(iterator* c = nullptr, Iterator_Base* n = nullptr)
			:_cur(c), _next(n) {}
		iterator* _cur;//维护了指向某一个迭代器的指针
		Iterator_Base* _next;//指向下一个迭代器对象的地址
	};
	Iterator_Base _head;//头结点

	void expand()//扩容
	{
		int size = _end - _first;
		//T *ptmp = new T[2*size];
		T* ptmp = _allocator.allocate(2 * size);
		for (int i = 0; i < size; ++i)
		{
			_allocator.construct(ptmp + i, _first[i]);
			//ptmp[i] = _first[i];
		}
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);
		_first = ptmp;
		_last = _first + size;
		_end = _first + 2 * size;
	}
};

