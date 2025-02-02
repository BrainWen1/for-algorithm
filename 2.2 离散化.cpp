// 离散化模板一：排序 + 去重 + 二分查找
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int n;
int a[N];//存放原始数据 

int pos;//记录离散化后元素个数 
int disc[N];//存放离散化后数据 

int find(int val)
{
	int left = 1, right = pos;//二分查找 
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(disc[mid] >= val) right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];//拷贝 
	}
	cout << endl;
	
	sort(disc + 1, disc + 1 + n);//排序 
	
	pos = unique(disc + 1, disc + 1 + n) - (disc + 1);//unique对排序后数组去重 
	
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << ": " << find(a[i]) << endl;
	}
	
	return 0;
}*/

// 离散化模板二：排序 + 哈希表实现去重和查找 
/*#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

const int N = 1e3 + 10;
int n;
int a[N];//存放原始数据 
int disc[N];//存放排序后数据 

unordered_map<int, int> mp;//<原始数据, 离散化数据>

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[i] = a[i];//拷贝 
	}
	cout << endl;
	
	sort(disc + 1, disc + 1 + n);//排序 
	int index = 0;//标记元素 
	for(int i = 1; i <= n; i++)
	{
		int val = disc[i];
		if(mp[val]) continue;//去重 
		index++;
		mp[val] = index;//离散化 
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << ": " << mp[a[i]] << endl;
	}
	
	return 0;
}

// P1496 火烧赤壁
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10;
int n, pos;
int a[N], b[N];//区间左右端点 
int f[2 * N];//差分数组 
int disc[2 * N];//离散化数组 
unordered_map<int, int> mp;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}
	
	sort(disc + 1, disc + 1 + pos);//排序 
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);//去重 
	
	for(int i = 1; i <= pos; i++)//离散化 
	{
		mp[disc[i]] = i; 
	}
	
	for(int i = 1; i <= n; i++)//差分 
	{
		int left = mp[a[i]], right = mp[b[i]];
		f[left]++;
		f[right]--;
	}
	
	for(int i = 1; i <= pos; i++)//还原数组 
	{
		f[i] = f[i] + f[i - 1];
	}
	
	int ret = 0;
	for(int i = 1; i <= pos; i++)
	{
		int j = i;
		for(; j <= pos; j++)
		{
			if(f[j] == 0) break; 
		}
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;
	
	return 0;
}

// P3740 [HAOI2014] 贴海报
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e3 + 10;
int n, m, pos;
int a[N], b[N];
int disc[4 * N];
unordered_map<int, int> mp;

int wall[4 * N];
bool is_counted[N];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; disc[++pos] = a[i] + 1;
		disc[++pos] = b[i]; disc[++pos] = b[i] + 1;
	}
	
	sort(disc + 1, disc + 1 + pos);//排序 
	
	int index = 0;//标记离散化后有多少元素 
	for(int i = 1; i <= pos; i++)//离散化 
	{
		if(mp[disc[i]]) continue;//去重 
		index++;
		mp[disc[i]] = index;
	}
	
	//模拟贴海报
	for(int i = 1; i <= m; i++)
	{
		int left = mp[a[i]], right = mp[b[i]];//获取离散化后的范围
		for(int r = left; r <= right; r++)
		{
			wall[r] = i;//覆盖 
		}
	}
	
	//统计结果
	int ret = 0;
	for(int i = 1; i <= index; i++)
	{
		if(wall[i] == 0 || is_counted[wall[i]]) continue;
		is_counted[wall[i]] = true;//标记为已存在的数，避免重复计算 
		ret++;
	}
	cout << ret << endl;
	
	return 0;
}
