//NC235950 多重背包
#include <iostream>
#include <algorithm>

const int N = 100 + 10;
int n, m;
struct node {
    int x;
    int v;
    int w;
}a[N];
int memo[N][N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].x >> a[i].v >> a[i].w;
    }

    //状态表示
    //状态表示
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 0; k <= a[i].x && j >= a[i].v * k; ++k) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].v * k] + a[i].w * k);
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
struct node {
    int x;
    int v;
    int w;
}a[N];
int memo[N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].x >> a[i].v >> a[i].w;
    }

    //状态表示
    //状态表示
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 1; k <= a[i].x && j >= a[i].v * k; ++k) {
                memo[j] = std::max(memo[j], memo[j - a[i].v * k] + a[i].w * k);
            } 
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P1077 [NOIP 2012 普及组] 摆花
#include <iostream>
#include <algorithm>

const int N = 100 + 10, MOD = 1e6 + 7;
int n, m;
int a[N], memo[N][N];

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
            for(int k = 0; k <= a[i] && j >= k; ++k) {
                memo[i][j] += memo[i - 1][j - k];
                memo[i][j] %= MOD;
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 100 + 10, MOD = 1e6 + 7;
int n, m;
int a[N], memo[N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memo[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 1; k <= a[i] && j >= k; ++k) {
                memo[j] += memo[j - k];
                memo[j] %= MOD;
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}