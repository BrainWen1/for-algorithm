//P1886 滑动窗口 /【模板】单调队列
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, k;

vector<int> getmax(vector<int>& nums)
{
    vector<int> ret;
    deque<int> q;

    for(int i = 0; i < n; i++)
    {
        //保持队列单调递减
        while (!q.empty() && nums[q.back()] <= nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);

        //队头元素不在窗口内
        if (q.front() <= i - k)
        {
            q.pop_front();
        }

        //存储当前最大值
        if (i >= k - 1)
        {
            ret.push_back(nums[q.front()]);
        }
    }
    return ret;
}

vector<int> getmin(vector<int>& nums)
{
    vector<int> ret;
    deque<int> q;

    for(int i = 0; i < n; i++)
    {
        //维持单调队列的单调性
        while(!q.empty() && nums[q.back()] >= nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);

        //维持单调队列内元素个数合法
        if(q.front() <= i - k)
        {
            q.pop_front();
        }

        //存储当前最小值
        if(i >= k - 1)
        {
            ret.push_back(nums[q.front()]);
        }
    }
    return ret;
}

int main(void)
{
    cin >> n >> k;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    //分别存放临时最大值和最小值
    vector<int> maxi, mini;

    maxi = getmax(nums);
    mini = getmin(nums);

    for(int e : mini) cout << e << ' ';
    cout << endl;
    for(int e : maxi) cout << e << ' ';
    cout << endl;

    return 0;
}

//P1440 求m区间内的最小值
#include <iostream>
#include <deque>

using namespace std;

const int N = 2e6 + 10;
int n, m;
int nums[N];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << 0 << endl;

    deque<int> q;

    for(int i = 1; i < n; i++)
    {
        //维持窗口单调
        while(!q.empty() && nums[q.back()] >= nums[i - 1])
        {
            q.pop_back();
        }
        q.push_back(i - 1);

        //维持窗口元素个数合法
        if(q.front() < i - m)
        {
            q.pop_front();
        }

        //输出窗口左端元素，即为当前最小值
        cout << nums[q.front()] << endl;
    }

    return 0;
}

//P1147 连续自然数和
#include <iostream>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    //直接滑动窗口扫描一遍范围值
    int left = 1, right = 2;//要求窗口元素个数大于等于2
    long long sum = left + right;
    while(right < n)
    {
        if(sum == n)
        {
            if(right - left + 1 >= 2)//元素个数合法检查
            {
                cout << left << ' ' << right << endl;
                
                //right右移
                right++;
                sum += right;
            }
            else
            {
                //right右移
                right++;
                sum += right;
            }
        }
        else if(sum > n)//新增右端元素过大
        {
            //left右移
            sum -= left;
            left++;
        }
        else if(sum < n)//不足
        {
            //right右移
            right++;
            sum += right;
        }
    }

    return 0;
}

//B4006 [GESP202406 四级] 宝箱
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int n, k;
int a[N], pre[N];

int main(void)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);//排序

    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];//前缀和处理，便于后续求区间总和
    }

    //双指针遍历数组
    int left = 1, right = 1;
    int maxi = a[left];
    while(right <= n) {
        if(a[right] - a[left] <= k)//合法，更新最大值并继续right右移
        {
            maxi = max(maxi, pre[right] - pre[left - 1]);
            right++;
        }
        else//不合法，left右移
        {
            left++;
        }
    }
    cout << maxi << endl;

    return 0;
}

//B3691 [语言月赛202212] 狠狠地切割(Easy Version)
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int INF = 1e9;
const int N = 5e5 + 10;
int n, m;
int a[N];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    //哈希表存储便于后续查找
    unordered_set<int> mp;
    for(int i = 1; i <= n; i++)
    {
        int val; cin >> val;
        mp.insert(val);
    }

    //遍历a数组，将断点设为大数INF
    int cur = 1;
    while(cur <= n) {
        if(mp.count(a[cur])) {
            a[cur] = INF;
        }
        cur++;
    }

    //双指针遍历a数组
    int left = 1, right = 1, count = 0;
    while(right <= n) {
        if(a[right] == INF) {
            if(right - left + 1 > 1) {
                count++;
                left = right + 1;
                right = left;
            }
            else {
                left++;
                right++;
            }
        } 
        else {
            right++;
        }
    }

    //处理边界情况
    if(a[n] != INF) count++;

    cout << count << endl;

    return 0;
}