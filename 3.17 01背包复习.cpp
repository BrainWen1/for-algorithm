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

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].v >> a[i].w;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];

            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].v] + a[i].w);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    memset(memo, -0x3f, sizeof(memo));
    for(int i = 0; i <= n; ++i) {
        memo[i][0] = 0;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];
            
            if(j >= a[i].v) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].v] + a[i].w);
            }
        }
    }
    int t = memo[n][m];
    if(t < 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << t << std::endl;
    }

    return 0;
}

//P1048 [NOIP 2005 普及组] 采药
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 1e3 + 10;
int n, m;
struct node {
    int t;
    int v;
}a[N];
int memo[N][M];

int main(void) {
    std::cin >> m >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].t >> a[i].v;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];

            if(j >= a[i].t) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].t] + a[i].v);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//P1164 小A点菜
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 1e4 + 10;
int n, m;
int a[N], memo[N][M];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memo[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];

            if(j >= a[i]) {
                memo[i][j] += memo[i - 1][j - a[i]];
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//P2946 [USACO09MAR] Cow Frisbee Team S
#include <iostream>
#include <algorithm>

const int N = 2e3 + 10, M = 1e3 + 10, MOD = 1e8;
int n, m;
int a[N], memo[N][M];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memo[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = m - 1; j >= 0; --j) {
            memo[i][j] = (memo[i - 1][j] + memo[i - 1][((j - a[i] % m) % m + m) % m]) % MOD;
        }
    }
    std::cout << memo[n][0] - 1 << std::endl;

    return 0;
}