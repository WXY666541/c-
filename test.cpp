#include<iostream>

class Animal
{
public:
	Animal(std::string name) :_name(name) {}
	virtual void bark() {}
protected:
	std::string _name;
};
//�����Ƕ���ʵ����
class Cat :public Animal
{
public:
	Cat(std::string name) :Animal(name) {}
	void bark() { std::cout << _name << "bark:miao miao!" << std::endl; }
};
class Dog :public Animal
{
public:
	Dog(std::string name) :Animal(name) {}
	void bark() { std::cout << _name << "bark:wang wang!" << std::endl; }
};
class Pig :public Animal
{
public:
	Pig(std::string name) :Animal(name) {}
	void bark() { std::cout << _name << "bark:heng heng!" << std::endl; }
};
void bark(Cat& cat)
{
	cat.bark();//���ñ��������麯������̬��
}
void bark(Dog& dog)
{
	dog.bark();
}
void bark(Pig& pig)
{
	pig.bark();
}
int main()
{
	Cat cat("����");
	Dog dog("����");
	Pig pig("����");

	bark(cat);
	bark(dog);
	bark(pig);
	return 0;
}
