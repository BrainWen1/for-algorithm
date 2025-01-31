// NC226337.【模板】二维差分
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e3 + 10;
int n, m, q;
LL f[N][N];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x; cin >> x;
			f[i][j] += x;
			f[i][j + 1] -= x;
			f[i + 1][j] -= x;
			f[i + 1][j + 1] += x;
		}
	
	while(q--)
	{
		int x1, y1, x2, y2, val;
		cin >> x1 >> y1 >> x2 >> y2 >> val;
		f[x1][y1] += val;
		f[x1][y2 + 1] -= val;
		f[x2 + 1][y1] -= val;
		f[x2 + 1][y2 + 1] += val;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

// P3397 地毯
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n, m;
int f[N][N];

int main(void)
{
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		f[x1][y1]++;
		f[x1][y2 + 1]--;
		f[x2 + 1][y1]--;
		f[x2 + 1][y2 + 1]++;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}*/
