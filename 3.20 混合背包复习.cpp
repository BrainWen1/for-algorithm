//P1833 樱花
#include <iostream>
#include <algorithm>

const int N = 1e4 + 10, M = 1e3 + 10;
int n, m;
struct node {
    int t;
    int c;
    int p;
}a[N];
int memo[N][M];

int get_time() {
    int h1, m1, h2, m2;
    char ch;
    std::cin >> h1 >> ch >> m1 >> h2 >> ch >> m2;
    m1 += h1 * 60;
    m2 += h2 * 60;

    return (m2 - m1);
}

int main(void) {
    m = get_time();

    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].t >> a[i].c >> a[i].p;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[i][j] = memo[i - 1][j];

            if(a[i].p >= 1) { //01背包 多重背包
                for(int k = 1; k <= a[i].p && j >= a[i].t * k; ++k) {
                    memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i].t * k] + a[i].c * k);
                }
            } else if(j >= a[i].t) { //完全背包
                memo[i][j] = std::max(memo[i][j], memo[i][j - a[i].t] + a[i].c);
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 1e4 + 10, M = 1e3 + 10;
int n, m;
struct node {
    int t;
    int c;
    int p;
}a[N];
int memo[M];

int get_time() {
    int h1, m1, h2, m2;
    char ch;
    std::cin >> h1 >> ch >> m1 >> h2 >> ch >> m2;
    m1 += h1 * 60;
    m2 += h2 * 60;

    return (m2 - m1);
}

int main(void) {
    m = get_time();

    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].t >> a[i].c >> a[i].p;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        if(a[i].p >= 1) { //01背包 多重背包
            for(int j = m; j >= a[i].t; --j) {
                for(int k = 1; k <= a[i].p && j >= a[i].t * k; ++k) {
                    memo[j] = std::max(memo[j], memo[j - a[i].t * k] + a[i].c * k);
                }
            }
        } else if(j >= a[i].t) { //完全背包
            for(int j = 0; j <= m; ++j) {
                memo[j] = std::max(memo[j], memo[j - a[i].t] + a[i].c);
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}