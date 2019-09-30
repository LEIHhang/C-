#include<iostream>
using namespace std;
namespace lh
{
	template<class T>
	class vector
	{
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		//member function

		//construct
		explicit vector()
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{}
		explicit vector(size_t n, T& value = T())
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		vector(const vector<T> x)
			:


	private:
		iterator start;//有效数据起始位置
		iterator finish;//有效数据结束位置
		iterator end_of_storage;//指向存储容量的尾
	};
}