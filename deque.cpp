#include<iostream>
#include<deque>


template <typename T>
void show(std::deque<T>& vec)
{
	typename std::deque<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
int main()
{
	std::deque<int> q1;//无参构造
	std::deque<int> q2(10);//一个int参数的构造
	std::deque<int> q3(10, 10);//两个int参数的构造

	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
	int len = sizeof(arr) / sizeof(arr[0]);
	std::deque<int> q4(arr, arr + len);//通过迭代器区间构造

	//1、使用数组打印整形迭代器
	std::cout << "使用数组打印整形迭代器：";
	for (int i = 0; i < q4.size(); i++)
	{
		std::cout << q4[i] << " ";
	}

	//2、使用迭代器打印整形迭代器
	std::cout << "使用迭代器打印整形迭代器：";
	show<int>(q4);


	//3、尾插10
	q4.push_back(10);
	std::cout << "尾插10后的结果：";
	show<int>(q4);

	//4、头插20
	q4.push_front(20);
	std::cout << "头插20后的结果：";
	show<int>(q4);

	//5、迭代器指向起始位置，将前五个元素插入2号元素后面
	std::cout << "将前五个元素插入2号元素后面的结果：";
	std::deque<int>::iterator it = q4.begin();
	q4.insert(it+2, arr, arr + 5);//传入的是插入区间
	show<int>(q4);

	//6、在0号下标插入2个100
	std::cout << "在0号下标插入2个100下标的结果：";
	std::deque<int>::iterator it1 = q4.begin();
	q4.insert(it1, 2, 100);//指定插入元素的个数,迭代器失效，所以下面使用begin().
	show<int>(q4);

	//7、删除0~9之间的元素
	std::cout << "删除0~9之间的元素的结果：";
	q4.erase(q4.begin(), q4.begin() + 10);
	show<int>(q4);
	
	//8、删除第2个元素
	std::cout << "删除第二个元素的结果：";
	q4.erase(q4.begin()+2);
	show<int>(q4);

	//9、删除尾部元素
	std::cout << "删除尾部元素的结果：";
	q4.pop_back();
	show<int>(q4);

	//10、删除头部元素
	std::cout << "删除头部元素的结果：";
	q4.pop_front();
	show<int>(q4);

	//11、扩容，扩大空间，并初始化为0
	std::cout << "原来大小：" << q4.size() << std::endl;
	q4.resize(20);
	std::cout << "现在大小：" << q4.size() << std::endl;
	show<int>(q4);

	//12、清除
	q4.clear();
	show<int>(q4);
	std::cout << "清除后的大小：" << q4.size() << std::endl;
}



