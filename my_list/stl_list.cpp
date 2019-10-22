#include<iostream>
namespace lh
{
	template < class T > 
	struct list_node
	{
		typedef list_node<T> node;
		node* _prev;
		node* _next;
		T date;
		list_node(const T& arg = T())
			:date(arg),
			_prev(nullptr),
			_next(nullptr)
		{}
	};
	template<class T ,class Ref,class Ptr>
	struct list_iterator
	{
		//目的是为了使一个类对象表现的像一个类型的指针一样
		//把list_iterator 的对对象想象为一个指针，并通过运算符重载实现对他完成指针实现的功能。
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> Self;
		node* pnode;
		list_iterator(node* arg)
			:pnode(arg)
		{}
		Ref operator*()
		{
			return pnode->date;
		}
		Self& operator++()
		{
			pnode = pnode->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp = *this;
			pnode = pnode->_next;
			return tmp;
		}
		Self& operator--()
		{
			pnode = pnode->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp = *this;
			pnode = pnode->_prev;
			return tmp;
		}
		//Ptr operator->()
		//{
		//	return &(operator*()) //特殊处理
		//}
		bool operator!=(const Self x)
		{
			return pnode != x.pnode;
		}
		bool operator==(const Self x)
		{
			return pnode == x.pnode;
		}
	};
	template < class T >
	class list
	{
	public:
		typedef list_node<T> node;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		list()
		{
			head = new node(T());
			head->_next = head;
			head->_prev = head;
		}
		~list()
		{
			delete head;
			head = nullptr;
		}
		iterator& begin()
		{
			return iterator(head->_next);
		}
		iterator& end()
		{
			return iterator(head);
		}
		const_iterator& begin() const
		{
			return const_iterator(head->_next);
		}
		const_iterator& end() const
		{
			return const_iterator(head);
		}
		//capacity
		bool empty()
		{
			return head->_next == head;
		}
		size_t size() const
		{
			size_t n = 0;
			iterator start = iterator(head->_next);
			iterator end = iterator(head);

			while (start != end)
			{
				++n;
				++start;
			}
			return n;
		}

		//modefiers
		void push_back(const T& val)
		{
			node* tail = head->_prev;
			node* newnode = new node(val);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = head;
			head->_prev = newnode;
		}
		void pop_back()
		{
			//先判空
			if (empty())
				return;
			else
			{
				node* tail = head->_prev;
				tail->_prev->_next = head;
				head->_prev = tail->_prev;
				delete tail;
			}
		}
		void push_front(const T& val)
		{
			node* start = head->_next;
			node* newnode = new node(val);
			head->_next = newnode;
			newnode->_prev = head;
			newnode->_next = start;
			start->_prev = newnode;
		}
		void pop_front()
		{
			//先判空
			if (empty())
				return;
			else
			{
				node* start = head->_next;
				head->_next = start->_next;
				start->_next->_prev = head;
				delete start;
			}
		}
		iterator insert(iterator pos, const T& val)//返回指向心插入元素 //前插
		{
			node* cur = pos.pnode;
			node* newnode = new node(val);
			newnode->_next = cur;
			newnode->_prev = cur->_prev;
			cur->_prev->_next = newnode;
			cur->_prev = newnode;
			return iterator(newnode);

		}
		iterator erase(iterator pos)
		{
			if (empty())
				return iterator(head);
			else
			{
				node* cur = pos.pnode;
				node* re = cur->_next;
				cur->_prev->_next = cur->_next;
				cur->_next->_prev = cur->_prev;
				delete cur;
				return iterator(re);
			}

		}
		void clear()
		{
			if (!empty())
			{
				iterator it = begin();
				while (it != end())
				{
					it=erase(it);
				}
			}
		/*	delete head;
			head = nullptr;*/
			//析构函数会释放head
		}
		void swap(list& x)
		{
		
		}

	private:
		node* head;
	};
	void print_list( list<int>& l)
	{
		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			std::cout << *it << std::endl;
			it++;
		}
		std::cout<<"输出结束\n"<<std::endl;
	}
}

void test1()
{
	using namespace lh;
	list<int> l;
	l.push_back(1);
	l.push_back(4);
	l.push_back(5);
	l.push_back(2);
	l.push_back(3);
	l.push_front(10);
	list<int>::iterator it = l.begin();
	l.erase(it);
	l.clear();
	print_list(l);
}
void test2()
{
	using namespace lh;
	list<int> l;
	l.push_back(3);
	l.push_back(3);
	l.pop_back();
	std::cout << l.size();
	
	//print_list(l);
}
int main()
{
	test1();
	
	return 0;
}