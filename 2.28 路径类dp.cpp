//DP11 矩阵的最小路径和
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500 + 10, INF = 0x3f3f3f3f;
int n, m;
int a[N][N], memo[N][N];

int main() {
    std::cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }

    //处理边界情况
    for(int i = 2; i <= n; i++) {
        memo[i][0] = INF;
    }
    for(int i = 2; i <= m; i++) {
        memo[0][i] = INF;
    }

    //状态表示：memo[i][j] 表示从左上角 memo[1][1] 到此位置的最小带权路径
    //状态转移：memo[i][j] 为左方和上方的 memo 值中的较小值加上自己的 a 值
    //拓扑顺序：每次使用的是左边和上面的数据, 故需从上往下、从左往右遍历
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            memo[i][j] = std::min(memo[i - 1][j], memo[i][j - 1]) + a[i][j];
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//NC53675.「木」迷雾森林
#include <iostream>
#include <algorithm>

const int N = 3e3 + 10;
int n, m;
int a[N][N], memo[N][N];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    std::cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }
    
    //状态表示：memo[i][j] 表示从左下角 memo[n][1] 走到当前位置的方案数
    //状态转移：memo[i][j] 为从 memo[i][j - 1] 和 memo[i + 1][j] (若存在) 中的方案数之和
    //拓扑顺序：因为是从左下角走到右上角，故需从下往上，从左往右
    memo[n][0] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            if(0 == a[i][j]) {
                memo[i][j] = (memo[i][j - 1] + memo[i + 1][j]) % 2333;
            }
        }
    }
    std::cout << memo[1][m] << std::endl;
    
    return 0;
}

//P1002 [NOIP 2002 普及组] 过河卒
#include <iostream>

typedef long long LL;
const int N = 20 + 5;
int n, m, x, y;
LL memo[N][N];

//马的所有控制点
int dx[] = { 0,-2,-2,-1,-1, 1, 1, 2, 2 };
int dy[] = { 0,-1, 1, 2,-2, 2,-2, 1,-1 };

int main(void) {
    std::cin >> n >> m >> x >> y;
    n++;
    m++;
    x++;
    y++;

    //初始化
    for(int k = 0; k < 9; k++) {
        int i = x + dx[k];
        int j = y + dy[k];
        if(i < 1 || i > n || y < 1 || y > m) {
            continue;
        }
        memo[i][j] = -1;
    }

    //状态表示：memo[i][j] 表示从左上角 memo[0][0] 到达此位置的路径数
    //状态转移：memo[i][j] 由左和上(若存在)的路径数之和得到
    //拓扑顺序：由于是从左上角走到右下角, 故从上到下、从左到右即可
    memo[1][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++) {
            if(-1 != memo[i][j]) {
                if(memo[i][j - 1] != -1) {
                    memo[i][j] += memo[i][j - 1];
                }
                if(memo[i - 1][j] != -1) {
                    memo[i][j] += memo[i - 1][j];
                }
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}

//P1004 [NOIP 2000 提高组] 方格取数
#include <iostream>
#include <algorithm>

const int N = 10 + 5;
int n;
int a[N][N], memo[2 * N][N][N];

int main(void)
{
    std::cin >> n;

    int x, y, val;
    while(std::cin >> x >> y >> val && (x || y || val)) {
        a[x][y] = val;
    }

    //状态表示：memo[s][i1][i2] 表示两个人同时同步从左上角走到 (i1, j1) (i2, j2) 位置的最大带权路径
    //状态转移：memo[s][i1][i2] 由两个人的左和上组合而成的四种路径中的最大值加两个人当前位置的值得到
    //拓扑顺序：因为是从左上角走到右下角, 所有从上到下、从左到右即可
    for(int s = 2; s <= n + n; s++) {
        for(int i1 = 1; i1 <= n; i1++) {
            for(int i2 = 1; i2 <= n; i2++) {
                int j1 = s - i1, j2 = s - i2;

                if(j1 < 1 || j1 > n || j2 < 1 || j2 > n) {
                    continue;
                }

                int maxi = memo[s - 1][i1][i2];
                maxi = std::max(maxi, memo[s - 1][i1][i2 - 1]);
                maxi = std::max(maxi, memo[s - 1][i1 - 1][i2]);
                maxi = std::max(maxi, memo[s - 1][i1 - 1][i2 - 1]);

                if(i1 == i2) {
                    memo[s][i1][i2] = maxi + a[i1][j1];
                } else {
                    memo[s][i1][i2] = maxi + a[i1][j1] + a[i2][j2];
                }
            }
        }
    }
    std::cout << memo[n + n][n][n] << std::endl;

    return 0;
}