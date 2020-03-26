#include<iostream>
#include<vector>
using namespace std;


/*
**********************************************
1、模拟实现顺序栈
*********************************************
*/
template<typename T>
class SeqStack//模板名称 + 类型参数列表 = 类名称
{
public:
	//构造和析构函数名不用加<T>,其他出现模板的地方都加上类型参数列表
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
		//不要用memcopy进行拷贝（做的是浅拷贝）
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
			throw "stack is empty!";//抛异常也代表函数逻辑结束
		return _pstack[_top - 1];
	}
	bool full()const { return _top == _size; }
	bool empty()const { return _top == 0; }


private:
	T* _pstack;
	int _top;
	int _size;

	//顺序栈底层数组按2倍的方式扩容
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
	//类模板的选择性实例化：当我们类模板实例化过后的模板类到底使用哪个方法编译器看代码中都调用过哪些方法
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
二、类模板
1、实现一个C++ STL里面的一个顺序容器 vetor 向量容器
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
		//拷贝有效元素
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
	void push_back(const T &val)//向容器末尾添加元素
	{
		if (full())
			expand();
		*_last++ = val;
	}
	void pop_back()//从容器末尾删除元素
	{
		if (empty())
			return;
		--_last;
	}
	T back() const//返回容器末尾的元素的值
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _first == _last; }
	int size()const { return _last - _first; }
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有效元素的后继位置
	T* _end;//指向数组空间的后继位置
	void expand()//容器的二倍扩容
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