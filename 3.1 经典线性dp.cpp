//B3637 最长上升子序列
#include <iostream>

const int N = 5000 + 10;
int n;
int a[N], memo[N];

int main(void) {
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        memo[i] = 1;
    }

    //状态表示：memo[i] 表示以 a[i] 结尾的最长上升子序列
    //状态转移：memo_left[i] 由左边的所有小于 a[i] 的位置中的最大的 memo_left 值加一得到
    //拓扑顺序：因为需要使用左边的数据，故从左到右即可
    int ret = 1;
    for(int i = 1; i <= n; i++) {
        int j = 1, maxi = 0;
        for(j = i - 1; j >= 1; j--) {
            if(a[i] > a[j] && memo[j] > maxi) {
                maxi = memo[j];
            }
        }

        memo[i] = maxi + 1;

        if(memo[i] > ret) {
            ret = memo[i];
        }
    }
    std::cout << ret << std::endl;

    return 0;
}

//NC226831【模板】最长上升子序列
// (贪心 + 二分) 优化动态规划
#include <iostream>
#include <algorithm>

const int N = 1e5 + 10;
int n;
int a[N], memo[N], len;

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        memo[i] = 1;
    }

    //状态表示：memo[i] 表示长度为 i 的所有上升子序列的末尾值中的最小值
    //状态转移：memo[i] 由原本存在的数和新遍历到的大于左边的 memo[i - 1] 数中的较小值
    //拓扑顺序：因为需要使用左边的数据，故从左到右即可
    for(int i = 1; i <= n; i++) {
        if(0 == len || a[i] > memo[len]) {
            memo[++len] = a[i];
        } else {
            int left = 1, right = len;
            while(left < right) {
                int mid = (left + right) / 2;
                if(memo[mid] >= a[i]) {
                    right = mid;
                } else {
                left = mid + 1;
                }
            }
            memo[left] = a[i];
        }
    }
    std::cout << len << std::endl;

    return 0;
}

//P1091 [NOIP 2004 提高组] 合唱队形
#include <iostream>
#include <algorithm>

const int N = 100 + 10;
int n;
int a[N], memo_left[N], memo_right[N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //状态表示：memo_left[i] 表示以 a[i] 为结尾的最长上升子序列; 类似的 memo_right[i] 表示以 a[i] 为起点的最长下降子序列
    //状态转移：memo_left[i] 由左边的所有小于 a[i] 的位置中的最大的 memo_left 值加一得到; 类似的 memo_right[i] 由右边所有小于 a[i] 的位置中的最大的 memo_right 值加一得到
    //拓扑顺序：显然 memo_left 需从左到右遍历, memo_right 需从右到左遍历
    for(int i = 1; i <= n; i++) {
        memo_left[i] = 1;
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                memo_left[i] = std::max(memo_left[i], memo_left[j] + 1);
            }
        }
    }
    for(int i = n; i >= 1; i--) {
        memo_right[i] = 1;
        for(int j = n; j > i; j--) {
            if(a[i] > a[j]) {
                memo_right[i] = std::max(memo_right[i], memo_right[j] + 1);
            }
        }
    }

    int maxi = 0;
    for(int i = 1; i <= n; i++) {
        maxi = std::max(maxi, memo_left[i] + memo_right[i] - 1);
    }
    std::cout << n - maxi << std::endl;

    return 0;
}

//NC235624 牛可乐和最长公共子序列
#include <iostream>
#include <algorithm>
#include <string>

const int N = 5e3 + 10;
int memo[N][N];

int main(void) {
    std::string s, t;
    while(std::cin >> s >> t) {
        int n = s.size();
        int m = t.size();
        s = " " + s;
        t = " " + t;

        //状态表示：memo[i][j] 表示以字符串 s 和 t 的第 i 个 和第 j 个字符结尾的最长公共子序列
        //状态转移：若 s[i] 等于 t[j], 则 memo[i][j] 等于前一个字符位置的 memo 值 memo[i - 1][j - 1] 加上一; 若二者不相等, 则可以分为三种情况并取三者中的较大值: 舍弃 s[i], 此时 memo[i][j] 等于 memo[i - 1][j] + 1; 舍弃 t[j]， 此时 memo[i][j] 等于 memo[i][j - 1] + 1; 将 s[i] 和 t[j] 都舍弃, 但是这种情况会包含在前两种情况中
        //拓扑顺序：由于计算 memo[i][j] 需要使用左和上面的数据, 故从上到下、从左到右即可
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i] == t[j]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                } else {
                    memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }
        std::cout << memo[n][m] << std::endl;
    }
    return 0;
}

//P2758 编辑距离
#include <iostream>
#include <algorithm>
#include <string>

const int N = 2e3 + 10;
int memo[N][N];

int main(void)
{
    std::string s, t;
    std::cin >> s >> t;

    int n = s.size(), m = t.size();

    s = " " + s;
    t = " " + t;

    //初始化外围一圈的数值, 因为当 s 或 t 为空字符串时也有其实际含义
    for(int i = 1; i <= n; i++) {
        memo[i][0] = i;
    }
    for(int i = 1; i <= m; i++) {
        memo[0][i] = i;
    }

    //状态表示：memo[i][j] 表示以字符串 s 和 t 的第 i 个 和第 j 个字符结尾的最少转换操作次数
    //状态转移：若 s[i] 等于 t[j], 则无需额外操作, 故 memo[i][j] 等于前一个字符位置的 memo 值 memo[i - 1][j - 1]; 若二者不相等, 则可以分为三种情况并取三者中的最小值: 删除 s[i], 此时 memo[i][j] 等于 memo[i - 1][j] + 1; 修改 s[i], 此时 memo[i][j] 等于 memo[i - 1][j - 1] + 1; 在 s[i] 后插入 t[j], 此时 memo[i][j] 等于 memo[i][j - 1] + 1
    //拓扑顺序：由于计算 memo[i][j] 需要使用左和上面的数据, 故从上到下、从左到右即可
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i] == t[j]) {
                memo[i][j] = memo[i - 1][j - 1];
            } else {
                memo[i][j] = std::min(memo[i - 1][j] + 1, std::min(memo[i - 1][j - 1] + 1, memo[i][j - 1] + 1));
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}