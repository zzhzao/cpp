#pragma once

#include<iostream>
#include<vector>
using namespace std;

inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] =
	{
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};

	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	// >=
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

template<class K>
struct HashFunc
{
	size_t operator()(const K& key) const
	{
		return (size_t)key;
	}
};

// 特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key) const
	{
		size_t hash = 0;
		for (auto ch : key)
		{
			hash += ch;
			hash *= 131;
		}

		return hash;
	}
};


namespace open_adrress
{

	enum State
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable(size_t n = __stl_next_prime(0))
			:_tables(n)
			, _n(0)
		{
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// 扩容，负载因子==0.7就扩容
			if ((double)_n / (double)_tables.size() >= 0.7)
			{
				HashTable<K, V, Hash> newht(__stl_next_prime(_tables.size() + 1));

				// 遍历旧表，将旧表的数据全部重新映射到新表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXIST)
					{
						newht.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newht._tables);
			}

			Hash hs;
			size_t hash0 = hs(kv.first) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			// 线性探测
			while (_tables[hashi]._state == EXIST)
			{
				hashi += i * i;
				i++;

				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			size_t hash0 = hs(key) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				// 线性探测
				hashi += i;
				i++;

				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n;   // 实际存储的数据个数
	};

	struct pairHash
	{
		size_t operator()(const pair<int, int>& kv) const
		{
			size_t hash = 0;
			hash += kv.first;
			hash *= 131;
			hash += kv.second;
			hash *= 131;

			cout << hash << endl;
			return hash;
		}
	};
}

namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;

		Node* _node;
		const HT* _pht;

		HTIterator(Node* node, const HT* pht)
			:_node(node)
			, _pht(pht)
		{
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				// 当前桶还没走完
				_node = _node->_next;
			}
			else 
			{
				// 当前桶走完了，需要找下一个不为空的桶里面的第一个节点
				KeyOfT kot;
				Hash hs;
				size_t hashi = hs(kot(_node->_data)) % _pht->_tables.size();
				hashi++;
				while (hashi < _pht->_tables.size())
				{
					if (_pht->_tables[hashi])
					{
						_node = _pht->_tables[hashi];
						break;
					}

					++hashi;
				}

				if (hashi == _pht->_tables.size())
				{
					// 所有桶都走完了，置为end()
					_node = nullptr;
				}
			}

			return *this;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
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

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		// 友元声明
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct HTIterator;

		typedef HashNode<T> Node;
	public:
		typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;


		Iterator Begin()
		{
			if (_n == 0)
				return End();

			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return Iterator(_tables[i], this);
				}
			}

			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		ConstIterator Begin() const
		{
			if (_n == 0)
				return End();

			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return ConstIterator(_tables[i], this);
				}
			}

			return End();
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr, this);
		}

		HashTable(size_t n = __stl_next_prime(0))
			:_tables(n, nullptr)
			, _n(0)
		{
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_tables[i] = nullptr;
			}
		}

		pair<Iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			Iterator it = Find(kot(data));
			if (it != End())
				return { it, false };

			Hash hs;

			// 负载因子到1扩容
			if (_n == _tables.size())
			{
				vector<Node*> newtables(__stl_next_prime(_tables.size() + 1), nullptr);
				// 遍历旧表，将旧表的数据全部重新映射到新表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						// cur头插到新表
						size_t hashi = hs(kot(cur->_data)) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}

				_tables.swap(newtables);
			}

			size_t hashi = hs(kot(data)) % _tables.size();

			// 头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return { Iterator(newnode, this), true };
		}

		Iterator Find(const K& key)
		{
			Hash hs;
			KeyOfT kot;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return Iterator(cur, this);

				cur = cur->_next;
			}

			return End();
		}

		bool Erase(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			KeyOfT kot;
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_n;
					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _n;				// 实际存储有效数据个数
	};
}


