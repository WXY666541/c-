#include<iostream>
#include<string.h>
using namespace std;
/*
***************************************
问题一：请问下列程序输出结果是什么？
***************************************
*/
#if 0
class Animal
{
public:
	Animal(string name) :_name(name) {}
	//纯虚函数
	virtual void bark() = 0;
protected:
	string _name;
};
//以下是动物实体类
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:wang wang!" << endl; }
};
int main()
{
	Animal* p1 = new Cat("加菲猫");//vfptr -> Dog vftable
	Animal* p2 = new Dog("二哈");//vfptr -> Cat vftable

	int* p11 = (int*)p1;
	int* p22 = (int*)p2;
	int tmp = p11[0];//p11[0]访问的就是Cat的前4个字节
	p11[0] = p22[0];//p22[0]访问的就是Dog的前4个字节
	p22[0] = tmp;

	p1->bark();//p1 -> Cat vfptr -> Dog vftable bark
	p2->bark();//p1 -> Dog vfptr -> Cat vftable bark

	delete p1;
	delete p2;

	return 0;
}

/*
***************************************
问题二：请问下列程序输出结果是什么？
***************************************
*/
/*
调用的派生类对象的show函数，但是输出的函数形参却是基类的函数形参值10
原因：因为是动态绑定，所以派生类的show只能在运行的时候发现。编译阶段只能看见基类里面的show。
所以入栈push 0Ah
        mov eax, dword ptr[p]
		mov ecx, dword ptr[eax]
		call ecx
这样与派生类形参的默认值已经没有了关系,压栈值已经确定好了
*/
class Base
{
public:
	virtual void show(int i = 10)
	{
		cout << "call Base::show i :" << i << endl;
	}
};
class Derive : public Base
{
public :
	void show(int i = 20)
	{
		cout << "call Derive::show i :" << i << endl;
	}
};
int main()
{
	Base* p = new Derive();//虚析构函数
	p->show();
	delete p;
	return 0;
}

/*
**********************************************
问题三：请问下列程序派生类方法能不能进行调用？
***********************************************
*/
/*
可以
因为 最终能调用到Derive::show是在运行时期才确定的。方法的访问权限是不是public的，是在编译阶段就需要确定好的，
因此在编译阶段只能看见Base::show,因为调用这个方法的指针是Base指针，为public的可以访问。
访问权限的作用只是在编译阶段看语法是否错误。如果把下列代码改成基类为private 派生类为public则程序不能运行成功
*/
class Base
{
public:
	virtual void show()
	{
		cout << "call Base::show i :" << endl;
	}
};
class Derive : public Base
{
private:
	void show()
	{
		cout << "call Derive::show i :" << endl;
	}
};
int main()
{
	Base* p = new Derive();
	p->show();
	delete p;
	return 0;
}
#endif
/*
******************************************************
问题四：请问下列程序运行是否正确？错误的话原因是什么？
******************************************************
*/
/*
前一个有问题，后面这个运行正常
*/
class Base
{
public:
	Base()
	{
		/*
		push ebp  调用方函数的栈底地址压栈放入当前函数的栈底
		mov ebp,esp
		sub esp ,4Ch
		rep stos esp<->ebp 0xcccccccc
		vfptr <- &Base ::vftable
		*/
		cout << "call Base()" << endl;
		clear();
	}
	void clear() { memset(this, 0, sizeof(*this)); }
	virtual void show()
	{
		cout << "call Base::show():" << endl;
	}
};
class Derive : public Base
{
public:
	Derive()
	{
		/*
		push ebp  调用方函数的栈底地址压栈放入当前函数的栈底
		mov ebp,esp
		sub esp ,4Ch
		rep stos esp<->ebp 0xcccccccc
		vfptr <- &Derive ::vftable
		*/
		cout << "call Derive()" << endl;
	}
	void show()
	{
		cout << "call Derive::show ()" << endl;
	}
};
int main()
{
	Base* pb1 = new Base();
	/*
	    mov eax, dword ptr[pb1]
		mov ecx, dword ptr[eax] eax:0x00000000 不是Base::vftable 
		call ecx
	*/
	pb1->show();//动态绑定
	delete pb1;

	Base* pb2 = new Derive();
	/*
	vfptr里面存储的是vftable的地址
	vfptr <- vftable把vftable的地址写入vfptr这个过程指令是在栈帧准备好，函数执行之前
	*/
	pb2->show();//动态绑定
	delete pb2;

	return 0;
}