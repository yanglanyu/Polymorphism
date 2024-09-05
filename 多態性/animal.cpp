#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()		//基底クラスの仮想関数
	{
		cout << "鳴る" << endl;
	}
};

//没有 virtual 关键字时，
// 编译器会在编译时就确定调用的是父类的 speak 函数，
// 这叫做静态联编。
// 但当使用了 virtual 关键字，
// 程序会在运行时根据对象的实际类型来调用子类的 speak 函数，
// 这就是动态联编，也称为多态。

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "ニャンー" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "ワンー" << endl;
	}
};
void Dospeak(Animal& animal)  //参照　派生オブジェクト
{
	animal.speak();
}
void test_1()
{
	Cat cat;
	Dospeak(cat);

	Dog dog;
	Dospeak(dog);
}
int main()
{
	test_1();

	return 0;
}