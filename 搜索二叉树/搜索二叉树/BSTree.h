#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class K>

struct BSTreeNode

{
	K _key;
	BSTNode<K>* _left;
	BSTNode<K>* _right;
	BSTNode(const K& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};


template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree() = default;
	BSTree(const BSTree<K>& t)
	{
		_root = Copy(t._root);
	}
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}
	~BSTree()
	{
		Destory(_root);
		_root = nullptr;
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
			cur = new Node(key);
			if (parent->_key > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}
	}
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{

				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else {
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = _root->_right;
					}
					if (parent->_right == cur)
					{
						parent->_right = cur->_right;
					}
					else
					{
						parent->_left = cur->_right;
					}
					delete cur;
				}
				else if(cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = _root->_left;
					}
					if (parent->_right == cur)
					{
						parent->_right = cur->_left;
					}
					else
					{
						parent->_left = cur->_left;
					}
					delete cur;
				}
				else
				{
					Node* pMinRight = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						pMinRight = minRight;
						minRight = minRight->_left;
					}
					swap(minRight->_key, cur->_key);
					if (pMinRight->_left == minRight)
					{
						pMinRight->_left = minRight->_right;
					}
					else
					{
						pMinRight->_right = minRight->_right;
					}
					delete minRight;
				}
				return true;
			}
		}
		return false;
	}	

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << ' ';
		_InOrder(root->_right);
	}
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return;
		Node* copy = new Node(root->_key);
		copy->_left = Copy(root->_left);
		copy->_right = Copy(root->_right);
		return copy;
	}
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}
private:
	Node* _root = nullptr;
};

