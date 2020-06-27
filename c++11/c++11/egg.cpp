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

//9.智能指针
//TODO

//10.显式定义缺省函数
//在C++11中，可以在默认的函数后加上=default，从而显式的指示编译器生成默认版本
//用=default修饰的函数称为显式缺省函数。

//11.删除默认函数，同显式定义缺省函数一样，有些缺省函数我们不希望生成就可以删掉它。
//在函数后面用=delete修饰的函数为删除函数。编译器不生成其默认版本。

//12.右值引用
//验证右值引用的移动构造函数生效
class Data
{
public:
	Data(int num)
		:_a(num)
	{
		cout << "拷贝构造" << endl;
	}
	Data(Data&& d)
		:_a(d._a)
	{
		
		cout << "移动拷贝构造" << endl;
	}
	Data(Data& d)
		:_a(d._a)
	{
		cout << "引用拷贝构造" << endl;
	}
private:
	int _a;
};

Data func()
{
	Data temp(1);
	return temp;
}

int main()
{
	Data one(func());
}

//右值引用的作用是为移动构造和完美转发以及给中建临时变量取别名。
//移动构造和完美转发都是为了提高程序效率的作用。
//移动构造保证在函数返回时，避免资源的多次占用和copy。
//完美转发则应用在模板函数编程中，当模板函数中需要用模板参数调用另一个函数，使用值传递效率也很低。如下:
template<class TYPE, class ARG>
TYPE* getInstance(ARG arg)
{
	TYPE* pRet = nullptr;
	pRet = new TYPE(arg);
	return pRet;
}


typedef const int T;
typedef T& TR;
typedef T&& TRR;

void JudgeType()
{
	cout << "lvalue_ref_type?: " << is_lvalue_reference<TR>::value << endl;  // 1
	cout << "rvalue_ref_type?: " << is_rvalue_reference<TR>::value << endl;  // 0

	cout << "lvalue_ref_type?: " << is_lvalue_reference<TR&>::value << endl; // 1
	cout << "rvalue_ref_type?: " << is_rvalue_reference<TR&>::value << endl; // 0

	cout << "lvalue_ref_type?: " << is_lvalue_reference<TR&&>::value << endl; // 1
	cout << "rvalue_ref_type?: " << is_rvalue_reference<TR&&>::value << endl; // 0

	cout << "lvalue_ref_type?: " << is_lvalue_reference<TRR>::value << endl;  // 0
	cout << "rvalue_ref_type?: " << is_rvalue_reference<TRR>::value << endl;  // 1

	cout << "lvalue_ref_type?: " << is_lvalue_reference<TRR&>::value << endl; // 1
	cout << "rvalue_ref_type?: " << is_rvalue_reference<TRR&>::value << endl; // 0

	cout << "lvalue_ref_type?: " << is_lvalue_reference<TRR&&>::value << endl; // 0
	cout << "rvalue_ref_type?: " << is_rvalue_reference<TRR&&>::value << endl; // 1
}

int main()
{
	JudgeType();
	system("pause");
}
#endif

//c++11引入了一个新的语法特性：引用折叠。
//https://www.cnblogs.com/Braveliu/p/12235618.html
//请参考以上博客。
//总结来说就是，引用折叠的原则是：一旦定义中出现了左值引用，引用折叠总是优先将其折叠成左值。
//在完美转发时，形参设置成一个右值引用的目的就是，如果传进来的实参类型是右值，引用折叠后依然是右值类型。
//如果实参类型是左值，引用折叠就会变成类型就会变成左值类型。所以传递左右值参数都可以。
//forward<T>和move()实现差不多，内部都是调用static_cast()进行类型转换，只不过forward指定类型转换是一个类，返回一个对象，而move是一个函数，固定转换成右值，然后返回传进去的参数本身。

//13.lambda表达式。
/*lambda表达式出现的作用就是替换仿函数的书写，因为要写一个仿函数还需要设计一个类，重载(),为了更好的编辑代码，提高代码可读性，所以添加了lambda表达式这一特性。
lambda表达式的形式：[capture-list](parameters-list)mutable->return-type{statment}
[]是捕捉列表，用来获取上下文中的变量供函数体内使用。
()内是参数列表，可以向该匿名函数传递指定的参数，不传递参数的话可以省略掉()。
mutable是一个修饰符，lambda函数总是一个const函数，这个修饰符可以取消其常量性。使用该修饰符，参数列表不可省略。
->后面设置返回值类型，也可以不设置，编译器会根据类型自动推导出返回值类型。
{}内是函数具体执行语句。
[var]：值传递var变量到函数中
[&var]:引用传递捕捉变量var
[=]:值传递捕捉上下文所有变量，包括this指针
[&]:引用传递捕捉上下文所有变量，包括this指针
[this]:值传递捕捉this指针
注意：1.捕捉列表可以分开类型捕捉[&a,b]，但不能让一个变量重复捕捉[=,a]，=已经捕捉到了a，再值传递捕捉a会编译错误。
2.在块作用域以外的lambda函数捕捉列表必须为空
3.在块作用域中的lambda函数只能捕捉到该作用域中的局部变量，捕捉非此作用域的局部变量会编译报错

lambda表达式的实现，通过反汇编查看汇编语言过程，发现lambda表达式和仿函数的实现一样，通过捕捉列表中的变量构造一个类对象，再通过参数列表中的参数调用operator()函数。*/

