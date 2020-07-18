#include<iostream>
#include<list>

#pragma warning(disable:4996);
class String;
class Iterator
{
public:
	//构造函数
	Iterator(String& str, int idx) 
		:pstring(&str), index(idx) {}

	//!=的运算符重载函数
	bool operator!=(const Iterator& rhs)
	{
		return index != rhs.index;
	}

	char& operator*();
	//后置加加
	const Iterator operator++(int)
	{
		const Iterator tmp(*this);
		index++;
		return tmp;
	}
	//前置加加
	Iterator& operator++()
	{
		index++;
		return *this;
	}
private:
	String* pstring;
	int index;
};
class String
{
public:
	typedef Iterator iterator;
	String()
	{
		pstr = new char[1]();
	}
	String(const char* str)
	{
		pstr = new char[strlen(str) + 1]();
		strcpy(pstr, str);
	}
	String& operator=(const String& rhs)
	{
		if (this != &rhs)
		{
			delete[] pstr;
			pstr = new char[strlen(rhs.pstr) + 1];
			strcpy(pstr, rhs.pstr);
		}
		return *this;
	}
	String(const String& rhs)
	{
		pstr = new char[strlen(rhs.pstr) + 1]();
		strcpy(pstr, rhs.pstr);
	}
	~String()
	{
		delete[] pstr;
		pstr = NULL;
	}
	iterator begin()
	{
		return iterator(*this, 0);
	}
	iterator end()
	{
		return iterator(*this, strlen(pstr));
	}

	const String operator+(const char* prhs)
	{
		int len = strlen(pstr) + strlen(prhs) + 1;
		char* ptmp = new char[len]();
		strcat(ptmp, pstr);
		strcat(ptmp, prhs);
		String tmp(ptmp);
		delete[] ptmp;
		return tmp;
	}
	bool operator<(const String& rhs)
	{
		return strcmp(pstr, rhs.pstr) < 0;
	}
	bool operator!=(const String& rhs)
	{
		return strcmp(pstr, rhs.pstr) != 0;
	}
	char& operator[](int index)
	{
		return pstr[index];
	}
private:
	char* pstr;
	friend const String operator+(const char*, const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
};
const String operator+(const char* plhs, const String& rhs)
{
	int len = strlen(plhs) + strlen(rhs.pstr) + 1;
	char* ptmp = new char[len]();
	strcat(ptmp, plhs);
	strcat(ptmp, rhs.pstr);
	String tmp(ptmp);
	delete[] ptmp;
	return tmp;
}

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	out << rhs.pstr;
	return out;
}
std::istream& operator>>(std::istream& in, String& rhs)
{
	char ptmp[1000] = { 0 };
	in >> ptmp;
	rhs = String(ptmp);
	return in;
}
char& Iterator::operator*()
{
	return (*pstring)[index];
}


int main()
{
	String str1("hello");
	Iterator it = str1.begin();
	while (it != str1.end())
	{
		std::cout << *it ;
		it++;
	}
	std::cout << std::endl;

	return 0;
}
