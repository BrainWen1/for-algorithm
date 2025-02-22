//递归型枚举与回溯剪枝初始
//P1706 全排列问题
#include <iostream>
#include <iomanip>
#include <vector>

const int N = 10;
int n;
bool st[N];
std::vector<int> a;

void dfs(int pos)
{
    if(pos > n) {
        for(int num : a) {
            std::cout << std::setw(5)  << num;
        }

        std::cout << std::endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(st[i]) {
            continue;
        }
        a.push_back(i);
        st[i] = true;

        dfs(pos + 1);

        a.pop_back();
        st[i] = false;
    }
}

int main(void)
{
    std::cin >> n;

    dfs(1);

    return 0;
}

//DFS
//P1036 [NOIP 2002 普及组] 选数
#include <iostream>
#include <cmath>

const int N = 20 + 5;
int n, k, sum, ret;
int a[N];

bool is_prime(int num)
{
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;

    int z = std::sqrt(num);
    for(int i = 5; i <= z; i+=6) {
        if(num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int pos, int index)
{
    if(pos > k) {
        if(is_prime(sum)) {
            ret++;
        }
        return;
    }

    for(int i = index; i <= n; i++) {
        sum += a[i];

        dfs(pos + 1, i + 1);

        sum -= a[i];
    }
}

int main(void)
{
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    dfs(1, 1);

    std::cout << ret << std::endl;

    return 0;
}

//剪枝与优化
//P1025 [NOIP 2001 提高组] 数的划分
#include <iostream>

const int N = 200 + 10;
int n, k, sum, ret;
int a[N];

void dfs(int pos, int val)
{
    if(pos > k) {
        if(sum == n) {
            ret++;
        }
        return;
    }

    for(int i = val; i <= n - k + 1; i++) {
        //剪枝
        if(sum + (k - pos + 1) * i > n) {
            return;
        }

        sum += i;

        dfs(pos + 1, i);

        sum -= i;
    }
}

int main(void)
{
    std::cin >> n >> k;

    dfs(1, 1);

    std::cout << ret << std::endl;

    return 0;
}

//记忆化搜索
//P1434 [SHOI2002] 滑雪
#include <iostream>
#include <algorithm>

const int N = 100 + 10;
int n, m, ret;
int a[N][N];
int mp[N][N];

int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

int dfs(int x, int y)
{
    if(mp[x][y]) {
        return mp[x][y];
    }

    int sum = 1;
    for(int k = 0; k < 4; k++) {
        int i = x + dx[k];
        int j = y + dy[k];

        if(i < 1 || i > n || j < 1 || j > m || a[i][j] >= a[x][y]) {
            continue;
        }

        sum = std::max(sum, dfs(i, j) + 1);
    }
    return mp[x][y] = sum;
}

int main(void)
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ret = std::max(ret, dfs(i, j));
        }
    }

    std::cout << ret << std::endl;

    return 0;
}