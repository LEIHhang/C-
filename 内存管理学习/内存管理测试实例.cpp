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

		void* p3 = 
	}
}

int main()
{
	day_1::test_allocators();
}