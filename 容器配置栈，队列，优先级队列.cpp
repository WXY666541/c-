#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<stack>
#include<queue>//queue ��priority_queue
using namespace std;
#if 0
/*
��׼����-���������� => ���ģʽ�ͽ���������ģʽ���൱�ھ���deque��stack������һ�£�
��ô��������������
1���������ײ�û���Լ������ݽṹ����������һ�������ķ�װ���ķ�����ȫ���ɵײ���������������ʵ��
2��û��ʵ���Լ��ĵ�����

template<typename T,typename Container = deque<T>>
class Stack
{
public:
	void push(const T& val) { con.push_back(val); }
	void pop() { con.pop_back(); }
	T top()const { return con.back(); }
private:
	Container con;
};
*/
int main()
{/*
	//priority_queue:push��� pop���� top�鿴�Ӷ�Ԫ��  size����Ԫ�ظ��� empty�ж϶ӿ�
	����vector
	�ײ�Ĭ�ϰ��������һ������ѽṹ����һ���ڴ������������Ϲ���һ������ѻ���С���ѣ��ѵ�ÿһ���������������֮���й�ϵ��
	priority_queue<int> pque;
	for (int i = 0; i < 20; i++)
	{
		pque.push(rand() % 100 + 1);
	}
	while (!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
	queue:push��� pop���� front�鿴��ͷԪ�� back�鿴��βԪ�� size����Ԫ�ظ��� empty�ж϶ӿ�
	����deque
	1��vector�ĳ�ʼʹ��Ч��̫����  vector 0-1-2-4-8  deque 4096/size(T)
	2������queue��˵����Ҫ֧��β�����룬ͷ��ɾ�� O(1) ���queue����vector��ײ����Ч�ʺܵ�
	3��vector��Ҫ��Ƭ�����ڴ棬dequeֻ��Ҫ�ֶε��ڴ棬���洢��������ʱ����Ȼdeque�����ڴ�������ʸ���һЩ
	queue<int> que;
	for (int i = 0; i < 20; i++)
	{
		que.push(rand() % 100 + 1);
	}
	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}
	 stack:push��ջ pop��ջ top�鿴ջ��Ԫ�� empty�ж�ջ�� size����Ԫ�ظ���
	 ����deque
	stack<int> s1;
	for (int i = 0; i < 20; i++)
	{
		s1.push(rand() % 100 + 1);
	}
	while (!s1.empty())
	{
		cout << s1.top() << endl;
		s1.pop();
	}*/
	return 0;
}
#endif