// 树
// 孩子表示法
// vector数组实现
/*#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3 + 10;
vector<int> edges[N];
int n;

int main(void)
{
	cin >> n;
	
	int a, b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	return 0;
}*/

// 链表前向星实现
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int h[N];
int nums[2 * N];
int nex[2 * N];
int id, n;

void add(int a, int b)
{
	id++;
	nums[id] = b;
	nex[id] = h[a];
	h[a] = id;
}

int main(void)
{
	cin >> n;
	
	int a, b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	return 0;
}*/


// 深度优先搜索 DFS遍历树
// 遍历vector数组实现的树
/*#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3 + 10;
vector<int> edges[N];
int n;
bool st[N];

void Dfs(int root)
{
	cout << root << ' ';
	st[root] = true;
	
	for(auto e : edges[root])
	{
		if(false == st[e])
		{
			Dfs(e);
		}
	}
}

int main(void)
{
	cin >> n;

	int a, b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	Dfs(1);

	return 0;
}*/

// 遍历链表前向星实现的树
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n;
int h[N], id;
int nums[2 * N], nex[2 * N];
bool st[N];

void add(int parent, int kid)
{
	id++;
	nums[id] = kid;
	nex[id] = h[parent];
	h[parent] = id;
}

void Dfs(int root)
{
	cout << root << ' ';
	st[root] = true;
	
	for(int i = h[root]; i > 0 ; i = nex[i])
	{
		if(false == st[nums[i]])
		{
			Dfs(nums[i]);
		}
	}
}

int main(void)
{
	cin >> n;
	
	int a, b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	Dfs(1);
	
	return 0;
}*/


// 广度优先搜索 BFS遍历树
// 遍历vector数组实现的树
/*#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 10;
int n;
vector<int> tree[N];
bool st[N];

void Bfs(int root)
{
	queue<int> que;
	que.push(root);
	
	while(que.size())
	{
		int tmp = que.front();
		que.pop();
		cout << tmp << ' ';
		st[tmp] = true;
		
		for(auto e : tree[tmp])
		{
			if(false == st[e])
			{
				que.push(e);
			}
		}
	}
}

int main(void)
{
	cin >> n;
	
	int a, b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	Bfs(1);
	
	return 0;
}*/

// 遍历链表向前星实现的树
/*#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 10;
int id, n;
int h[N];
int nums[2 * N], nex[2 * N];
bool st[N];

void add(int parent, int kid)
{
	id++;
	nums[id] = kid;
	nex[id] = h[parent];
	h[parent] = id;
}

void Bfs(int root)
{
	queue<int> que;
	que.push(root);
	
	while(que.size())
	{
		int tmp = que.front();
		que.pop();
		cout << tmp << ' ';
		st[tmp] = true;
		
		for(int i = h[tmp]; i > 0; i = nex[i])
		{
			if(false == st[nums[i]])
			{
				que.push(nums[i]);
			}
		}
	}
}

int main(void)
{
	cin >> n;
	
	int a, b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	Bfs(1);
	
	return 1;
}*/


































































