//⼊⻔：从记忆化搜索到动态规划
//P10250 [GESP样题 六级] 下楼梯
#include <iostream>

typedef unsigned long long ULL;
const int N = 60 + 10;
ULL n;
ULL memo[N];

int main(void)
{
    std::cin >> n;

    //初始化前 3 或 4 个 memo 值便于直接使用状态转移公式计算后续值
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    //状态：memo[i] 表示 memo[0] 走到这个位置的可行路径数量
    //状态转移：到 memo[i] 有如下公式中的三条路径，每个位置存放的路径数量总和就是到 memo[i] 的路径总数
    //拓扑顺序：每次复用前三个位置的数据，从左到右即可
    for(int i = 4; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }

    //最后一个位置存的就是从开始到末尾的可行路径数
    std::cout << memo[n] << std::endl;

    return 0;
}
//空间优化
#include <iostream>

typedef long long LL;
const int N = 60 + 10;
int n;

int main(void)
{
    std::cin >> n;

    LL a = 1, b = 1, c = 2;
    for(int i = 3; i <= n; i++) {
        LL sum = a + b + c;
        a = b;
        b = c;
        c = sum;
    }
    
    if(1 == n) {
        std::cout << b << std::endl;
    } else {
        std::cout << c << std::endl;
    }

    return 0;
}

//P1216 [IOI 1994] 数字三角形 Number Triangles
#include <iostream>
#include <algorithm>

const int N = 1e3 + 10;
int n;
int a[N][N], memo[N][N];

int main(void)
{
    std::cin >> n;

    //存下金字塔
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            std::cin >> a[i][j];
        }
    }

    //状态：memo[i][j] 表示 memo[1][1] 走到这个位置的最大带权路径
    //状态转移：金字塔中左方和右方的 memo 值中的最大值(相同子问题) + 当前位置的原始值
    //拓扑顺序：使用的是上一行的 memo 值和当前行的 a 值，从左到右即可
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            memo[i][j] = std::max(memo[i - 1][j - 1], memo[i - 1][j]) + a[i][j];
        }
    }

    //遍历最后一行找出最大值
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        ret = std::max(ret, memo[n][i]);
    }
    std::cout << ret << std::endl;

    return 0;
}
//空间优化
#include <iostream>
#include <algorithm>

const int N = 1e3 + 10;
int n;
int a[N][N], memo[N];

int main(void)
{
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            std::cin >> a[i][j];
        }
    }

    //改用一维备忘录
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) {
            memo[j] = std::max(memo[j - 1], memo[j]) + a[i][j];
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        ret = std::max(ret, memo[i]);
    }
    std::cout << ret << std::endl;

    return 0;
}