#include<iostream>

template<typename T>
class Auto_Ptr
{
public:
	Auto_Ptr(T* ptr)
		:mptr(ptr)
	{}

	//拷贝构造函数
	Auto_Ptr(Auto_Ptr<T>& rhs)
	{
		mptr = rhs.Release();
	}

	//赋值运算符重载函数
	Auto_Ptr<T>& operator=(Auto_Ptr<T>& rhs)
	{
		if (this != &rhs)
		{
			delete mptr;
			mptr = rhs.Release();
		}
		return *this;
	}

	~Auto_Ptr()
	{
		delete mptr;
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
	//释放旧指针的所有权
	T* Release()
	{
		T* tmp = mptr;
		mptr = NULL;
		return tmp;
	}
	T* mptr;
};
class Test
{
public:
	void show()
	{
		std::cout << "hello world!" << std::endl;
	}
};

int main()
{
	int* p = new int(10);
	Auto_Ptr<int> pa = new int(10);
	*p = 20;
	*pa = 20;

	Test* ptest = new Test();
	ptest->show();

	Auto_Ptr<Test> ap1 = new Test();
	ap1->show();

	return 0;
}
