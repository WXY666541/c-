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
	std::set<int> myset1;//�޲ι���
	int a[] = { 0,1,2,3,4,5,6,7 };
	int len = sizeof(a) / sizeof(a[0]);
	std::set<int> myset(a, a + len);//ͨ�����������乹��

	//2.��������ӡ��������
	show(myset);

	//3.������ָ����ʼλ�ã��������Ԫ�ز���2���±�,��ȥ�أ����Բ������
	myset.insert(a + 2, a + 5);
	show(myset);

	//4.���뵥��Ԫ��
	myset.insert(8);
	show(myset);

	//5.��0���±����100
	std::set<int>::iterator it = myset.begin();
	myset.insert(it, 100);
	show(myset);

	//5.ɾ����2��Ԫ��
	myset.erase(2);
	show(myset);

	//6.ɾ��Ԫ��100
	myset.erase(100);
	show(myset);

	//6.ɾ������Ԫ��
	std::set<int>::iterator it1 = myset.begin();
	myset.erase(it1, myset.end());
	show(myset);
}

