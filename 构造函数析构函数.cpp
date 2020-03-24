#include<iostream>
#include<string.h>
using namespace std;
#if 0
/*
���캯������������
���������ֺ�������һ����û�з���ֵ
*/
//oopʵ��һ��˳��ջ
class SeqStack
{
public:
	//���캯�����ǿ��Դ������ģ���˿����ṩ������캯���������غ�init�Ĺ���һ�������캯��һ����������������
	SeqStack(int size = 10)
	{
		cout << this << "SeqStack()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//�����Ա�����ĳ�ʼ������
	void init(int size = 10)
	{
		_pstack = new int[size];
		_top = -1;
		_size = size;
	} 
	//��������������������������������ֻ����һ�����������ʱ���Զ����ã����󼴲�������
	~SeqStack()
	{
		cout << this << "~SeqStack()" << endl;
		delete[] _pstack;
		_pstack = nullptr;
	}
	//�ͷŶ����Ա����ռ�õ��ⲿ���ڴ棨�ⲿ��Դ��
	void release()
	{
		delete[] _pstack;
		_pstack = nullptr;
	}
	void push(int val)
	{
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty() { return _top == -1; }
	bool full() { return _top == _size - 1; }
private:
	int* _pstack;//��̬�������飬�洢˳��ջ��Ԫ��
	int _top;//ָ��ջ��Ԫ�ص�λ��
	int _size;//�������ݵ��ܴ�С
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		//Ϊʲô����memcpy(ptmp,_pstack,sizeof(int)*_size);realloc
		//��Ϊ���漰�����ڴ濽�����ڶ������������⣬��Ϊ�п������ݵ��Ƕ����������
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
SeqStack gs;
int main()
{
	//1.�����ڴ� 2.���ù��캯��
	SeqStack s;//������ջ�ϣ�ָ�����һ�����ϵ��ڴ�

	SeqStack* ps = new SeqStack(60);//�����ڣ�.heap)������malloc�ڴ濪��+SeqStack��60�����������
	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << endl;
	delete ps;//���ϵĶ���Ҫ�Լ��ֶ��ͷ� delete(�ȵ���ps->~SeqStack()Ȼ��free(ps))


	//s.init(5);
	for (int i = 0; i < 15; ++i)
	{
		s.push(rand() % 100);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	SeqStack s1(50);//���캯���ĵ��ÿ��Բ��ö��󣬸��ݴ����������ƥ��
	//s1.~SeqStack();//���������ĵ���Ҫ�ж�����Ϊ��û�е�������֮ǰ����û����ʧ
	//s1.push(30);//��ʱ���øö���ķ�������ڶ��ڴ�ķǷ����ʣ����Բ������Լ�������������
	return 0;
}
#endif

