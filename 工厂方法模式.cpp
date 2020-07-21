#include<iostream>
#include<string>

class Fruit
{
public:
   Fruit(std::string name)
   	:mname(name)
   {}
   virtual void operation() = 0;
private:
   std::string mname;
};
class Apple :public Fruit
{
public:
   Apple(std::string name)
   	:Fruit(name)
   {}
   void operation()
   {
   	std::cout << "this is apple!" << std::endl;
   }
};

class Banana :public Fruit
{
public:
   Banana(std::string name)
   	:Fruit(name)
   {}
   void operation()
   {
   	std::cout << "this is banana!" << std::endl;
   }
};
class Factory
{
public:
   Factory(std::string name)
   	:mname(name)
   {}
   virtual Fruit* createFruit() = 0;
protected:
   std::string mname;
};
class F1 :public Factory
{
public:
   F1(std::string name)
   	:Factory(name)
   {}
   Fruit* createFruit()
   {
   	return new Apple("apple!");
   }
};
��������������������������������
��Ȩ����������ΪCSDN����������ҪŬ��ѽ����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_43412060/article/details/107492769
