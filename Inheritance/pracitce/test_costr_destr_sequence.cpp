//该类子用来测试在继承和组合中，构造/析构函数的调用顺序
#include<iostream>
using namespace std;

class Father
{
public:
	Father();
	~Father();

private:
	int _Fa;
};

Father::Father()
{
	cout << "Father construct.." << endl;
	_Fa = 0;
}

Father::~Father()
{
	cout << "Father destruct.." << endl;
}

class Brother
{
public:
	Brother();
	~Brother();

private:
	int _Bro;
};

Brother::Brother()
{
	cout << "Brother construct.." << endl;
	_Bro = 3;
}

Brother::~Brother()
{
	cout << "Brother destruct.." << endl;
}


class Son:public Father
{
public:
	Son();
	~Son();
	
private:
	Brother br;
	int _So;
};

Son::Son() 
{
	cout << "Son construct.." << endl;
	_So = 1;
}

Son::~Son()
{
	cout << "Son destruct.." << endl;
}


int main()
{
	Son* son = new Son();
	delete son;
	//通过测试发现构造函数的调用顺序 父类-》组合类-》自身类 
	//析构顺序和构造顺序相反
}