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
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};

namespace open_address
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
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			if ((double)_n / (double)_tables.size() >= 0.7)
			{
				HashTable<K, V, Hash> newht(__stl_next_prime(_tables.size() + 1));

				for (size_t i = 0;i < _tables.size();i++)
				{
					if (_tables[i]._state == EXIST)
					{
						newht.Insert(_tables[i].kv);
					}
				}
				_table.swap(newht._tables);
			}

			Hash hs;
			size_t hash0 = hs(kv.first) % _table.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_table[hashi].state == EXIST)
			{
				hashi = hash0 + i;
				i++;
				hashi %= _tables.size();
			}

			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}
		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			size_t hash0 = hs(key) % _table.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_table[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST && _table[hashi]._kv.first == key)
				{
					return &_table[hashi];

				}

				hashi = hash0 + i;
				i++;
				
				hashi %= _table.size();
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
		size_t _n = 0;  // 表中存储数据个数
	};
}

