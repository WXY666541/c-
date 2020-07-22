#include<iostream>

template<typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:mptr(ptr),flag(true)
	{}
	~SmartPtr()
	{
		if (flag)
		{
			delete mptr;
		}
		mptr = NULL;
	}
	SmartPtr(SmartPtr<T>& rhs)
	{
		mptr = rhs.mptr;

		flag = rhs.flag;//旧的释放权赋值给新的
		rhs.flag = false;//把就的释放权置为false
	}

	SmartPtr<T>& operator=(SmartPtr<T>& rhs)
	{
		if (this != &rhs)
		{
			this->~SmartPtr();
			mptr = rhs.mptr;
			flag = rhs.flag;
			rhs.flag = false;
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
	int flag;//释放权的标志，默认为true可释放
};

int main()
{
	SmartPtr<int> sq1 = new int(10);
	SmartPtr<int> sq2 = sq1;
	return 0;
}
