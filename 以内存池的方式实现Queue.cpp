#include<iostream>

const int Node_count = 10;
template<typename T>
class Queue;
template<typename T>
class Node
{
public:
	Node(T val=T())
		:mdata(val),pnext(NULL)
	{}
	void* operator new(size_t size)
	{
		if (pool == NULL)
		{
			pool = (Node<T>*)new char[size * Node_count];
			Node<T>* pcur = pool;
			for (pcur; pcur < pool + Node_count - 1; pcur = pcur + 1)
			{
				pcur->pnext = pcur + 1;
			}
			pcur->pnext = NULL;
		}
		void* ptr = pool;
		pool = pool->pnext;
		return ptr;
	}
	void operator delete(void* ptr)
	{
		Node<T>* pqtr = (Node<T>*)ptr;
		pqtr->pnext = pool;
		pool = pqtr;
	}
private:
	template<typename T>
	friend class Queue;
	T mdata;
	Node<T>* pnext;
	static Node<T>* pool;
};

template<typename T>
Node<T>* Node<T>::pool = NULL;

template<typename T>
class Queue
{
public:
	Queue()
	{
		phead = ptail = new Node<T>();
	}
	void push(T val)
	{
		Node<T>* pnewnode = new Node<T>(val);
		ptail->pnext = pnewnode;
		ptail = ptail->pnext;
	}
	bool empty()
	{
		return (phead == ptail) && (phead != NULL);
	}
	void pop()
	{
		if (empty())
		{
			return;
		}
		Node<T>* pcur = phead->pnext;
		phead->pnext = pcur->pnext;
		delete pcur;
	}
	T back()
	{
		if (empty())
		{
			throw std::exception("queue is empty!");
		}
		return ptail->mdata;
	}
	T front()
	{
		if (empty())
		{
			throw std::exception("queue is empty!");
		}
		return phead->pnext->mdata;
	}
	~Queue()
	{
		Node<T>* pcur = phead;
		Node<T>* pNext;
		while (pcur != NULL)
		{
			pNext = pcur->pnext;
			delete pcur;
			pcur = pNext;
		}
		phead = NULL;
	}
private:
	Node<T>* phead;
	Node<T>* ptail;
};

int main()
{
	Queue<int> que;
	for (int i = 0; i < 5; i++)
	{
		que.push(i + 1);
	}
	que.pop();
	auto qfront = que.front();
	auto qback = que.back();
	std::cout << "queue front:" << qfront << std::endl;
	std::cout << "queue qback:" << qback << std::endl;
	return 0;
}