#include<iostream>
 
class Rector
{
public:
	static Rector* getInstance()
	{
		return reator;
	}
	static void show()
	{
		std::cout << "----唯一的校长信息---" << std::endl;
		std::cout << "name: " << reator->mname << std::endl;
		std::cout << "age: " << reator->mage << std::endl;
		std::cout << "sex: " << reator->msex << std::endl;
		std::cout << "---------------------" << std::endl;
	}
private:
	Rector(const  char* name, int age, bool sex)//构造函数
	{
		mname = new char[strlen(name) + 1]();
		strcpy_s(mname, strlen(name) + 1, name);
		mage = age;
		msex = sex;
		std::cout << "Rector finsh" << std::endl;
	}
	Rector(const Rector&);//拷贝构造函数
    char* mname;
	int mage;
	bool msex;
	static Rector* reator;//指向唯一的对象
};
Rector* Rector::reator = new Rector("wxy",21,false);//饿汉模式，提前生成唯一的对象

int main()
{
	Rector* pr1 = Rector::getInstance();
	Rector* pr2 = Rector::getInstance();
	Rector* pr3 = Rector::getInstance();
	Rector::show();
	std::cout << "pr1" << pr1 << std::endl;
	std::cout << "pr2" << pr2 << std::endl; 
	std::cout << "pr3" << pr3 << std::endl;
}
