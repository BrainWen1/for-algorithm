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

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].v >> a[i].w;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[i][j] = memo[i - 1][j];

            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i][j - a[i].v] + a[i].w);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    memset(memo, -0x3f, sizeof(memo));
    memo[0][0] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
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

//P1616 疯狂的采药
#include <iostream>
#include <algorithm>

typedef long long LL;
const int N = 1e4 + 10, M = 1e7 + 10;
int n, m;
struct node {
    int t;
    int w;
}a[N];
LL memo[M];

int main(void) {
    std::cin >> m >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].t >> a[i].w;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = a[i].t; j <= m; ++j) {
            memo[j] = std::max(memo[j], memo[j - a[i].t] + a[i].w);
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
    int v;//重量
    int w;//开销
}a[N];
int memo[N][M];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].v >> a[i].w;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memset(memo, 0x3f, sizeof(memo));
    memo[0][0] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[i][j] = std::min(memo[i - 1][j], memo[i][std::max(0, j - a[i].v)] + a[i].w);
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//P5662 [CSP-J2019] 纪念品
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100 + 10, M = 1e4 + 10;
int T, n, m;
int a[N][N], memo[N][M];

int solve(int a[], int b[], int m) {
    memset(memo, 0, sizeof(memo));

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[i][j] = memo[i - 1][j];

            if(j >= a[i]) {
                memo[i][j] = std::max(memo[i][j], memo[i][j - a[i]] + b[i] - a[i]);
            }
        }
    }
    return m + memo[n][m];
}

int main(void) {
    std::cin >> T >> n >> m;

    for(int i = 1; i <= T; ++i) {
        for(int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
        }
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i < T; ++i) {
        m = solve(a[i], a[i + 1], m);//买入 卖出 本金
    }
    std::cout << m << std::endl;

    return 0;
}