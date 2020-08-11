#include<iostream>
#include<list>


template <typename T>
void show(std::list<T>& vec)
{
	typename std::list<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
int main()
{
	std::list<int> l1;//无参构造
	std::list<int> l2(10);//一个int参数的构造
	std::list<int> l3(10, 10);//两个int参数的构造

	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
	int len = sizeof(arr) / sizeof(arr[0]);
	std::list<int> l4(arr, arr + len);//通过迭代器区间构造


	//1、使用迭代器打印整形迭代器
	std::cout << "使用迭代器打印整形迭代器：";
	show<int>(l4);


	//2、尾插10
	l4.push_back(10);
	std::cout << "尾插10后的结果：";
	show<int>(l4);

	//3、头插20
	l4.push_front(20);
	std::cout << "头插20后的结果：";
	show<int>(l4);

	//4、迭代器指向起始位置，将前五个元素插入0号元素后面
	std::cout << "将前五个元素插入0号元素后面的结果：";
	std::list<int>::iterator it = l4.begin();
	l4.insert(it, arr, arr + 5);//传入的是插入区间
	show<int>(l4);

	//5、在0号下标插入2个100
	std::cout << "在0号下标插入2个100下标的结果：";
	l4.insert(it, 2, 100);//指定插入元素的个数,迭代器失效，所以下面使用begin().
	show<int>(l4);

	//6、删除第2个元素
	std::cout << "删除第2个元素的结果：";
	l4.erase(l4.begin());
	show<int>(l4);

	//7、删除尾部元素
	std::cout << "删除尾部元素的结果：";
	l4.pop_back();
	show<int>(l4);

	//8、删除头部元素
	std::cout << "删除头部元素的结果：";
	l4.pop_front();
	show<int>(l4);

	//9、扩容，扩大空间，并初始化为0
	std::cout << "原来大小：" << l4.size() << std::endl;
	l4.resize(20);
	std::cout << "现在大小：" << l4.size() << std::endl;
	show<int>(l4);

	//10、清除
	l4.erase(l4.begin(), l4.end());
	show<int>(l4);
	std::cout << "清除后的大小：" << l4.size() << std::endl;
}


