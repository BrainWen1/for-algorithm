// P10452 货仓选址
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	int pos = (n + 1) / 2;
	int ret = 0;
	for(int i = 1; i <= n; i++) ret += fabs(a[i] - a[pos]);
	cout << ret << endl;
	
	return 0;
}

// P1115 最大子段和
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;
int a[N];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	LL sum = 0, ret = -1e5;
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		ret = max(ret, sum); 
		
		if(sum <= 0) sum = 0;
	}
	cout << ret << endl;
	
	return 0;
}

// P1094 [NOIP2007 普及组] 纪念品分组
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e4 + 10;
int top, n;
int a[N];

int main(void)
{
	cin >> top >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	int count = 0;
	int left = 1, right = n;
	while(left < right)
	{
		if(a[right] == top || a[left] + a[right] > top)
		{
			count++;
			right--;
		}
		else if(a[left] + a[right] <= top)
		{
			count++;
			left++;
			right--;
		}
	}
	if(left == right) count++;
	
	cout << count << endl;
	
	return 0;
}

// P1056 [NOIP2008 普及组] 排座椅
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int m, n, k, l, d;
struct node
{
	int count;
	int index;
}row[N], col[N];

bool cmp_count(node& l, node& r)
{
	return l.count > r.count;
}

bool cmp_index(node& l, node& r)
{
	return l.index < r.index;
}

int main(void)
{
	cin >> m >> n >> k >> l >> d;
	for(int i = 1; i <= m; i++) row[i].index = i; 
	for(int i = 1; i <= n; i++) col[i].index = i;
	
	while(d--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2) col[min(y1, y2)].count++;
		if(y1 == y2) row[min(x1, x2)].count++;
	}
	
	sort(row + 1, row + m + 1, cmp_count);//k
	sort(col + 1, col + n + 1, cmp_count);//l
	
	sort(row + 1, row + k + 1, cmp_index);
	sort(col + 1, col + l + 1, cmp_index);
	
	for(int i = 1; i <= k; i++) cout << row[i].index << ' '; cout << endl;
	for(int i = 1; i <= l; i++) cout << col[i].index << ' '; cout << endl;
	
	return 0;
}

// NC200190.矩阵消除游戏
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 15 + 10;
int n, m, k;
int a[N][N];
int col[N];

bool cmp(int l, int r)
{
	return l > r;
}

int compute(int val)
{
	int count = 0;
	while(val)
	{
		count++;
		val &= val - 1;
	}
	return count;
}

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin >> a[i][j];//输入权值 
	
	int ret = 0;
	for(int st = 0; st < (1 << n); st++)
	{
		memset(col, 0, sizeof(col));//col数组重新置0
		int num = compute(st);//计算当前枚举的st中的1的个数，即选中的行数 
		if(num > k) continue;//边界情况 处理 
		
		int sum = 0;//sum重新置0 
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if((st >> (i - 1)) & 1) sum += a[i][j];//计算行数得到的和 
				else col[j] += a[i][j];//不计算已选中的行，避免重复计算 
			}
		}
		sort(col + 1, col + m + 1, cmp);//降序排列，方便查找和最大的几列 
		for(int i = 1; i <= k - num; i++)
		{
			sum += col[i];//加和最大的(k - num)列
		}
		ret = max(ret, sum);//更新最大值 
	}
	
	cout << ret << endl;
	
	return 0;
}
