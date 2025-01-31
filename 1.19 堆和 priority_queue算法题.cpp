// P3378 【模板】堆
/*#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int>> heap;
	int n;
	cin >> n;

	int op = 0;
	while(n--)
	{
		cin >> op;
		if(1 == op)
		{
			int val;
			cin >> val;
			heap.push(val);
		}
		if(2 == op)
			cout << heap.top() << endl;
		if(3 == op)
			heap.pop();
	}
	return 0;
}*/

// NC214362.第k小
/*#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	priority_queue<int> heap;
	int n, m, k;
	cin >> n >> m >> k;

	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		heap.push(tmp);
		if(heap.size() > k) heap.pop();
	}

	int op;
	while(m--)
	{
		cin >> op;
		if(1 == op)
		{
			int val;
			cin >> val;
			heap.push(val);
			if(heap.size() > k) heap.pop();
		}
		if(2 == op)
		{
			if(k > heap.size())
			{
				cout << -1 << endl;
				continue;
			}
			cout << heap.top() << endl;
		}
	}
	return 0;
}*/

// NC213140.除2!
/*#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<int> heap;
	int n, k;
	cin >> n >> k;

	int tmp;
	unsigned long long ret = 0;
	while(n--)
	{
		cin >> tmp;
		ret += tmp;
		if(tmp % 2 == 0) heap.push(tmp);
	}

	while(heap.size() && k--)
	{
		tmp = heap.top();
		heap.pop();
		tmp /= 2;
		ret -= tmp;
		if(tmp % 2 == 0) heap.push(tmp);
	}
	cout << ret << endl;

	return 0;
}*/

// P2085 最小函数值
/*#include <iostream>
#include <queue>

using namespace std;

const int N = 1e4 + 10;
struct func_info
{
	int x;
	int a;
	int b;
	int c;
	int y;
	bool operator<(const func_info& temp)const
	{
		return y > temp.y;
	}
}nums[N];

int main(void)
{
	priority_queue<func_info> heap;
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		cin >> nums[i].a >> nums[i].b >> nums[i].c;
	}

	for(int i = 1; i <= n; i++)
	{
		nums[i].y = nums[i].a * 1 * 1 + nums[i].b * 1 + nums[i].c;
		nums[i].x = 1;
		heap.push(nums[i]);
	}

	func_info tmp, ret;
	for(int i = 1; i <= m; i++)
	{
		tmp = heap.top();
		heap.pop();
		cout << tmp.y << ' ';
		ret.y = tmp.a * (tmp.x + 1) * (tmp.x + 1) + tmp.b * (tmp.x + 1) + tmp.c;
		ret.x = tmp.x + 1;
		ret.a = tmp.a; ret.b = tmp.b; ret.c = tmp.c;
		heap.push(ret);
	}
	cout << endl;

	return 0;
}*/

// P1631 序列合并
/*#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], b[N];

struct node
{
	int sum;
	int x, y;
	bool operator<(const node& temp)const//优先队列 100分
	{
		return sum > temp.sum;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<node> heap;

	cin >> n;

	int tmp;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++)
		cin >> b[i];

	for(int i = 1; i <= n; i++)
	{
		heap.push({a[i] + b[1], i, 1});
	}
	
	for(int i = 0; i < n; i++)
	{
		node tmp = heap.top();
		cout << tmp.sum << ' ';
		heap.pop();
		
		if(tmp.y + 1 <= n) heap.push({a[tmp.x] + b[tmp.y + 1], tmp.x, tmp.y + 1});
	}

	return 0;
}*/

/*#include <iostream>//暴力求解 64分
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n;

int main(void)
{
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}

	vector<long long> ret;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			ret.push_back(a[i] + b[j]);
		}
	}

	sort(ret.begin(), ret.end());

	for(int i = 0; i < n; i++)
	{
		cout << ret[i] << ' ';
	}
	cout << endl;

	return 0;
}*/
