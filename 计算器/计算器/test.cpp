#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<stack>
#include<map>


using namespace std;

class Solution
{
public:


	map<char, int> _operatorPrecedence = { { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 } };


	void toRPN(const string& s, size_t& i, vector<string>& v)
	{
		stack<char> st;
		while (i < s.size())
		{

			if (isdigit(s[i]))
			{
				string num;
				while (i < s.size() && isdigit(s[i]))
				{
					num += s[i];
					++i;
				}
				v.push_back(num);
			}
			else
			{
				if (s[i] == '(')
				{
					i++;
					toRPN(s, i, v);
				}
				else if (s[i] == ')')
				{
					i++;
					while (!st.empty())
					{
						v.push_back(string(1,st.top()));
						st.pop();
					}
					return;
				}
				else
				{
					if (st.empty() || _operatorPrecedence[s[i]] > _operatorPrecedence[st.top()])
					{
						st.push(s[i]);
						i++;
					}
					else
					{
						v.push_back(string(1,st.top()));
						st.pop();
					}
				}
			}
		}
		while (!st.empty())
		{
			v.push_back(string(1, st.top()));
			st.pop();
		}
	}




	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			const string& str = tokens[i];
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(stoi(str));
			}
			else
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}


	int calculate(string s)
	{

		std::string s1;
		s1.reserve(s.size());
		for (auto e : s)
		{
			if (e != ' ')
			{
				s1 += e;
			}
		}
		s.swap(s1);
		s1.clear();
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == '-' && (i == 0 || (!isdigit(s[i - 1]) && s[i - 1] !=')')))
			{
				s1 += "0-";
			}
			else
			{
				s1 += s[i];
			}
		}

		size_t i = 0;
		vector<string> v;
		toRPN(s1, i, v);
		return evalRPN(v);
	}
};












class Solution {
public:

int operatorPrecedence(char ch)
{
	struct opPD
	{
		char _op;
		int _pd;
	};
	static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
	for (auto& e : arr)
	{
		if (e._op == ch)
		{
			return e._pd;
		}
	}
		assert(false);
	return -1;
}
void toRPN(const string& s, size_t& i, vector<string>& v)
{
	stack<char> st;
	while (i < s.size())
	{
		if (isdigit(s[i]))
		{
			// 运算数输出
			string num;
			while (i < s.size() && isdigit(s[i]))
			{
				num += s[i];
				++i;
			}
			v.push_back(num);
		}
		else
		{
			if (s[i] == '(')
			{
				// 递归⽅式处理括号中的⼦表达式
				++i;
				toRPN(s, i, v);
			}
			else if (s[i] == ')')
			{
				++i;
				// 栈中的运算符全部输出
				while (!st.empty())
				{
					v.push_back(string(1, st.top()));
					st.pop();
				}
				// 结束递归
				return;
			}
			else
			{

					if (st.empty() || operatorPrecedence(s[i]) >
						operatorPrecedence(st.top()))
					{
						st.push(s[i]);
						++i;
					}
					else
					{
						v.push_back(string(1, st.top()));
						st.pop();
					}
			}
		}
	}
	// 栈中的运算符全部输出
	while (!st.empty())
	{
		v.push_back(string(1, st.top()));
		st.pop();
	}
}
int evalRPN(const vector<string>& tokens) {
	stack<int> s;
	for (size_t i = 0; i < tokens.size(); ++i)
	{
		const string& str = tokens[i];
		// str为数字
		if (!("+" == str || "-" == str || "*" == str || "/" == str))
		{
			s.push(stoi(str));
		}
		else
		{
			// str为操作符
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();

				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
		}
	}
	return s.top();
}
int calculate(string s)
{
	// 1、去除所有空格，否则下⾯的⼀些逻辑没办法处理
	std::string news;
	news.reserve(s.size());
	for (auto ch : s)
	{
		if (ch != ' ')
			news += ch;
	}
	s.swap(news);
	news.clear();
	// 2、将所有的负数-x转换为0-x
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == '-' && (i == 0 || (!isdigit(s[i - 1]) && s[i - 1] !=
			')')))
			news += "0-";
		else
			news += s[i];
	}
	// 中缀表达式转成后缀表达式

		size_t i = 0;
	vector<string> v;
	toRPN(news, i, v);
	// 后缀表达式进⾏运算
	return evalRPN(v);
}
};
