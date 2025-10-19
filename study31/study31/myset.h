#pragma once
namespace bit
{
	template<class K>
	class set
	{
		struct SetKeyOfT

		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		iterator begin()
		{
			_t.Begin();
		}
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}
