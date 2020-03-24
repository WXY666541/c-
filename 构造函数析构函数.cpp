#include<iostream>
#include<string.h>
using namespace std;
#if 0
/*
构造函数和析构函数
函数的名字和类名不一样，没有返回值
*/
//oop实现一个顺序栈
class SeqStack
{
public:
	//构造函数，是可以带参数的，因此可以提供多个构造函数，可重载和init的功能一样，构造函数一调用完对象就生成了
	SeqStack(int size = 10)
	{
		cout << this << "SeqStack()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//对象成员变量的初始化操作
	void init(int size = 10)
	{
		_pstack = new int[size];
		_top = -1;
		_size = size;
	} 
	//析构函数，不带参数，所以析构函数只能有一个出作用域的时候自动调用，对象即不存在了
	~SeqStack()
	{
		cout << this << "~SeqStack()" << endl;
		delete[] _pstack;
		_pstack = nullptr;
	}
	//释放对象成员变量占用的外部堆内存（外部资源）
	void release()
	{
		delete[] _pstack;
		_pstack = nullptr;
	}
	void push(int val)
	{
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty() { return _top == -1; }
	bool full() { return _top == _size - 1; }
private:
	int* _pstack;//动态开辟数组，存储顺序栈的元素
	int _top;//指向栈顶元素的位置
	int _size;//数组扩容的总大小
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		//为什么不用memcpy(ptmp,_pstack,sizeof(int)*_size);realloc
		//因为其涉及的是内存拷贝，在对象里面有问题，因为有可能扩容的是对象或者数据
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
SeqStack gs;
int main()
{
	//1.开辟内存 2.调用构造函数
	SeqStack s;//对象在栈上，指向的是一个堆上的内存

	SeqStack* ps = new SeqStack(60);//开辟在（.heap)段里面malloc内存开辟+SeqStack（60）对象构造操作
	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << endl;
	delete ps;//堆上的对象要自己手动释放 delete(先调用ps->~SeqStack()然后free(ps))


	//s.init(5);
	for (int i = 0; i < 15; ++i)
	{
		s.push(rand() % 100);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	SeqStack s1(50);//构造函数的调用可以不用对象，根据传入参数进行匹配
	//s1.~SeqStack();//析构函数的调用要有对象，因为在没有调用析构之前对象还没有消失
	//s1.push(30);//此时再用该对象的方法会存在堆内存的非法访问，所以不建议自己调用析构函数
	return 0;
}
#endif

