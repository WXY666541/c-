#include<iostream>
#include<string>


/*
   用oop的思想模拟实现一个商品类
*/

class CGoods
{
public:
	//构造函数
	CGoods(const char* name, float price, int amount)
	{
		mname = new char[strlen(name) + 1]();
		strcpy_s(mname, strlen(name) + 1, name);
		mprice = price;
		mamount = amount;
	}

	//拷贝构造函数
	CGoods(const CGoods& rhs)
	{
		mname = new char[strlen(rhs.mname) + 1]();
		strcpy_s(mname, strlen(rhs.mname ) + 1, rhs.mname);
		mprice = rhs.mprice;
		mamount = rhs.mamount;
	}
	
	//赋值运算符重载函数
	CGoods& operator =(const CGoods& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		delete[] mname;
		mname = new char[strlen(rhs.mname) + 1]();
		strcpy_s(mname, strlen(rhs.mname) + 1, rhs.mname);
		mprice = rhs.mprice;
		mamount = rhs.mamount;
	}
	~CGoods()
	{
		delete[] mname;
		mname = NULL;
	}
	void show();
private:
	char* mname;
	double mprice;
	int mamount;
};
void CGoods::show()
{
	std::cout << "商品的名字是：" << mname<<" ";
	std::cout << "商品的价格是：" << mprice<<" ";
	std::cout << "商品的数量是：" << mamount << std::endl;
}

int main()
{
	CGoods good1("面包", 10.0, 200);
	good1.show();
	CGoods good2 = good1;
	good2.show();
	CGoods good3 = good2 = good1;
	good3.show();
	return 0;
}



