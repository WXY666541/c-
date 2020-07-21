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
————————————————
版权声明：本文为CSDN博主「汪汪要努力呀」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_43412060/article/details/107492769
