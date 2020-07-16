#include<iostream>
#include<string>


/*
   ��oop��˼��ģ��ʵ��һ����Ʒ��
*/

class CGoods
{
public:
	//���캯��
	CGoods(const char* name, float price, int amount)
	{
		mname = new char[strlen(name) + 1]();
		strcpy_s(mname, strlen(name) + 1, name);
		mprice = price;
		mamount = amount;
	}

	//�������캯��
	CGoods(const CGoods& rhs)
	{
		mname = new char[strlen(rhs.mname) + 1]();
		strcpy_s(mname, strlen(rhs.mname ) + 1, rhs.mname);
		mprice = rhs.mprice;
		mamount = rhs.mamount;
	}
	
	//��ֵ��������غ���
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
	std::cout << "��Ʒ�������ǣ�" << mname<<" ";
	std::cout << "��Ʒ�ļ۸��ǣ�" << mprice<<" ";
	std::cout << "��Ʒ�������ǣ�" << mamount << std::endl;
}

int main()
{
	CGoods good1("���", 10.0, 200);
	good1.show();
	CGoods good2 = good1;
	good2.show();
	CGoods good3 = good2 = good1;
	good3.show();
	return 0;
}



