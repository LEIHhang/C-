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
		iterator begin()
		{
			return start;
		}
		const_iterator begin() const
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
		const_iterator end()
		{
			return finish;
		}
		iterator rbegin()
		{
			return finishi - 1;
		}
		iterator rend()
		{
			return start - 1;
		}
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
		void reserve(size_t n)
		{
			//1、开辟新的空间
			int newn = n*1.5;
			T* arr=new T[newn];
			//2、拷贝数据
			T* first = start;
			int i = 0;
			while (first != finish)
			{
				arr[i++] = *(first++);
			}

			//3、释放旧空间
			delete start;
			//4、更新信息
			start = arr;
			finish = arr + i;
			end_of_storage = arr + newn;
		}
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