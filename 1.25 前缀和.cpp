// NC226282��ģ�塿ǰ׺��
/*#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n, q, l, r;
int a[N];
LL sum[N];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];//һά�㷨
	}
	
	while(q--)
	{
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << endl;//һά�㷨
	}
	
	return 0;
}*/

// P1115 ����Ӷκ�
/*#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, x;
long long sum[N];

int main(void)
{
	cin >> n;
	long long ret = -1e20, prevmin = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		sum[i] = sum[i - 1] + x;
		ret = max(ret, sum[i] - prevmin);
		prevmin = min(prevmin, sum[i]);
	}
	
	cout << ret << endl;
	
	return 0;
}*/

// NC226333��ģ�塿��άǰ׺��
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n, m, q;
long long sum[N][N];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> q;

	int tmp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> tmp;
			sum[i][j] = sum[i][j - 1] + tmp;//ͬһά
		}

	int x1, y1, x2, y2;
	while (q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		long long ans = 0;
		for (int i = x1; i <= x2; i++)
			ans += sum[i][y2] - sum[i][y1 - 1];//һάѭ���Ӻ�ģ���ά
		cout << ans << endl;
	}

	return 0;
}*/
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n, m, q;
long long sum[N][N];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> q;

	int tmp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> tmp;
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tmp;//��ά�㷨
		}

	int x1, y1, x2, y2;
	while (q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;//��ά�㷨
	}

	return 0;
}*/

// P2280 [HNOI2003] ����ը��
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e3 + 10;
int n, m, x, y, val;
int a[N][N];
int sum[N][N];

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y >> val;
		x++; y++;
		a[x][y] += val;
	}

	n = 5001;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

	int ret = 0;
	m = min(m, n);
	for (int x2 = m; x2 <= n; x2++)
		for (int y2 = m; y2 <= n; y2++)
		{
			int x1 = x2 - m + 1;
			int y1 = y2 - m + 1;
			ret = max(ret, sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
		}
	cout << ret << endl;

	return 0;
}
