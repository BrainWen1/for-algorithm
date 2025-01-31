// P1012 [NOIP1998 提高组] 拼数
#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

const int N = 20 + 10;
int n;
string nums[N];

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];

	sort(nums, nums + n, [](string l, string r)->bool{
		if(l.size() == r.size()) return l > r;
		else if(l.size() > r.size())
		{
			if(l.substr(0, r.size()) == r) return l[r.size()] > r[0];
			else return l > r;
		}
		else
		{
			if(r.substr(0, l.size()) == l) return l[0] > r[l.size()];
			else return l > r;
		}
	});    
    
    string ret;
    for(int i = 0; i < n; i++) ret += nums[i];
    cout << ret << endl;
    
    return 0;
}

// P2878 [USACO07JAN] Protecting the Flowers S
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
struct node
{
	int t;
	int d;
}a[N];
int n;

int main(void)
{
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].t >> a[i].d;
		sum += a[i].d;
	}
	
	sort(a, a + n, [](node& l, node& r)->bool{
		return l.t * r.d < r.t * l.d;
	});
	
	long long ret = 0;
	for(int i = 0; i < n; i++)
	{
		sum -= a[i].d;
		ret += 2 * a[i].t * sum;
	}
	cout << ret << endl;
	
	return 0;
}

// P1842 [USACO05NOV] 奶牛玩杂技
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;
struct node
{
	int w;
	int s;
}a[N];
int n;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i].w >> a[i].s;
	
	sort(a, a + n, [](node& l, node& r)->bool{
		return max(-l.s, l.w - r.s) < max(-r.s, r.w - l.s);
	});
	
	long long ret = -1e10, W = 0;
	for(int i = 0; i < n; i++)
	{
		ret = max(ret, W - a[i].s);
		W += a[i].w;
	}
	cout << ret << endl;
	
	return 0;
}
