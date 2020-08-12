# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
# include<map>

/*
   map�Ļ���ʹ��
*/

template<typename Container>
void show(Container& con)
{
	typename Container::iterator it = con.begin();
	for (; it != con.end(); it++)
	{
		std::cout << it->first << "-" << it->second << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::map<int, int> mymap;//�޲ι���

	//1������pair����
	std::pair<int, int>p1(1, 1);//pair����
	mymap.insert(p1);
	std::cout << "����pair����" ;
	show(mymap);

	//2�����ɶ��󲢲���
	std::map<int, int>::value_type p2(8, 1);//������ʽpair����
	mymap.insert(p2);
	std::cout << "���ɶ��󲢲���" ;
	show(mymap);

	//3��ͨ����ֵ����
	mymap[9] = 100;
	mymap[2] = 6;
	mymap[3] = 4;
	mymap[4] = 5;
	mymap[2] = 1;//��֮ǰ�����key��Ӧ��ֵvalue���棬����������2-1��������2-6����Ϊ������keyֵ�ظ�
	std::cout << "ͨ����ֵ����" ;
	show(mymap);

	//4��ͨ��keyֵ��ӡ
	std::map<int, int>::iterator it = mymap.begin();
	std::cout << "ͨ��keyֵ��ӡ" ;
	while (it != mymap.end())
	{
		std::cout << it->first <<"-"<< it->second<<" ";
		it++;
	}
	std::cout << std::endl;

	//5������Ԫ��1
	std::map<int,int>::iterator fit=mymap.find(1);
	if(fit!=mymap.end())
	{
		std::cout<<fit->first<<"-"<<fit->second<<std::endl;
	}
	else
	{
		std::cout<<"no"<<std::endl;
	}

	//6��ɾ����2��Ԫ��
	std::map<int, int>::iterator it2 = mymap.begin();
	mymap.erase(++it2);
	std::cout << "ɾ����2��Ԫ��:";
	show(mymap);

	//7��ɾ����ֵ1��Ӧ��ֵ
	mymap.erase(1);
	std::cout << "ɾ����ֵ1��Ӧ��ֵ:";
	show(mymap);

	//8��ɾ��0-3�����Ԫ�أ���0,1,2�±��
	std::map<int, int>::iterator it1 = mymap.begin();
	++it1; ++it1; ++it1;
	std::cout << "ɾ��0-3�����Ԫ�أ���0,1,2�±��:";
	mymap.erase(mymap.begin(), it1);
	show(mymap);
}

/*
  multimap�Ļ���ʹ��
*/
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it = con.begin();//iteratorΪ�������ƣ������������ͣ������������֪��
	for (; it != con.end(); it++)
	{
		std::cout << it->first << "-" << it->second << " ";
	}
	std::cout << std::endl;
}
int main()
{
	std::multimap<int, int> mymap;//�޲ι���
	//1.����pair���󣬲���ͨ����ֵ����
	std::pair<int, int>p1(2, 7);//pair����
	std::pair<int, int>p2(2, 1);//���Ա����ظ�keyֵ
	std::pair<int, int>p3(3, 6);//pair����
	std::pair<int, int>p4(5, 8);//pair����
	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	show(mymap);
}

