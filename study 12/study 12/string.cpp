#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"


namespace zzh
{

	const size_t string::npos = -1;

	size_t string::size() const
	{
		return _size;
	}
	char& string::operator[](size_t i)
	{
		assert(i < _size);
		return _str[i];
	}
	const char& string::operator[](size_t i) const
	{
		assert(i < _size);
		return _str[i];
	}
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::iterator string::begin() const
	{
		return _str;
	}
	string::iterator string::end() const
	{
		return _str + _size;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			if (_str)
			{
				memcpy(tmp, _str, _size + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = _size + len > 2 * _capacity ? _size + len : 2 * _capacity;
			reserve(newcapacity);
		}
		memcpy(_str + _size, str, len + 1);
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		//size_t end = _size;
		//while (end >= pos)
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		_size++;

	}

	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = _size + len > 2 * _capacity ? _size + len : 2 * _capacity;
			reserve(newcapacity);
		}
		size_t end = _size + len;
		while (end  >  pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		//memcpy(_str + pos, str, len);
		for (size_t i = 0;i < len;i++)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len == npos || _size - pos <= len)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			memmove(_str + pos, _str + pos + len, _size+1 - pos - len);
		}
	}
	size_t string::find(char ch, size_t pos) const
	{
		for (size_t i = pos;i < _size;i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}

	size_t string::find(const char* sub, size_t pos) const
	{
		const char* p = strstr(_str, sub);
		if (p == nullptr)
		{
			return npos;
		}
		else
		{
			return p - _str;
		}
	}
	string string::substr(size_t pos, size_t len) const
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string ret;
		for (size_t i = 0; i < len;i++)
		{
			ret += _str[pos + i];
		}
		return ret;
	}
	//string::string(const string& s)
	//{
	//	_str = new char[s._capacity + 1];
	//	memcpy(_str, s._str, _size + 1);
	//}
	//string& string::operator=(const string& s)
	//{
	//	if (&s != this)
	//	{
	//		//char* tmp = new char[s._capacity + 1];
	//		//memcpy(tmp, s._str, s._size + 1);
	//		//delete[] _str;

	//		//_str = tmp;
	//		//_size = s._size;
	//		//_capacity = s._capacity;
	//		string tmp(s);
	//		swap(tmp);
	//	}
	//	return *this;

	//}
	string& string::operator=(string tmp)
	{
		swap(tmp);
		return *this;
	}
	bool string::operator<(const string& s) const
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < s._size)
		{
			if (_str[i1] < s[i2])
			{
				return true;
			}
			else if (_str[i1] > s[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}

		return i2 < s._size;
	}
	//bool string::operator>(const string& s) const
	//{
	//
	//}
	//bool string::operator<=(const string& s) const
	//{

	//}
	//bool string::operator>=(const string& s) const
	//{

	//}
	//bool string::operator==(const string& s) const
	//{
	//	
	//}
	bool string::operator!=(const string& s) const
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < s._size)
		{
			if (_str[i1] != s[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}

		return i1 == _size && i2 == s._size;
	}
	std::ostream& operator<<(std::ostream& os, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			os << s[i];
		}
		return os;
	}
	std::istream& operator>>(std::istream& is, string& s)
	{
		s.clear();
		char ch = is.get();
		char buff[256];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			//s += ch;
			//is >> ch;
			buff[i++] = ch;
			ch = is.get();
			if (i == 255)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return is;
	}
	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
	size_t string::capacity() const
	{
		return _capacity;
	}
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
}