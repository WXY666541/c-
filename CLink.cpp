#include<iostream>

class Node
{
public:
	Node(int data = 0);
private:
	int mdata;
	Node* pnext;
	friend class CLink;
};
Node::Node(int data)
{
	mdata = data;
	pnext = NULL;
}

class CLink
{
public:
	CLink();
	~CLink();
	void InsertHead(int val);
	void InsertTail(int val);

	bool Empty();
	bool DeleteHead();
	bool DeleteTail();

	void show();
private:
	Node* phead;
};

CLink::~CLink()
{
	Node* pCur = phead;
	Node* pNext;
	while (pCur != NULL)
	{
		pNext = pCur->pnext;
		delete pCur;
		pCur = pNext;
	}
	phead = NULL;
}

void CLink::InsertHead(int val)
{
	Node* pnewnode = new Node(val);
	pnewnode->pnext = phead->pnext;
	phead->pnext = pnewnode;
}

void CLink::InsertTail(int val)
{
	Node* pnewnode = new Node(val);

	Node* ptail = phead;
	while (ptail->pnext != NULL)
	{
		ptail = ptail->pnext;
	}
	ptail->pnext = pnewnode;
}

bool CLink::Empty()
{
	return phead->pnext == NULL;
}

bool CLink::DeleteHead()
{
	if (Empty())
	{
		return false;
	}
	Node* pFirst = phead->pnext;
	phead->pnext = pFirst->pnext;
	delete  pFirst;
	return true;
}

bool CLink::DeleteTail()
{
	if (Empty())
	{
		return false;
	}
	Node* ptail2 = phead;
	Node* ptail1 = ptail2->pnext;

	while (ptail1->pnext != NULL)
	{
		ptail2 = ptail2->pnext;
		ptail1 = ptail2->pnext;
	}
	ptail2->pnext = NULL;
	delete ptail1;
	return true;
}

void CLink::show()
{
	Node* pCur = phead->pnext;
	while (pCur != NULL)
	{
		std::cout << pCur->mdata << " ";
		pCur = pCur->pnext;
	}
	std::cout << std::endl;
}

int main()
{
	CLink cl;
	for (int i = 0; i < 5; i++)
	{
		cl.InsertHead(i + 1);
	}
	cl.show();
	for (int i = 0; i < 5; i++)
	{
		cl.InsertTail(i + 1);
	}
	cl.show();
	cl.DeleteHead();
	cl.show();
	cl.DeleteTail();
	cl.show();
	return 0;
}


