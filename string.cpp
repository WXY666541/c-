#include<iostream>
using namespace std;

class String
{
public:
	//��ͨ�Ĺ��캯��
	String(const char* str = nullptr)
	{
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];

			//���ⲿд����ַ���������m_data
			strcpy_s(m_data,strlen(str)+1, str);
		}
		//�����������ָ��Ϊ�յĻ�
		else
		{
			m_data = new char[1];
			*m_data = '\0';
		}

	}
	//�������캯��
	String(const String& other)
	{
		m_data = new char[strlen(other.m_data) + 1];
		strcpy_s(m_data,strlen(other.m_data)+1, other.m_data);
	}

	//��������
	~String(void)
	{
		delete[] m_data;
		m_data = nullptr;
	}
	
	//��ֵ��������غ���
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
	String str1;//Ĭ�ϵĹ���
	str1.show();
	String str2("hello");//���ô�const char*�����Ĺ��캯��
	str2.show();
	String str3 = "world";
	str3.show();

	//�������캯������
	String str4 = str3;
	str4.show();
	String str5(str3);
	str5.show();

	//��ֵ���غ�����������
	str1 = str2;
	str1.show();
	return 0;
}