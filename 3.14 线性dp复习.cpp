//P1192 台阶问题
#include <iostream>

const int N = 1e5 + 10, MOD = 100003;
int n, k;
int memo[N];

int main(void) {
    std::cin >> n >> k;

    //状态表示
    //状态转移
    //拓扑顺序
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= k && i - j >= 0; ++j) {
            memo[i] = (memo[i] + memo[i - j]) % MOD;
        }
    }
    std::cout << memo[n] << std::endl;

    return 0;
}

//P1115 最大子段和
#include <iostream>
#include <algorithm>

typedef long long LL;
const int N = 2e5 + 10;
int n;
LL a[N], memo[N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    LL ret = 0;
    for(int i = 1; i <= n; ++i) {
        memo[i] = std::max(memo[i - 1] + a[i], a[i]);
        ret = std::max(ret, memo[i]);
    }
    std::cout << ret << std::endl;

    return 0;
}

//P1057 [NOIP 2008 普及组] 传球游戏
#include <iostream>

const int N = 30 + 10, M = 30 + 10;
int n, m;
int memo[M][N];

int main(void) {
    std::cin >> n >> m;

    //状态表示
    //状态转移
    //拓扑顺序
    memo[0][1] = 1;
    for(int i = 1; i <= m; ++i) {
        memo[i][1] = memo[i - 1][n] + memo[i - 1][2];
        for(int j = 2; j < n; ++j) {
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j + 1];
        }
        memo[i][n] = memo[i - 1][n - 1] + memo[i - 1][1];
    }
    std::cout << memo[m][1] << std::endl;

    return 0;
}

//P1541 [NOIP 2010 提高组] 乌龟棋
#include <iostream>
#include <algorithm>

const int N = 350 + 10, M = 40 + 10;
int n, m;
int a[N], b[5], memo[M][M][M][M];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int idx = 0;
    for(int i = 1; i <= m; ++i) {
        std::cin >> idx;
        b[idx]++;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memo[0][0][0][0] = a[1];
    for(int i = 0; i <= b[1]; ++i) {
        for(int j = 0; j <= b[2]; ++j) {
            for(int k = 0; k <= b[3]; ++k) {
                for(int g = 0; g <= b[4]; ++g) {
                    int len = 1 + i + j * 2 + k * 3 + g * 4;

                    if(i) memo[i][j][k][g] = std::max(memo[i][j][k][g], memo[i - 1][j][k][g] + a[len]);
                    if(j) memo[i][j][k][g] = std::max(memo[i][j][k][g], memo[i][j - 1][k][g] + a[len]);
                    if(k) memo[i][j][k][g] = std::max(memo[i][j][k][g], memo[i][j][k - 1][g] + a[len]);
                    if(g) memo[i][j][k][g] = std::max(memo[i][j][k][g], memo[i][j][k][g - 1] + a[len]);
                }
            }
        }
    }
    std::cout << memo[b[1]][b[2]][b[3]][b[4]] << std::endl;

    return 0;
}