// P1067 [NOIP2009 普及组] 多项式输出
#include <iostream>

using namespace std;

int n, a;

int main(void)
{
	cin >> n;
	
	for(int i = n; i >= 0; i--)
	{
		cin >> a;
		if(0 == n) cout << a;
		else if(n == i)
		{
			if(a == 0) continue;
			else if(a == 1) cout << "x^" << i;
			else if(a == -1) cout << "-x^" << i;
			else cout << a << "x^" << i;
		}
		else if(0 == i)
		{
			if(a == 0) continue;
			else if(a > 0) cout << '+' << a;
			else cout << a;
		}
		else if(1 == i)
		{
			if(a == 0) continue;
			else if(a == 1) cout << "+x";
			else if(a == -1) cout << "-x";
			else if(a > 0) cout << '+' << a << "x";
			else cout << a << "x";
		}
		else
		{
			if(a == 0) continue;
			else if(a == 1) cout << "+x^" << i;
			else if(a == -1) cout << "-x^" << i;
			else if(a > 0) cout << '+' << a << "x^" << i;
			else cout << a << "x^" << i;
		}
	}
	
	return 0;
}

// P5731 【深基5.习6】蛇形方阵
/*#include <iostream>
#include <iomanip>

using namespace std;

const int N = 9 + 10;
int n;
int nums[N][N];//[x][y]

int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1, 0,-1, 0 };
int pos;

int main(void)
{
	cin >> n;
	
	int j = 1;
	int x = 1, y = 1;
	while(j <= n * n)
	{
		nums[x][y] = j++;
		
		int a = x + dx[pos], b = y + dy[pos];
		
		if(a > n || b > n || a < 1 || b < 1 || nums[a][b])
		{
			pos = (pos + 1) % 4;
			a = x + dx[pos];
			b = y + dy[pos];
		}
		x = a;
		y = b;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << setw(3) << setfill(' ') << nums[i][j];
		cout << endl;
	}
	cout << endl;
	
	return 0;
}*/
