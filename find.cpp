#include<iostream>
#include<vector>

//查询第一个大于某个数的数据
template<typename T>
class Compare_1
{
public:
	Compare_1(T val = T())
		:mvalue(val)
	{}
	bool operator()(const T& arg)
	{
		return arg > mvalue;
	}
private:
	T mvalue;
};

//查询第一个小于某个数的数据
template<typename T>
class Compare_2
{
public:
	Compare_2(T val = T())
		:mvalue(val)
	{}
	bool operator()(const T& arg)
	{
		return arg < mvalue;
	}
private:
	T mvalue;
};

//查询第一个大于等于某个数的数据
template<typename T>
class Compare_3
{
public:
	Compare_3(T val = T())
		:mvalue(val)
	{}
	bool operator()(const T& arg)
	{
		return arg >= mvalue;
	}
private:
	T mvalue;
};

//查询第一个小于等于某个数的数据
template<typename T>
class Compare_4
{
public:
	Compare_4(T val = T())
		:mvalue(val)
	{}
	bool operator()(const T& arg)
	{
		return arg <= mvalue;
	}
private:
	T mvalue;
};

//查找函数实现
template<typename Iterator,
	typename Comp>
Iterator Find(Iterator _First, Iterator _Last,Comp cmp)
{
	for (_First; _First != _Last; _First++)
	{
		if (cmp(*_First))
		{
			break;
		}
	}
	return _First;
}

//对容器的遍历
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it = con.begin();
	while (it != con.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main()
{
	int arr[] = { 1,23,312,534,654,2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vec(arr, arr + len);
	show(vec);
	std::vector<int>::iterator fit = Find(vec.begin(), vec.end(), Compare_1<int>(312));
	if (fit != vec.end())
	{
		std::cout << *fit << std::endl;
	}
	return 0;
}
