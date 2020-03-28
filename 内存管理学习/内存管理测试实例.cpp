#include<allocators>
#include<iostream>
using namespace std;

namespace day_1
{
	void test_allocators()
	{
		int *p1 = allocator<int>().allocate(3);
		allocator<int>().deallocate(p1,3);

		void *p2 = ::operator new(512);
		*(char*)p2 = 'a';
		::operator delete(p2);
	}
}
namespace day_2
{
	void* myAlloc(size_t size)
	{
		return malloc(size);
	}
	void myFree(void* ptr)
	{
		return free(ptr);
	}
	class Foo
	{
	public:
		int _id;
		long _data;
		std::string _string;
		Foo() :_id(0)
		{
			cout << "default ctor.this=" << this << "id=" << _id << endl;
		}
		Foo(int i) :_id(i)
		{
			cout << "ctor.this=" << this << "id=" << _id << endl;
		}

		~Foo()
		{
			cout << "dtor.this=" << this << "id=" << _id << endl;
		}
		static void* operator new(size_t size) //size==sizeof(Foo)
		{
			cout << "day_2 global new()\n";
			return myAlloc(size);
		}
		static void* operator new(size_t size,void* start)
		{
			cout << "day_2 global new(void*)\n";
			return start;
		}
		static void* operator new[](size_t size)
		{
			cout << "day_2 global new[]\n";
			return myAlloc(size);
		}
		//
		static void operator delete(void* ptr, void* start)
		{
			cout << "day_2 global delete(void*)\n";
			return ;
		}
		static void operator delete(void* ptr)
		{
			cout << "day_2 global delete()\n";
			return myFree(ptr);
		}

		static void operator delete[](void* ptr)
		{
			cout << "day_2 global delete[]\n";
			return myFree(ptr);
		}
	};
	
	void test()
	{
		Foo* p = new Foo(7);
		//operator 函数必须写在类中才会调用。
		//但是这几个函数应该是静态的才行，这里成功只是编译器的原因

		//place new定位new
		//已经开辟的空间进行初始化
		//new(void*)Foo()
		new(p)Foo(1);
		delete p;

		Foo* pArray = new Foo[5];
		delete[] pArray;
	}
}

int main()
{
	//day_1::test_allocators();
	day_2::test();
}