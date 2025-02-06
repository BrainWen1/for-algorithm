//分治 
// P1908 逆序对
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;
int n;
int a[N];
int tmp[N];

LL merge_count(int left, int right)
{
	if(left >= right) return 0;
	
	LL ret = 0;
	
	int mid = (left + right) / 2;
	ret += merge_count(left, mid);
	ret += merge_count(mid + 1, right);
	
	int cur1 = left, cur2 = mid + 1, i = left;
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
		else
		{
			ret += mid - cur1 + 1;
			tmp[i++] = a[cur2++];
		}
	}
	while(cur1 <= mid) tmp[i++] = a[cur1++];
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	for(i = left; i <= right; i++)
		a[i] = tmp[i];
	
	return ret;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	cout << merge_count(1, n) << endl;
	
	return 0;
}

// P1923 【深基9.例4】求第 k 小的数
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 5e6 + 10;
int n, k;
int a[N];

int random_number(int left, int right)
{
	return a[rand() % (right - left + 1) + left];
}

int quick_select(int left, int right, int k)
{
	if(left >= right) return a[left];
	
	int pivot = random_number(left, right);
	
	int l = left - 1, i = left, r = right + 1;
	while(i < r)
	{
		if(a[i] < pivot) swap(a[++l], a[i++]);
		else if(a[i] == pivot) i++;
		else swap(a[--r], a[i]);
	}
	
	int num1 = l - left + 1, num2 = r - 1 - l, num3 = right - r + 1;
	if(k <= num1) return quick_select(left, l, k);
	else if(k <= num1 + num2) return pivot;
	else return quick_select(r, right, k - num1 - num2);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	srand(time(0));
	cin >> n >> k;
	k++;
	for(int i = 1; i <= n; i++) cin >> a[i];

	cout << quick_select(1, n, k) << endl;
	
	return 0;
}

// P1115 最大子段和
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n;
int a[N];

int dfs(int left, int right)
{
	if(left >= right) return a[left];
	
	int mid = (left + right) / 2;
	int ret = max(dfs(left, mid), dfs(mid + 1, right));
	
	int sum = a[mid], lmax = a[mid];
	for(int i = mid - 1; i >= left; i--)
	{
		sum += a[i];
		lmax = max(lmax, sum);
	}
	sum = a[mid + 1];
	int rmax = a[mid + 1];
	for(int i = mid + 2; i <= right; i++)
	{
		sum += a[i];
		rmax = max(rmax, sum);
	}
	ret = max(ret, lmax + rmax);
	
	return ret;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	cout << dfs(1, n) << endl;
	
	return 0;
}

// P1228 地毯填补问题
#include <iostream>

using namespace std;

int n;
int x, y;

void dfs(int a, int b, int len, int x, int y)
{
	if(1 == len) return;
	
	len /= 2;
	if(x < a + len && y < b + len)//左上角 
	{
		cout << a + len << ' ' << b + len << ' ' << 1 << endl;
		dfs(a, b, len, x, y);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	else if(x < a + len && y >= b + len)//右上角 
	{
		cout << a + len << ' ' << b + len - 1 << ' ' << 2 << endl;
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, x, y);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	else if(x >= a + len && y < b + len)//左下角 
	{
		cout << a + len - 1 << ' ' << b + len << ' ' << 3 << endl;
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, x, y);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	else if(x >= a + len && y >= b + len)//右下角 
	{
		cout << a + len - 1 << ' ' << b + len - 1 << ' ' << 4 << endl;
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, x, y);
	}
}

int main(void)
{
	cin >> n >> x >> y;
	n = (1 << n);
	
	dfs(1, 1, n, x, y);
	
	return 0;
}
