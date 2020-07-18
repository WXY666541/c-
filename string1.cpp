#include<iostream>

class String
{
public:
	String(const char* ptr)
	{
		mptr = new char[strlen(ptr) + 1 + 4]();
		mptr += 4;
		strcpy_s(mptr, strlen(ptr) + 1, ptr);
	}
	~String()
	{
		--getRef();
		if (getRef() == 0)
		{
			delete[](mptr - 4);
		}
		mptr = NULL;
	}
	//浅拷贝的拷贝构造函数
	String(const String& rhs)
	{
		mptr = rhs.mptr;
		getRef()++;
	}
	//赋值运算符的重载函数
	String& operator=(const String& rhs)
	{
		if (this != &rhs)
		{
			--getRef();
			if (getRef() == 0)
			{
				delete[](mptr - 4);
			}
			mptr = rhs.mptr;
			getRef()++;
		}
		return *this;
	}

	//深拷贝的[]运算符重载函数
	char& operator[](int index)
	{
		if (getRef() > 1)
		{
			char* tmp = new char[strlen(mptr) + 1 + 4]();
			tmp += 4;
			strcpy_s(tmp, strlen(mptr) + 1, mptr);
			getRef()--;

			mptr = tmp;
			getRef() = 1;
		} 
		return mptr[index];
	}
private:
	int& getRef()
	{
		return *(int*)(mptr - 4);
	}
	char* mptr;
	friend std::ostream& operator<<(std::ostream&, const String&);
};
std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	out << rhs.mptr;
	return out;
}
int main()
{
	String str1("hello");
	std::cout << str1 << std::endl;

	String str2(str1);
	std::cout << str2 << std::endl;

	String str3(str2);
	std::cout << str3 << std::endl;

	String str4("world");
	std::cout << str4 << std::endl;

	str1[0] = 'a';
	std::cout << str1 << std::endl;
	return 0;
}

