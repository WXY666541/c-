#include<iostream>

const int MEM_SIZE = 10;
template<typename T>
class MEM_Pool
{
public:
	MEM_Pool()
	{
		pool = NULL;
	}
	void* Alloc(rsize_t size)
	{
		if (pool == NULL)
		{
			pool = (Node*)new char[(size + 4) * MEM_SIZE]();
			Node* pcur = pool;
			for (pcur; pcur + MEM_SIZE - 1; pcur = pcur + 1)
			{
				pcur->pnext = pcur + 1;
			}
			pcur->pnext = NULL;
		}
		void* ptr = pool;
		pool = pool->pnext;
		return ptr;
	}
	void Dealloc(void* ptr)
	{
		Node* pptr = (Node*)ptr;
		if (pptr == NULL)
		{
			return;
		}
		pptr->pnext = pool;
		pool = pptr;
	}
private:
	class Node
	{
	public:
		Node(T val)
			:mdata(val),pnext(NULL)
		{}
	public:
		T mdata;
		Node* pnext;
	};
	Node* pool;
};

class Student
{
public:
	Student(std::string name, std::string id, int age)
		:mname(name), mid(id), mage(age)
	{}
	void* operator new(size_t size)
	{
		return mm.Alloc(size);
	}
	void operator delete(void* ptr)
	{
		mm.Dealloc(ptr);
	}
private:
	std::string mname;
	std::string mid;
	int mage;
	static MEM_Pool<Student> mm;
};
MEM_Pool<Student> Student::mm;

int main()
{
	Student* pstu1 = new Student("zhangsan", "001", 20);
	Student* pstu2 = new Student("wangwu", "002", 30);

	delete pstu2;
	return 0;
}