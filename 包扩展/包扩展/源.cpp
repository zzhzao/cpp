#define _CRT_SECURE_NO_WARNINGS 1
template <class T>
const T& GetArg(const T& x)
{
	cout << x << " ";
	return x;
}

template <class ...Args>
void Arguments(Args... args)
{}

template <class ...Args>
void Print(Args... args)
{
	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
	// GetArg的返回值组成实参参数包，传给Arguments
	Arguments(GetArg(args)...);
}
void ShowList()
{
	cout << endl;
}

template <class T, class ...Args>
void ShowList(T x, Args... args)
{
	cout << x << " ";
	ShowList(args...);
}

template <class ...Args>
void Print(Args... args)
{
	// N个参数，第一个传给x，剩下N-1参数传给ShowList的第二个参数包
	ShowList(args...);
}

int main()
{
	double x = 2.2;
	Print(); // 包里有0个参数
	Print(1); // 包里有1个参数
	Print(1, string("xxxxx")); // 包里有2个参数
	Print(1.1, string("xxxxx"), x); // 包里有3个参数

	return 0;
}


int main()
{
	// 效率用法都是一样的
	bit::list<int> lt1;
	lt1.push_back(1);
	lt1.emplace_back(2);

	bit::list<bit::string> lt2;
	// 传左值效率用法都是一样的
	bit::string s1("111111111");
	lt2.push_back(s1);
	lt2.emplace_back(s1);
	cout << "*****************************************" << endl;
	// 传右值效率用法都是一样的
	bit::string s2("111111111");
	lt2.push_back(move(s2));
	bit::string s3("111111111");
	lt2.emplace_back(move(s3));
	cout << "*****************************************" << endl;
	// emplace_back的效率略高一筹
	lt2.push_back("1111111111111111111111111111");
	lt2.emplace_back("11111111111111111111111111");
	cout << "*****************************************" << endl;
}