#include<iostream>

template<typename T>
class Unique_Ptr
{
public:
	Unique_Ptr(T* ptr)
		:mptr(ptr)
	{}
	~Unique_Ptr()
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
	Unique_Ptr(const Unique_Ptr<T>&);
	Unique_Ptr<T>& operator=(const Unique_Ptr<T>&);
	T* mptr;
};
int main()
{
	Unique_Ptr<int> up1(new int);
	return 0;
}
