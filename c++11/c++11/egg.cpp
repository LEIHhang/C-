#include<iostream>
#include<vector>
#include<map>
using namespace std;

#ifdef lei
int main()
{
	//1.֧��������ʼ��
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

	//2.�������͵ĳ�ʼ��
	int x1 = { 10 };
	int x2{ 11 };
	int x3 = 1 + 1;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };

	//3.��̬����
	int* arr1 = new int[5]{ 1,2,3,4,5 };
	cout << sizeof(arr1) << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	

}

//4.�Զ������͵��б��ʼ��
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

//5.���������б��ʼ��
//�������������͵�һ�������Ĺ��캯����һ������Ĺ��캯����
//��Ϊinitializer_list���캯����
//ʹ�ó�ʼ�����б������﷨ʱ��
//��ʼ�����б�����������������������

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


//6.ʹ��auto�Զ��Ƶ�ʵ�����ͣ�����д��������������
//In the C++ programming language, decltype is an operator for querying the type of an expression.It was introduced in the current version of the C++ standard, C++11.
//autoʹ�õ�ǰ���Ǳ����auto���������ͽ��г�ʼ��������������޷��Ƶ���auto��ʮ�����͡�
//����ʱ������Ҫ���ݱ��ʽ������ɺ��������ͽ����Ƶ�����Ϊ�����ڼ䣬���벻�����У���ʱautoҲ����Ϊ��
int main()
{
	int a = 10;
	int b = 20;

	//��decltype����a+b��ʵ�����ͣ���Ϊ����c�����ͣ���������ʱ����ʶ��
	decltype(a + b) c;
	cout << typeid(c).name() << endl;
}



void* GetMemory(size_t size)
{
	return malloc(size);
}

int main()
{
	//����������������ݳ�����������
	cout << typeid(decltype(GetMemory)).name() << endl;
	//��������������ݳ���������ֵ������
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	return 0;
}

//7.ʹ�÷�Χforѭ������������
//for(i:container) i�������е�ÿ��Ԫ��

//8.final��override
//final�����麯������ʾ���麯�������ٱ��̳�
//override����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��

//9.����ָ��
//TODO

//10.��ʽ����ȱʡ����
//��C++11�У�������Ĭ�ϵĺ��������=default���Ӷ���ʽ��ָʾ����������Ĭ�ϰ汾
//��=default���εĺ�����Ϊ��ʽȱʡ������

//11.ɾ��Ĭ�Ϻ�����ͬ��ʽ����ȱʡ����һ������Щȱʡ�������ǲ�ϣ�����ɾͿ���ɾ������
//�ں���������=delete���εĺ���Ϊɾ����������������������Ĭ�ϰ汾��

//12.��ֵ����
//��֤��ֵ���õ��ƶ����캯����Ч
class Data
{
public:
	Data(int num)
		:_a(num)
	{
		cout << "��������" << endl;
	}
	Data(Data&& d)
		:_a(d._a)
	{
		
		cout << "�ƶ���������" << endl;
	}
	Data(Data& d)
		:_a(d._a)
	{
		cout << "���ÿ�������" << endl;
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

//��ֵ���õ�������Ϊ�ƶ����������ת���Լ����н���ʱ����ȡ������
//�ƶ����������ת������Ϊ����߳���Ч�ʵ����á�
//�ƶ����챣֤�ں�������ʱ��������Դ�Ķ��ռ�ú�copy��
//����ת����Ӧ����ģ�庯������У���ģ�庯������Ҫ��ģ�����������һ��������ʹ��ֵ����Ч��Ҳ�ܵ͡�����:
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

//c++11������һ���µ��﷨���ԣ������۵���
//https://www.cnblogs.com/Braveliu/p/12235618.html
//��ο����ϲ��͡�
//�ܽ���˵���ǣ������۵���ԭ���ǣ�һ�������г�������ֵ���ã������۵��������Ƚ����۵�����ֵ��
//������ת��ʱ���β����ó�һ����ֵ���õ�Ŀ�ľ��ǣ������������ʵ����������ֵ�������۵�����Ȼ����ֵ���͡�
//���ʵ����������ֵ�������۵��ͻ������;ͻ�����ֵ���͡����Դ�������ֵ���������ԡ�
//forward<T>��move()ʵ�ֲ�࣬�ڲ����ǵ���static_cast()��������ת����ֻ����forwardָ������ת����һ���࣬����һ�����󣬶�move��һ���������̶�ת������ֵ��Ȼ�󷵻ش���ȥ�Ĳ�������

//13.lambda���ʽ��
/*lambda���ʽ���ֵ����þ����滻�º�������д����ΪҪдһ���º�������Ҫ���һ���࣬����(),Ϊ�˸��õı༭���룬��ߴ���ɶ��ԣ����������lambda���ʽ��һ���ԡ�
lambda���ʽ����ʽ��[capture-list](parameters-list)mutable->return-type{statment}
[]�ǲ�׽�б�������ȡ�������еı�������������ʹ�á�
()���ǲ����б��������������������ָ���Ĳ����������ݲ����Ļ�����ʡ�Ե�()��
mutable��һ�����η���lambda��������һ��const������������η�����ȡ���䳣���ԡ�ʹ�ø����η��������б���ʡ�ԡ�
->�������÷���ֵ���ͣ�Ҳ���Բ����ã�����������������Զ��Ƶ�������ֵ���͡�
{}���Ǻ�������ִ����䡣
[var]��ֵ����var������������
[&var]:���ô��ݲ�׽����var
[=]:ֵ���ݲ�׽���������б���������thisָ��
[&]:���ô��ݲ�׽���������б���������thisָ��
[this]:ֵ���ݲ�׽thisָ��
ע�⣺1.��׽�б���Էֿ����Ͳ�׽[&a,b]����������һ�������ظ���׽[=,a]��=�Ѿ���׽����a����ֵ���ݲ�׽a��������
2.�ڿ������������lambda������׽�б����Ϊ��
3.�ڿ��������е�lambda����ֻ�ܲ�׽�����������еľֲ���������׽�Ǵ�������ľֲ���������뱨��

lambda���ʽ��ʵ�֣�ͨ�������鿴������Թ��̣�����lambda���ʽ�ͷº�����ʵ��һ����ͨ����׽�б��еı�������һ���������ͨ�������б��еĲ�������operator()������*/

