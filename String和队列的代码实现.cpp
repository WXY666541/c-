#include<iostream>
using namespace std;
//实现String类
#if 0
class String
{
public:
	String(const char* str = nullptr)//普通的构造函数
	{
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];//所以应该首先开辟一个空间，+1是因为strlen没有\0
			strcpy(this->m_data, str);//将外部写入的字符串拷贝给m_data，但是并不知道这个指针是否指向一个合法的空间
		}
		else//如果传进来的指针为空的话不应该把m_data置为空，这样的话会存在使后续的所有方法也要判断为空的情况，所以做以下处理
		{
			m_data = new char[1];//不写new char的原因后续运算符重载介绍
			*m_data = '\0';
		}
	
	}
	String(const String& other)//拷贝构造函数
	{
		//m_data = other.m_data;默认的方式：让两个对象的指针指向同一块构造时申请的堆内存，但是析构的时候就存在问题了
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);//根据你的大小给我自己的指针重新指向对象的一块内存，然后进行数据的拷贝
	}
	~String(void)//析构函数
	{
		delete[] m_data;
		m_data = nullptr;//防止野指针的出现
	}
	//返回引用相当于返回地址为了支持连续赋值，如果返回值的话会产生临时对象
	String& operator = (const String& other)//赋值重载函数(给两个已经存在的字符串对象赋值）
	{
		if (this == &other)//防止自赋值
		{
			return *this;
		}
		delete[]m_data;//把当前对象所占的外部资源释放掉
		//再调用拷贝构造,再重新根据传入的对象的字符串的大小开辟空间拷贝字符串
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
private:
	char* m_data;//用于保存字符串

};
int main()
{
	//调用带const char*参数的构造函数
	String str1;//默认的构造
	String str2("hello");
	String str3="world";

	//都调用拷贝构造，是初始化不是赋值（左边的对象已经存在）。这是左边的对象不存在，正在拷贝构造中
	String str4 = str3;
	String str5(str3);

	//调用赋值重载函数
	/*
	赋值重载函数的返回值不能是void，因为当实现连续赋值的时候，例如：str3 = str1 = str2;相当于
	str1 = str2
	str1.operator =(str2)==>void
	str3 = void //错误的
	*/
	str1 = str2;
	return 0;
}
#endif

/*
对象的拷贝不要使用memcpy realloc因为他们是做内存的直接拷贝，但是对象可能涉及到外部堆内存
*/
//实现循环队列  
class Queue
{
public:
	Queue(int size = 20)
	{
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}
	Queue(const Queue& src)
	{
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}

	}
	Queue& operator=(const Queue& src)
	{
		if (this == &src)
			return *this;
		delete[]_pQue;

		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
		return *this;
	}
	
	~Queue()
	{
		delete[] _pQue;
		_pQue = nullptr;
	}
	void push(int val)
	{
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	void pop()
	{
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}
	int front()
	{
		return _pQue[_front];
	}
	bool full() { return (_rear + 1) % _size == _front; }
	bool empty() { return _front == _rear; }
private:
	int* _pQue;//申请队列的数组空间，定义成指针可扩容
	int _front;//指示队头的位置
	int _rear;//指示队尾的位置
	int _size;//队列扩容的总大小

	void resize()
	{
		int* ptmp = new int[2 * _size];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			ptmp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};
int main()
{
	Queue queue;
	for (int i=0; i < 20; ++i)
	{
		queue.push(rand() % 100);
	}
	while (!queue.empty())
	{
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;

	//Queue queue1 = queue;浅拷贝有问题，共享了内存
	return 0;
}