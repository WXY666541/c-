#include<iostream>
using namespace std;
#if 0
/*
��������أ�ʹ�����������ֵúͱ�������������һ��

���磺��ģ���У����Ƕ��������µ�sum����
template<typename T>
T sum(T a,T b)
{
	return a+b;
}
������������������ͻ��������㣬�������������������ô���أ�
��������ֻ����ͼ��a�����������ȥ�ҿ���û��һ���ӷ�����
*/
//������
class CComplex
{
public:
	//CComplex() CComplex(20)CComplex(30,30)�������Ͷ������ɹ��캯�����������ֲ�ͬ�ĸ�������
	CComplex(int r = 0,int i =0)
		:mreal(r)
		,mimage(i)
	{}
	//ָ����������ô��CComplex�����ļӷ�����
	CComplex operator+(const CComplex& src)//���ý�����һ�����������
	{
		CComplex comp;//����һ���¶���
		comp.mreal = this->mreal + src.mreal;
		comp.mimage = this->mimage + src.mimage;
		return comp;
		return CComplex(this->mreal + src.mreal,this->mimage+src.mimage);
	}
	CComplex operator++(int)
	{
	/*	CComplex comp = *this;
		mreal += 1;
		mimage += 1;
		return comp;*/
		return CComplex(mreal++, mimage++);//���϶����ֵ���ع�����ʵ���鲿�Ӽӣ�����comp������������Ĺ���
	}
	CComplex& operator++()
	{
		mreal += 1;
		mimage += 1;
		return *this;
	}
	void operator+=(const CComplex& src)
	{
		mreal += src.mreal;
		mimage += src.mimage;
	}
	void show() { cout << "real:" << mreal << "image:" << mimage << endl; }
private:
	int mreal;
	int mimage;
	friend CComplex operator+(const CComplex& lhs, const CComplex& rhs);
	friend ostream& operator<<(ostream& out, const CComplex& src);
	friend istream& operator>>(istream& in, CComplex& src);
};
//��Ϊ�������������˽�г�Ա������������������Ԫ�����������������
CComplex operator+(const CComplex& lhs, const CComplex& rhs)
{
	return CComplex(lhs.mreal + rhs.mreal, rhs.mimage + rhs.mimage);
}
ostream& operator<<(ostream& out, const CComplex& src)
{
	out << "mreal:" << src.mreal << "mimage:" << src.mimage << endl;
	return out;
}
istream& operator>>(istream& in,CComplex& src)
{
	in >> src.mreal >> src.mimage;
	return in;
}
int main()
{
	CComplex comp1(10, 10);
	CComplex comp2(20, 20);
	CComplex comp3 = comp1 + comp2;
	//ȥѰ��comp1�������������û��һ���Ӻŷ�����comp2����һ��ʵ�ν��� comp1.operatpr+(comp2) �ӷ�����������غ���
	//�����������㣬ʵ����������Ա�����ĵ���
	//д������Ҳ��CComplex comp3 = comp1.operator+(comp2);
	comp3.show();

	CComplex comp4 = comp1 + 20;
	//comp1�����˼ӷ���������أ���20����ʵ�δ��롣Ȼ��ʵ�ε��βε�����ǿת������������ת�ɸ���CComplex���ͣ�������ʱ����
	comp4.show();

	CComplex comp5 = 30 + comp2;
	comp5.show();
	//����ģ������û�н�����ת�ɸ������ͣ������������������ʱ�򣬻���ö������������غ��������ȵ��ó�Ա�����������û�г�Ա����
	//����ȫ���������Һ��ʵ���������غ���,��������ȫ�ֵģ��ֲ��Ĵ��붼�������ε�
	//�����������ȫ�ֶ���һ���ӷ���������أ�����30��comp2������ʵ�δ���

	//CComplex operator++(int)
	comp5 = comp1++;//++ --��һ����Ŀ�����operator++() ��ʾǰ��++��operator++(int)��ʾ����++
	comp1.show();
	comp5.show();

	//CComplex operator++()
	comp5 = ++comp1;
	comp1.show();
	comp5.show();

	//���ϸ�ֵ�����comp1.operatpr+=(comp2)
	comp1 += comp2;
	comp1.show();

	//������������
	//cout::operator<<(cout,comp1)
	//ostream& operator<<(ostream &out,const CComplex &src)
	cout << comp1 << endl;
	cin >> comp1 >> comp2;
	cout << comp1 << comp2 << endl;
}
#endif

