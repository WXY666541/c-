#include<iostream>
#if 0
class CComplex
{
public:
	CComplex(int r = 0, int i = 0)
		:mreal(r)
		, mimage(i)
	{}
	
	//����+����
	CComplex operator+(const CComplex& src)
	{
		CComplex comp;
		comp.mreal = mreal + src.mreal;
		comp.mimage = mimage + src.mimage;
		return comp;
		return CComplex(mreal + src.mreal, mimage + src.mimage);
	}
	
	//����+����
	const CComplex operator+(int rhs)
	{
		return CComplex(mreal + rhs, mimage);
	}

	//�Ƚ������==
	bool operator==(const CComplex& src)
	{
		return (mreal == src.mreal) && (mimage == src.mimage);
	}

	//�Ƚ������>
	bool operator >(const CComplex& src)
	{
		return (mreal > src.mreal) ||( (mreal > src.mreal) && (mimage > src.mimage));
	}

private:
	int mreal;
	int mimage;

	friend const CComplex operator+(int lhs, const CComplex& rhs);
	friend std::ostream& operator<<(std::ostream& out, const CComplex& src);
	friend std::istream& operator>>(std::istream& in, CComplex& src);
};

//����+����
const CComplex operator+(int lhs, const CComplex& rhs)
{
	return CComplex(lhs + rhs.mreal, rhs.mimage);
}
//��������
std::ostream& operator<<(std::ostream& out, const CComplex& src)
{
	out << "mreal:" << src.mreal << "mimage:" << src.mimage << std::endl;
	return out;
}
//���������
std::istream& operator>>(std::istream& in, CComplex& src)
{
	in >> src.mreal >> src.mimage;
	return in;
}
int main()
{
	//���캯��
	CComplex comp1(10, 10);
	std::cout << "comp1��ֵΪ��";
	std::cout << comp1;

	//����+����
	CComplex comp2 = comp1 + 10;
	std::cout << "comp1+10��ֵΪ��";
	std::cout << comp2;

	//����+����
	CComplex comp3 = 10 + comp1;
	std::cout << "10+comp1��ֵΪ��";
	std::cout << comp3;

	//>�Ƚ������>
	std::cout << "comp2��comp3�ıȽϽ��Ϊ��";
	if (comp2 > comp3)
	{
		std::cout << comp2;
	}
	else
	{
		std::cout << comp3;
	}

	//�Ƚ������==
	std::cout << "comp1��comp3�ıȽϽ��Ϊ��";
	if (comp3 == comp1)
	{
		std::cout << comp1;
	}
	else
	{
		std::cout << "����ȣ�"<<std::endl;
	}

	//���������
	std::cout << "������һ��������";
	std::cin >> comp2;

	//��������
	std::cout << "�����ӡ���Ϊ��";
	std::cout << comp2 << std::endl;
	return 0;
}
#endif
