#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<stack>
#include<queue>//queue 和priority_queue
using namespace std;
#if 0
/*
标准容器-容器适配器 => 设计模式就叫做适配器模式（相当于就是deque把stack代理了一下）
怎么理解这个适配器？
1、适配器底层没有自己的数据结构，他是另外一个容器的封装他的方法，全部由底层依赖的容器进行实现
2、没有实现自己的迭代器

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
	//priority_queue:push入队 pop出队 top查看队顶元素  size返回元素个数 empty判断队空
	依赖vector
	底层默认把数据组成一个大根堆结构，在一个内存连续的数组上构建一个大根堆或者小根堆，堆的每一个结点与数组坐标之间有关系，
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
	queue:push入队 pop出队 front查看队头元素 back查看队尾元素 size返回元素个数 empty判断队空
	依赖deque
	1、vector的初始使用效率太低了  vector 0-1-2-4-8  deque 4096/size(T)
	2、对于queue来说，需要支持尾部插入，头部删除 O(1) 如果queue依赖vector其底层出队效率很低
	3、vector需要大片连续内存，deque只需要分段的内存，当存储大量数据时，显然deque对于内存的利用率更好一些
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
	 stack:push入栈 pop出栈 top查看栈顶元素 empty判断栈空 size返回元素个数
	 依赖deque
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