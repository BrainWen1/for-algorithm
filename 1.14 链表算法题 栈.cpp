// B3630 排队顺序
/*#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int peo[N], nex[N];
int h, id;

void push_back(int val, int pos)
{
	id++;
	peo[id] = val;

	nex[id] = pos;
}

int main(void)
{
	int k = 0, n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		push_back(i, k);
	}
	
	int h;
	cin >> h;
	for(int i = 0; i < n; i++)
	{
		if(peo[i] == h)
		{
			h = i;
			break;
		}
	}

	for(int i = h; i > 0; i = nex[i])
		printf("%d ", peo[i]);
	cout << endl;

	return 0;
}*/

// B3631 单向链表
/*#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int nums[N], nex[N];
int map[N];
int h, id;

int find(int val)
{
	return map[val];
}

void insert(int val, int num)
{
	int pos = find(num);
	if(pos <= 0)
		return;
	id++;
	nums[id] = val;
	map[val] = id;
	
	nex[id] = nex[pos];
	nex[pos] = id;
}

void erase(int num)
{
	int pos = find(num);
	if(0 == pos || 0 == nex[pos])
		return;
	map[nums[nex[pos]]] = 0;
	nex[pos] = nex[nex[pos]];
}

int main(void)
{
	nums[1] = 1;
	nex[h] = 1;
	map[1] = 1;
	id = 1;
	int n;
	cin >> n;

	int k, x, y;
	while(n--)
	{
		cin >> k >> x;
		if(1 == k)
		{
			cin >> y;
			insert(y, x);
		}
		else if(2 == k)
		{
			if(0 == nex[map[x]])
				cout << 0 << endl;
			else
			{
				cout << nums[nex[map[x]]] << endl;
			}
		}
		else if(3 == k)
		{
			erase(x);
		}
	}
	return 0;
}*/

// P1160 队列安排
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int nums[N], pre[N], nex[N];
int map[N];
int h, id;

int find(int val)
{
	return map[val];
}

void insert(int val, int num, int p)
{
	id++;
	nums[id] = val;
	map[val] = id;
	int pos = find(num);
	if(p)
	{
		pre[id] = pos;
		nex[id] = nex[pos];
		pre[nex[pos]] = id;
		nex[pos] = id;
	}
	else
	{
		pre[id] = pre[pos];
		nex[id] = pos;
		nex[pre[pos]] = id;
		pre[pos] = id;
	}
}

void erase(int val)
{
	int pos = find(val);
	if(0 == pos)
		return;
	map[val] = 0;
	pre[nex[pos]] = pre[pos];
	nex[pre[pos]] = nex[pos];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	nums[1] = 1;
	map[1] = 1;
	id = 1;
	nex[h] = 1;
	int n;
	cin >> n;
	
	int k, p;
	for(int i = 2; i <= n; i++)
	{
		cin >> k >> p;
		insert(i, k, p);
	}
	
	int m, x;
	cin >> m;
	while(m--)
	{
		cin >> x;
		erase(x);
	}
	
	for(int i = nex[h]; i > 0; i = nex[i])
	{
		cout << nums[i] << ' ';
	}
	cout << endl;
	
	return 0;
}*/

// P1996 约瑟夫问题
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int nums[N], nex[N];
int map[N];
int h, id;

int main(void)
{
	
	
	return 0;
}
