#include<iostream>
#pragma warning(disable:4996)
class String
{
public:
	//不带参数的构造函数
	String()
	{
		pstr = new char[1]();
	}

	//带一个参数的构造函数
	String(const char* str)
	{
		pstr = new char[strlen(str) + 1]();
		strcpy_s(pstr,strlen(str)+1, str);
	}

	//拷贝构造函数
	String(const String& rhs)
	{
		pstr = new char[strlen(rhs.pstr) + 1]();
		strcpy_s(pstr, strlen(rhs.pstr) + 1, rhs.pstr);
	}
	//对象+字符串的重载函数
	const String operator+(const char* rhs)
	{
		//首先开辟能容纳对象+字符串的空间
		char* tmp = new char[strlen(pstr) + strlen(rhs) + 1]();
		//将原对象内容拷贝到新开辟的空间中
		strcpy_s(tmp, strlen(pstr) + 1, pstr);
		//将传入的字符串参数连接到原对象字符串后面
		strcat(tmp, rhs);

		String str(tmp);
		delete[] tmp;
		return str;
	}

	//对象+对象
	const String operator+(const String& rhs)
	{
		char* tmp = new char[strlen(pstr) + strlen(rhs.pstr) + 1]();
		strcpy_s(tmp, strlen(pstr) + 1, pstr);
		strcat(tmp, rhs.pstr);

		String str(tmp);
		delete[] tmp;
		return str;
	}
	//大于运算符重载函数
	bool operator>(const String& str)
	{
		return strcmp(pstr, str.pstr) > 0;
	}

	//小于运算符重载函数
	bool operator<(const String& str)
	{
		return strcmp(pstr, str.pstr) < 0;
	}

	//等于运算符重载函数
	bool operator==(const String& str)
	{
		return strcmp(pstr, str.pstr) == 0;
	}
	~String()
	{
		delete[] pstr;
		pstr = NULL;
	}

private:
	char* pstr;
	friend const String operator+(const char* lhs, const String& rhs);
	friend std::ostream& operator<<(std::ostream& out, const String rhs);
	friend std::ostream& operator>>(std::ostream& in, String rhs);
};

//字符串+对象
const String operator+(const char* lhs, const String& rhs)
{
	char* tmp = new char[strlen(lhs) + strlen(rhs.pstr) + 1]();
	strcpy_s(tmp, strlen(lhs) + 1, lhs);
	strcat(tmp, rhs.pstr);

	String str(tmp);
	delete[] tmp;
	return str;
}

//输出运算符重载
std::ostream& operator<<(std::ostream& out, const String rhs)
{
	out << rhs.pstr;
	return out;
}

//输入运算符重载
std::ostream& operator>>(std::ostream& in, String rhs)
{
	in << rhs.pstr;
	return in;
}


int main()
{
	String str1("hello");
	std::cout << "str1为：" << str1 << std::endl;

	String str2 = str1 + "world";
	std::cout << "str1 + world的结果str2为："<< str2 << std::endl;

	String str3 = "hi" + str1;
	std::cout << "hi + str1的结果str3为：" << str3 << std::endl;

	String str4 = str1 + str2;
	std::cout << "str2 + str1的结果str4为：" << str4 << std::endl;


	std::cout << "str1 是否小于str2：";
	if (str1 < str2)
	{
		std::cout << "是"<< std::endl;
	}
	else
	{
		std::cout << "否" << std::endl;
	}

	std::cout << "str3 和str4是否相等：";
	if (str3 == str4)
	{
		std::cout <<"相等"<< std::endl;
	}
	else
	{
		std::cout << "不相等" << std::endl;
	}
	return 0;
}