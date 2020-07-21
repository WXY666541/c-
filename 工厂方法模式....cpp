#include<iostream>

class Bird
{
public:
	Bird(std::string nm)
		:mname(nm)
	{}
	virtual void FlyHigh() = 0;
protected:
	std::string mname;
};

class Eagle:public Bird
{
public:
	Eagle(std::string name)
		:Bird(name)
	{}
	void FlyHigh()
	{
		std::cout << mname << "can fly 1000m!" << std::endl;
	}
};
class chicken:public Bird
{
public:
	chicken(std::string name)
		:Bird(name)
	{}
	void FlyHigh()
	{
		std::cout << mname << "can fly 0m!" << std::endl;
	}
};

void showFly(Bird* pb)
{
	chicken* pc = dynamic_cast<chicken*>(pb);
	if (pc != NULL)
	{
		std::cout << "chicken can not fly!" << std::endl;
	}
	else
	{
		pb->FlyHigh();
	}
}
int main()
{
	Bird* pb1 = new Eagle("eagle");
	showFly(pb1);
	Bird* pb2 = new chicken("chicken");
	showFly(pb2);

}


