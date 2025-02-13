//P1571 眼红的Medusa 二分查找
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, m;
long long a[N];
long long b[N];

bool binarysearch(int left, int right, int val)
{
    while(left < right) {
        int mid = (left + right) / 2;
        if(b[mid] >= val) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return b[left] == val;
}

int main(void)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(b + 1, b + 1 + m);

    for(int i = 1; i <= n; i++) {
        if(binarysearch(1, m, a[i])) cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}

//哈希表解法
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

int main(void)
{
    cin >> n >> m;

    //哈希表<编号, 获b奖>
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        int index = 0;
        cin >> index;
        mp[index]++;
    }
    
    //查询所有获a奖者的编号是否在获b奖名单中
    for(int i = 0; i < n; i++) {
        if(mp[a[i]]) cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}

//P1918 保龄球 二分查找
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, q;
struct node {
    int val;
    int index;
}a[N];

int binarysearch(int left, int right, int x)
{
    while(left < right) {
        int mid = (left + right) / 2;
        if(a[mid].val >= x) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return a[left].val == x ? a[left].index : 0;
}

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].index = i;
    }

    sort(a + 1, a + 1 + n, [](node& l, node& r)->bool {
        return l.val < r.val;
    });

    cin >> q;
    int x;
    while(q--) {
        cin >> x;
        cout << binarysearch(1, n, x) << endl;
    }

    return 0;
}

//P2249 【深基13.例1】查找 二分查找
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, m, x;
struct node
{
    int val;
    int index;
}a[N];

int binarysearch(int x)
{
    int left = 1, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if(a[mid].val >= x) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return a[left].val == x ? a[left].index : -1;
}

int main(void)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].index = i;
    }

    while(m--) {
        cin >> x;
        cout << binarysearch(x) << ' ';
    }
    cout << endl;

    return 0;
}

//P1182 数列分段 Section II 二分答案
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

int main(void)
{
    cin >> n >> m;

    //答案的最大值right为所有元素和，最小值left为单个最大元素
    int left = 0, right = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        right += a[i];
        left = max(left, a[i]);
    }

    //二分答案
    while(left < right) {
        int mid = left + (right - left) / 2;//防溢出

        //划分区间
        int cnt = 1;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            //当前区间超出枚举的答案mid,需另开一个区间存放a[i]
            if(sum + a[i] > mid) {
                cnt++;
                sum = a[i];
            }
            //当前区间能够存放a[i]
            else {
                sum += a[i];
            }
        }

        //段数过多,最大值过小,需缩小较小区间
        if(cnt > m) {
            left = mid + 1;
        }
        //段数过少,最大值过大,需需缩小较大区间
        else {
            right = mid;
        }
    }
    cout << left << endl;

    return 0;
}

//P11388 [COCI 2024/2025 #1] 飞跃 / Skokovi 模拟
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n, k;
int a[N];

int main(void)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //维护两个变量,代表当前可到达的花朵的最高和最低处
    int maxi = a[1], mini = a[1];
    for(int i = 1; i <= n; i++) {
        //可到达,输出1并更新最值
        if(mini - k <= a[i] && maxi + k >= a[i]) {
            cout << 1 << ' ';
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }

        //不可到达,输出0,无需更新最值
        else {
            cout << 0 << ' ';
        }
    }

    return 0;
}

//P8647 [蓝桥杯 2017 省 AB] 分巧克力 二分答案
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, k;
pair<int, int> a[N];

int main(void)
{
    cin >> n >> k;

    //最小边长left为1,最大边长right为所有巧克力块的最小边长中的最大值
    int left = 1, right = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        right = max(right, min(a[i].first, a[i].second));
    }

    //二分答案
    while(left < right) {
        int mid = (left + right + 1) / 2;

        //统计当前答案对应的可分割出的数量
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            cnt += (a[i].first / mid) * (a[i].second / mid);
        }

        //数量过多,边长过小,需缩小较小区间
        if(cnt >= k) {
            left = mid;
        }
        //数量过少,边长过大,需缩小较大区间
        else {
            right = mid - 1;
        }
    }
    cout << left << endl;

    return 0;
}