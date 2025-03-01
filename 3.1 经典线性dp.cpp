//经典线性dp
//B3637 最长上升子序列
/*#include <iostream>

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
}*/

//NC226831【模板】最长上升子序列
// (贪心 + 二分) 优化动态规划
/*#include <iostream>
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
}*/

//P1091 [NOIP 2004 提高组] 合唱队形
/*#include <iostream>
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
}*/

//NC235624 牛可乐和最长公共子序列
#include <iostream>
#include <algorithm>

int main(void) {
    
}