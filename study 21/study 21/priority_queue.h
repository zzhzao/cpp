#pragma once
#include<vector>

using namespace std;

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Graeter
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
namespace zzh
{
	template<class T, class Container = std::vector<T>,class Compare  = Less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{

		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjustup(_con.size() - 1);
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustdown(0);
		}
		const T & top() const
		{
			return _con[0];
		}
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
	private:
		void adjustup(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjustdown(int parent)
		{
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size()&&_con[child + 1] > _con[child])
				{
					++child;
				}
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	private:
		Container _con;
	};
}