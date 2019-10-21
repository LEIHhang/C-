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
		//设想它为一个指针，对他完成指针实现的功能
		typedef list_node<T> node;
		node* pnde;//list_iterator可以理解为时指向一个node类型的指针
		list_iterator(node* arg)
			:pnde(arg)
		{}
		Ref operator*()
		{
			return pnde->date;
		}
		void operator++()
		{
			pnde = pnde->_next;
		}
	};
	template < class T >
	class list
	{
	public:
		typedef list_node<T> node;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		iterator& begin()
		{
			return head->_next;
		}
		iterator& end()
		{
			return head;
		}
		const_iterator& begin() const
		{
			return head->_next;
		}
		const_iterator& end() const
		{
			return head;
		}
		void push_back(const T& val)
		{
			node* tail = head->_prev;
			node* newnode = new node(val);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = head;
			head->_prev = newnode;
		}
		list()
		{
			head = new node(T());
			head->_next = head;
			head->_prev = head;
		}
	private:
		node* head;
	};
	template<class T>
	void print_list(list<T>& l)
	{
		list<int>::iterator it = l.begin();
		while (it != l.end)
		{
			cout << *it << endl;
			++it;
		}
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
	print_list(l);
}