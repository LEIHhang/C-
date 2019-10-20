#include<iostream>
#include<assert.h>
#include<utility>
#include<istream>
#include<string>
#include<stdint.h>
using namespace std;
namespace lh
{
	class string
	{

		typedef const char* const_iterator;
		typedef char* iterator;
		friend istream& getline(istream& _cin, const string& s);
		friend string operator+(const string& lhs, const string& rhs);
		friend string operator>>(istream& _in, const string& s);
		//friend string operator<<(ostream& _out);
	public:
		//�ڹ��캯���У�_size��capacity�����ó�ʵ�ʴ洢��Ч�ַ��ĸ�������ȥ��\0��
		//���ں���ĳ�Ա�����У�����_size�������±����ʾָ��\0����ַ�����Ϊ��һ��Ԫ���±�Ϊ0
		//string()//defaultĬ��
		//	:_str(new char[1])
		//{
		//	*_str = '\0';
		//}
		
		//Ĭ�Ϲ���
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
			if (len==npos)
				strcpy(_str, newstart);
			else
			{
				strncpy(_str, newstart, len);
			}
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
			for (int i = 0; i < n;i++)
			{
				_str[i] = c;
			}
			_str[n] = '\0';
		}
		string(const string& s)//copy�������캯��
			:_str(new char[strlen(s.c_str()) + 1]),
			_size(s._size),
			_capacity(s._capacity)
		{
			strcpy(_str, s._str);
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
		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}

		//������
		iterator begin()//������
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		//����
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
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
				_size = n;
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
				this->append(n - _size, c);//�������
			}
		}
		void resever(int n)
		{
			if (n > _capacity)
				
			{
				iterator tmp = new char[n + 1];//������ռ�
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		bool empty() const
		{
			return _size;
		} 



		//Ԫ�ط���
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

		//�޸���
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
		string&	append(const string& str)//��ĩβ��ӣ����Զ�����\0
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
		string& assign(const string& str)//���·�������
		{
			_size = 0;
			_str[_size] = '\0';//Ϊ��ʵ��Insert�������ã����Խ���һ��Ԫ������Ϊ\0
			return this->insert(0, str);
		}
		string& assign(const string& str, size_t subpos, size_t sublen) //subpos��ʼ�±�
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
			size_t sz = str.size();//�����봮�� Ҳ����Ҫ�ƶ��ľ���
			//�жϿռ��Ƿ��㹻
			while (sz + _size > _capacity)
			{
				this->resever(1.5*_capacity);
			}
			size_t move_len = _size - pos + 1;//��Ҫ�ƶ�Ԫ�ظ���(����\0)
			size_t temp_size = _size;//�ݴ�_size
			while (move_len--)
			{
				//�Ӻ���ǰŲ������
				_str[_size + sz] = _str[_size];
				--_size;
			}
			//����_size���ڲ���λ���±�
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
				size_t start = pos + len;//��Ҫɾ�����ĺ��洮�Ŀ�ʼλ��
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
		iterator erase(iterator p)//ɾ��ָ����ַ�������ָ��ɾ��Ԫ�ؽ���λ�õĵ�����
		{
			if (*p != '\0')
			{
				iterator i = p;
				//copy(i+1, end() , p);
				strcpy(p, p + 1);
				--_size;
				return i;
			}
		}
		//iterator erase(iterator first, iterator last)
		//{
		//	if (*last != '\0')
		//	{
		//		copy((iterator)last + 1, end(), first);
		//		_size = _size - (last - first);
		//		return (iterator)first;
		//	}
		//}

		//replace portion of string
		//if the string is shorter,as many characters as possible are replaced
		string& replace(size_t pos, size_t len, const string& str)
		{
			assert(pos < str.size()); 
			for (int i = 0; i < len; i++)
			{
				if (pos >= _capacity)
					resever(1.5*_capacity);
				_str[pos++] = str._str[i];
			}
			if (pos > _size)
			{
				_size = pos;
				_str[pos] = '\0';
			}
		}


		const char* c_str() const
		{
			return _str;
		}
		size_t find(string& s, size_t pos)
		{
			//�ַ���ƥ������
			assert(_size - pos > s.size());
			
			while (_str[pos] != '\0')
			{
				int j = 0;
				int i = pos;
				while (_str[i] == s._str[j])
				{
					++i;
					++j;
					if (s._str[j] == '\0')
						return pos;
				}
				pos = i;
			}
		}

		size_t find(char* s, size_t pos)
		{
			while (_str[pos] != '\0')
			{
				int j = 0;
				int i = pos;
				while (_str[i] == s[j])
				{
					++i;
					++j;
					if (s[j] == '\0')
						return pos;
				}
				pos = i;
			}
		}
		size_t find(char* s, size_t pos, size_t n)
		{
			while (_str[pos] != '\0')
			{
				int j = 0;
				int i = pos;
				int k = n;
				while (_str[i] == s[j])
				{
					++i;
					++j;
					--k;
					if (k==0)
						return pos;
				}
				pos = i;
			}
		}
	private:
		char* _str;
		int _size;//��ǰ�洢Ԫ����
		int _capacity;//������С
		static const size_t npos = -1;

	};
	//istream& getline(istream&  _cin,const string& s)
	void test1()
	{
		string s("abcdef");
		string str("ghinm");
		char* arr = "woaini";

		s.assign(arr);
		cout << s.size() << endl;
		cout << s.capacity() << endl;
		cout << s.c_str() << endl;

		s.erase(arr);
		cout << s.c_str() << endl;

		//s.resize(15,'a');
		//cout << s.c_str() << endl;
		//s[0] = 'b';
		//cout << s[0] << endl;

		//string s1(5, 'a');
		//cout << s1.c_str() << endl;






	}

}
using namespace lh;
int main()
{
	test1();
	return 0;
}