// 离散化模板⼀: 排序 + 去重 + ⼆分查找离散之后的结果
#include <iostream>
#include <algorithm>

const int N = 1e3 + 10;
int n, pos;
int a[N], disc[N];

//二分查找
int find(int val)
{
    int left = 1, right = pos;
    while(left < right) {
        int mid = (left + right) / 2;
        if(disc[mid] >= val) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;//返回映射的下标,即离散化后的值为对应下标
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        disc[++pos] = a[i];
    }

    std::sort(disc + 1, disc + 1 + n);//排序
    pos = std::unique(disc + 1, disc + 1 + n) - (disc + 1);//去重

    for(int i = 1; i <= n; i++) {
        std::cout << find(a[i]) << ' ';
    }
    std::cout << std::endl;

    return 0;
}

// 离散化模板⼆: 排序 + 哈希表去重以及记录最终的位置
#include <iostream>
#include <algorithm>
#include <unordered_map>

const int N = 1e3 + 10;
int n, pos;
int a[N], disc[N];
std::unordered_map<int, int> mp;

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        disc[++pos] = a[i];
    }

    std::sort(disc + 1, disc + 1 + n);//排序
    int index = 1;//作为映射值标记元素
    for(int i = 1; i <= n; i++) {
        if(mp[disc[i]]) continue;
        mp[disc[i]] = index++;
    }
    pos = --index;//离散化后元素个数

    for(int i = 1; i <= n; i++) {
        std::cout << mp[a[i]] << ' ';//使用mp[val]查找映射值
    }
    std::cout << std::endl;

    if(mp.size() == pos) std::cout << "yes" << std::endl;//相等

    return 0;
}

//P1097 [NOIP 2007 提高组] 统计数字
#include <iostream>
#include <algorithm>
#include <unordered_map>

const int N = 2e5 + 10;
int n, pos;
int a[N];
std::unordered_map<int, int> mp, count;


int main(void)
{
    std::cin >> n;

    int index = 1;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        count[a[i]]++;//对每一个数据计数
        // if(mp[a[i]]) {
        //     count[mp[a[i]]]++;
        //     continue;
        // }
        // mp[a[i]] = index++;

        // count[mp[a[i]]]++;
    }

    std::sort(a + 1, a + 1 + n);//排序
    pos = std::unique(a + 1, a + 1 + n) - (a + 1);//去重

    for(int i = 1; i <= pos; i++) {
        std::cout << a[i] << ' ' << count[a[i]] << std::endl;
    }

    return 0;
}

//P1496 火烧赤壁
#include <iostream>
#include <algorithm>
#include <unordered_map>

const int N = 2e4 + 10;
int n, pos;
int a[N], b[N], disc[2 * N], f[2 * N];

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
        disc[++pos] = a[i];
        disc[++pos] = b[i];
    }

    std::sort(disc + 1, disc + 1 + pos);//排序
    pos = std::unique(disc + 1, disc + 1 + pos) - (disc + 1);//去重

    // <原始数据, 映射数据>
    std::unordered_map<int, int> mp;

    for(int i = 1; i <= pos; i++) {
        mp[disc[i]] = i;// <disc[i],i>  可以用 i查找到原始的范围 disc[i]
    }

    //使用原始数据映射的下标进行差分处理
    for(int i = 1; i <= n; i++) {
        f[mp[b[i]]]--;
        f[mp[a[i]]]++;
    }

    //还原数组
    for(int i = 1; i <= pos; i++) {
        f[i] += f[i - 1];
    }

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        int j = i;
        for(j = i; j <= pos; j++) {
            if(f[j] == 0) break;//找到一个着火区间的结尾
        }
        ret += disc[j] - disc[i];// [i, j)找到原始着火区间
        i = j;//类似维护一个滑动窗口
    }
    std::cout << ret << std::endl;

    return 0;
}

//P3740 [HAOI2014] 贴海报
#include <iostream>
#include <algorithm>
#include <unordered_map>

const int N = 1e3 + 10;
int n, m, pos;
int a[N], b[N], disc[4 * N];
int wall[4 * N];
bool is_counted[N];

int main(void)
{
    std::cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        std::cin >> a[i] >> b[i];

        //保存 a[i] + 1 和 b[i] + 1 可以保证离散化后不会出现部分海报被覆盖
        disc[++pos] = a[i]; disc[++pos] = a[i] + 1;
        disc[++pos] = b[i]; disc[++pos] = b[i] + 1;
    }

    std::sort(disc + 1, disc + 1 + pos);//排序
    pos = std::unique(disc + 1, disc + 1 + pos) - (disc + 1);//去重

    // <原始数据, 映射数据>
    std::unordered_map<int, int> mp;
    for(int i = 1; i <= pos; i++) {
        mp[disc[i]] = i;
    }

    //模拟贴海报
    for(int i = 1; i <= m; i++) {
        int left = mp[a[i]], right = mp[b[i]];//使用离散化后的下标来标记
        for(int k = left; k <= right; k++) {
            wall[k] = i;//每种海报使用不同值标记
        }
    }

    //根据遍历wall数组有多少种值来统计可见海报数
    int ret = 0;
    for(int i = 1; i <= pos; i++) {
        if(true == is_counted[wall[i]] || 0 == wall[i]) continue;
        is_counted[wall[i]] = true;//使用bool数组来标记当前值代表的海报是否已经计数
        ret++;
    }
    std::cout << ret << std::endl;

    return 0;
}