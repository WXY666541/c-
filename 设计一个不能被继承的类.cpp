#include<iostream>

/*
���һ�����ܱ��̳е���
*/
#if 0
//��ʽһ��ģ�ⵥ��ģʽ
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
//��ʽ����ʹ����̳еķ�ʽ,ʹ��A�����Ͳ��ܱ��̳���
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

