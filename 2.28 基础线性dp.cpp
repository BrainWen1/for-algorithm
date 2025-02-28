//P1192 台阶问题
#include <iostream>

const int N = 1e5 + 10;
int n, k;
int memo[N];

int main(void)
{
    std::cin >> n >> k;

    //初始化
    memo[0] = 1;
    memo[1] = 1;
    
    //状态表达：memo[i] 表示 memo[0] 走到这个位置的可行路径数量
    //状态转移：到 memo[i] 有 k 条路径，每个位置存放的路径数量总和就是到 memo[i] 的路径总数
    //拓扑顺序：每次复用前 k 个位置的数据，从左到右即可
    //注意：若前面没有 k 个数字，则截断到 0 号位置
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k && i - j >= 0; j++) {
            memo[i] = (memo[i] + memo[i - j]) % 100003;
        }
    }

    std::cout << memo[n] << std::endl;

    return 0;
}

//P1115 最大子段和
#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;
int n;
int memo[N];

int main(void)
{
    std::cin >> n;

    //初始化
    int tmp = 0;
    std::cin >> memo[1];

    //状态表示：memo[i] 表示以当前位置为终点的最大子段和
    //状态转移：当前位置原始值为val, 则 memo[i] 是 memo[i - 1] + val 和 val 之间的较大值, 因为以当前位置为结尾的最大子段和只可能出现在这两个状态中
    //拓扑顺序：因为只需使用 memo[i - 1] 和当前位置的 val 值，故从左到右即可
    for(int i = 2; i <= n; i++) {
        std::cin >> tmp;
        memo[i] = std::max(memo[i - 1] + tmp, tmp);
    }
    
    int ret = memo[1];
    for(int i = 2; i <= n; i++) {
        ret = std::max(ret, memo[i]);
    }
    std::cout << ret << std::endl;

    return 0;
}

//P1057 [NOIP 2008 普及组] 传球游戏
#include <iostream>

const int N = 30 + 5;
int n, m;
int memo[N][N];

int main(void)
{
    std::cin >> n >> m;

    //初始化
    memo[0][1] = 1;
    memo[1][2] = 1;
    memo[1][n] = 1;

    //状态表示：memo[i][j] 表示经过 i 次传递后到达第 j 号人手中的方案数量
    //状态转移：memo[i][j] 为 memo[i - 1][j - 1] 和 memo[i - 1][j + 1]
    //         的总和，即经过 i - 1 次传递后到达其左右两个人手中的方案总数
    //拓扑顺序：因为只使用上一行的数据, 故从左到右即可
    //注意：对于 memo[i][1] 和 memo[i][n], 需要特殊处理使其首尾相连
    for(int i = 2; i <= m; i++) {//外循环为传递次数, 内循环为所有人
        //第 1 号
        memo[i][1] = memo[i - 1][2] + memo[i - 1][n];

        //中间 2 -> (n - 1) 号
        for(int j = 2; j < n; j++) {
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j + 1];
        }

        //第 n 号
        memo[i][n] = memo[i - 1][1] + memo[i - 1][n - 1];
    }

    std::cout << memo[m][1] << std::endl;

    return 0;
}

//P1541 [NOIP 2010 提高组] 乌龟棋
#include <iostream>
#include <algorithm>

const int N = 350 + 10 ,M = 40 + 5;
int n, m;
int x[N], cnt[5], memo[M][M][M][M];

int main(void)
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::cin >> x[i];
    }

    //统计每种牌的数量
    for(int i = 1; i <= m; i++) {
        int tmp = 0;
        std::cin >> tmp;
        cnt[tmp]++;
    }

    //初始化
    memo[0][0][0][0] = x[1];

    //状态表达：memo[a][b][c][d] 表示牌号为 1 2 3 4 的牌使用了 a b c d 张时的最大分数
    //状态转移：memo[a][b][c][d] 等于上一次操作对此次操作使用不同牌的四种情况加上当前位置的分数中的最大值
    //拓扑顺序：因为题目保证所有牌刚好能到达终点，故从小到大枚举使用的每一种牌数即可
    for(int a = 0; a <= cnt[1]; a++) {
        for(int b = 0; b <= cnt[2]; b++) {
            for(int c = 0; c <= cnt[3]; c++) {
                for(int d = 0; d <= cnt[4]; d++) {
                    int i = 1 + (1 * a) + (2 * b) + (3 * c) + (4 * d);//(+1) 是因为初始位置在下标为 1 的位置
                    int& val = memo[a][b][c][d];
                    if(a) val = std::max(val, memo[a - 1][b][c][d] + x[i]);
                    if(b) val = std::max(val, memo[a][b - 1][c][d] + x[i]);
                    if(c) val = std::max(val, memo[a][b][c - 1][d] + x[i]);
                    if(d) val = std::max(val, memo[a][b][c][d - 1] + x[i]);
                }
            }
        }
    }

    std::cout << memo[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << std::endl;

    return 0;
}