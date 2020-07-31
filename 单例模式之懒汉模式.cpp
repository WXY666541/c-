#include<iostream>
class Rector
{
public:
	static Rector* getInstance(const char* name, int age, bool sex)
	{
		if (pre == NULL)
		{
			pre = new Rector(name, age, sex);
		}
		return pre;
	}
	static void show()
	{
		std::cout << "----唯一的校长信息---" << std::endl;
		std::cout << "name: " << pre->mname << std::endl;
		std::cout << "age: " << pre->mage << std::endl;
		std::cout << "sex: " << pre->msex << std::endl;
		std::cout << "---------------------" << std::endl;
	}
private:
	Rector(const char* name, int age, bool sex)
	{
		mname = new char[strlen(name) + 1]();
		strcpy_s(mname, strlen(name) + 1, name);
		mage = age;
		msex = sex;
	}
	char* mname;
	int mage;
	bool msex;
	static Rector* pre;
};
Rector* Rector::pre = NULL;

int main()
{
	Rector* pr1 = Rector::getInstance("zhangsan", 45, true);
	Rector* pr2 = Rector::getInstance("zhangsan", 45, true);
	Rector* pr3 = Rector::getInstance("zhangsan", 45, true);
    Rector::show();
	std::cout << "pr1" << pr1 << std::endl;
	std::cout << "pr2" << pr2 << std::endl; 
	std::cout << "pr3" << pr3 << std::endl;
	return 0;
}

