#include<iostream>
#if 0
class CComplex
{
public:
	CComplex(int r = 0, int i = 0)
		:mreal(r)
		, mimage(i)
	{}
	
	//对象+对象
	CComplex operator+(const CComplex& src)
	{
		CComplex comp;
		comp.mreal = mreal + src.mreal;
		comp.mimage = mimage + src.mimage;
		return comp;
		return CComplex(mreal + src.mreal, mimage + src.mimage);
	}
	
	//对象+变量
	const CComplex operator+(int rhs)
	{
		return CComplex(mreal + rhs, mimage);
	}

	//比较运算符==
	bool operator==(const CComplex& src)
	{
		return (mreal == src.mreal) && (mimage == src.mimage);
	}

	//比较运算符>
	bool operator >(const CComplex& src)
	{
		return (mreal > src.mreal) ||( (mreal > src.mreal) && (mimage > src.mimage));
	}

private:
	int mreal;
	int mimage;

	friend const CComplex operator+(int lhs, const CComplex& rhs);
	friend std::ostream& operator<<(std::ostream& out, const CComplex& src);
	friend std::istream& operator>>(std::istream& in, CComplex& src);
};

//变量+对象
const CComplex operator+(int lhs, const CComplex& rhs)
{
	return CComplex(lhs + rhs.mreal, rhs.mimage);
}
//输出运算符
std::ostream& operator<<(std::ostream& out, const CComplex& src)
{
	out << "mreal:" << src.mreal << "mimage:" << src.mimage << std::endl;
	return out;
}
//输入运算符
std::istream& operator>>(std::istream& in, CComplex& src)
{
	in >> src.mreal >> src.mimage;
	return in;
}
int main()
{
	//构造函数
	CComplex comp1(10, 10);
	std::cout << "comp1的值为：";
	std::cout << comp1;

	//对象+变量
	CComplex comp2 = comp1 + 10;
	std::cout << "comp1+10的值为：";
	std::cout << comp2;

	//变量+对象
	CComplex comp3 = 10 + comp1;
	std::cout << "10+comp1的值为：";
	std::cout << comp3;

	//>比较运算符>
	std::cout << "comp2和comp3的比较结果为：";
	if (comp2 > comp3)
	{
		std::cout << comp2;
	}
	else
	{
		std::cout << comp3;
	}

	//比较运算符==
	std::cout << "comp1和comp3的比较结果为：";
	if (comp3 == comp1)
	{
		std::cout << comp1;
	}
	else
	{
		std::cout << "不相等！"<<std::endl;
	}

	//输入运算符
	std::cout << "请输入一个复数：";
	std::cin >> comp2;

	//输出运算符
	std::cout << "输出打印结果为：";
	std::cout << comp2 << std::endl;
	return 0;
}
#endif
