//区间dp
//P1435 [IOI 2000] 回文字串
/*#include <iostream>
#include <algorithm>
#include <string>

const int N = 1e3 + 10;
int memo[N][N];

int main(void) {
    std::string str;
    std::cin >> str;

    int n = str.size();
    str = " " + str;
    
    //State representation: memo[i][j] -> from the i.th to the j.th of the string, the minimal numbers of chars to insert in that string to make the it palindrome.
    //State transition: memo[i][j] -> First: str[i] is equal to str[j], so we will find answer in memo[i + 1][j - 1]; Second: they are not equal, so we will find answer in (memo[i + 1][j] + 1) and (memo[i][j - 1] + 1), the answer is the minimal one.
    //Topological order: because of using the next row and the left elements in this row, we choose to traverse the matrix from n to 1, and from m to 1
    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if(str[i] == str[j]) {
                memo[i][j] = memo[i + 1][j - 1];
            } else {
                memo[i][j] = std::min(memo[i + 1][j], memo[i][j - 1]) + 1;
            }
        }
    }
    std::cout << memo[1][n] << std::endl;

    return 0;
}*/

//P2858 [USACO06FEB] Treats for the Cows G/S
/*#include <iostream>
#include <algorithm>

const int N = 2e3 + 10;
int n;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示：memo[i][j] -> 区间 [i, j] 中的零食的最大价值
    //状态转移：memo[i][j] -> 拿走 a[i] 或者 a[j], 值为 a[i] 或 a[j] 乘以当前经过的天数 (n - len + 1), 结果为二者最大值
    //拓扑顺序：由于循环是使用区间长度 len 和左端点 i, 即以对角线方向遍历, 故直接从小到大即可
    for(int len = 1; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            int d = n - len + 1;
            memo[i][j] = std::max(memo[i + 1][j] + a[i] * d, memo[i][j - 1] + a[j] * d);
        }
    }
    std::cout << memo[1][n] << std::endl;

    return 0;
}*/

//P1775 石子合并（弱化版）
/*#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 300 + 10;
int n;
int a[N], f[N], memo[N][N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        f[i] = f[i - 1] + a[i];//前缀和数组方便后续计算合并两堆石子的花费
    }

    //状态表示：memo[i][j] -> 于区间 [i, j] 中合并得到的最小花费
    //状态转移：以变量 mid 划分区间为 [i, mid] [mid + 1, j], 结果为左右区间的值加上将此两个区间合并所需的花费
    //拓扑顺序：以区间长度 len 和左端点 left 循环, 从小到大遍历即可
    //初始化：因为要求最小值, 若全初始化为 0, 则最终计算结果全会取到 0
    memset(memo, 0x3f, sizeof(memo));

    for(int i = 0; i <= n; ++i) {
        memo[i][i] = 0;
    }

    for(int len = 1; len <= n; ++len) {
        for(int left = 1; left + len - 1 <= n; ++left) {
            int right = left + len - 1;
            int sum = f[right] - f[left - 1];
            
            for(int mid = left; mid < right; ++mid) {
                memo[left][right] = std::min(memo[left][right], memo[left][mid] + memo[mid + 1][right] + sum);
            }
        }
    }
    std::cout << memo[1][n] << std::endl;

    return 0;
}*/

//P1880 [NOI1995] 石子合并
/*#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 200 + 10;
int n;
int a[N], f[N], memo[N][N], maxi[N][N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];//倍增 -> 处理环形数据
    }

    int m = (n << 1);

    //前缀和预处理数据
    for(int i = 1; i <= m; ++i) {
        f[i] = f[i - 1] + a[i];
    }

    //状态表示：memo[i][j] -> 于区间 [i, j] 中合并得到的最小花费, maxi[i][j] 为最大花费
    //状态转移：以变量 mid 划分区间为 [i, mid] [mid + 1, j], 结果为左右区间的值加上将此两个区间合并所需的花费
    //拓扑顺序：以区间长度 len 和左端点 left 循环, 从小到大遍历即可
    //初始化：因为要求最小值, 若全初始化为 0, 则最终计算结果全会取到 0
    memset(memo, 0x3f, sizeof(memo));
    memset(maxi, -0x3f, sizeof(maxi));
    for(int i = 1; i <= m; ++i) {
        memo[i][i] = 0;
        maxi[i][i] = 0;
    }

    for(int len = 1; len <= n; ++len) {
        for(int l = 1; l + len - 1 <= m; ++l) {
            int r = l + len - 1;
            int sum = f[r] - f[l - 1];

            for(int mid = l; mid < r; ++mid) {
                memo[l][r] = std::min(memo[l][r], memo[l][mid] + memo[mid + 1][r] + sum);
                maxi[l][r] = std::max(maxi[l][r], maxi[l][mid] + maxi[mid + 1][r] + sum);                
            }
        }
    }
    
    int minret = 0x3f3f3f3f, maxret = -0x3f3f3f3f;
    for(int i = 1; i <= m; ++i) {
        minret = std::min(minret, memo[i][i + n - 1]);
        maxret = std::max(maxret, maxi[i][i + n - 1]);
    }
    std::cout << minret << std::endl;
    std::cout << maxret << std::endl;

    return 0;
}*/

//