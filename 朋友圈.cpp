#include<iostream>
#include<vector>
#include<set>
#include<map>

#if 0
//使用set管理朋友圈
class Friend
{
public:
	Friend(std::string name, int age,bool sex)
		:mname(name),mage(age), msex(sex)
	{}
	bool operator <(const Friend& rhs) const
	{
		return mname < rhs.mname;
	}
	friend std::ostream& operator<<(std::ostream&, const Friend&);
private:
	std::string mname;
	int mage;
	bool msex;
};

std::ostream& operator<<(std::ostream& out, const Friend& f)
{
	out << f.mname << "-" << f.mage << "-" << f.msex;
	return out;
}

class FriendList
{
public:
	void AddFirend(const Friend& f)
	{
		myset.insert(f);
	}
	void DelFriend(const Friend& f)
	{
		myset.erase(f);
	}
	void show()
	{
		std::set<Friend>::iterator it = myset.begin();
		while (it != myset.end())
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
private:
	std::set<Friend> myset;
};

int main()
{
	Friend f1("zhansan", 19, true);
	Friend f2("lisi", 20, false);
	Friend f3("wangwang", 22, true);

	FriendList f6;
	f6.AddFirend(f1);
	f6.AddFirend(f2);
	f6.AddFirend(f3);
	f6.show();
	f6.DelFriend(f1);
	f6.show();
	return 0;
}

#endif
//使用map管理朋友圈,使之按照年龄升序排列
class Friend
{
public:
	Friend(std::string name=" ", int age=0, bool sex=true)
		:mname(name), mage(age), msex(sex)
	{}
	int getAge()
	{
		return mage;
	}
	friend std::ostream& operator<<(std::ostream&, const Friend&);
private:
	std::string mname;
	int mage;
	bool msex;
};

std::ostream& operator<<(std::ostream& out, const Friend& f)
{
	out << f.mname << "-" << f.mage << "-" << f.msex;
	return out;
}

int main()
{
	std::map<int, Friend> mymap;
	Friend f1("zhangsan", 19, true);
	Friend f2("lisi", 20, false);
	Friend f3("wangwu", 22, true);

	//插入方式一
	std::pair<int, Friend>p1(f1.getAge(), f1);
	mymap.insert(p1);
	std::pair<int, Friend>p3(f3.getAge(), f3);
	mymap.insert(p3);

	//插入方式二
	typedef std::map<int, Friend>::value_type _Valty;
	_Valty p2(f2.getAge(), f2);
	mymap.insert(p2);

	//打印
	std::map<int, Friend>::iterator it = mymap.begin();
	while (it != mymap.end())
	{
		std::cout << it->first << "-" << it->second << std::endl;
		it++;
	}
	return 0;
}
