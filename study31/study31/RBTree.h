#pragma once
enum Colour

{
	RED,
	BLACK
};

template<class T>

struct RBTreeNode

{
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;
	RBTreeNode(const T& data)
		: _data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{
	}
};
template<class K, class T, class KeyOfT>

class RBTree

{

private:
	typedef RBTreeNode<T> Node;
	Node* _root = nullptr;


public:
	typedef RBTreeIterator<T> Iterator;
	Iterator Begin()
	{
		Node* minleft = _root;
		while (minleft && minleft->_left)
		{
			minleft = minleft->_left;
		}
		return Iterator(minleft,_root);
	}
	Iterator End()
	{
		return Iterator(nullptr,_root);
	}
	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}
		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else

			{
				return false;
			}
		}
		cur = new Node(data);
		Node* newnode = cur;
		// 新增结点。颜⾊给红⾊ 
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else

		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		//...

		return true;
	}
};
template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator Self;
	Node* _node;
	Node* _root;
	RBTreeIterator(Node* node,Node* root)
		:_node(node)
		:_root(root)
	{ }
	T& operator*()
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &_node->_data;
	}
	Self& operator++()
	{
		if (_node->_right)
		{
			Node* minleft = _node->_right;
			while (minleft->_left)
			{
				minleft = minleft->_left;
			}
			_node = minleft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self& operator--()
	{
		//++逻辑反过来
		if (_node == nullptr)
		{
			// --end()，到最右节点
			Node* maxRight = _root;
			while (maxRight && maxRight->_right)
			{
				maxRight = maxRight->_right;
			}

			_node = maxRight;
		}
		else if (_node->_left)
		{
			// 左子树不为空，中序左子树最后一个
			Node* rightMost = _node->_left;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else
		{
			// 孩子是父亲右的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}

		return *this;
	}
	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}
	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}
};