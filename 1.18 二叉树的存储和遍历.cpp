// 二叉树
// 二叉树的存储
// 顺序存储 -> 搜索和遍历时需用到二叉树的父子编号性质:
// i的左孩子:2 * i,右孩子:2 * i + 1,父亲:i / 2(整数除法)
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n;
int tree[N];

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		tree[i] = i;
	}
	return 0;
}*/

// 链式存储
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n;
int left[N], right[N];

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> left[i] >> right[i];
	}
	return 0;
}*/


// 二叉树的遍历
// 使用链式存储搜索遍历时更直观
// 深度优先搜索 DFS
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n;
int l[N], r[N];

void Dfs_front(int root)//先序遍历
{
	cout << root << ' ';
	if(l[root]) Dfs_front(l[root]);
	if(r[root]) Dfs_front(r[root]);
}

void Dfs_middle(int root)//中序遍历
{
	if(l[root]) Dfs_middle(l[root]);
	cout << root << ' ';
	if(r[root]) Dfs_middle(r[root]);
}

void Dfs_back(int root)//后序遍历
{
	if(l[root]) Dfs_back(l[root]);
	if(r[root]) Dfs_back(r[root]);
	cout << root << ' ';
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	
	Dfs_front(1);//先
	cout << endl;
	
	Dfs_middle(1);//中
	cout << endl;
	
	Dfs_back(1);//后
	cout << endl;
	
	return 0;
}*/

// 广度优先搜索 BFS
/*#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 10;
int n;
int l[N], r[N];

void Bfs(int root)
{
	queue<int> que;
	que.push(root);
	
	while(que.size())
	{
		int tmp = que.front();
		que.pop();
		cout << tmp << ' ';
		
		if(l[tmp]) que.push(l[tmp]);
		if(r[tmp]) que.push(r[tmp]);
	}
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	
	Bfs(1);
	
	return 0;
}*/
