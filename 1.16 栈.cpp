// 数组模拟实现栈
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stack[N];
int n;

void push(int val)
{
	stack[++n] = val;
}

void pop()
{
	stack[n--] = 0;
}

int top()
{
	return stack[n];
}

bool empty()
{
	return n == 0;
}

int size()
{
	return n;
}

int main(void)
{
	for(int i = 1; i <= 10; i++)
	{
		push(i);
	}
	
	cout << top() << endl;

	if(empty())
		cout << "empty" << endl;
	else
		cout << size() << endl;

	for(int i = 0; i < 10; i++)
	{
		cout << top() << ' ';
		pop();
	}
	return 0;
}*/

// STL中的栈stack
/*#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> stk;
	
	for(int i = 1; i <= 10; i++)
		stk.push(i);

	if(stk.empty())
		cout << "empty" << endl;
	else
		cout << stk.size() << endl;

	for(int i = 0; i < 10; i++)
	{
		cout << stk.top() << ' ';
		stk.pop();
	}
	cout << endl;
	
	if(stk.empty())
		cout << "empty" << endl;
	else
		cout << stk.size() << endl;
		
	return 0;
}*/

// B3614 【模板】栈
/*#include <iostream>
#include <string>

typedef unsigned long long ull;

using namespace std;

const int N = 1e6 + 10;
ull stack[N];
int n;

int size()
{
	return n;
}

void push(ull val)
{
	stack[++n] = val;
}

void pop()
{
	if(size())
		stack[n--] = 0;
	else
		cout << flush << "Empty" << endl;
}

void query()
{
	if(size())
		cout << flush << stack[n] << endl;
	else
		cout << flush << "Anguei!" << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	int T, m;
	ull x;
	cin >> T;

	while(T--)
	{
		n = 0;
		cin >> m;
		while(m--)
		{
			cin >> str;
			if(str == "push")
			{
				cin >> x;
				push(x);
			}
			else if(str == "pop")
				pop();
			else if(str == "query")
				query();
			else if(str == "size")
				cout << flush << size() << endl;
		}
	}
	
	return 0;
}*/

// 20.有效的括号
/*#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
	stack<char> stk;
	
	if(s.size() % 2 != 0)
		return false;
	
	for(auto ch : s)
	{
		if(ch == '[' || ch == '(' || ch == '{')
		{
			stk.push(ch);
		}
		else
		{
			if(stk.empty())
				return false;
				
			char top = stk.top();
			
			if(top == '(' && ch != ')')
				return false;
			if(top == '[' && ch != ']')
				return false;
			if(top == '{' && ch != '}')
				return false;
				
			stk.pop();
		}
	}
	return stk.empty();
}

int main(void)
{
	string str;
	cin >> str;

	if(isValid(str))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}*/

// P4387 【深基15.习9】验证栈序列
/*#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int pushed[N], poped[N];

int main(void)
{
	stack<int> stk;
	
	int n, m;
	cin >> n;

	while(n--)
	{
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			cin >> pushed[i];
		}
		for(int i = 0; i < m; i++)
		{
			cin >> poped[i];
		}
		
		int pos = 0;
		for(int i = 0; i < m; i++)
		{
			stk.push(pushed[i]);
			while(stk.top() == poped[pos])
			{
				pos++;
				stk.pop();
				if(stk.empty()) break;
			}
		}
		if(stk.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		while(!stk.empty()) stk.pop();
	}
	return 0;
}*/

// P1449 后缀表达式
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	stack<int> nums;
	string str;
	
	getline(cin, str, '@');
	
	int val;
	char ch;
	while()
	
	return 0;
}























































