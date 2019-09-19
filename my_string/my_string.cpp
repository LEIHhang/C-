#include<iostream>
#include<assert.h>
#include<utility>
#include<istream>
typedef const char* const_iterator;
typedef char* iterator;
namespace lh
{
	class string
	{
		friend istream getline(istream& _cin,const string& s);
	public:
		//string()//默认构造函数
		//	:_str (new char[1])
		//{
		//	*_str = '\0';
		//}
		string(const char* s='\0')//默认构造函数
			:_str(new char[strlen(s)+1])
		{
			strcpy(_str, s);
			_size = strlen(s) + 1;
			_capacity = _size;
		}

		string(string& s)//拷贝构造函数
			:_str(new char[strlen(s._str)+1]),
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

		string& operator=(string& s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			
			return *this;
		}

		iterator& begin()
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
		int _size;
		int _capacity;
	};
	istream getline(istream&  _cin,const string& s)
	{
		
	}
}