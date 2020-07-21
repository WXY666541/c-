#include<iostream>

/*
设计一个不能被继承的类
*/
#if 0
//方式一：模拟单例模式
class A
{
public:
	A* getInstance(int a)
	{
		return new A(a);
	}
private:
	int ma;
	A(int a):ma(a)
	{}
};
class Derive :public A
{
protected:
	int mb;
};
int main()
{
	A* pa = A::getInstance();
	return 0;
}

#endif
//方式二：使用虚继承的方式,使得A这个类就不能被继承了
class A;
class Base
{
private:
	Base() {};
	friend class A;
};
class A :virtual public Base
{
public:
	A(int a)
		:ma(a)
	{}
	void show()
	{
		std::cout << "Base::ma" << ma << std::endl;
	}
protected:
	int ma;
};
int main()
{
	A a(20);
}

