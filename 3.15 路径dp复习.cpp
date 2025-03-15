//路径dp
//DP11 矩阵的最小路径和
#include <iostream>

const int N = 500 + 10, INF = 0x3f3f3f3f;
int n, m;
int a[N][N], memo[N][N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 2; i <= n; ++i) {
        memo[i][0] = INF;
    }
    for(int i = 2; i <= m; ++i) {
        memo[0][i] = INF;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            memo[i][j] = std::min(memo[i - 1][j], memo[i][j - 1]) + a[i][j];
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//NC53675「木」迷雾森林
#include <iostream>
#include <algorithm>

const int N = 3e3 + 10;
int n, m;
int a[N][N], memo[N][N];

template<class T> inline void read(T &res)
{
    char c = 0;
    T flag = 1;
    
    while((c = getchar()) <  '0' || c >  '9') if(c == '-') flag = -1;
    res = c - '0';
    
    while((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
    
    res *= flag;
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            read(a[i][j]);
        }
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memo[n][0] = 1;
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j]) {
                continue;
            }

            memo[i][j] = (memo[i + 1][j] + memo[i][j - 1]) % 2333;
        }
    }
    std::cout << memo[1][m] << std::endl;

    return 0;
}

//P1002 [NOIP 2002 普及组] 过河卒
#include <iostream>

typedef long long LL;
const int N = 20 + 10;
int n, m, x, y;
LL memo[N][N];

int dx[] = { 0,-2,-2,-1,-1, 1, 1, 2, 2 };
int dy[] = { 0,-1, 1,-2, 2,-2, 2,-1, 1 };

int main(void) {
    std::cin >> n >> m >> x >> y;
    n++; m++; x++; y++;

    //状态表示
    //状态转移
    //拓扑顺序
    memo[1][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if((i == x && j == y) || (i != x && j != y && abs(i - x) + abs(j - y) == 3)) {
                continue;
            }

            memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//P1004 [NOIP 2000 提高组] 方格取数
#include <iostream>

const int N = 9 + 5;
int n;
int a[N][N], memo[N << 1][N][N];

int main(void) {
    std::cin >> n;

    int x, y, val;
    while(std::cin >> x >> y >> val && (x || y || val)) {
        a[x][y] = val;
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int sum = 2; sum <= (n << 1); ++sum) {
        for(int i1 = 1; i1 <= n; ++i1) {
            for(int i2 = 1; i2 <= n; ++i2) {
                int j1 = sum - i1, j2 = sum - i2;
                if(j1 < 1 || j1 > n || j2 < 1 || j2 > n) {
                    continue;
                }
                
                val = 0;
                val = std::max(val, memo[sum - 1][i1 - 1][i2 - 1]);
                val = std::max(val, memo[sum - 1][i1][i2 - 1]);
                val = std::max(val, memo[sum - 1][i1 - 1][i2]);
                val = std::max(val, memo[sum - 1][i1][i2]);

                if(i1 == i2) {
                    memo[sum][i1][i2] = val + a[i1][j1];
                } else {
                    memo[sum][i1][i2] = val + a[i1][j1] + a[i2][j2];
                }
            }
        }
    }
    std::cout << memo[n << 1][n][n] << std::endl;

    return 0;
}