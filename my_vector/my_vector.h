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
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*firat);
				++first;
			}
		}
		vector(const vector<T> x)
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserver(x.capacity());
			iterator xit = x.begin();
			iterator it = begin();
			while (xit != x.end())
			{
				*it++ = *xit++;
			}
			finish = start + x.size();
			end_of_storage = start + x.capacity();
		}
		//destruct
		~vector()
		{
			delete[] start;
			start = finish = end_of_storage = nullptr;
		}
		//operator =
		vector& operator=(const vector& x)
		{
			reserver(x.capacity());
			iterator xit = x.begin();
			iterator it = begin();
			while (xit != x.end())
			{
				*it++ = *xit++;
			}
			finish = start + x.size();
			end_of_storage = start + x.capacity();
		}
	public:
		//Iterator
		begin();
		end();
		rbegin();
		rend();
		cbegin();
		cend();
		crbegin();
		crend();
		//capacity
		size();
		max_size();
		resize();
		capacity();
		empty();
		reserve();
		shrink_to_fit();
		//element access
		operator[]();
		at();
		front();
		back();
		date();
		//modifers
		assign();
		push_back();
		pop_back();
		insert();
		erase();
		swap();
		clear();
		emplace();
		emplace_back();



	private:
		iterator start;//有效数据起始位置
		iterator finish;//有效数据结束位置
		iterator end_of_storage;//指向存储容量的尾
	};
}