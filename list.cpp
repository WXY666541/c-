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
	std::list<int> l1;//�޲ι���
	std::list<int> l2(10);//һ��int�����Ĺ���
	std::list<int> l3(10, 10);//����int�����Ĺ���

	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
	int len = sizeof(arr) / sizeof(arr[0]);
	std::list<int> l4(arr, arr + len);//ͨ�����������乹��


	//1��ʹ�õ�������ӡ���ε�����
	std::cout << "ʹ�õ�������ӡ���ε�������";
	show<int>(l4);


	//2��β��10
	l4.push_back(10);
	std::cout << "β��10��Ľ����";
	show<int>(l4);

	//3��ͷ��20
	l4.push_front(20);
	std::cout << "ͷ��20��Ľ����";
	show<int>(l4);

	//4��������ָ����ʼλ�ã���ǰ���Ԫ�ز���0��Ԫ�غ���
	std::cout << "��ǰ���Ԫ�ز���0��Ԫ�غ���Ľ����";
	std::list<int>::iterator it = l4.begin();
	l4.insert(it, arr, arr + 5);//������ǲ�������
	show<int>(l4);

	//5����0���±����2��100
	std::cout << "��0���±����2��100�±�Ľ����";
	l4.insert(it, 2, 100);//ָ������Ԫ�صĸ���,������ʧЧ����������ʹ��begin().
	show<int>(l4);

	//6��ɾ����2��Ԫ��
	std::cout << "ɾ����2��Ԫ�صĽ����";
	l4.erase(l4.begin());
	show<int>(l4);

	//7��ɾ��β��Ԫ��
	std::cout << "ɾ��β��Ԫ�صĽ����";
	l4.pop_back();
	show<int>(l4);

	//8��ɾ��ͷ��Ԫ��
	std::cout << "ɾ��ͷ��Ԫ�صĽ����";
	l4.pop_front();
	show<int>(l4);

	//9�����ݣ�����ռ䣬����ʼ��Ϊ0
	std::cout << "ԭ����С��" << l4.size() << std::endl;
	l4.resize(20);
	std::cout << "���ڴ�С��" << l4.size() << std::endl;
	show<int>(l4);

	//10�����
	l4.erase(l4.begin(), l4.end());
	show<int>(l4);
	std::cout << "�����Ĵ�С��" << l4.size() << std::endl;
}


