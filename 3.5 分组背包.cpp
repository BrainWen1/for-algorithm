//P1757 通天之分组背包
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10, K = 100 + 10;
int n, m;
std::vector<PII> group[K];
int memo[K][N];

int main(void) {
    std::cin >> m >> n;

    int len = 0;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        group[c].push_back({a, b});
        len = std::max(len, c);
    }

    //状态表示：memo[i][j] -> 在前 i 个组别中挑选出总重量不超过 j 的最大价值方案
    //状态转移：memo[i][j] -> 枚举从当前组别 group[i] 中挑选物品的的情况
    //拓扑顺序：因为要使用上一行的数据, 故从上到下即可
    for(int i = 1; i <= len; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];//不选
            for(PII e : group[i]) {//在当前组别中挑选一个
                if(j >= e.first) {
                    memo[i][j] = std::max(memo[i][j], memo[i - 1][j - e.first] + e.second);
                }
            }
        }
    }
    std::cout << memo[len][m] << std::endl;

    return 0;
}
///空间优化
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10, K = 100 + 10;
int n, m;
std::vector<PII> group[K];
int memo[N];

int main(void) {
    std::cin >> m >> n;

    int len = 0;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        group[c].push_back({a, b});
        len = std::max(len, c);
    }

    //空间优化时, 因为要使用上一行的左边的数据, 故需要从右往左遍历 memo 数组
    for(int i = 1; i <= len; ++i) {
        for(int j = m; j >= 0; --j) {
            for(PII e : group[i]) {
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
int a[N][M];
int memo[N][M];

int main(void) {
    std::cin >> s >> n >> m;

    for(int i = 1; i <= s; ++i) {
        for(int j = 1; j <= n; ++j) {
            int x = 0;
            std::cin >> x;
            a[j][i] = 2 * x + 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        std::sort(a[i] + 1, a[i] + 1 + s);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            memo[i][j] = memo[i - 1][j];
            for(int k = 1; k <= s; ++k) {
                if(j >= a[i][k]) {
                    memo[i][j] = std::max(memo[i][j], memo[i - 1][j - a[i][k]] + k * i);
                }
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
int a[N][M];
int memo[M];

int main(void) {
    std::cin >> s >> n >> m;

    for(int i = 1; i <= s; ++i) {
        for(int j = 1; j <= n; ++j) {
            int x = 0;
            std::cin >> x;
            a[j][i] = 2 * x + 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        std::sort(a[i] + 1, a[i] + 1 + s);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            for(int k = 1; k <= s; ++k) {
                if(j >= a[i][k]) {
                    memo[j] = std::max(memo[j], memo[j - a[i][k]] + k * i);
                }
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}