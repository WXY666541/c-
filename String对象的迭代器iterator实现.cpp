#include<iostream>
using namespace std;
#if 0
/*
1��Ϊʲôiterator�������������ķ�ʽ����һ�����أ�
*/
template<typename T>
struct Allocator
{
	T* allocate(size_t size)//�����ڴ濪��
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//�����ڴ��ͷ�
	{
		free(p);
	}
	void construct(T* p, const T& val)//���������
	{
		new(p) T(val);//��λnew
	}
	void destory(T* p)//�����������
	{
		p->~T();//~T()������T���͵���������
	}
};
/*
�����ͳ��ڴ濪�٣��ڴ��ͷţ���������������ͨ��allocator�ռ���������ʵ��
*/
template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
	{
		//��Ҫ���ڴ濪�ٺͶ����촦��
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		//����������Ч��Ԫ�أ�Ȼ���ͷ�_firstָ��ָ��Ķ��ڴ�
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);//��_firstָ��ָ����������ЧԪ�ؽ�����������
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		//������ЧԪ��
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator = (const vector<T>& rhs)
	{
		if (this == &rhs)
			return *this;

		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);//��_firstָ��ָ����������ЧԪ�ؽ�����������
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�

		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	void push_back(const T& val)//������ĩβ���Ԫ��
	{
		if (full())
			expand();
		_allocator.construct(_last, val);
		_last++;
	}
	void pop_back()//������ĩβɾ��Ԫ��
	{
		if (empty())
			return;
		//--_last;����Ҫ��_lastָ��--������Ҫ����ɾ����Ԫ��
		--_last;
		_allocator.destory(_last);
	}
	T back() const//��������ĩβ��Ԫ�ص�ֵ
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _first == _last; }
	int size()const { return _last - _first; }
	//���������������
	T& operator[](int index)
	{
		if (index < 0 || index >= size())
		{
			throw "OutOfRangException";
		}
		return _first[index];
	}

	//������һ��ʵ�ֳ�������Ƕ������
	class iterator
	{
	public:
		iterator(T *ptr = nullptr)
			:_ptr(ptr){}
		bool operator !=(const iterator& it)const
		{
			return _ptr != it._ptr;//�������Ĳ���Ⱦ��ǵײ�ָ��Ĳ����
		}
		void operator++()//���üӼ�Ҫ������ʱ����Ч�ʲ��ߣ�����ļӼ�һ�㶼����ǰ�üӼ�
		{
			++_ptr;
		}
		T& operator*() const { return *_ptr; }//�ɷ���Ҳ���޸� int data = *it;*it = 20;
		const T& operator*() const { return *_ptr; }//�ɶ�
	private:
		T* _ptr;//�������ײ����ݽṹ��Ҫһ��ʲô���ı�������
	};
	//��Ҫ�������ṩbegin��end����
	iterator begin() { return iterator(_first); }
	iterator end() { return iterator(_last); }
private:
	T* _first;//ָ��������ʼ��λ��
	T* _last;//ָ����������ЧԪ�صĺ��λ��
	T* _end;//ָ������ռ�ĺ��λ��
	Alloc _allocator;//���������Ŀռ�����������
	void expand()//�����Ķ�������
	{
		int size = _end - _first;
		//T* ptmp = new T[2 * size];
		T* ptmp = _allocator.allocate(2 * size);
		for (int i = 0; i < size; ++i)
		{
			_allocator.construct(ptmp + i, _first[i]);
			//ptmp[i] = _first[i];
		}
		delete[]_first;
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

int main()
{
	vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}

	//���ַ�ʽ����ֻ���vector����
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//��ײ�ԭ������ͨ�������ĵ�������ʵ�������ı���
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

//�����Ŀռ�������
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
		//--_last;
		//����Ҫ��_lastָ��--������Ҫ����ɾ����Ԫ��
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
		iterator(T* ptr = nullptr)
			:_ptr(ptr) {}
		bool operator!=(const iterator& it)const
		{
			return _ptr != it._ptr;
		}
		void operator++()
		{
			_ptr++;
		}
		T& operator*()
		{
			return *_ptr;
		}
		const T& operator*()const
		{
			return *_ptr;
		}
	private:
		T* _ptr;
	};
	iterator begin()
	{
		return iterator(_first);
	}
	iterator end()
	{
		return iterator(_last);
	}
private:
	T* _first;//��ʼ����λ��
	T* _last;//ָ�����һ����ЧԪ�غ��λ��
	T* _end;//ָ������ռ�ĺ��λ��
	Alloc _allocator;//���������Ŀռ�����������

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

int main()
{
	vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100);
	}

	int size = vec.size();//[]�������vector������
	for (int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";//�ײ������飬O(1)
	}
	cout << endl;

	vector<int>::iterator it = vec.begin();
	//auto it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (int val : vec)//�ײ㻹��ͨ�������ĵ�������ʵ�ֱ�����
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}

#endif