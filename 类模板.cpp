#include<iostream>
#include<vector>
using namespace std;


/*
**********************************************
1��ģ��ʵ��˳��ջ
*********************************************
*/
template<typename T>
class SeqStack//ģ������ + ���Ͳ����б� = ������
{
public:
	//������������������ü�<T>,��������ģ��ĵط����������Ͳ����б�
	SeqStack(int size = 10)
		:_pstack(new T[size])
		,_top(0)
		,_size(size)
	{}
	~SeqStack()
	{
		delete[] _pstack;
		_pstack = nullptr;
	}
	SeqStack(const SeqStack<T>& stack)
		:_top(stack._top)
		,_size(stack._size)
	{
		_pstack = new T[_size];
		//��Ҫ��memcopy���п�����������ǳ������
		for (int i = 0; i < _top; ++i)
		{
			_pstack[i] = stack._pstack[i];
		}
	}
	SeqStack<T>& operator = (const SeqStack<T>& stack)
	{
		if (this == &stack)
			return *this;

		delete[] _pstack;

		_top = stack._top;
		_size = stack._size;
		_pstack = new T[_size];
		for (int i = 0; i < _top; ++i)
		{
			_pstack[i] = stack._pstack[i];
		}
		return *this;
	}

	void push(const T& val)
	{
		if (full())
			expand();
		_pstack[_top++] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	T top()const
	{
		if (empty())
			throw "stack is empty!";//���쳣Ҳ�������߼�����
		return _pstack[_top - 1];
	}
	bool full()const { return _top == _size; }
	bool empty()const { return _top == 0; }


private:
	T* _pstack;
	int _top;
	int _size;

	//˳��ջ�ײ����鰴2���ķ�ʽ����
	void expand()
	{
		T* ptmp = new T[_size * 2];
		for (int i = 0; i < _top; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
int main()
{
	//��ģ���ѡ����ʵ��������������ģ��ʵ���������ģ���ൽ��ʹ���ĸ������������������ж����ù���Щ����
	SeqStack<int> s1;
	s1.push(20);
	s1.push(89);
	s1.push(21);
	s1.push(12);
	s1.pop();
	return 0;
}

/*
****************************************************
������ģ��
1��ʵ��һ��C++ STL�����һ��˳������ vetor ��������
****************************************************
*/
template<typename T>
class vector
{
public:
	vector(int size = 10)
	{
		_first = new T[size];
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		delete[] _first;
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		_first = new T[size];
		//������ЧԪ��
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator = (const vector<T>& rhs)
	{
		if (this == &rhs)
			return *this;
		
		delete[] _first;

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
	void push_back(const T &val)//������ĩβ���Ԫ��
	{
		if (full())
			expand();
		*_last++ = val;
	}
	void pop_back()//������ĩβɾ��Ԫ��
	{
		if (empty())
			return;
		--_last;
	}
	T back() const//��������ĩβ��Ԫ�ص�ֵ
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _first == _last; }
	int size()const { return _last - _first; }
private:
	T* _first;//ָ��������ʼ��λ��
	T* _last;//ָ����������ЧԪ�صĺ��λ��
	T* _end;//ָ������ռ�ĺ��λ��
	void expand()//�����Ķ�������
	{
		int size = _end - _first;
		T* ptmp = new T[2 * size];
		for (int i = 0; i < size; ++i)
		{
			ptmp[i] = _first[i];
		}
		delete[]_first;
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
	//vec.pop_back();
	while (!vec.empty())
	{
		cout << vec.back() << " ";
		vec.pop_back();
	}
	cout << endl;
	return 0;
}