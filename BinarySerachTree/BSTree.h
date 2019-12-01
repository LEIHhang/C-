template<typename k>
struct BSTreeNode
{
	k _key;
	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;

	BSTreeNode(k key)
	{
		_key = key;
		_left = nullptr;
		_right = nullptr;
	}
};

template<typename k>

class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	bool Insert(const k& key)
	{
		//如果key小于当前节点，和左孩子节点继续进行比较
		//如果Key大于当前节点，和右孩子节点继续进行比较
		//如果key等于当前节点，则插入失败
		
		//根节点为空，直接插入
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//搜索二叉树不能有相同的key值
				return false;
			}
		}
		//cur只是一个临时变量，他和cur->_right共同指向了nullptr这块空间
		//所以在后面为cur开辟空间赋值是没有意义的。
		//这里只是将开辟的空间赋值给了一个临时变量，并没有真正存到书上
		cur = new Node(key);

		//这里才是真正将开辟的结点链接到树上的操作
		if (key < parent->_key)
		{
			parent->_left = cur;
		}
		else if (key > parent->_key)
		{
			parent->_right = cur;
		}

		return true;
	}
	bool Erase(const k& key)
	{
		//1.当为叶子节点的时候直接将其父节点指向置为空
		//2.如果要删除结点只有一个孩子，则让其父节点指向其孩子结点
		//	前两种情况可以用一套代码实现
		//3.若删除结点有两个孩子结点，则找其右子树中序遍历的第一个结点进行替换，然后删除该结点

		//先找到该结点
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//开始删除
				if (cur->_left == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
						parent->_right = cur->_right;
					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
						parent->_right = cur->_left;
					delete cur;
					return true;
				}
				else
				{
					//设置一个结点追踪指向右子树中序遍历第一个结点
					parent = cur;
					Node* rightLess = cur->_right;
					while (rightLess->_left)
					{
						parent = rightLess;
						rightLess = rightLess->_left;
					}
					//找到结点后的操作
					cur->_key = rightLess->_key;
					if (parent->_right == rightLess)
					{
						parent->_right = rightLess->_right;
					}
					else if (parent->_left == rightLess)
					{
						parent->_left = rightLess->_right;
					}
					delete rightLess;
				}
			}
		}
		return false;

	}
	void print_Ldr(Node* root)
	{
		if (root != nullptr)
		{
			print_Ldr(root->_left);
			cout << root->_key << " ";
			print_Ldr(root->_right);
		}
	}
	void LDR()
	{
		print_Ldr(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};



void TeseBST()
{
	BSTree<int> t;
	int arr[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
	for (auto e : arr)
	{
		t.Insert(e);
	}
	t.LDR();
	t.Erase(0);
	t.LDR();
	t.Erase(1);
	t.LDR();
	t.Erase(2);
	t.LDR();
	t.Erase(3);
	t.LDR();
	t.Erase(4);
	t.LDR();

}