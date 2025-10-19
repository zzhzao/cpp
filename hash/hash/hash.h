#pragma once
#include<iostream>
#include<vector>
using namespace std;
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

template<class K, class V>

class HashTable
{
public:
	HashTable(size_t n = 11)
		:_tables(n)
		,_n(0)
	{ }

	bool Insert(const pair<K, V>& kv)
	{
		if (Find(kv.first))
			return false;

		//if ((double)_n / _tables.size() >= 0.7)
		//{
		//	vector<HashData<K, V>> newtables;
		//	newtabels.resize(_tables.size() * 2);
		//	for (size_t i = 0; i < _tables.size() ; i++)
		//	{
		//		if (_table[i]._state == EXIST)
		//		{

		//		}
		//	}	
		//}
		//_tables.swap(newtables);
		if ((double)_n % _tables.size() >= 0.7)
		{
			HashTable<K, V> ht(_tables.size() * 2);

			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					ht.Insert(_tables[i]._kv);
				}
			}
			_tables.swap(ht._tables);
		}
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_table[hashi]._state == EXIST)
		{
			hashi = hash0 + i;
			i++;
			hashi %= _tables.size();
		}
		_tables[hashi].kv = kv;
		_table[hashi]._state = EXIST;
		++_n;
		return true;
	}
	 HashData<K, V>* Find(const K& key)
	{
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_table[hashi]._state != EMPTY)
		{
			if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
			{
				return &_table[hashi];
			}
			hashi = hash0 + i;
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
		return false;
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n = 0; // 表中存储数据个数 
};
