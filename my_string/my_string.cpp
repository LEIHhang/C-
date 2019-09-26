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
			:_str(new char[strlen(s.c_str()) + 1]),
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

		//Resizes the string to a length of n characters.
		void resize(size_t n)
		{
			size_t sz = this->size();
			if (n < sz)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				this->resever(n);
			}
		}

		void resize(size_t n, char c)
		{
			size_t sz = this->size();
			if (n < sz)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				this->append(n - _size, c);//后面添加
			}
		}

		void resever(int n)
		{
			assert(n > _capacity);
			//先申请空间
			iterator tmp = new char[n+1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void clear()
		{
			_size = 0;
		}

		bool empty() const
		{
			return _size;
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
			return _str[_size - 1];
		}
		const char& back() const
		{
			return _str[_size - 1];
		}
		char& front()//return the first character of string
		{
			return _str[0];
		}
		const char& front() const
		{
			return _str[0];
		}
		string& operator+=(const string& str)
		{
			return append(str);
		}
		string& operator+=(const char* s)
		{
			return append(s);
		}
		string& operator+=(char c)
		{
			return append(1, c);
		}
		string&	append(const string& str)//在末尾添加，并自动加上\0
		{
			return insert(_size, str);
		}
		string& append(const string& str, size_t subpos, size_t sublen)
		{
			return insert(_size, str, subpos, sublen);
		}
		string& append(const char* s)
		{
			return insert(_size, s);
		}
		string& append(const char* s, size_t n)
		{
			return insert(_size, s, n);
		}
		string& append(size_t n, char c)
		{
			return insert(_size, n, c);
		}
		void push_back(char c)
		{
			insert(_size, 1, c);
		}
		string& assign(const string& str)//重新分配内容
		{
			_size = 0;
			_str[_size] = '\0';//为了实习Insert函数复用，所以将第一个元素设置为\0
			return this->insert(0, str);
		}
		string& assign(const string& str, size_t subpos, size_t sublen) //subpos开始下标
		{
			_size = 0;
			_str[_size] = '\0';
			return this->insert(0, str, subpos, sublen);
		}
		string& assign(const char* s)
		{
			_size = 0;
			_str[_size] = '\0';
			return this->insert(0, s);
		}
		string& assign(const char* s, size_t n)
		{
			_size = 0;
			_str[_size] = '\0';
			return this->insert(0, s, n);
		}
		string& assign(size_t n, char c)
		{
			_size = 0;
			_str[_size] = '\0';
			return this->insert(0, n, c);
		}
		string& insert(size_t pos, const string& str)
		{
			assert(pos <= _size);
			size_t sz = str.size();//待插入串长 也是需要移动的距离
			//判断空间是否足够
			while (sz + _size > _capacity)
			{
				this->resever(1.5*_capacity);
			}
			size_t move_len = _size - pos + 1;//需要移动元素个数(包括\0)
			size_t temp_size = _size;//暂存_size
			while (move_len--)
			{
				//从后向前挪动数据
				_str[_size + sz] = _str[_size];
				--_size;
			}
			//现在_size等于插入位置下标
			strncpy(&_str[_size+1], str._str, sz);
			_size = temp_size + sz;
			return *this;
		}
		string& insert(size_t pos, const string& str, size_t subpos, size_t sublen)
		{
			string sl(str, subpos, sublen);
			return insert(pos, sl);
		}
		string& insert(size_t pos, const char* s)
		{
			string sl(s);
			return insert(pos, sl);
		}
		string& insert(size_t pos, const char* s, size_t n)
		{
			string sl(s, n);
			return insert(pos, sl);
		}
		string& insert(size_t pos, size_t n, char c)
		{
			string sl(n, c);
			return insert(pos, sl);
		}
		//Erases part of the string, reducing its length :
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos+len>_size)
			{
				_str[pos] = '\0';
				_size = pos;
				return *this;
			}
			else
			{
				size_t start = pos + len;//需要删除串的后面串的开始位置
				_size = pos;
				while (_str[start] != '0')
				{
					_str[_size] = _str[start];
					_size++;
					start++;
				}
				_str[_size] = '\0';
			}
		}
		iterator erase(const_iterator p)//删除指向的字符
		{
			while (*p != '\0')
			{
				*p = *(p + 1);
			}
		}
		iterator erase(const_iterator first, const_iterator last)
		{

		}
		string& replace(size_t pos, size_t len, const string& str);
		string& replace(const_iterator i1, const_iterator i2, const string& str);
		string& replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen);
	private:
		char* _str;
		int _size;//当前存储元素
		int _capacity;//容量大小
		static const size_t npos = -1;

	};
	//istream& getline(istream&  _cin,const string& s)
	void test1()
	{
		string s("abcdef");
		string str("abc");
		s.insert(4, str);
		cout << s.c_str() << endl;
	}
}
int main()
{
	lh::test1();
}