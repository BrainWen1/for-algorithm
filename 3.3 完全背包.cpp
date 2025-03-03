//NC226516【模板】完全背包
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

    //状态表示：memo[i][j] 表示从前 i 个物品中挑选出总体积不超过 j 的物品的总价值
    //状态转移：memo[i][j] 由两种情况的最大值得到：一.不选 a[i], 则为 memo[i - 1][j]; 二.选 a[i](若 j >= a[i].v), 但是涉及到选几个的问题, 故可归纳为 memo[i][j - a[i].v] + a[i].w, 则可保证后一次循环可继续询问是否选择 a[i]
    //拓扑顺序：因为要使用上一行和这一行的左边的数据, 故从上到下、从左到右即可
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i][j - a[i].v] + a[i].w);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    memset(memo, -0x3f, sizeof(memo));
    memo[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i][j - a[i].v] + a[i].w);
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

    //状态表示：memo[j] 表示从前 i 个物品中挑选出总体积不超过 j 的物品的总价值
    //状态转移：memo[j] 由两种情况的最大值得到：一.不选 a[i], 则为 memo[j]; 二.选 a[i](若 j >= a[i].v), 但是涉及到选几个的问题, 故可归纳为 memo[j - a[i].v] + a[i].w, 则可保证后一次循环可继续询问是否选择 a[i]
    //拓扑顺序：因为要使用上一行和这一行的左边的数据, 故从上到下、从左到右即可
    for(int i = 1; i <= n; i++) {
        for(int j = a[i].v; j <= m; j++) {
            memo[j] = std::max(memo[j], memo[j - a[i].v] + a[i].w);
        }
    }
    std::cout << memo[m] << std::endl;

    memset(memo, -0x3f, sizeof(memo));
    memo[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = a[i].v; j <= m; j++) {
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

//P1616 疯狂的采药
#include <iostream>
#include <algorithm>

typedef long long LL;
const int N = 1e4 + 10, M = 1e7 + 10;
int n, m;
struct node {
    LL v;
    LL w;
}a[N];
LL memo[M];

int main(void) {
    std::cin >> m >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //状态表示：memo[j] 表示在前 i 个草药中挑选出总时间不超过 j 的草药的最大价值
    //状态转移：memo[j] 由两种情况的最大值得到：一.不选a[i], 则为 memo[j]; 二.选a[i], 涉及到选几个的问题, 与上一模板题相同
    //拓扑顺序：因为要使用上一行和当前行左边的数据, 故需从上到下、从左到右
    for(int i = 1; i <= n; i++) {
        for(int j = a[i].v; j <= m; j++) {
            memo[j] = std::max(memo[j], memo[j - a[i].v] + a[i].w);
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P2918 [USACO08NOV] Buying Hay S
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, M = 5e4 + 10;
int n, m;
struct node {
    int v;
    int w;
}a[N];
int memo[N][M];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //初始化
    memset(memo, 0x3f, sizeof(memo));
    memo[0][0] = 0;

    //状态表示：memo[i][j] 表示在前 i 个公司中挑选出总重量至少为 j 的干草的最小开销
    //状态转移：memo[i][j] 为可能的两种情况的最小值：一.不选 a[i], 则从前 (i - 1) 个公司里挑选, 并且总重量保持至少为 j, 即 (memo[i - 1][j]); 二.选择 a[i], 则涉及到选多少的问题, 故是在前 (i) 个公司中挑选, 且此时总重量应该至少为 (j - a[i].v), 且此值若小于零, 则应取 0 以尽量往最小开销凑, 即 (memo[i][max(j - a[i].v), 0] + a[i].w)
    //拓扑顺序：需要使用上一行和当前行左边的数据, 故需从上到下、从左到右
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[i][j] = std::min(memo[i - 1][j], memo[i][std::max(j - a[i].v, 0)] + a[i].w);
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, M = 5e4 + 10;
int n, m;
struct node {
    int v;
    int w;
}a[N];
int memo[M];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].v >> a[i].w;
    }

    //初始化
    memset(memo, 0x3f, sizeof(memo));
    memo[0] = 0;

    //状态表示：memo[i][j] 表示在前 i 个公司中挑选出总重量至少为 j 的干草的最小开销
    //状态转移：memo[i][j] 为可能的两种情况的最小值：一.不选 a[i], 则从前 (i - 1) 个公司里挑选, 并且总重量保持至少为 j, 即 (memo[i - 1][j]); 二.选择 a[i], 则涉及到选多少的问题, 故是在前 (i) 个公司中挑选, 且此时总重量应该至少为 (j - a[i].v), 且此值若小于零, 则应取 0 以尽量往最小开销凑, 即 (memo[i][max(j - a[i].v), 0] + a[i].w)
    //拓扑顺序：需要使用上一行和当前行左边的数据, 故需从上到下、从左到右
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[j] = std::min(memo[j], memo[std::max(j - a[i].v, 0)] + a[i].w);
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P5662 [CSP-J2019] 纪念品
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, M = 1e4 + 10;
int t, n, m;
int a[N][N], memo[N][M];

//动态规划 完全背包dp
int solve(int pre[], int nex[], int mon) {
    memset(memo, 0, sizeof(memo));
    //状态表示：memo[i][j] -> 从前 i 个物品中挑选出总价格不超过 j 的物品买入, 并在后一天部分卖出的最大利润
    //状态转移：memo[i][j] -> 一：不买 pre[i], memo[i - 1][j]; 二：买 pre[i], memo[i][j - pre[i]] + nex[i] - pre[i]; 取二者最大值
    //拓扑顺序：由于需要使用上一行和当前行左边的数据, 故需从上到下、从左到右
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= mon; ++j) {
            memo[i][j] = memo[i - 1][j];
            if(j >= pre[i]) {
                memo[i][j] = std::max(memo[i][j], memo[i][j - pre[i]] + nex[i] - pre[i]);
            }
        }
    }
    return mon + memo[n][mon];
}

int main(void) {
    std::cin >> t >> n >> m;

    for(int i = 1; i <= t; ++i) {
        for(int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
        }
    }

    //贪心拿到每一天的最大利润
    for(int i = 1; i < t; i++) {
        m = solve(a[i], a[i + 1], m);
    }
    std::cout << m << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, M = 1e4 + 10;
int t, n, m;
int a[N][N], memo[M];

//动态规划 完全背包dp
int solve(int pre[], int nex[], int mon) {
    memset(memo, 0, sizeof(memo));
    //状态表示：memo[i][j] -> 从前 i 个物品中挑选出总价格不超过 j 的物品买入, 并在后一天部分卖出的最大利润
    //状态转移：memo[i][j] -> 一：不买 pre[i], memo[i - 1][j]; 二：买 pre[i], memo[i][j - pre[i]] + nex[i] - pre[i]; 取二者最大值
    //拓扑顺序：由于需要使用上一行和当前行左边的数据, 故需从上到下、从左到右
    for(int i = 1; i <= n; ++i) {
        for(int j = pre[i]; j <= mon; ++j) {
            memo[j] = std::max(memo[j], memo[j - pre[i]] + nex[i] - pre[i]);
        }
    }
    return mon + memo[mon];
}

int main(void) {
    std::cin >> t >> n >> m;

    for(int i = 1; i <= t; ++i) {
        for(int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
        }
    }

    //贪心拿到每一天的最大利润
    for(int i = 1; i < t; i++) {
        m = solve(a[i], a[i + 1], m);
    }
    std::cout << m << std::endl;

    return 0;
}