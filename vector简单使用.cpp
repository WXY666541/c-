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
	std::vector<int> vec1;//�޲ι���
	std::vector<int> vec2(10);//һ��int�����Ĺ���
	std::vector<int> vec3(10,10);//����int�����Ĺ���

	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vec4(arr, arr + len);//ͨ�����������乹��

	//1�������ӡ�ַ�������
	std::cout << "����ķ�ʽ��ӡ�ַ���������" ;
	for (int i = 0; i < vec4.size(); i++)
	{
		std::cout << vec4[i] << " ";
	}
	std::cout << std::endl;

	//2��ʹ�õ�������ӡ���ε�����
	std::cout << "ʹ�õ�������ӡ���ε�������" ;
	show<int>(vec4);


	//3��β��10
	vec4.push_back(10);
	std::cout << "β��10��Ľ����" ;
	show<int>(vec4);

	//4��������ָ����ʼλ�ã�������0-5��Ԫ�ز���2���±�
	std::cout << "������0-5���±��Ԫ�ز���2���±�Ľ����" ;
	std::vector<int>::iterator it = vec4.begin();
	vec4.insert(it + 2, arr, arr + 5);//������ǲ�������
	show<int>(vec4);

	//5����0���±����2��100
	std::cout << "��0���±����2��100�±�Ľ����" ;
	vec4.insert(it, 2, 100);//ָ������Ԫ�صĸ���,������ʧЧ����������ʹ��begin().
	show<int>(vec4);

	//6��ɾ��ǰ0-9�±�֮���Ԫ��
	std::cout << "ɾ��ǰ0-9�±�֮���Ԫ�صĽ����";
	vec4.erase(vec4.begin(), vec4.begin() + 10);
	show<int>(vec4);

	//7�����ݣ�����ռ䣬����ʼ��Ϊ0
	std::cout << "ԭ����С��" << vec4.size() << std::endl;
	vec4.resize(20);
	std::cout << "���ڴ�С��" << vec4.size() << std::endl;
	show<int>(vec4);

	//8��Ԥ���ռ�
	std::cout << "ԭ����С��" << vec4.size() << std::endl;
	vec4.reserve(20);
	std::cout << "���ڴ�С��" << vec4.size() << std::endl;
	show<int>(vec4);

	//9�����
	vec4.clear();
	show<int>(vec4);
	std::cout << "�����Ĵ�С��" << vec4.size() << std::endl;
}



