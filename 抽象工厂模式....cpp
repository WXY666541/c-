class A
{
public:
   A(std::string name)
   	:mname(name)
   {}
   virtual void operation() = 0;
private:
   std::string mname;
};
class A1 :public A
{
public:
   A1(std::string name)
   	:A(name)
   {}
   virtual void operation()
   {
   	std::cout << "a1" << std::endl;
   }
};
class A2 :public A
{
public:
   A2(std::string name)
   	:A(name)
   {}
   virtual void operation()
   {
   	std::cout << "a2" << std::endl;
   }
};

class B
{
public:
   B(std::string name)
   	:mname(name)
   {}
   virtual void operation() = 0;
private:
   std::string mname;
};
class B1 :public B
{
public:
   B1(std::string name)
   	:B(name)
   {}
   virtual void operation()
   {
   	std::cout << "b1" << std::endl;
   }
};
class B2 :public B
{
public:
   B2(std::string name)
   	:B(name)
   {}
   virtual void operation()
   {
   	std::cout << "b2" << std::endl;
   }
};

class AbstractFactory
{
public:
   AbstractFactory(std:: string name)
   	:mname(name)
   {}
   virtual A* createA() = 0;
   virtual B* createB() = 0;
protected:
   std::string mname;
};
class Factory_1 :public AbstractFactory
{
public:
   Factory_1(std::string name)
   	:AbstractFactory(name)
   {}
   virtual A* createA()
   {
   	return new A1("a1");
   }
   virtual B* createB()
   {
   	return new B1("b1");
   }
};


