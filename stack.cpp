#include<iostream>
const int STACK_SIZE = 10;
template<typename T>
class Stack
{
public:
	Stack()
	{
		mtop = 0;
	}
	bool push(T val)
	{
		if (full())
		{
			return false;
		}
		arr[mtop++] = val;
		return true;
	}
	bool Empty()
	{
		return mtop == 0;
	}
	T top()
	{
		if (Empty())
		{
			throw std::exception("top :: stack is empty!");
		}
		return arr[mtop - 1];
	}
	bool pop()
	{
		if (Empty())
		{
			throw std::exception("stack is empty!");
		}
		mtop--;
		return true;
	}
	
private:
	bool full()
	{
		return mtop = STACK_SIZE;
	}
	T arr[STACK_SIZE];
	int mtop;
};

int main()
{
	Stack<int> st;
	for (int i = 0; i < 5; i++)
	{
		st.push(i);
	}
	try
	{
		st.top();
	}
	catch (std::exception & err)
	{
		std::cout << err.what() << std::endl;
	}
	return 0;
}