// ������
// �������Ĵ洢
// ˳��洢 -> �����ͱ���ʱ���õ��������ĸ��ӱ������:
// i������:2 * i,�Һ���:2 * i + 1,����:i / 2(��������)
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

// ��ʽ�洢
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


// �������ı���
// ʹ����ʽ�洢��������ʱ��ֱ��
// ����������� DFS
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n;
int l[N], r[N];

void Dfs_front(int root)//�������
{
	cout << root << ' ';
	if(l[root]) Dfs_front(l[root]);
	if(r[root]) Dfs_front(r[root]);
}

void Dfs_middle(int root)//�������
{
	if(l[root]) Dfs_middle(l[root]);
	cout << root << ' ';
	if(r[root]) Dfs_middle(r[root]);
}

void Dfs_back(int root)//�������
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
	
	Dfs_front(1);//��
	cout << endl;
	
	Dfs_middle(1);//��
	cout << endl;
	
	Dfs_back(1);//��
	cout << endl;
	
	return 0;
}*/

// ����������� BFS
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
