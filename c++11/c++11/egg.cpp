#include<iostream>
#include<vector>
#include<map>
using namespace std;

#ifdef lei
int main()
{
	//1.支持容器初始化
	vector<int> vec{ 0,1,2,3,4,5 };
	vector<int> vec2 = { 0,1,2,3,4,5 };
	map<int, int> m{ {1,1},{2,2},{3,3} };
	for (auto i : m)
	{
		cout << i.second << " ";
	}
	cout << endl;
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	for (auto i : vec2)
	{
		cout << i << " ";
	}
	cout << endl;

	//2.内置类型的初始化
	int x1 = { 10 };
	int x2{ 11 };
	int x3 = 1 + 1;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };

	//3.动态数组
	int* arr1 = new int[5]{ 1,2,3,4,5 };
	cout << sizeof(arr1) << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	

}

//4.自定义类型的列表初始化
class egg
{
public:
	egg(int x = 0, int y = 0):_x(x),_y(y)
	{}
	void print()
	{
		cout << _x << " " << _y << endl;
	}
private:
	int _x;
	int _y;
};

int main()
{
	egg e{ 1,2 };
	e.print();
	return 0;
}

//5.多个对象的列表初始化
//仅采用这种类型的一个参数的构造函数是一种特殊的构造函数，
//称为initializer_list构造函数。
//使用初始化器列表构造器语法时，
//初始化器列表构造器优先于其他构造器。

#include<initializer_list>
template<typename T>
class Vector
{

public:
	Vector(initializer_list<T> l):_capacity(l.size()),_size(0)
	{
		_arr = new T[_capacity];
		for (auto e : l)
		{
			_arr[_size++] = e;
		}
	}

	Vector<T>& operator=(initializer_list<T> l)
	{
		delete[] _arr;
		size_t i = 0;
		for (auto e : l)
		{
			_arr[i++] = e;
		}
		return *this;
	}
private:
	T* _arr;
	size_t _capacity;
	size_t _size;
};

int main()
{
	Vector<int> vec{ 1,2,3,4,5 };
	Vector<int> vec2 = vec;
}


//6.使用auto自动推导实际类型，方便写代码和特殊情况。
//In the C++ programming language, decltype is an operator for querying the type of an expression.It was introduced in the current version of the C++ standard, C++11.
//auto使用的前提是必须对auto声明的类型进行初始化，否则编译器无法推导出auto的十几类型。
//但有时可能需要根据表达式运行完成后结果的类型进行推导，因为编译期间，代码不会运行，此时auto也无能为力
int main()
{
	int a = 10;
	int b = 20;

	//用decltype推演a+b的实际类型，作为定义c的类型，这是运行时类型识别
	decltype(a + b) c;
	cout << typeid(c).name() << endl;
}
#endif


void* GetMemory(size_t size)
{
	return malloc(size);
}

int main()
{
	//如果不带参数，推演出函数的类型
	cout << typeid(decltype(GetMemory)).name() << endl;
	//如果带参数，推演出函数返回值的类型
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	return 0;
}

//7.使用范围for循环，遍历容器
//for(i:container) i是容器中的每个元素

//8.final和override
//final修饰虚函数，表示该虚函数不能再被继承
//override检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。