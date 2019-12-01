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
		//���keyС�ڵ�ǰ�ڵ㣬�����ӽڵ�������бȽ�
		//���Key���ڵ�ǰ�ڵ㣬���Һ��ӽڵ�������бȽ�
		//���key���ڵ�ǰ�ڵ㣬�����ʧ��
		
		//���ڵ�Ϊ�գ�ֱ�Ӳ���
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
				//������������������ͬ��keyֵ
				return false;
			}
		}
		//curֻ��һ����ʱ����������cur->_right��ָͬ����nullptr���ռ�
		//�����ں���Ϊcur���ٿռ丳ֵ��û������ġ�
		//����ֻ�ǽ����ٵĿռ丳ֵ����һ����ʱ��������û�������浽����
		cur = new Node(key);

		//����������������ٵĽ�����ӵ����ϵĲ���
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
		//1.��ΪҶ�ӽڵ��ʱ��ֱ�ӽ��丸�ڵ�ָ����Ϊ��
		//2.���Ҫɾ�����ֻ��һ�����ӣ������丸�ڵ�ָ���亢�ӽ��
		//	ǰ�������������һ�״���ʵ��
		//3.��ɾ��������������ӽ�㣬��������������������ĵ�һ���������滻��Ȼ��ɾ���ý��

		//���ҵ��ý��
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
				//��ʼɾ��
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
					//����һ�����׷��ָ�����������������һ�����
					parent = cur;
					Node* rightLess = cur->_right;
					while (rightLess->_left)
					{
						parent = rightLess;
						rightLess = rightLess->_left;
					}
					//�ҵ�����Ĳ���
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