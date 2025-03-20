//P1910 L国的战斗之间谍
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 1e3 + 10;
int n, m, x;
struct node {
    int a;
    int b;
    int c;
}a[N];
int memo[N][M][M]; //这题不优化百分之百爆栈 -> (N * M * M) == 1e8 -> (1e8 * 4) bytes

int main(void) {
    std::cin >> n >> m >> x;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].a >> a[i].b >> a[i].c;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = x; k >= 0; --k) {
                memo[i][j][k] = memo[i - 1][j][k];

                if(j >= a[i].b && k >= a[i].c) {
                    memo[i][j][k] = std::max(memo[i][j][k], memo[i - 1][j - a[i].b][k - a[i].c] + a[i].a);
                }
            }
        }
    }
    std::cout << memo[n][m][x] << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 1e3 + 10;
int n, m, x;
struct node {
    int a;
    int b;
    int c;
}a[N];
int memo[M][M]; // M * M == 1e6

int main(void) {
    std::cin >> n >> m >> x;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].a >> a[i].b >> a[i].c;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= a[i].b; --j) {
            for(int k = x; k >= a[i].c; --k) {
                memo[j][k] = std::max(memo[j][k], memo[j - a[i].b][k - a[i].c] + a[i].a);
            }
        }
    }
    std::cout << memo[m][x] << std::endl;

    return 0;
}