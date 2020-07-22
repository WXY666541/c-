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

	//获取引用计数
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

	//删除引用计数
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

	//引用计数结点类
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
	Node node[10];//由10个结点组成的引用计数对象
	int current;//代表住里面有效元素的个数
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
	//拷贝构造函数的实现
	Shared_Ptr(const Shared_Ptr<T>& rhs)
	{
		mptr = rhs.mptr;
		rm.addRef(mptr);
	}

	//赋值运算符重载函数的实现
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
	T* getPtr() const
	{
		return mptr;
	}
private:
	T* mptr;
	static Ref_Mangement<T> rm;
};

template<typename T>
Ref_Mangement<T> Shared_Ptr<T>::rm;

template<typename T>
class Weak_ptr
{
public:
	Weak_ptr(T* ptr = NULL)
		:mptr(ptr)
	{}
	~Weak_ptr()
	{}
	Weak_ptr(const Weak_ptr<T>& rhs)
	{
		mptr = rhs.mptr;
	}
	Weak_ptr<T>& operator=(const Weak_ptr<T>& rhs)
	{
		if (this != &rhs)
		{
			mptr = rhs.mptr;
		}
		return *this;
	}
	Weak_ptr<T>& operator=(const Shared_Ptr<T>& rhs)
	{
		mptr = rhs.getPtr();
		return *this;
	}
private:
	T* mptr;
};

class B;
class A
{
public:
	A()
	{
		std::cout << "A::A()" << std::endl;
	}
	~A()
	{
		std::cout << "A::~A()" << std::endl;
	}
public:
	Weak_ptr<B> spa;
};

class B
{
public:
	B()
	{
		std::cout << "B::B()" << std::endl;
	}
	~B()
	{
		std::cout << "B::~B()" << std::endl;
	}
public:
	Weak_ptr<A> spb;
};
int main()
{
	Shared_Ptr<A> pa(new A());
	Shared_Ptr<B> pb(new B());
	pa->spa = pb;
	pb->spb = pa;

	return 0;
}
