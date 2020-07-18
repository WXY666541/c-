#include<iostream>
#if 0
class CInt
{
public:
	CInt(int val) :value(val) {}
	bool operator <(int rhs)
	{
		return value < rhs;
	}
	const CInt operator++(int)
	{
		CInt tmp(*this);
		value++;
		return tmp;
	}
	const CInt operator++()
	{
		value++;
		return *this;
	}
	int& operator[](int* parr)
	{
		return parr[value];
	}
private:
	int value;
};
int main()
{
	int arr[] = { 1,22,32,45,67,46,69 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (CInt i = 0; i < len; i++)
	{
		std::cout << i[arr] << " ";
	}
	std::cout << std::endl;
	return 0;
}
#endif