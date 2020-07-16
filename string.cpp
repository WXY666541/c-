#include<iostream>
using namespace std;

class String
{
public:
	//普通的构造函数
	String(const char* str = nullptr)
	{
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];

			//将外部写入的字符串拷贝给m_data
			strcpy_s(m_data,strlen(str)+1, str);
		}
		//如果传进来的指针为空的话
		else
		{
			m_data = new char[1];
			*m_data = '\0';
		}

	}
	//拷贝构造函数
	String(const String& other)
	{
		m_data = new char[strlen(other.m_data) + 1];
		strcpy_s(m_data,strlen(other.m_data)+1, other.m_data);
	}

	//析构函数
	~String(void)
	{
		delete[] m_data;
		m_data = nullptr;
	}
	
	//赋值运算符重载函数
	String& operator = (const String& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[]m_data;
		m_data = new char[strlen(other.m_data) + 1];
		strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
		return *this;
	}
	void show();
 private:
	char* m_data;
};

void String::show()
{
	std::cout << m_data << std::endl;
}
int main()
{
	String str1;//默认的构造
	str1.show();
	String str2("hello");//调用带const char*参数的构造函数
	str2.show();
	String str3 = "world";
	str3.show();

	//拷贝构造函数测试
	String str4 = str3;
	str4.show();
	String str5(str3);
	str5.show();

	//赋值重载函数函数测试
	str1 = str2;
	str1.show();
	return 0;
}