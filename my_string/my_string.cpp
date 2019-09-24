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
		//在构造函数中，_size和capacity都设置成实际存储有效字符的个数（除去了\0）
		//但在后面的成员函数中，若将_size和用作下标则表示指向\0这个字符，因为第一个元素下标为0
		string()//default默认
			:_str(new char[1])
		{
			*_str = '\0';
		}
		string(const char* s = '\0')//from C string
			:_str(new char[strlen(s) + 1]),
			_size(strlen(s)),
			_capacity(_size)
		{
			strcpy(_str, s);
		}
		string(const string& str, size_t pos, size_t len = npos)//substring 子串
			:_str(new char[(str._size - pos)<len ? str._size - pos + 1:len + 1]),
			_size((str._size - pos)<len ? str._size - pos : len),
			_capacity((str._size - pos)<len ? str._size - pos : len)
		{
			char* newstart = str._str + pos;
			strcpy(_str, newstart);
		}
		string(const char* str, size_t n)//from buffer从缓冲区
			:_str(new char[n + 1]),
			_size(n),
			_capacity(n)
		{
			strncpy(_str, str, n);
			_str[n] = '\0'; //strncpy空字符要手动添加
		}
		string(size_t n, char c)//fill 填充n个c
			: _str(new char[n + 1]),
			_size(n),
			_capacity(n)
		{
			while (n--)
			{
				_str[n - 1] = c;//从后往前填充
			}
			_str[n] = '\0';
		}
		template<class InputIterator>
		string(InputIterator begin, InputIterator last)//range 取范围
			:_str(new char[last-begin+1]),
			_size(last-begin),
			_capacity(last-begin)
		{
			while (begin != last)
			{

			}
		}
		string(initializer_list<char> il);//initializer_list 初始化列表
		string(const string& s)//copy拷贝构造函数
			:_str(new char[strlen(s.c_str) + 1]),
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
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		const char* c_str() const
		{
			return _str;
		}

		void rsize(size_t n)
		{

		}

		void rsize(size_t n, char c)
		{

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

		void clear()
		{

		}

		bool empty() const
		{

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
		char& back()//return the last character of string
		{

		}
		const char& back() const
		{

		}
		char& front()//return the first character of string
		{

		}
		const char& front() const
		{

		}
		string& operator+=(const string& str)
		{

		}
		string& operator+=(const char* s)
		{

		}
		string& operator+=(char c)
		{

		}
		string&	append(const string& str)
		{

		}
		string& append(const string& str, size_t subpos, size_t sublen)
		{

		}
		string& append(const char* s)
		{

		}
		string& append(const char* s, size_t n)
		{

		}
		string& append(size_t n, char c)
		{

		}
		void push_back(char c)
		{

		}
	private:
		char* _str;
		int _size;//当前存储元素
		int _capacity;//容量大小
		static const size_t npos = -1;

	};
	//istream& getline(istream&  _cin,const string& s)
}