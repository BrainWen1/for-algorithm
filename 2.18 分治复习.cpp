//归并排序
#include <iostream>

const int N = 1e3 + 10;
int a[N];
int tmp[N];

void MergeSort(int left, int right)
{
    //递归出口
    if(left == right) {
        return;
    }

    //二分区间
    int mid = (left + right) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);

    //合并两个有序数组
    int cur1 = left, cur2 = mid + 1, i = left;
    while(cur1 <= mid && cur2 <= right) {
        if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
        else if(a[cur1] > a[cur2]) tmp[i++] = a[cur2++];
    }

    //处理为合并完全地数组
    while(cur1 <= mid) tmp[i++] = a[cur1++];
    while(cur2 <= right) tmp[i++] = a[cur2++];

    //将合并到tmp数组中的有序序列覆盖到a数组中
    for(i = left; i <= right; i++) a[i] = tmp[i];
}

int main(void)
{
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    MergeSort(1, n);

    for(int i = 1; i <= n; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

//P1908 逆序对
#include <iostream>

typedef long long LL;
const int N = 5e5 + 10;
int n;
int a[N], tmp[N];

LL MergeSort_count(int left, int right)
{
    //递归出口
    if(left >= right) {
        return 0;
    }

    //划分区间,创当前递归层数下的计数器
    int mid = (left + right) / 2;
    LL ret = 0;
    ret += MergeSort_count(left, mid);
    ret += MergeSort_count(mid + 1, right);

    //合并有序数组
    int cur1 = left, cur2 = mid + 1, i = left;
    while(cur1 <= mid && cur2 <= right) {
        if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
        else if(a[cur1] > a[cur2]) {
            tmp[i++] = a[cur2++];
            ret += mid - cur1 + 1;//左边元素大于右边的某个元素,则左边的剩余右半部分都大于该元素
        }
    }

    //处理没合并完全的数组,可以验证这两种情况都不需要再次计数
    while(cur1 <= mid) tmp[i++] = a[cur1++];
    while(cur2 <= right) tmp[i++] = a[cur2++];

    //将tmp数组中的合并后的内容覆盖到a数组中
    for(i = left; i <= right; i++) a[i] = tmp[i];

    return ret;
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::cout << MergeSort_count(1, n) << std::endl;

    return 0;
}

//P1923 【深基9.例4】求第 k 小的数
#include <iostream>
#include <ctime>
#include <algorithm>

const int N = 5e6 + 10;
int n, k;
int a[N];

//随机获取范围内的的一个值
int RandomNum(int left, int right)
{
    return a[rand() % (right - left + 1) + left];
}

//快排模板
int QuickSort_Find(int left, int right, int k)
{
    //递归出口
    if(left >= right) {
        return a[left];
    }

    //随机获取一个基准值
    int pivot = RandomNum(left, right);

    // [left, l] [l + 1, r - 1] [r, right] 分割数组
    int l = left - 1, i = left, r = right + 1;
    while(i < r) {
        if(a[i] < pivot) std::swap(a[++l], a[i++]);
        else if(a[i] > pivot) std::swap(a[--r], a[i]);
        else i++;
    }

    //按照k处于哪个下标区间内决定是返回该基准值还是递归处理左或右区间
    int len1 = l - left + 1, len2 = r - 1 - l;
    if(k <= len1) return QuickSort_Find(left, l, k);
    else if(k <= len1 + len2) return pivot;
    else return QuickSort_Find(r, right, k - len1 - len2);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //获取初始随机数种子
    srand(time(0));
    std::cout << QuickSort_Find(1, n, ++k) << std::endl;

    return 0;
}

//P1115 最大子段和
#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;
int n;
int a[N];

int dfs(int left, int right)
{
    //递归出口
    if(left >= right) {
        return a[left];
    }

    //二分区间,分别计算左右区间内的最大子段和
    int mid = (left + right) / 2;
    int maxi = std::max(dfs(left, mid), dfs(mid + 1, right));

    //计算跨左右区间的最大子段和
    int sum1 = 0, sum2 = 0;
    int maxi1 = a[mid], maxi2 = a[mid + 1];

    //延伸左区间
    for(int i = mid; i >= left; i--) {
        sum1 += a[i];
        maxi1 = std::max(maxi1, sum1);
    }

    //延伸右区间
    for(int i = mid + 1; i <= right; i++) {
        sum2 += a[i];
        maxi2 = std::max(maxi2, sum2);
    }

    //得到三者最大值
    maxi = std::max(maxi, maxi1 + maxi2);

    return maxi;
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::cout << dfs(1, n) << std::endl;

    return 0;
}

//P1228 地毯填补问题
#include <iostream>

int n, x, y;

void dfs(int a, int b, int len, int x, int y)
{
    if(1 == len) {
        return;
    }

    len /= 2;

    //划分区间
    //左上角
    if(x < a + len && y < b + len) {
        std::cout << a + len << ' ' << b + len << ' ' << 1 << std::endl;
        dfs(a, b, len, x, y);//左上角
		dfs(a, b + len, len, a + len - 1, b + len);//右上角
		dfs(a + len, b, len, a + len, b + len - 1);//左下角
		dfs(a + len, b + len, len, a + len, b + len);//右下角
    }
    //右上角
    else if(x < a + len && y >= b + len) {
        std::cout << a + len << ' ' << b + len - 1 << ' ' << 2 << std::endl;
        dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, x, y);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
    }
    //左下角
    else if(x >= a + len && y < b + len) {
        std::cout << a + len - 1 << ' ' << b + len << ' ' << 3 << std::endl;
        dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, x, y);
		dfs(a + len, b + len, len, a + len, b + len);
    }
    //右下角
    else {
        std::cout << a + len - 1 << ' ' << b + len - 1 << ' ' << 4 << std::endl;
        dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, x, y);
    }
}

int main(void)
{
    std::cin >> n >> x >> y;
    n = (1 << n);

    dfs(1, 1, n, x, y);
}