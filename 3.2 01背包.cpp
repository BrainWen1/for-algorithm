//NC226514【模板】01背包
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1e3 + 10;
int n, m;
struct node {
    int v;
    int w;
}a[N];
int memo[N][N];

int main(void) {
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //(1)求这个背包至多能装多大价值的物品?
    //状态表示：memo[i][j] 表示从第 1 ~ i 个物品中挑出若干个物品组成最大价值且总体积小于等于 j
    //状态转移：memo[i][j] 可分为两种情况且取二者中的最大值：一.不选择 a[i], 则需从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j) 的最大价值物品; 二.选择 a[i] 且 j >= a[i].v, 则从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j - a[i].v) 的最大价值物品, 且需额外加上当前 a[i] 的价值
    //拓扑顺序：需使用上一行中的若干数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].v] + a[i].w);

            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    //(2)若背包恰好装满，求至多能装多大价值的物品?
    //状态三问与上一问基本没区别, 只是挑出的物品总体积要恰好等于 j
    //初始化：与上一问不同, 第二问的边界情况没有实际意义, 因为物品为 0 时要选出物品使其体积恰好等于 j 是无意义的, 所以可以将这些位置初始化为无穷小, 后续若使用到这些位置也只是会继续保持无穷小或至少会小于零, 仅需在输出答案时特殊判断即可
    memset(memo, -0x3f, sizeof(memo));
    memo[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].v] + a[i].w);
            }
        }
    }
    if(memo[n][m] < 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << memo[n][m] << std::endl;
    }

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1e3 + 10;
int n, m;
struct node {
    int v;
    int w;
}a[N];
int memo[N];

int main(void) {
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //(1)求这个背包至多能装多大价值的物品?
    //状态表示：memo[i][j] 表示从第 1 ~ i 个物品中挑出若干个物品组成最大价值且总体积小于等于 j
    //状态转移：memo[i][j] 可分为两种情况且取二者中的最大值：一.不选择 a[i], 则需从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j) 的最大价值物品; 二.选择 a[i] 且 j >= a[i].v, 则从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j - a[i].v) 的最大价值物品, 且需额外加上当前 a[i] 的价值
    //拓扑顺序：需使用上一行中的若干数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= a[i].v; j--) {//因为需要使用左边的数据, 故需从右往左遍历以免污染原数据
            memo[j] = std::max(memo[j], memo[j - a[i].v] + a[i].w);
        }
    }
    std::cout << memo[m] << std::endl;

    //(2)若背包恰好装满，求至多能装多大价值的物品?
    //状态三问与上一问基本没区别, 只是挑出的物品总体积要恰好等于 j
    //初始化：与上一问不同, 第二问的边界情况没有实际意义, 因为物品为 0 时要选出物品使其体积恰好等于 j 是无意义的, 所以可以将这些位置初始化为无穷小, 后续若使用到这些位置也只是会继续保持无穷小或至少会小于零, 仅需在输出答案时特殊判断即可
    memset(memo, -0x3f, sizeof(memo));
    memo[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= a[i].v; j--) {
                memo[j] = std::max(memo[j], memo[j - a[i].v] + a[i].w);
            }
        }
    if(memo[m] < 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << memo[m] << std::endl;
    }

    return 0;
}

//P1048 [NOIP 2005 普及组] 采药
#include <iostream>
#include <algorithm>

const int N = 1e3 + 10;
int m, n;
struct node {
    int v;
    int w;
}a[N];
int memo[N][N];

int main(void) {
    std::cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //物品 -> 草药; 体积 -> 时间
    //状态表示：memo[i][j] 表示从第 1 ~ i 个物品中挑出若干个物品组成最大价值且总体积小于等于 j
    //状态转移：memo[i][j] 可分为两种情况且取二者中的最大值：一.不选择 a[i], 则需从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j) 的最大价值物品; 二.选择 a[i] 且 j >= a[i].v, 则从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j - a[i].v) 的最大价值物品, 且需额外加上当前 a[i] 的价值
    //拓扑顺序：需使用上一行中的若干数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].v] + a[i].w);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 1e3 + 10;
int m, n;
struct node {
    int v;
    int w;
}a[N];
int memo[N];

int main(void) {
    std::cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //物品 -> 草药; 体积 -> 时间
    //状态表示：memo[i][j] 表示从第 1 ~ i 个物品中挑出若干个物品组成最大价值且总体积小于等于 j
    //状态转移：memo[i][j] 可分为两种情况且取二者中的最大值：一.不选择 a[i], 则需从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j) 的最大价值物品; 二.选择 a[i] 且 j >= a[i].v, 则从前 (1 ~ i - 1) 个物品中挑选总体积小于等于 (j - a[i].v) 的最大价值物品, 且需额外加上当前 a[i] 的价值
    //拓扑顺序：需使用上一行中的若干数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= a[i].v; j--) {
            memo[j] = std::max(memo[j], memo[j - a[i].v] + a[i].w);
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P1164 小A点菜
#include <iostream>
#include <algorithm>

const int N = 1e4 + 10;
int n, m;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //初始化
    memo[0][0] = 1;

    //状态表示：memo[i][j] 表示在 1 ~ i 个菜品中挑选若干菜品使总费用恰好为 j 是的方案数
    //状态转移：memo[i][j] 为两种情况的方案总和：一.不选择 a[i], 则为从前 (1 ~ i - 1) 个物品中挑选总费用等于 (j) 的方案数; 二.选择 a[i] 且 j >= a[i], 则从前 (1 ~ i - 1) 个物品中挑选总费用等于 (j - a[i]) 的方案数
    //拓扑顺序：需要使用上一行的数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if(j >= a[i]) {
                memo[i][j] += memo[i - 1][j - a[i]];
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 1e4 + 10;
int n, m;
int a[N], memo[N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //初始化
    memo[0] = 1;

    //状态表示：memo[j] 表示在 1 ~ i 个菜品中挑选若干菜品使总费用恰好为 j 是的方案数
    //状态转移：memo[j] 为两种情况的方案总和：一.不选择 a[i], 则为从前 (1 ~ i - 1) 个物品中挑选总费用等于 (j) 的方案数; 二.选择 a[i] 且 j >= a[i], 则从前 (1 ~ i - 1) 个物品中挑选总费用等于 (j - a[i]) 的方案数
    //拓扑顺序：需要使用上一行的数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= a[i]; j--) {
            memo[j] += memo[j - a[i]];
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P2946 [USACO09MAR] Cow Frisbee Team S
#include <iostream>
#include <algorithm>

const int N = 2e3 + 10;
int n, m;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //初始化
    memo[0][0] = 1;

    //状态表示：memo[i][j] 表示从 1 ~ i 头奶牛中挑选出总能力模 F 之后为 j 的奶牛的方案数
    //状态转移：memo[i][j] 由两种情况得到：一.不选a[i], 则需从 (1 ~ i - 1) 头奶牛中挑选出总能力模 F 之后为 j 的奶牛; 二.选 a[i], 此时已经有⼀个余数为 (a[i] % F), 只⽤再去前⾯凑⼀个 (j - a[i] % F) 即可, 但是直接减可能会减出来⼀个负数, 要使用模加模把它补正
    //拓扑顺序：因为要使用上一行的数据, 故从上往下即可
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            memo[i][j] = (memo[i - 1][j] + memo[i - 1][(j - a[i] % m + m) % m]) % (int)1e8;
        }
    }
    std::cout << memo[n][0] - 1 << std::endl;

    return 0;
}