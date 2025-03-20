//P1757 通天之分组背包
#include <iostream>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10, M = 100 + 10;
int n, m, k;
std::vector<PII> a[N];
int memo[M][N];

int main(void) {
    std::cin >> m >> n;

    int v, w, g;
    for(int i = 1; i <= n; ++i) {
        std::cin >> v >> w >> g;
        a[g].push_back({v, w});
        k = std::max(k, g);
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= k; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];
            for(PII e : a[i]) {
                if(j >= e.first) {
                    memo[i][j] = std::max(memo[i][j], memo[i - 1][j - e.first] + e.second);
                }
            }
        }
    }
    std::cout << memo[k][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10, M = 100 + 10;
int n, m, k;
std::vector<PII> a[N];
int memo[N];

int main(void) {
    std::cin >> m >> n;

    int v, w, g;
    for(int i = 1; i <= n; ++i) {
        std::cin >> v >> w >> g;
        a[g].push_back({v, w});
        k = std::max(k, g);
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= k; ++i) {
        for(int j = m; j >= 0; --j) {
            for(PII e : a[i]) {
                if(j >= e.first) {
                    memo[j] = std::max(memo[j], memo[j - e.first] + e.second);
                }
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}

//P5322 [BJOI2019] 排兵布阵
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 2e4 + 10;
int s, n, m;
int a[N][N], memo[N][N];

int main(void) {
    std::cin >> s >> n >> m;

    for(int i = 1; i <= s; ++i) {
        for(int j = 1; j <= n; ++j) {
            std::cin >> a[j][i];
            a[j][i] = (a[j][i] << 1) + 1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        std::sort(a[i] + 1, a[i] + 1 + s);
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];

            for(int k = 1; k <= s && j >= a[i][k]; ++k) {
                memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i][k]] + k * i);  
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 2e4 + 10;
int s, n, m;
int a[N][N], memo[M];

int main(void) {
    std::cin >> s >> n >> m;

    for(int i = 1; i <= s; ++i) {
        for(int j = 1; j <= n; ++j) {
            std::cin >> a[j][i];
            a[j][i] = (a[j][i] << 1) + 1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        std::sort(a[i] + 1, a[i] + 1 + s);
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 1; k <= s && j >= a[i][k]; ++k) {
                memo[j] = std::max(memo[j], memo[j - a[i][k]] + k * i);  
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}