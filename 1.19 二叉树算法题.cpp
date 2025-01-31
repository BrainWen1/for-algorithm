// B3642 二叉树的遍历
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int l[N], r[N];

void Dfs_1(int root)
{
	cout << root << ' ';
	if(l[root]) Dfs_1(l[root]);
	if(r[root]) Dfs_1(r[root]);
}

void Dfs_2(int root)
{
	if(l[root]) Dfs_2(l[root]);
	cout << root << ' ';
	if(r[root]) Dfs_2(r[root]);
}

void Dfs_3(int root)
{
	if(l[root]) Dfs_3(l[root]);
	if(r[root]) Dfs_3(r[root]);
	cout << root << ' ';
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	
	Dfs_1(1);
	cout << endl;
	
	Dfs_2(1);
	cout << endl;
	
	Dfs_3(1);
	cout << endl;
	
	return 0;
}

// P4913 【深基16.例3】二叉树深度
/*#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n;
int l[N], r[N];

int Deepth(int root)
{
	if(!root)
		return 0;
	return max(Deepth(l[root]), Deepth(r[root])) + 1;
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	
	cout << Deepth(1) << endl;
	
	return 0;
}*/

// P1030 [NOIP2001 普及组] 求先序排列
/*#include <iostream>
#include <string>

using namespace std;

string a, b;

void Dfs(int l1, int r1, int l2, int r2)
{
	if(l1 > r1)
		return;
	
	char root = b[r2];
	cout << root;//根
	
	int i = 0;
	for(i = l1; i <= r1; i++)
	{
		if(a[i] == root)
			break;
	}
	
	Dfs(l1, i - 1, l2, l2 + i - l1 - 1);//左
	Dfs(i + 1, r1, l2 + i - l1, r2 - 1);//右
}

int main(void)
{
	cin >> a >> b;
	
	Dfs(0, a.size() - 1, 0, b.size() - 1);
	cout << endl;
	
	return 0;
}*/

// P1827 [USACO3.4] 美国血统 American Heritage
/*#include <iostream>
#include <string>

using namespace std;

string a, b;

void Dfs(int l1, int r1, int l2, int r2)
{
	//递归出口
	if(l1 > r1)
		return;
	
	char root = b[l2];
	int i = l1;
	for(i = l1; i <= r1; i++)
	{
		if(a[i] == root)
			break;
	}
	
	Dfs(l1, i - 1, l2 + 1, l2 + i - l1);//左
	Dfs(i + 1, r1, l2 + i - l1 + 1, r2);//右
	cout << root;//根
}

int main(void)
{
	cin >> a >> b;
	
	Dfs(0, a.size(), 0, b.size());
	cout << endl;
	
	return 0;
}*/

// P3884 [JLOI2009] 二叉树问题
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100 + 10;
int n;
vector<int> tree[N];
int fa[N], dist[N];

int Deepth(int root)
{
	int ret = 0;
	for(auto e : tree[root])
	{
		ret = max(ret, Deepth(e));
	}
	return ret + 1;
}

int Breadth(int root)
{
	queue<int> que;
	que.push(1);
	int sz = 0;
	int ret = 0;
	
	while(que.size())
	{
		sz = que.size();
		ret = max(ret, sz);
		
		while(sz--)
		{
			int tmp = que.front();
			que.pop();
			for(auto e : tree[tmp])
			{
				que.push(e);
			}
		}
	}
	return ret;
}

int Distance(int x, int y)
{
	while(x != 1)
	{
		dist[fa[x]] = dist[x] + 1;
		x = fa[x];
	}
	int len = 0;
	while(y != 1 && dist[y] == 0)
	{
		len++;
		y = fa[y];
	}
	return dist[y] * 2 + len;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	int u, v;
	for(int i = 1; i < n; i++)
	{
		cin >> u >> v;
		tree[u].push_back(v);
		fa[v] = u;
	}
	
	cin >> u >> v;
	
	cout << Deepth(1) << endl;
	
	cout << Breadth(1) << endl;
	
	cout << Distance(u, v) << endl;
	
	return 0;
}*/
