#include<iostream>
#pragma warning(disable:4996)
class String
{
public:
	//���������Ĺ��캯��
	String()
	{
		pstr = new char[1]();
	}

	//��һ�������Ĺ��캯��
	String(const char* str)
	{
		pstr = new char[strlen(str) + 1]();
		strcpy_s(pstr,strlen(str)+1, str);
	}

	//�������캯��
	String(const String& rhs)
	{
		pstr = new char[strlen(rhs.pstr) + 1]();
		strcpy_s(pstr, strlen(rhs.pstr) + 1, rhs.pstr);
	}
	//����+�ַ��������غ���
	const String operator+(const char* rhs)
	{
		//���ȿ��������ɶ���+�ַ����Ŀռ�
		char* tmp = new char[strlen(pstr) + strlen(rhs) + 1]();
		//��ԭ�������ݿ������¿��ٵĿռ���
		strcpy_s(tmp, strlen(pstr) + 1, pstr);
		//��������ַ����������ӵ�ԭ�����ַ�������
		strcat(tmp, rhs);

		String str(tmp);
		delete[] tmp;
		return str;
	}

	//����+����
	const String operator+(const String& rhs)
	{
		char* tmp = new char[strlen(pstr) + strlen(rhs.pstr) + 1]();
		strcpy_s(tmp, strlen(pstr) + 1, pstr);
		strcat(tmp, rhs.pstr);

		String str(tmp);
		delete[] tmp;
		return str;
	}
	//������������غ���
	bool operator>(const String& str)
	{
		return strcmp(pstr, str.pstr) > 0;
	}

	//С����������غ���
	bool operator<(const String& str)
	{
		return strcmp(pstr, str.pstr) < 0;
	}

	//������������غ���
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

//�ַ���+����
const String operator+(const char* lhs, const String& rhs)
{
	char* tmp = new char[strlen(lhs) + strlen(rhs.pstr) + 1]();
	strcpy_s(tmp, strlen(lhs) + 1, lhs);
	strcat(tmp, rhs.pstr);

	String str(tmp);
	delete[] tmp;
	return str;
}

//������������
std::ostream& operator<<(std::ostream& out, const String rhs)
{
	out << rhs.pstr;
	return out;
}

//�������������
std::ostream& operator>>(std::ostream& in, String rhs)
{
	in << rhs.pstr;
	return in;
}


int main()
{
	String str1("hello");
	std::cout << "str1Ϊ��" << str1 << std::endl;

	String str2 = str1 + "world";
	std::cout << "str1 + world�Ľ��str2Ϊ��"<< str2 << std::endl;

	String str3 = "hi" + str1;
	std::cout << "hi + str1�Ľ��str3Ϊ��" << str3 << std::endl;

	String str4 = str1 + str2;
	std::cout << "str2 + str1�Ľ��str4Ϊ��" << str4 << std::endl;


	std::cout << "str1 �Ƿ�С��str2��";
	if (str1 < str2)
	{
		std::cout << "��"<< std::endl;
	}
	else
	{
		std::cout << "��" << std::endl;
	}

	std::cout << "str3 ��str4�Ƿ���ȣ�";
	if (str3 == str4)
	{
		std::cout <<"���"<< std::endl;
	}
	else
	{
		std::cout << "�����" << std::endl;
	}
	return 0;
}