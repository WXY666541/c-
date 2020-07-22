#include<iostream>

template<typename T>
class Ref_Mangement
{
public:
	Ref_Mangement()
	{
		current = 0;
	}
	void addRef(void* ptr)
	{
		int index = Findindex(ptr);
		if (index < 0)
		{
			node[current].addr = ptr;
			node[current].count = 1;
			current++;
		}
		else
		{
			node[index].count++;
		}
	}

	//��ȡ���ü���
	int getRef(void* ptr)
	{
		int index = Findindex(ptr);
		if (index < 0)
		{
			return -1;
		}
		else
		{
			return node[index].count;
		}
	}

	//ɾ�����ü���
	void delRef(void* ptr)
	{
		int index = Findindex(ptr);
		if (index < 0)
		{
			throw std::exception("ref is error!");
		}
		else
		{
			if (getRef(ptr) > 0)
			{
				node[index].count--;
			}
		}
	}
private:
	int Findindex(void* ptr)
	{
		for (int i = 0; i < 10; i++)
		{
			if(node[i].addr == ptr)
			{
				return i;
			}
		}
		return -1;
	}

	//���ü��������
	class Node
	{
	public:
		Node(void* add = NULL,int cnt = 0)
			:addr(add),count(cnt)
		{}
	public:
		void* addr;
		int count;
	};
	Node node[10];//��10�������ɵ����ü�������
	int current;//����ס������ЧԪ�صĸ���
};

template<typename T>
class Shared_Ptr
{
public:
	Shared_Ptr(T* ptr)
		:mptr(ptr)
	{
		rm.addRef(mptr);
	}
	~Shared_Ptr()
	{
		rm.delRef(mptr);
		if (rm.getRef(mptr) == 0)
		{
			delete mptr;
		}
		mptr = NULL;
	}
	//�������캯����ʵ��
	Shared_Ptr(const Shared_Ptr<T>& rhs)
	{
		mptr = rhs.mptr;
		rm.addRef(mptr);
	}

	//��ֵ��������غ�����ʵ��
	Shared_Ptr<T> operator=(const Shared_Ptr<T>& rhs)
	{
		if (this != &rhs)
		{
			rm.delRef(mptr);
			if (rm.getRef(mptr) == 0)
			{
				delete mptr;
			}
			mptr = rhs.mptr;
			rm.addRef(mptr);
		}
		return *this;
	}
	T* operator->()
	{
		return mptr;
	}
	T& operator*()
	{
		return *mptr;
	}
private:
	T* mptr;
	static Ref_Mangement<T> rm;
};

template<typename T>
Ref_Mangement<T> Shared_Ptr<T>::rm;

int main()
{
	int* p = new int;
	Shared_Ptr<int> sp1(p);
	Shared_Ptr<int> sp2(p);
	Shared_Ptr<int> sp3(p);

	Shared_Ptr<int> sp4(new int);
	sp2 = sp4;
	return 0;
}
