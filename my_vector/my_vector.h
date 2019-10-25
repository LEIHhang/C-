#include<iostream>
#include<assert.h>
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
			return *this;
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

		//capacity
		size_t size() const
		{
			return finish - start;
		}
		size_t capacity() const
		{
			return capacity - start;
		}
		bool empty() const
		{
			return finish == start;
		}
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
		T operator[](size_t n)
		{
			assert(n < (finish - start));
			return *(start + n);
		}
		T front()
		{
			if (!empty())
				return *start;
		}
		T back()
		{
			if (!empty())
				return *finish;
		}
		//modifers
		void push_back(const T& x)
		{
			*finish = x;
			finish++;
		}
		pop_back()
		{
			finish--;
		}
		iterator insert(iterator pos,const T& val)//before insert
		{
			iterator it = end();
			while (it != pos)//从后往前，前一个覆盖下一个位置
			{
				*it = *(it - 1);
				--it;
			}
			*it = val;
			finish++;
			return it;
		}
		iterator erase(iterator pos)
		{
			iterator it = pos;
			while (it != end())
			{
				*it = *(it + 1);
				++it;
			}
			--finish;
			return pos;
		}
		//swap();
		void clear()
		{
			finish = start;
		}

	private:
		iterator start;//有效数据起始位置
		iterator finish;//有效数据结束位置
		iterator end_of_storage;//指向存储容量的尾
	};
}