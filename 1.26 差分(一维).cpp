// NC226303.【模板】差分
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
LL sum[N];

int main(void)
{
	cin >> n >> m;
	int x;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		sum[i] += x;
		sum[i + 1] -= x;
	}
	
	int l, r, k;
	while(m--)
	{
		cin >> l >> r >> k;
		sum[l] += k;
		sum[r + 1] -= k;
	}
	
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i] + sum[i - 1];
		cout << sum[i] << ' ';
	}
	cout << endl;
	
	return 0;
}

// P3406 海底高铁
/*#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
LL d_val[N];

int main(void)
{
	cin >> n >> m;
	int l, r;
	cin >> l;
	for(int i = 1; i < m; i++)
	{
		cin >> r;
		if(l < r)
		{
			d_val[l]++;
			d_val[r]--;
		}
		else
		{
			d_val[l]--;
			d_val[r]++;
		}
		l = r;
	}
	
	for(int i = 1; i < n; i++)
	{
		d_val[i] = d_val[i] + d_val[i - 1];
	}
	
	int a, b, c;
	LL ret = 0;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		LL k = d_val[i];
		ret += min(a * k, b * k + c);
	}
	
	cout << ret << endl;
	
	return 0;
}*/
