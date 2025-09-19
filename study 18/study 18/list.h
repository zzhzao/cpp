#pragma once
#include<iostream>
#include<assert.h>
namespace zzh
{
	template<class T>
	struct list_node
	{
		list_node* _next;
		list_node* _prev;
		T _data;
		list_node(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{

		}
	};
	//template<class T,class ref>
	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T,Ref,Ptr> Self;
		node* _node;

		list_iterator(node* node)
			:_node(node)
		{ }
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}
		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};
	/*template<class T>
	struct list_const_iterator
	{
		typedef list_node<T> node;
		typedef list_const_iterator<T> Self;
		node* _node;

		list_const_iterator(node* node)
			:_node(node)
		{
		}
		const T& operator*()
		{
			return _node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}
		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};*/
	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef list_iterator<T£¬T&,T*> iterator;
	
		typedef list_iterator<T£¬const T&,const T*> const_iterator;
		list()
		{
			empty_init();
		}
		void push_back(const T& x)
		{
			//node* tail = _head->_prev;
			//node* newnode = new node(x);
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return iterator(_head->_next);
		}
		const_iterator end()
		{
			return iterator(_head);
		}
		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			_size--;
			return next;
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_head()
		{
			erase(begin());
		}
		size_t size()
		{
			return _size;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0
		}
		list(list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}
		list(initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}
		void swap(list<T> lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);

		}
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
	private:
		node* _head;
		size_t _size;
	};
}