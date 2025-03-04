//NC235950 多重背包
#include <iostream>
#include <algorithm>

const int N = 100 + 10;
int n, m;
class node {
public:
    int x;
    int w;
    int v;
}a[N];
int memo[N][N];

int main(void) {
    std::cin >> n >> m;

    for (size_t i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].w >> a[i].v;
    }

    //状态表示：memo[i][j] -> 从前 i 个物品中挑选出总重量不超过 j 的物品的最大价值
    //状态转移：memo[i][j] -> 枚举挑选 (0 ~ a[i].x) 个 a[i] 物品并取其中的最大值
    //拓扑顺序：由于要使用上一行的数据, 故从上到下即可
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 0; k <= a[i].x && j >= k * a[i].w; ++k) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - k * a[i].w] + k * a[i].v);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 100 + 10;
int n, m;
class node {
public:
    int x;
    int w;
    int v;
}a[N];
int memo[N];

int main(void) {
    std::cin >> n >> m;

    for (size_t i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].w >> a[i].v;
    }

    //状态表示：memo[j] -> 从前 i 个物品中挑选出总重量不超过 j 的物品的最大价值
    //状态转移：memo[j] -> 枚举挑选 (0 ~ a[i].x) 个 a[i] 物品并取其中的最大值
    //拓扑顺序：由于要使用上一行的数据, 故从上到下即可
    //注意：因为状态转移时使用的是上一行左边的数据, 故空间优化时需从右向左扫描, 以免污染上一行的原数据
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 0; k <= a[i].x && j >= k * a[i].w; ++k) {
                memo[j] = std::max(memo[j], memo[j - k * a[i].w] + k * a[i].v);
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}
//二进制优化: 在求解最大最小值问题时可以使用, 求方案数时不能使用
#include <iostream>
#include <algorithm>

const int N = 110 * 5;
int n, m, pos;
class node {
public:
    int w;
    int v;
}a[N];
int memo[N];

int main(void) {
    std::cin >> n >> m;

    for (size_t i = 1; i <= n; i++) {
        int x, w, v;
        std::cin >> x >> w >> v;

        //二进制优化
        int tmp = 1;
        while(x >= tmp) {
            pos++;
            a[pos].w = tmp * w;
            a[pos].v = tmp * v;
            x -= tmp;
            tmp *= 2;
        }
        if(x) {
            pos++;
            a[pos].w = x * w;
            a[pos].v = x * v;
        }
    }

    //此时对数据做一次 01背包 算法即可
    //状态表示：memo[j] -> 从前 i 个物品中挑选出总重量不超过 j 的物品的最大价值
    //状态转移：memo[j] -> 枚举挑选 (0 ~ a[i].x) 个 a[i] 物品并取其中的最大值
    //拓扑顺序：由于要使用上一行的数据, 故从上到下即可
    for(int i = 1; i <= pos; ++i) {
        for(int j = m; j >= a[i].w; --j) {
            memo[j] = std::max(memo[j], memo[j - a[i].w] + a[i].v);
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P1077 [NOIP 2012 普及组] 摆花
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, mod = 1e6 + 7;
int n, m;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示：memo[i][j] -> 于前 i 盆花中挑选 j 盆花的方案数
    //状态转移：memo[i][j] -> 枚举挑选 (0 ~ a[i]) 盆 a[i] 花并统计总方案数
    //拓扑顺序：因为要使用上一行和当前行的左边的数据, 故需从上到下、从右到左即可
    memo[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 0; k <= a[i] && j >= k; ++k) {
                memo[i][j] = (memo[i][j] + memo[i - 1][j - k]) % mod;
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, mod = 1e6 + 7;
int n, m;
int a[N], memo[N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示：memo[j] -> 于前 i 盆花中挑选 j 盆花的方案数
    //状态转移：memo[j] -> 枚举挑选 (0 ~ a[i]) 盆 a[i] 花并统计总方案数
    //拓扑顺序：因为要使用上一行和当前行的左边的数据, 故需从上到下、从右到左即可
    memo[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            //注意要从 k = 1 开始, 因为 k = 0 时会重复计算一次 memo[j] 本身
            for(int k = 1; k <= a[i] && j >= k; ++k) {
                memo[j] = (memo[j] + memo[j - k]) % mod;
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}