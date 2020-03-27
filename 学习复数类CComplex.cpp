#include<iostream>
using namespace std;
#if 0
/*
运算符重载：使对象的运算表现得和编译器内置类型一样

例如：在模板中，我们定义了如下的sum函数
template<typename T>
T sum(T a,T b)
{
	return a+b;
}
如果是正常的数据类型还可以运算，但是遇到对象相加了怎么办呢？
编译器就只能试图在a这个对象里面去找看有没有一个加法函数
*/
//复数类
class CComplex
{
public:
	//CComplex() CComplex(20)CComplex(30,30)三种类型都能生成构造函数，构造三种不同的复数对象
	CComplex(int r = 0,int i =0)
		:mreal(r)
		,mimage(i)
	{}
	//指导编译器怎么做CComplex类对象的加法操作
	CComplex operator+(const CComplex& src)//引用接收另一个复数类对象
	{
		CComplex comp;//定义一个新对象
		comp.mreal = this->mreal + src.mreal;
		comp.mimage = this->mimage + src.mimage;
		return comp;
		return CComplex(this->mreal + src.mreal,this->mimage+src.mimage);
	}
	CComplex operator++(int)
	{
	/*	CComplex comp = *this;
		mreal += 1;
		mimage += 1;
		return comp;*/
		return CComplex(mreal++, mimage++);//把老对象的值返回过后再实部虚部加加，少了comp对象构造和析构的过程
	}
	CComplex& operator++()
	{
		mreal += 1;
		mimage += 1;
		return *this;
	}
	void operator+=(const CComplex& src)
	{
		mreal += src.mreal;
		mimage += src.mimage;
	}
	void show() { cout << "real:" << mreal << "image:" << mimage << endl; }
private:
	int mreal;
	int mimage;
	friend CComplex operator+(const CComplex& lhs, const CComplex& rhs);
	friend ostream& operator<<(ostream& out, const CComplex& src);
	friend istream& operator>>(istream& in, CComplex& src);
};
//因为不能在类外访问私有成员变量，所以我们用友元函数来解决这种问题
CComplex operator+(const CComplex& lhs, const CComplex& rhs)
{
	return CComplex(lhs.mreal + rhs.mreal, rhs.mimage + rhs.mimage);
}
ostream& operator<<(ostream& out, const CComplex& src)
{
	out << "mreal:" << src.mreal << "mimage:" << src.mimage << endl;
	return out;
}
istream& operator>>(istream& in,CComplex& src)
{
	in >> src.mreal >> src.mimage;
	return in;
}
int main()
{
	CComplex comp1(10, 10);
	CComplex comp2(20, 20);
	CComplex comp3 = comp1 + comp2;
	//去寻找comp1这个对象里面有没有一个加号方法把comp2当做一个实参进来 comp1.operatpr+(comp2) 加法运算符的重载函数
	//看似在做运算，实质上是做成员方法的调用
	//写成这样也可CComplex comp3 = comp1.operator+(comp2);
	comp3.show();

	CComplex comp4 = comp1 + 20;
	//comp1调用了加法运算符重载，把20当做实参传入。然后实参到形参的类型强转。把整数类型转成复数CComplex类型，生成临时对象
	comp4.show();

	CComplex comp5 = 30 + comp2;
	comp5.show();
	//错误的，在这儿没有将整数转成复数类型，编译器做对象运算的时候，会调用对象的运算符重载函数（优先调用成员方法），如果没有成员方法
	//就在全局作用域找合适的运算符重载函数,所以有了全局的，局部的代码都可以屏蔽掉
	//解决方案：在全局定义一个加法运算符重载，这样30和comp2都当成实参传入

	//CComplex operator++(int)
	comp5 = comp1++;//++ --是一个单目运算符operator++() 表示前置++，operator++(int)表示后置++
	comp1.show();
	comp5.show();

	//CComplex operator++()
	comp5 = ++comp1;
	comp1.show();
	comp5.show();

	//复合赋值运算符comp1.operatpr+=(comp2)
	comp1 += comp2;
	comp1.show();

	//输出运算符重载
	//cout::operator<<(cout,comp1)
	//ostream& operator<<(ostream &out,const CComplex &src)
	cout << comp1 << endl;
	cin >> comp1 >> comp2;
	cout << comp1 << comp2 << endl;
}
#endif

