//P1614 爱与愁的心痛 简单贪心
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e3 + 10;
int n, m;
int a[N];

int main(void)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //计算前m项和
    int ret = 0;
    for(int i = 1; i <= m; i++) {
        ret += a[i];
    }
    
    int sum = ret;
    for(int i = m + 1; i <= n; i++) {
        //贪心得到当前最优解,遍历结束后得到整体最优解
        sum += a[i] - a[i - m];
        ret = min(ret, sum);
    }
    cout << ret << endl;

    return 0;
}

//P1639 [USACO18FEB] Teleportation B 简单贪心
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    
    //计算三种情况各自的路程消耗
    int len1 = abs(a - b);
    int len2 = abs(a - x) + abs(b - y);
    int len3 = abs(a - y) + abs(b - x);

    //贪心得到最小路程
    cout << min(len1, min(len2, len3)) << endl;

    return 0;
}

//P1031 [NOIP 2002 提高组] 均分纸牌 简单贪心
#include <iostream>

const int N = 100 + 10;
int n;
int a[N];

int main(void)
{
    std::cin >> n;
    int ret = 0;//用于计算最终每组有多少纸牌
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        ret += a[i];
    }
    ret /= n;

    int count = 0;
    //从前往后遍历,因为ret是确定值,故只需每次贪心确定是向后一个拿纸牌还是给纸牌
    for(int i = 1; i < n; i++) {
        int carry = a[i] - ret;
        if(carry > 0) {//给出
            a[i] -= carry;
            a[i + 1] += carry;
            count++;
        }
        else if(carry < 0) {//拿取
            carry = -carry;
            a[i] += carry;
            a[i + 1] -= carry;
            count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}

//P1109 学生分组 简单贪心
#include <iostream>
#include <algorithm>

const int N = 50 + 10;
int n, left, right;
int a[N];

int main(void)
{
    std::cin >> n;
    int sum = 0;//用于判断学生数是否有解
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }

    std::cin >> left >> right;

    //无解情况
    if(sum < left * n || sum > right * n) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int sum_in = 0, sum_out = 0;
    for(int i = 1; i <= n; i++) {
        //限制每组的最终人数在[Li, Ri]之间
        int Li = std::max(left, sum - right * (n - 1));
        int Ri = std::min(right, sum - left * (n - 1));

        //每组需要移入或移出的人数
        sum_out += std::max(0, a[i] - Ri);
        sum_in += std::max(0, Li - a[i]);
    }
    //对给出和拿取取最大值,得到的最大值能确保二者都能完成,因为操作一次即会拿取也会给出
    std::cout << std::max(sum_out, sum_in) << std::endl;

    return 0;
}

//P2970 [USACO09DEC] Selfish Grazing S 区间问题
#include <iostream>
#include <algorithm>

const int N = 5e4 + 10;
int n;
struct node
{
    int left;
    int right;
}a[N];

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].left >> a[i].right;
    }

    //按左端点升序排序
    std::sort(a + 1, a + 1 + n, [](node& l, node& r)->bool {
        return l.left < r.left;
    });

    int count = 1;//最后一个也要被计数
    int r = a[1].right;//以第一个区间为基准

    for(int i = 2; i <= n; i++) {
        //重叠
        if(a[i].left < r) {
            //保留右端点靠左的区间为基准区间
            r = std::min(r, a[i].right);
        }

        //不重叠
        else {
            //基准区间拿出计数
            count++;

            //更新基准区间
            r = a[i].right;
        }
    }
    std::cout << count << std::endl;

    return 0;
}

//P1223 排队接水 简单贪心
#include <iostream>
#include <algorithm>

const int N = 1e3 + 10;
int n;
struct node
{
    long long time;
    int index;
}a[N];

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].time;
        a[i].index = i;
    }

    //按持续时间升序排列
    std::sort(a + 1, a + 1 + n, [](node& l, node& r)->bool {
        return l.time < r.time;
    });

    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        std::cout << a[i].index << ' ';
        sum += a[i].time * (n - i);//计算总的等待时间
    }
    //格式化输出
    printf("\n%.2f\n", 1.0 * sum / n);

    return 0;
}

//P2878 [USACO07JAN] Protecting the Flowers S(第二次做) 推公式
#include <iostream>
#include <algorithm>

typedef long long LL;
const int N = 1e5 + 10;
int n;
struct node
{
    LL Ti;
    LL Di;
}a[N];

int main(void)
{
    std::cin >> n;
    LL sum = 0;//用于记录剩余的奶牛每分钟吃草量
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].Ti >> a[i].Di;
        sum += a[i].Di;
    }

    //推公式得到排序规则应满足: l.Ti * r.Di < r.Ti * l.Di
    std::sort(a + 1, a + 1 + n, [](node& l, node& r)->bool {
        return l.Ti * r.Di < r.Ti * l.Di;
    });

    LL ret = 0;
    for(int i = 1; i <= n; i++) {
        //减去当前要牵的奶牛的每分钟吃草量
        sum -= a[i].Di;
        ret += sum * (2 * a[i].Ti);
    }
    std::cout << ret << std::endl;

    return 0;
}

//NC233601.[模板]哈夫曼编码 哈夫曼编码
#include <iostream>
#include <queue>
#include <vector>

typedef long long LL;

int main(void)
{
    int n;
    std::cin >> n;

    //建小根堆
    std::priority_queue<LL, std::vector<LL>, std::greater<LL>> heap;
    for(int i = 1; i <= n; i++) {
        LL tmp;
        std::cin >> tmp;
        heap.push(tmp);
    }

    LL sum = 0;
    while(heap.size() > 1) {
        //取出最小的两个子树
        LL a = heap.top(); heap.pop();
        LL b = heap.top(); heap.pop();

        //合并放入小根堆
        heap.push(a + b);

        //累加计算最终树的带权路径长度
        sum += a + b;
    }
    std::cout << sum << std::endl;

    return 0;
}