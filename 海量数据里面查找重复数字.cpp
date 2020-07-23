#include<iostream>
#include<vector>
#include<set>
#include<map>

/*
��ĿҪ����10�������У��ں��������в����ظ���Ԫ��
��������Ϊ�ڴ�Ҫ�������ں���������ֻ���ҵ��ظ���Ԫ��ֵ���ɣ����Բ���set
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
��ĿҪ��10�������У�ͳ����Щ�����ظ��ˣ�����ͳ�������ظ��Ĵ���
������ʹ�ö���ӳ���map
*/
int main()
{
	const int ARR_LEN = 100000;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; ++i)
	{
		arr[i] = rand() % 10000 + 1;
	}
	std::map<int, int>map1;//�ֱ����ֵ���ظ�����
	for (int k : arr)
	{

		auto it = map1.find(k);
		if (it == map1.end())//��ʾ������־�û���ֹ�
		{
			map1.insert({ k,1 });
		}
		else
		{
			it->second++;
		}
	}
	//��ӡ
	for (const std::pair<int, int>& p : map1)//���峣����ͨ��for each�����������������޸�����
	{
		if (p.second > 1)
		{
			std::cout << "key:" << p.first << "count:" << p.second << std::endl;
		}
	}
	return 0;
}

