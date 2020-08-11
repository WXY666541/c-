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
	std::deque<int> q1;//�޲ι���
	std::deque<int> q2(10);//һ��int�����Ĺ���
	std::deque<int> q3(10, 10);//����int�����Ĺ���

	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
	int len = sizeof(arr) / sizeof(arr[0]);
	std::deque<int> q4(arr, arr + len);//ͨ�����������乹��

	//1��ʹ�������ӡ���ε�����
	std::cout << "ʹ�������ӡ���ε�������";
	for (int i = 0; i < q4.size(); i++)
	{
		std::cout << q4[i] << " ";
	}

	//2��ʹ�õ�������ӡ���ε�����
	std::cout << "ʹ�õ�������ӡ���ε�������";
	show<int>(q4);


	//3��β��10
	q4.push_back(10);
	std::cout << "β��10��Ľ����";
	show<int>(q4);

	//4��ͷ��20
	q4.push_front(20);
	std::cout << "ͷ��20��Ľ����";
	show<int>(q4);

	//5��������ָ����ʼλ�ã���ǰ���Ԫ�ز���2��Ԫ�غ���
	std::cout << "��ǰ���Ԫ�ز���2��Ԫ�غ���Ľ����";
	std::deque<int>::iterator it = q4.begin();
	q4.insert(it+2, arr, arr + 5);//������ǲ�������
	show<int>(q4);

	//6����0���±����2��100
	std::cout << "��0���±����2��100�±�Ľ����";
	std::deque<int>::iterator it1 = q4.begin();
	q4.insert(it1, 2, 100);//ָ������Ԫ�صĸ���,������ʧЧ����������ʹ��begin().
	show<int>(q4);

	//7��ɾ��0~9֮���Ԫ��
	std::cout << "ɾ��0~9֮���Ԫ�صĽ����";
	q4.erase(q4.begin(), q4.begin() + 10);
	show<int>(q4);
	
	//8��ɾ����2��Ԫ��
	std::cout << "ɾ���ڶ���Ԫ�صĽ����";
	q4.erase(q4.begin()+2);
	show<int>(q4);

	//9��ɾ��β��Ԫ��
	std::cout << "ɾ��β��Ԫ�صĽ����";
	q4.pop_back();
	show<int>(q4);

	//10��ɾ��ͷ��Ԫ��
	std::cout << "ɾ��ͷ��Ԫ�صĽ����";
	q4.pop_front();
	show<int>(q4);

	//11�����ݣ�����ռ䣬����ʼ��Ϊ0
	std::cout << "ԭ����С��" << q4.size() << std::endl;
	q4.resize(20);
	std::cout << "���ڴ�С��" << q4.size() << std::endl;
	show<int>(q4);

	//12�����
	q4.clear();
	show<int>(q4);
	std::cout << "�����Ĵ�С��" << q4.size() << std::endl;
}



