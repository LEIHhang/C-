#include<iostream>
#include<assert.h>
#include<utility>
#include<istream>
#include<string>
using namespace std;
namespace lh
{

	class string
	{
		typedef const char* const_iterator;
		typedef char* iterator;
		friend istream& getline(istream& _cin, const string& s);
	public:
		string()//default默认
			:_str(new char[1])
		{
			*_str = '\0';
		}
		string(const char* s = '\0')//from C string
			:_str(new char[strlen(s) + 1])
		{
			strcpy(_str, s);
			_size = strlen(s) + 1;
			_capacity = _size;
		}
		string(const string& str, size_t pos, size_t len = npos)//substring 子串
			:_str(new char[(str._size - pos + 1)<len ? str._size - pos + 1:len]),
			_size((str._size - pos + 1)<len ? str._size - pos + 1 : len),
			_capacity((str._size - pos + 1)<len ? str._size - pos + 1 : len)
		{
			char* newstart = str._str + pos;
			strcpy(_str, newstart);
		}
		string(const char* str, size_t n)//from buffer从缓冲区
			:_str(new char[n + 1]),
			_size(n + 1),
			_capacity(n + 1)
		{
			strncpy(_str, str, n);
			_str[n] = '\0'; //strncpy空字符要手动添加
		}
		string(size_t n, char c)//fill 填充n个c
			: _str(new char[n]),
			_size(n),
			_capacity(n)
		{
			while (n--)
			{
				_str[n - 1] = c;//从后往前填充
			}
		}
		template<class InputIterator>
		string(InputIterator begin, InputIterator last)//range 取范围
			:_str(new char[last-begin+1]),
			_size(last-begin+1),
			_capacity(last-begin+1)
		{
			while (begin != last)
			{

			}
		}
		string(initializer_list<char> il);//initializer_list 初始化列表
		string(const string& s)//copy拷贝构造函数
			:_str(new char[strlen(s.c_str)]),
			_size(s._size),
			_capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}

		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		size_t size()
		{
			return _size;
		}

		const char* c_str() const
		{
			return _str;
		}

		void resever(int n)
		{
			assert(n > _capacity);
			//先申请空间
			iterator tmp = new char[n];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		string& operator=(const string& s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			
			return *this;
		}

		iterator begin() 
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			char* end = _str;
			while (end != '\0')
			{
				++end;
			}
			return end;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			if (pos < _size)
			{
				return _str[pos];
			}
		}

	private:
		char* _str;
		int _size;//当前存储元素
		int _capacity;//容量大小
		static const size_t npos = -1;

	};
	//istream& getline(istream&  _cin,const string& s)
}