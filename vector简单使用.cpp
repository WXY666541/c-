#include<iostream>
#include<vector>

template <typename T>
void show(std::vector<T>& vec)
{
	typename std::vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
int main()
{
	std::vector<int> vec1;//无参构造
	std::vector<int> vec2(10);//一个int参数的构造
	std::vector<int> vec3(10,10);//两个int参数的构造

	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vec4(arr, arr + len);//通过迭代器区间构造

	//1、数组打印字符迭代器
	std::cout << "数组的方式打印字符迭代器：" ;
	for (int i = 0; i < vec4.size(); i++)
	{
		std::cout << vec4[i] << " ";
	}
	std::cout << std::endl;

	//2、使用迭代器打印整形迭代器
	std::cout << "使用迭代器打印整形迭代器：" ;
	show<int>(vec4);


	//3、尾插10
	vec4.push_back(10);
	std::cout << "尾插10后的结果：" ;
	show<int>(vec4);

	//4、迭代器指向起始位置，将数组0-5的元素插入2号下标
	std::cout << "将数组0-5号下标的元素插入2号下标的结果：" ;
	std::vector<int>::iterator it = vec4.begin();
	vec4.insert(it + 2, arr, arr + 5);//传入的是插入区间
	show<int>(vec4);

	//5、在0号下标插入2个100
	std::cout << "在0号下标插入2个100下标的结果：" ;
	vec4.insert(it, 2, 100);//指定插入元素的个数,迭代器失效，所以下面使用begin().
	show<int>(vec4);

	//6、删除前0-9下标之间的元素
	std::cout << "删除前0-9下标之间的元素的结果：";
	vec4.erase(vec4.begin(), vec4.begin() + 10);
	show<int>(vec4);

	//7、扩容，扩大空间，并初始化为0
	std::cout << "原来大小：" << vec4.size() << std::endl;
	vec4.resize(20);
	std::cout << "现在大小：" << vec4.size() << std::endl;
	show<int>(vec4);

	//8、预留空间
	std::cout << "原来大小：" << vec4.size() << std::endl;
	vec4.reserve(20);
	std::cout << "现在大小：" << vec4.size() << std::endl;
	show<int>(vec4);

	//9、清除
	vec4.clear();
	show<int>(vec4);
	std::cout << "清除后的大小：" << vec4.size() << std::endl;
}



