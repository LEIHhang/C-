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
		//�ڹ��캯���У�_size��capacity�����ó�ʵ�ʴ洢��Ч�ַ��ĸ�������ȥ��\0��
		//���ں���ĳ�Ա�����У�����_size�������±����ʾָ��\0����ַ�����Ϊ��һ��Ԫ���±�Ϊ0
		string()//defaultĬ��
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
		string(const string& str, size_t pos, size_t len = npos)//substring �Ӵ�
			:_str(new char[(str._size - pos)<len ? str._size - pos + 1:len + 1]),
			_size((str._size - pos)<len ? str._size - pos : len),
			_capacity((str._size - pos)<len ? str._size - pos : len)
		{
			char* newstart = str._str + pos;
			strcpy(_str, newstart);
		}
		string(const char* str, size_t n)//from buffer�ӻ�����
			:_str(new char[n + 1]),
			_size(n),
			_capacity(n)
		{
			strncpy(_str, str, n);
			_str[n] = '\0'; //strncpy���ַ�Ҫ�ֶ����
		}
		string(size_t n, char c)//fill ���n��c
			: _str(new char[n + 1]),
			_size(n),
			_capacity(n)
		{
			while (n--)
			{
				_str[n - 1] = c;//�Ӻ���ǰ���
			}
			_str[n] = '\0';
		}
		template<class InputIterator>
		string(InputIterator begin, InputIterator last)//range ȡ��Χ
			:_str(new char[last-begin+1]),
			_size(last-begin),
			_capacity(last-begin)
		{
			while (begin != last)
			{

			}
		}
		string(initializer_list<char> il);//initializer_list ��ʼ���б�
		string(const string& s)//copy�������캯��
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
			//������ռ�
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
		int _size;//��ǰ�洢Ԫ��
		int _capacity;//������С
		static const size_t npos = -1;

	};
	//istream& getline(istream&  _cin,const string& s)
}