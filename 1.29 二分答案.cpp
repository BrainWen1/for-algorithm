// P2440 木材加工
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, k;
int a[N];

int main(void)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int left = 0, right = 1e8;
    while(left < right)
    {
        LL mid = (left + right + 1) / 2;
        int x = 0;
        for(int i = 1; i <= n; i++) x += a[i] / mid;
        if(x >= k) left = mid;
        else right = mid - 1;
    }
    cout << left << endl;

    return 0;
}

// P1873 [COCI 2011/2012 #5] EKO / 砍树
/*#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int n, m;
int a[N];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	LL left = 0, right = 2e9;
	while(left < right)
	{
		LL mid = (left + right + 1) / 2;
		LL len = 0;
		for(auto e : a)
		{
			if(e <= mid);
			else len += e - mid;
		}
		if(len >= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	
	return 0;
}*/

// P2678 [NOIP2015 提高组] 跳石头
/*#include <iostream>

using namespace std;

const int N = 5e4 + 10;
int L, n, m;
int a[N];

int main(void)
{
	cin >> L >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = L;
	
	int left = 1, right = L;
	while(left < right)
	{
		long long mid = (left + right + 1) / 2;
		int count = 0;
		for(int i = 0; i <= n; i++)
		{
			int j = i + 1;
			while(j <= n + 1 && a[j] - a[i] < mid) j++;
			count += j - i - 1;
			i = j - 1;
		}
		if(count <= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	
	return 0;
}*/
