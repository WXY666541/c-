#include<iostream>
using namespace std;
#if 0
/*
oop面向对象 opp编程 
c:各种各样的函数的定义
c++:类===>实体的抽象类型
实体（属性、行为）  -》ADT(abstract data type)类（属性-->成员变量 行为--》成员方法
对象《-----实例化 类（属性-->成员变量 行为--》成员方法
类描述一个商品实体
*/
/*
CGoods可以定义无数个对象，每一个对象都有自己的成员变量，但他们共享一套成员方法
对象内存大小之和成员变量有关
*/
//定义类，C语言里面用struct
//oop语言的四大特征：抽象 封装（隐藏） 继承 多态
const int NAME_LEN = 20;
class CGoods//商品的抽象数据类型，不占空间
{
public://给外部提供共有的方法，来访问私有的属性
	void init(const char* name, double price, int amount);//做商品数据初始化
	void show();//打印商品信息
	//设置一个接口单独访问成员变量或者获取成员变量的值，给成员变量提供一组getXXX或setXXX的方法
	//类体内实现的方法，自动处理成inline内联函数
	void setName(char* name) { strcpy(_name, name); }//给对象的成员变量赋值
	void setPrice(double price) { _price = price ;}
	void setAmount(int amount) { _amount = amount ;}

	const char* getName() {return _name;}//防止name被修改
	double getPrice() { return _price ;}
	int getAmount() { return _amount; }



private://属性一般都是私有的
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
//类外定义的方法一定要在类的函数名前面加作用域，是普通函数，如果要成为内联函数要显式添加inline
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << _name << endl;
	cout << "price:" << _price << endl;
	cout << "amount:" << _amount << endl;
}
int main()
{
	CGoods good1;//类实例化了一个对象，对象占用空间，在栈上
	good1.init("面包", 10.0, 200);
	good1.show();
	good1.setPrice(20.5);
	good1.setAmount(100);
	good1.show();

	CGoods good2;
	good2.init("空调", 10000.0, 50);
	good2.show();

	return 0;
}
/*
this指针:在方法里面去区分不同对象
init( name, price, amount)怎么知道把信息初始化给哪一个对象呢？
good1.init("面包", 10.0, 200);实际上是把good1.init(&good1,"面包", 10.0, 200);对象地址传入了的
类的成员方法一经编译，所有的方法参数，都会加一个this指针，接收调用该方法的对象的地址
为什么一套方法可以处理多个对象呢？
因为当对象调用方法的时候，他就把对象的地址通过实参传给其函数，这些函数就会用编译时候生成的tils指针来接受
说传入对象的地址
*/
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	this->_price = price;
	this->_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << this->_name << endl;
	cout << "price:" << this->_price << endl;
	cout << "amount:" << this->_amount << endl;
}
#endif