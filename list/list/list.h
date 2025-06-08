#pragma once
#include<iostream>
using namespace std;


namespace zzh
{
    // List的节点类
    template<class T>
    struct ListNode
    {
  
        ListNode(const T& val = T())
            :_pPre(nullptr)
            , _pNext(nullptr)
            , _val(val)
        { }
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
        ListIterator(PNode pNode = nullptr)
            :_pNode(PNode)
        { }
        ListIterator(const Self& s)
            :_pNode(s._pNode)
        { }
        Ref operator*()
        {
            return _pNode->_val;
        }
        Ptr operator->()
        {
            return &_pNode->_val;
        }
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return _pNode;
        }
        Self operator++(int)
        {
            Self tmp(_pNode);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return _pNode;
        }
        Self& operator--(int)
        {
            Self tmp(_pNode);
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& s)
        {
            return _pNode != s._pNode;
        }
        bool operator==(const Self& s)
        {
            return _pNode == s._pNode;
        }

        PNode _pNode;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        // List的构造
        void CreateHead()
        {
            _pHead = new PNode;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
            _size = 0;
        }
        list()
        {
            CreateHead();
        }
        list(int n, const T& value = T())
        {
            for (int i = 0;i < n;i++)
            {
                push_back(value);
            }
        }
        list(const list<T>& lt)
        {
            CreateHead();
            for (auto e : lt)
            {
                push_back(e);
            }
        }
        list<T>& operator=(list<T> lt)
        {
            swap(lt);
            return *this;
        }
        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }

        // List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }
        iterator end()
        {
            return iterator(_pHead);
        }
        const_iterator begin()
        {
            return const_iterator(_pHead->_pNext);
        }
        const_iterator end()
        {
            return const_iterator(_pHead);
        }

        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }


        // 在pos位置前插入值为val的节点
        void insert(iterator pos, const T& val)
        {
            PNode cur = pos._pNode;
            PNode prev = cur->_pPre;
            PNode newnode = new PNode(val);
            newnode->_pNext = cur;
            newnode->_pPre = prev;
            prev->_pNext = newnode;
            cur->_pPre = newnode;

            _size++;

        }
        iterator erase(iterator pos)
        {
            PNode cur = pos._pNode;
            PNode prev = cur->_pPre;
            PNode next = cur->_pNext;
            prev->_pNext = next;
            next->_pPre = prev;
            delete cur;
            _size--;
            return next;
        }
        void clear()
        {
            auto it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }
        void swap(list<T>& lt)
        {
            std::swap(lt._pHead, _pHead);
            std::swap(lt._size, _size);
        }
    private:
        size_t _size;
        PNode _pHead;
    };
};