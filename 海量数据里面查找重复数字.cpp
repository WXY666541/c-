#include<iostream>
#include<vector>
#include<set>
#include<map>

/*
题目要求：在10万整数中，在海量数据中查找重复的元素
分析：因为在此要求我们在海量数据中只是找到重复的元素值即可，所以采用set
*/
int main()
{
	const int ARR_LEN = 1000000;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; ++i)
	{
		arr[i] = rand() % 1000000 + 1;
	}
	std::set<int> myset;
	for (int v : arr)//O(n)
	{
		myset.insert(v);//O(1)
	}
	for (int v : myset)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	return 0;
}

/*
题目要求：10万整数中，统计哪些数字重复了，并且统计数字重复的次数
分析：使用多重映射表map
*/
int main()
{
	const int ARR_LEN = 100000;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; ++i)
	{
		arr[i] = rand() % 10000 + 1;
	}
	std::map<int, int>map1;//分别代表值和重复次数
	for (int k : arr)
	{

		auto it = map1.find(k);
		if (it == map1.end())//表示这个数字就没出现过
		{
			map1.insert({ k,1 });
		}
		else
		{
			it->second++;
		}
	}
	//打印
	for (const std::pair<int, int>& p : map1)//定义常引用通过for each来遍历容器而不是修改容器
	{
		if (p.second > 1)
		{
			std::cout << "key:" << p.first << "count:" << p.second << std::endl;
		}
	}
	return 0;
}

