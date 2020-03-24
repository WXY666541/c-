#include<iostream>
using namespace std;
#if 0
/*
oop������� opp��� 
c:���ָ����ĺ����Ķ���
c++:��===>ʵ��ĳ�������
ʵ�壨���ԡ���Ϊ��  -��ADT(abstract data type)�ࣨ����-->��Ա���� ��Ϊ--����Ա����
����-----ʵ���� �ࣨ����-->��Ա���� ��Ϊ--����Ա����
������һ����Ʒʵ��
*/
/*
CGoods���Զ�������������ÿһ���������Լ��ĳ�Ա�����������ǹ���һ�׳�Ա����
�����ڴ��С֮�ͳ�Ա�����й�
*/
//�����࣬C����������struct
//oop���Ե��Ĵ����������� ��װ�����أ� �̳� ��̬
const int NAME_LEN = 20;
class CGoods//��Ʒ�ĳ����������ͣ���ռ�ռ�
{
public://���ⲿ�ṩ���еķ�����������˽�е�����
	void init(const char* name, double price, int amount);//����Ʒ���ݳ�ʼ��
	void show();//��ӡ��Ʒ��Ϣ
	//����һ���ӿڵ������ʳ�Ա�������߻�ȡ��Ա������ֵ������Ա�����ṩһ��getXXX��setXXX�ķ���
	//������ʵ�ֵķ������Զ������inline��������
	void setName(char* name) { strcpy(_name, name); }//������ĳ�Ա������ֵ
	void setPrice(double price) { _price = price ;}
	void setAmount(int amount) { _amount = amount ;}

	const char* getName() {return _name;}//��ֹname���޸�
	double getPrice() { return _price ;}
	int getAmount() { return _amount; }



private://����һ�㶼��˽�е�
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
//���ⶨ��ķ���һ��Ҫ����ĺ�����ǰ�������������ͨ���������Ҫ��Ϊ��������Ҫ��ʽ���inline
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << _name << endl;
	cout << "price:" << _price << endl;
	cout << "amount:" << _amount << endl;
}
int main()
{
	CGoods good1;//��ʵ������һ�����󣬶���ռ�ÿռ䣬��ջ��
	good1.init("���", 10.0, 200);
	good1.show();
	good1.setPrice(20.5);
	good1.setAmount(100);
	good1.show();

	CGoods good2;
	good2.init("�յ�", 10000.0, 50);
	good2.show();

	return 0;
}
/*
thisָ��:�ڷ�������ȥ���ֲ�ͬ����
init( name, price, amount)��ô֪������Ϣ��ʼ������һ�������أ�
good1.init("���", 10.0, 200);ʵ�����ǰ�good1.init(&good1,"���", 10.0, 200);�����ַ�����˵�
��ĳ�Ա����һ�����룬���еķ��������������һ��thisָ�룬���յ��ø÷����Ķ���ĵ�ַ
Ϊʲôһ�׷������Դ����������أ�
��Ϊ��������÷�����ʱ�����ͰѶ���ĵ�ַͨ��ʵ�δ����亯������Щ�����ͻ��ñ���ʱ�����ɵ�tilsָ��������
˵�������ĵ�ַ
*/
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	this->_price = price;
	this->_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << this->_name << endl;
	cout << "price:" << this->_price << endl;
	cout << "amount:" << this->_amount << endl;
}
#endif