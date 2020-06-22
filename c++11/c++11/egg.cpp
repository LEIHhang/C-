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
#endif


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