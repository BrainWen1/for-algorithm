// P1003 [NOIP2011 提高组] 铺地毯
#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n;
int a[N], b[N], lx[N], ly[N];
int x, y;

int search()
{
	for(int i = 0; i < n; i++)
	{
		if(x >= a[i] && x <= a[i] + lx[i] && y >= b[i] && y <= b[i] + ly[i])
			return (n - i);
	}
	return -1;
}

int main(void)
{
	cin >> n;
	
	for(int i = n - 1; i >= 0; i--)
		cin >> a[i] >> b[i] >> lx[i] >> ly[i];
		
	cin >> x >> y;
	
	cout << search() << endl;
	
	return 0;
}

// P2010 [NOIP2016 普及组] 回文日期
/*#include <iostream>//最优解

using namespace std;

int main(void)
{
	int tou, wei;
	cin >> tou >> wei;
					   //1   2   3   4   5   6   7   8   9  10  11  12
	int days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int count = 0;
	for(int i = 1; i <= 12; i++)
		for(int j = 1; j <= days[i]; j++)
		{
			int year = j % 10 * 1000 + j / 10 * 100 + i % 10 * 10 + i / 10;
			int num = year * 10000 + i * 100 + j;
			if(num >= tou && num <= wei) count++;
		}
	cout << count << endl;

	return 0;
}*/
/*#include <iostream>//暴力枚举
#include <string>
#include <algorithm>

using namespace std;

string sta, ed;

bool isrun(int& year)
{
	if(year % 400 == 0) return true;
	else if(year % 4 == 0 && year % 100 != 0) return true;
	else return false;
}

bool isvalid(string& str)
{
	int year = stoi(str.substr(0, 4));
	int month = stoi(str.substr(4, 2));
	int day = stoi(str.substr(6, 2));
	if(month > 12 || day > 31) return false;
	else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
	else if(month == 2 && isrun(year) && day > 29) return false;
	else if(month == 2 && !isrun(year) && day > 28) return false;
	else return true;
}

int main(void)
{
	cin >> sta >> ed;
	
	int num1 = stoi(sta), num2 = stoi(ed);
	
	string str, tmp;
	int count = 0;
	for(int i = num1; i <= num2; i++)
	{
		str = to_string(i);
		tmp = str; reverse(tmp.begin(), tmp.end());
		if(str == tmp)
			if(isvalid(str)) count++;
	}
	cout << count << endl;
	
	return 0;
}*/

// P2327 [SCOI2005] 扫雷
/*#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n;
int sec[N];
int mp[N];

int check(int val)
{
	mp[1] = val;
	for(int i = 2; i <= n + 1; i++)
	{
		mp[i] = sec[i - 1] - mp[i - 1] - mp[i - 2];
		if(mp[i] < 0 || mp[i] > 1) return 0;
	}
	if(mp[n + 1]) return 0;
	return 1;
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> sec[i];
	
	int count = check(1) + check(0);
	
	cout << count << endl;
	
	return 0;
}*/

// 78.子集
/*#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
	int len = nums.size();
	vector<vector<int>> ret;
	for(int i = 0; i < (1 << len); i++)
	{
		vector<int> tmp;
		for(int j = 0; j < len; j++)
			if((i >> j) & 1) tmp.push_back(nums[i]);
		ret.push_back(tmp);
	}
	return ret;
}
int main(void)
{
	vector<vector<int>> nums;
	vector<vector<int>> tmp = subsets(nums);
	for(auto& e : tmp)
	{
		for(auto& q : e) cout << q << ' ';
		cout << endl;
	}
	return 0;
}*/

// P10449 费解的开关
/*#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10, INF = 0x3f3f3f3f;
int n;
int a[N];
int t[N];

int calc(int val)
{
	int cnt = 0;
	while(val)
	{
		val &= val - 1;
		cnt++;
	}
	return cnt;
}

int main(void)
{
	cin >> n;
	
	while(n--)
	{
		memset(a, 0, sizeof(a));//每一次计算结束将数组置0
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				char tmp = 0;
				cin >> tmp;
				if(tmp == '0') a[i] |= (1 << j);//读取，存下初始状态
			}
		}
		
		int ret = INF;
		for(int st = 0; st < (1 << 5); st++)//枚举第一行的所有按法
		{
			memcpy(t, a, sizeof(a));//每一次枚举对数组t操作
			int push = st;
			int count = 0;//计数器
			
			for(int i = 0; i < 5; i++)//遍历五行01234
			{
				t[i] = t[i] ^ push ^ (push << 1) ^ (push >> 1);//推出当前行结果
				t[i] = t[i] & ((1 << 5) - 1);//处理边界情况
				t[i + 1] = t[i + 1] ^ push;//推出下一行被影响结果
				count += calc(push);//计数
				push = t[i];//推出下一行按法
			}
			if(!t[4]) ret = min(ret, count);//判断末行是否合法，记录当前最小值
		}
		if(ret > 6) cout << -1 << endl;
		else cout << ret << endl;
	}
	
	return 0;
}*/

// UVA.Even Parity
#include <bits/stdc++.h>

using namespace std;

const int N = 15 + 10, INF = 0x3f3f3f3f;
int T, n;
int a[N];
int t[N];
typedef pair<bool, int> PBI;

PBI check_count(int val, int pos)
{
	int count = 0;
	int tmp = a[pos];
	for(int i = 0; i < n; i++)
	{
		if(!(tmp & (1 << i)) && (val & (1 << i))) count++;
		else if((tmp & (1 << i)) && !(val & (1 << i))) return {false, -1};
	}
	return {true, count};
}

int main(void)
{
	cin >> T;
	
	for(int p = 1; p <= T; p++)
	{
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < n; j++)
			{
				int tmp;
				cin >> tmp;
				if(tmp) a[i] |= (1 << j);//存入矩阵
			}
		int ret = INF;
		for(int st = 0; st < (1 << n); st++)//枚举第一行的所有情况
		{
			memcpy(t, a, sizeof(a));
			
			int flag = 1;
			PBI ans;
			int count = 0;
			int change = st;
			
			for(int i = 1; i <= n; i++)
			{
				ans = check_count(change, i);//拿到计算结果
				if(false == ans.first)//判断是否合法
				{
					flag = 0;
					break;
				}
				count += ans.second;//计数
				t[i] = change;//更新t[i]
				change = t[i - 1] ^ (t[i] << 1) ^ (t[i] >> 1);//更新change
				change &= (1 << n) - 1;//处理边界问题
			}
			if(flag) ret = min(ret, count);//获取当前最小值
		}
		if(ret == INF) cout << "Case " << p << ": " << -1 << endl;//无解
		else cout << "Case " << p << ": " << ret << endl;//有解
	}
	
	return 0;
}
