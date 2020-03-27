#include<iostream>
#include<vector>
using namespace std;

/*
������ʧЧ����
1��������Ϊʲô��ʧЧ��
a.����������erase�����󣬵�ǰλ�õ�����ĩβԪ�ص����е�����ȫ��ʧЧ
b.����������insert�����󣬵�ǰλ�õ�����ĩβԪ�ص����е�����ȫ��ʧЧ
c.insert��˵����������������ݡ�ԭ�����������е�������ȫ��ʧЧ�ˣ���Ϊ���ڴ涼�ı���
d.��ͬ�����ĵ������ǲ��ܽ��бȽ������
2��������ʧЧ�˹����������ô�����
�Բ���/ɾ����ĵ��������и��²���,ȥ��ǰԪ������һ��Ԫ�أ����߽���ǰʧЧ�ĵ�����ɾ�������µ�iterator����
*/
template <typename T>
struct Allocator
{
	T* allocate(size_t size)//ֻ�����ڴ濪��
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//ֻ�����ڴ��ͷ�
	{
		free(p);
	}
	void construct(T* p, const T& val)//�Ѿ����ٺõ��ڴ��ϣ����������
	{
		new (p) T(val);//��λnew��ָ���ڴ��Ϲ���val��T(val)��������
	}
	void destroy(T* p)//ֻ�����������
	{
		p->~T();//~T()������T���͵���������
	}
};

template <typename T, typename Alloc = Allocator<T>>
class vector//��������
{
public:
	vector(int size = 10)//����
	{
		//_first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()//����
	{
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);//��_firstָ��ָ����������ЧԪ������
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)//��������
	{
		int size = rhs._end - rhs._first;//�ռ��С
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;//��ЧԪ��
		for (int i = 0; i < len; ++i)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)//��ֵ���������
	{
		if (this == &rhs)
		{
			return *this;
		}

		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destory(p);//��_firstָ��ָ����������ЧԪ������
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�

		int size = rhs._end - rhs._first;//�ռ��С
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;//��ЧԪ��
		for (int i = 0; i < len; ++i)
		{
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	void push_back(const T& val)//β��
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		_allocator.construct(_last, val);//_lastָ��ָ����ڴ湹��һ��ֵΪval�Ķ���
		_last++;
	}
	void pop_back()//βɾ
	{
		if (empty()) return;
		//����Ƿ�ʧЧ
		//�����ʹ��erase(it),��鷶Χ�ı�verify(it._ptr, _last);
		//�����ʹ��insert(it),��鷶Χ�ı�verify(it._ptr, _last);
		verify(_last - 1, _last);
		--_last;
		_allocator.destroy(_last);
	}
	T back()const//��������ĩβԪ��ֵ
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
	int size()const//����������Ԫ�ظ���
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
	//������һ��ʵ�ֳ�������Ƕ������
	class iterator
	{
	public:
		iterator(vector<T, Alloc>* pvec=null��T* ptr = nullptr)
			:_ptr(ptr), _pVec(pvec){}
		{
			Iterator_Base* itb =
				new Iterator_Base(this, _pVec->_head._next);
			_pVec->_head._next = itb;
		}
		bool operator!=(const iterator& it)const
		{
			//������������Ч�ԣ����Ϊ�գ�������ָ��ָ��������ǿյı�ʾ������ʧЧ�ˡ�
			//����������ͬ����ĵ������Ƚ���û�������
			if (_pVec == nullptr || _pVec != it._pVec)
			{
				throw"ierator incompatable!";
				return false;
			}
			return _ptr != it._ptr;
		}
		void operator++()
		{
			//������������Ч��
			if (_pVec == nullptr)
			{
				throw"iterator invalid";
			}
			_ptr++;
		}
		T& operator*()
		{
			//������������Ч��
			if (_pVec == nullptr)
			{
				throw"iterator invalid";
			}
			return *_ptr;
		}
		const T& operator*()const
		{
			//������������Ч��
			if (_pVec == nullptr)
			{
				throw"iterator invalid";
			}
			return *_ptr;
		}
	private:
		T* _ptr;
		vector<T, Alloc>* _pVec;
		//�õ�����֪����ǰ���������������ĸ������������Ը��������ṩһ��ָ��ǰ���������ָ��
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
				//������ʧЧ����itreator���е�����ָ����nullptr
				it->_cur->_pVec = nullptr;
				//ɾ����ǰ�������ڵ㣬�����жϺ���ĵ������ڵ��Ƿ�ʧЧ
				pre->_next = it->_next;
				delete it;
				it = pre->_next;
			}
			else
			{
				pre = it;
				it = it->_next;
		}
	//�Զ���vector����insert����ʵ��
	iterator insert(iterator it, const T &val)
	{
		//1.��������δ��������
		//2.��δ����it._ptrָ��Ϸ��ԣ��������Ϸ�
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

	//�Զ���vector����erase����ʵ��
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
	T* _first;//��ʼ����λ��
	T* _last;//ָ�����һ����ЧԪ�غ��λ��
	T* _end;//ָ������ռ�ĺ��λ��
	Alloc _allocator;//���������Ŀռ�����������

	//����������ʧЧ���Ӵ��룬�������¼�û���ȡ����һ��������
	struct Iterator_Base
	{
		Iterator_Base(iterator* c = nullptr, Iterator_Base* n = nullptr)
			:_cur(c), _next(n) {}
		iterator* _cur;//ά����ָ��ĳһ����������ָ��
		Iterator_Base* _next;//ָ����һ������������ĵ�ַ
	};
	Iterator_Base _head;//ͷ���

	void expand()//����
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

