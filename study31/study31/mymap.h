#pragma once
namespace bit
{
	template<class K, class V>
	class map

	{
		struct MapKeyOfT

		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, const pair<K, V>, SetKeyOfT>::Iterator iterator;
		iterator begin()
		{
			_t.Begin();
		}
		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};
}
