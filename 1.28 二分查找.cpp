// 34.在排序数组中查找元素的第一个和最后一个位置
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int len;
	vector<int> nums;
	int target;
	cin >> len;
	for(int i = 1; i <= len; i++)
	{
		int x; cin >> x;
		nums.push_back(x);
	}
	cin >> target;

    if(0 == len)//无元素情况处理 
    {
    	cout << "[-1, -1]" << endl;
    	return 0;
	}

    int left = 0, right = len - 1;
    //左端点
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] < target) left = mid + 1;
        else right = mid;
	}
    if(nums[left] != target)//判断是否存在该元素 
    {
    	cout << "[-1, -1]" << endl;
    	return 0;
	}
    int l = left;
    //右端点
    left = 0, right = len - 1;
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(nums[mid] <= target) left = mid;
        else right = mid - 1;
    }
    cout << '[' << l << ", " << right << ']' << endl;
	
	return 0;
}

// NC235558.牛可乐和魔法封印 
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, q;
int a[N];

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        
        //左端点
        int left = 1, right =  n;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(a[mid] < x) left = mid + 1;
            else right = mid;
        }
        if(a[left] < x)
        {
        	cout << 0 << endl;
        	continue;
		}
        int l = left;
        //右端点
        left = 1, right = n;
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(a[mid] <= y) left = mid;
            else right = mid - 1;
        }
        if(a[left] > y)
        {
        	cout << 0 << endl;
        	continue;
		}
        int r = left;
        cout << r - l + 1 << endl;
    }
    return 0;
}*/

// P1102 A-B 数对
/*#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n, C;
int a[N];

int main(void)
{
	cin >> n >> C;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	int ret = 0;
	for(int i = 2; i <= n; i++)
	{
		int A = a[i];
		int B = A - C;
		
		auto l = lower_bound(a + 1, a + i, B);
		auto r = upper_bound(a + 1, a + i, B);
		ret += r - l;
	}
	cout << ret << endl;
	
	return 0;
}*/

// P1678 烦恼的高考志愿
/*#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int m, n;
LL a[N];

int main(void)
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + m);
	
	LL ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		auto pos = lower_bound(a + 1, a + 1 + m, x);
		if(*pos == x);
		else if(*pos != a[1]) ret += min(abs(*pos - x), abs(*(pos - 1) - x));
		else ret += abs(*pos - x);
	}
	cout << ret << endl;
	
	return 0;
}*/
/*#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int m, n;
LL a[N];

int find(int val)
{
	int left = 1, right = m;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(a[mid] >= val) right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(void)
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + m);
	a[0] = -1e7;
	
	LL ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		int pos = find(x);
		ret += min(abs(a[pos] - x), abs(a[pos - 1] - x));
	}
	cout << ret << endl;
	
	return 0;
}*/
