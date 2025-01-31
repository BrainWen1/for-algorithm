// P1449 后缀表达式
/*#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int main(void)
{
	stack<int> nums;
	
	char ch;
	int num = 0;
	while(cin >> ch)
	{
		if(ch == '@')
			break;
		else if(isdigit(ch))
		{
			num = num * 10 + (ch - '0');
		}
		else if(ch == '.')
		{
			nums.push(num);
			num = 0;
		}
		else
		{
			int num_2 = nums.top();
			nums.pop();
			int num_1 = nums.top();
			nums.pop();
			switch(ch)
			{
				case '+': nums.push(num_1 + num_2); break;
				case '-': nums.push(num_1 - num_2); break;
				case '*': nums.push(num_1 * num_2); break;
				case '/': nums.push(num_1 / num_2); break;
				default : break;
			}
		}
	}
	cout << nums.top() << endl;

	return 0;
}*/

// P1241 括号序列
/*#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 110;
bool arr[N];

int main(void)
{
	stack<int> stk;
	string str;
	cin >> str;
	
	char ch;
	int len = str.size();
	for(int i = 0; i < len; i++)
	{
		ch = str[i];
		if(ch == '(' || ch == '[')
			stk.push(i);
		else
		{
			char left = str[stk.top()];
			if((left == '(' && ch == ')') || (left == '[' && ch == ']'))
			{
				arr[i] = true;
				arr[stk.top()] = true;
				stk.pop();
			}
		}
	}
	
	for(int i = 0; i < len; i++)
	{
		ch = str[i];
		if(arr[i])
			cout << ch;
		else
		{
			if(ch == '(' || ch == ')') cout << "()";
			else if(ch == '[' || ch == ']') cout << "[]";
		}
	}
	
	return 0;
}*/


// 数组模拟队列
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int queue[N];
int h, t;

void push(int val)
{
	queue[++t] = val;
}

void pop()
{
	h++;
}

int size()
{
	return (t - h);
}

bool empty()
{
	return (h == t);
}

int front()
{
	return queue[h + 1];
}

int back()
{
	return queue[t];
}

int main(void)
{
	for(int i = 1; i <= 9; i++)
		push(i);
		
	while(!empty())
	{
		cout << front() << ' ' << back() << ' ' << size() << endl;
		pop();
	}
	
	return 0;
}*/

// STL中的队列queue
/*#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> PII;

int main(void)
{
	queue<PII> que;
	
	for(int i = 1; i <= 10; i++)
		que.push( {i, 2 * i} );
	
	while(!que.empty())
	{
		PII x = que.front();
		PII y = que.back();
		cout << x.first << ' ' << x.second << endl;
		cout << y.first << ' ' << y.second << endl;
		cout << que.size() << endl << endl;
		que.pop();
	}
	
	return 0;
}*/

// B3616 【模板】队列
/*#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int que[N];
int h, t;

int size()
{
	return (t - h);
}

void push(int val)
{
	que[++t] = val;
}

void pop()
{
	if(size())
		h++;
	else
		cout << "ERR_CANNOT_POP" << endl;
}

void front()
{
	if(size())
		cout << que[h + 1] << endl;
	else
		cout << "ERR_CANNOT_QUERY" << endl;
}

int main(void)
{
	int n, x;
	cin >> n;
	
	while(n--)
	{
		cin >> x;
		switch(x)
		{
			case 1 :
				{
					cin >> x;
					push(x); break;
				}
			case 2 : pop(); break;
			case 3 : front(); break;
			case 4 : cout << size() << endl; break;
			default: break;
		}
	}
}*/

// P1540 [NOIP2010 提高组] 机器翻译
/*#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	queue<int> memory;
	int tmp, count = 0, flag = 1;
	while(n--)
	{
		vector<int> temp;
		queue<int> memo;
		while(!memory.empty())
		{
			temp.push_back(memory.front());
			memory.pop();
		}
		for(auto e : temp)
		{
			memo.push(e);
		}
		//
		cin >> tmp;
		for(auto e : temp)
		{
			if(e == tmp)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			count++;
			memo.push(tmp);
			if(memo.size() > m)
				memo.pop();
		}
		flag = 1;
		//
		temp.clear();
		while(!memo.empty())
		{
			temp.push_back(memo.front());
			memo.pop();
		}
		for(auto e : temp)
		{
			memory.push(e);
		}
	}
	cout << count << endl;
	
	return 0;
}*/

// P2058 [NOIP2016 普及组] 海港
/*#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
const int N = 3e5 + 10;
queue<PII> q;// <时间,国家>
int cnt[N];// 每个国家人数
int kinds;// 国家种类

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	int t, k, x;
	while(n--)
	{
		cin >> t >> k;
		while(k--)
		{
			cin >> x;
			q.push({t,x});
			if(1 == ++cnt[x])
				kinds++;
		}
		
		while(q.size() && q.back().first - q.front().first >= 86400)
		{
			PII tmp = q.front();
			q.pop();
			if(0 == --cnt[tmp.second])
				kinds--;
		}
		cout << kinds << endl;
	}
	return 0;
}*/


// STL中的双端队列 deque
/*#include <iostream>
#include <deque>

using namespace std;

typedef pair<int,int> PII;

int main(void)
{
	deque<PII> nums;
	
	for(int i = 1; i <= 5; i++)
	{
		nums.push_front({i, 2*i});
	}
	while(nums.size())
	{
		PII tmp = nums.front();
		nums.pop_front();
		cout << tmp.first << ' ' << tmp.second << endl;
	}
	//
	for(int i = 1; i <= 5; i++)
	{
		nums.push_back({i, 2*i});
	}
	while(!nums.empty())
	{
		PII tmp = nums.back();
		nums.pop_back();
		cout << tmp.first << ' ' << tmp.second << endl;
	}
	//
	for(int i = 100; i <= 500; i+=100)
	{
		nums.push_back({i, 2*i});
	}
	cout << nums.size() << endl;
	nums.clear();
	cout << nums.size() << endl;
	
	return 0;
}*/
