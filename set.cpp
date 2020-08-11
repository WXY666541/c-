# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>

template<typename Container>
void show(Container& con)
{
	typename Container::iterator it = con.begin();
	for (; it != con.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::set<int> myset1;//无参构造
	int a[] = { 0,1,2,3,4,5,6,7 };
	int len = sizeof(a) / sizeof(a[0]);
	std::set<int> myset(a, a + len);//通过迭代器区间构造

	//2.迭代器打印整型容器
	show(myset);

	//3.迭代器指向起始位置，将数组的元素插入2号下标,会去重，所以不会插入
	myset.insert(a + 2, a + 5);
	show(myset);

	//4.插入单个元素
	myset.insert(8);
	show(myset);

	//5.在0号下标插入100
	std::set<int>::iterator it = myset.begin();
	myset.insert(it, 100);
	show(myset);

	//5.删除第2个元素
	myset.erase(2);
	show(myset);

	//6.删除元素100
	myset.erase(100);
	show(myset);

	//6.删除所有元素
	std::set<int>::iterator it1 = myset.begin();
	myset.erase(it1, myset.end());
	show(myset);
}

