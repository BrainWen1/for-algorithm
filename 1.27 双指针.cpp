// 唯一的雪花 Unique Snowflakes
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 10;
int n;
int a[N];

int main(void)
{
	int T; cin >> T;
	
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		int ret = 0;
		int left = 1, right = 1;
		unordered_map<int, int> mp;//初始化 
		
		for(right = 1; right <= n; right++)
		{
			mp[a[right]]++;//进窗口 
		
			while(mp[a[right]] > 1) mp[a[left++]]--;//判断,出窗口 
			
			ret = max(ret, right - left + 1);//更新结果
		}
		cout << ret << endl;
	}
	
	return 0;
}

// P1638 逛画展
/*#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e3 + 10;
int n, m;
int a[N];

int main(void)
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int left = 1, right = 1;//初始化 
	unordered_map<int, int> mp;
	int l = 1, r = n;
	
	for(right = 1; right <= n; right++)
	{
		mp[a[right]]++;//进窗口 
		
		while(mp.size() == m)//判断 
		{
			if(right - left + 1 < r - l + 1)//更新 
			{
				l = left;
				r = right;
			}
			
			if(mp[a[left]]-- == 1) mp.erase(a[left]);//出窗口 
			left++;
		}
	}
	cout << l << ' ' << r << endl;
	
	return 0;
}*/
/*#include <iostream>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e3 + 10;
int n, m;
int a[N];
int mp[M];
int kind;

int main(void)
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int left = 1, right = 1;//初始化 
	int l = 1, r = n;
	
	for(right = 1; right <= n; right++)
	{
		if(mp[a[right]]++ == 0) kind++;//进窗口 
		
		while(kind == m)//判断 
		{
			if(right - left + 1 < r - l + 1)//更新 
			{
				l = left;
				r = right;
			}
			
			if(mp[a[left]]-- == 1) kind--;//出窗口 
			left++;
		}
	}
	cout << l << ' ' << r << endl;
	
	return 0;
}*/

// NC18386.字符串
/*#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 1e6 + 10;
string s;

int main(void)
{
	cin >> s;
	int n = s.size();
	
	int left = 0, right = 0;//初始化 
	unordered_map<char, int> mp;
	int len = n;

	while(right < n)
	{
		//进窗口
		mp[s[right]]++;
		
		//判断
		while(mp.size() == 26)
		{
			//更新
			if(len > right - left + 1) len = right - left + 1;
			//出窗口
			if(mp[s[left]]-- == 1) mp.erase(s[left]);
			left++;
		}
		right++;
	}
	cout << len << endl;
	
	return 0;
}*/

// NC207040.丢手绢
/*#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
LL a[N];
LL sum;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	int left = 1, right = 1;//初始化 
	LL k = 0, ret = 0;
	
	while(right <= n)
	{
		//进窗口
		k += a[right];
		//判断
		while(2 * k >= sum)
		{
			//更新
			ret = max(ret, sum - k);
			//出窗口
			k -= a[left];
			left++;
		}
		ret = max(ret, k);
		right++;
	}
	cout << ret << endl;
	
	return 0;
}*/
