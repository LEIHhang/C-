//���������������ڼ̳к�����У�����/���������ĵ���˳��
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
	//ͨ�����Է��ֹ��캯���ĵ���˳�� ����-�������-�������� 
	//����˳��͹���˳���෴
}