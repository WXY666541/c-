#include<iostream>
#include<string.h>
using namespace std;
/*
***************************************
����һ���������г�����������ʲô��
***************************************
*/
#if 0
class Animal
{
public:
	Animal(string name) :_name(name) {}
	//���麯��
	virtual void bark() = 0;
protected:
	string _name;
};
//�����Ƕ���ʵ����
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:wang wang!" << endl; }
};
int main()
{
	Animal* p1 = new Cat("�ӷ�è");//vfptr -> Dog vftable
	Animal* p2 = new Dog("����");//vfptr -> Cat vftable

	int* p11 = (int*)p1;
	int* p22 = (int*)p2;
	int tmp = p11[0];//p11[0]���ʵľ���Cat��ǰ4���ֽ�
	p11[0] = p22[0];//p22[0]���ʵľ���Dog��ǰ4���ֽ�
	p22[0] = tmp;

	p1->bark();//p1 -> Cat vfptr -> Dog vftable bark
	p2->bark();//p1 -> Dog vfptr -> Cat vftable bark

	delete p1;
	delete p2;

	return 0;
}

/*
***************************************
��������������г�����������ʲô��
***************************************
*/
/*
���õ�����������show��������������ĺ����β�ȴ�ǻ���ĺ����β�ֵ10
ԭ����Ϊ�Ƕ�̬�󶨣������������showֻ�������е�ʱ���֡�����׶�ֻ�ܿ������������show��
������ջpush 0Ah
        mov eax, dword ptr[p]
		mov ecx, dword ptr[eax]
		call ecx
�������������βε�Ĭ��ֵ�Ѿ�û���˹�ϵ,ѹջֵ�Ѿ�ȷ������
*/
class Base
{
public:
	virtual void show(int i = 10)
	{
		cout << "call Base::show i :" << i << endl;
	}
};
class Derive : public Base
{
public :
	void show(int i = 20)
	{
		cout << "call Derive::show i :" << i << endl;
	}
};
int main()
{
	Base* p = new Derive();//����������
	p->show();
	delete p;
	return 0;
}

/*
**********************************************
���������������г��������෽���ܲ��ܽ��е��ã�
***********************************************
*/
/*
����
��Ϊ �����ܵ��õ�Derive::show��������ʱ�ڲ�ȷ���ġ������ķ���Ȩ���ǲ���public�ģ����ڱ���׶ξ���Ҫȷ���õģ�
����ڱ���׶�ֻ�ܿ���Base::show,��Ϊ�������������ָ����Baseָ�룬Ϊpublic�Ŀ��Է��ʡ�
����Ȩ�޵�����ֻ���ڱ���׶ο��﷨�Ƿ������������д���ĳɻ���Ϊprivate ������Ϊpublic����������гɹ�
*/
class Base
{
public:
	virtual void show()
	{
		cout << "call Base::show i :" << endl;
	}
};
class Derive : public Base
{
private:
	void show()
	{
		cout << "call Derive::show i :" << endl;
	}
};
int main()
{
	Base* p = new Derive();
	p->show();
	delete p;
	return 0;
}
#endif
/*
******************************************************
�����ģ��������г��������Ƿ���ȷ������Ļ�ԭ����ʲô��
******************************************************
*/
/*
ǰһ�������⣬���������������
*/
class Base
{
public:
	Base()
	{
		/*
		push ebp  ���÷�������ջ�׵�ַѹջ���뵱ǰ������ջ��
		mov ebp,esp
		sub esp ,4Ch
		rep stos esp<->ebp 0xcccccccc
		vfptr <- &Base ::vftable
		*/
		cout << "call Base()" << endl;
		clear();
	}
	void clear() { memset(this, 0, sizeof(*this)); }
	virtual void show()
	{
		cout << "call Base::show():" << endl;
	}
};
class Derive : public Base
{
public:
	Derive()
	{
		/*
		push ebp  ���÷�������ջ�׵�ַѹջ���뵱ǰ������ջ��
		mov ebp,esp
		sub esp ,4Ch
		rep stos esp<->ebp 0xcccccccc
		vfptr <- &Derive ::vftable
		*/
		cout << "call Derive()" << endl;
	}
	void show()
	{
		cout << "call Derive::show ()" << endl;
	}
};
int main()
{
	Base* pb1 = new Base();
	/*
	    mov eax, dword ptr[pb1]
		mov ecx, dword ptr[eax] eax:0x00000000 ����Base::vftable 
		call ecx
	*/
	pb1->show();//��̬��
	delete pb1;

	Base* pb2 = new Derive();
	/*
	vfptr����洢����vftable�ĵ�ַ
	vfptr <- vftable��vftable�ĵ�ַд��vfptr�������ָ������ջ֡׼���ã�����ִ��֮ǰ
	*/
	pb2->show();//��̬��
	delete pb2;

	return 0;
}