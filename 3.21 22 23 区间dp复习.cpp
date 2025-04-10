//P1435 [IOI 2000] 回文字串
#include <iostream>
#include <algorithm>
#include <string>

const int N = 1e3 + 10;
std::string str;
int memo[N][N];

int main(void) {
    std::cin >> str;

    int n = str.size();
    str = " " + str;

    //状态表示
    //状态转移
    //拓扑顺序
    for(int len = 2; len <= n; ++len) {
        for(int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;

            if(str[l] == str[r]) {
                memo[l][r] = memo[l + 1][r - 1];
            } else {
                memo[l][r] = std::min(memo[l][r - 1], memo[l + 1][r]) + 1;
            }
        }
    }
    std::cout << memo[1][n] << std::endl;

    return 0;
}

//P2858 [USACO06FEB] Treats for the Cows G/S
#include <iostream>
#include <algorithm>

const int N = 2e3 + 10;
int n;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        memo[i][i] = a[i] * n;
    }

    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            int val = n - len + 1;

            memo[i][j] = std::max(memo[i + 1][j] + a[i] * val, memo[i][j - 1] + a[j] * val);
        }
    }
    std::cout << memo[1][n] << std::endl;

    return 0;
}

//P1775 石子合并（弱化版）
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 300 + 10;
int n;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n;
    
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i] += a[i - 1]; //前缀和
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memset(memo, 0x3f, sizeof(memo));
    for(int i = 0; i <= n; ++i) {
        memo[i][i] = 0;
    }
    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            int sum = a[j] - a[i - 1];

            for(int k = i; k < j; ++k) {
                memo[i][j] = std::min(memo[i][j], memo[i][k] + memo[k + 1][j] + sum);
            }
        }
    }
    std::cout << memo[1][n] << std::endl;

    return 0;
}

//P1880 [NOI1995] 石子合并
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = (100 << 1) + 10;
int n;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    int m = n << 1;

    for(int i = 1; i <= m; ++i) {
        a[i] += a[i - 1];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    memset(memo, 0x3f, sizeof(memo));
    for(int i = 0; i <= m; ++i) {
        memo[i][i] = 0;
    }

    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= m; ++i) {
            int j = i + len - 1;
            int sum = a[j] - a[i - 1];

            for(int k = i; k < j; ++k) {
                memo[i][j] = std::min(memo[i][j], memo[i][k] + memo[k + 1][j] + sum);
            }
        }
    }
    int mini = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++i) {
        mini = std::min(mini, memo[i][i + n - 1]);
    }
    std::cout << mini << std::endl;

    memset(memo, 0, sizeof(memo));

    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= m; ++i) {
            int j = i + len - 1;
            int sum = a[j] - a[i - 1];

            for(int k = i; k < j; ++k) {
                memo[i][j] = std::max(memo[i][j], memo[i][k] + memo[k + 1][j] + sum);
            }
        }
    }
    int maxi = -0x3f3f3f3f;
    for(int i = 1; i <= n; ++i) {
        maxi = std::max(maxi, memo[i][i + n - 1]);
    }
    std::cout << maxi << std::endl;

    return 0;
}

//P3146 [USACO16OPEN] 248 G
#include <iostream>
#include <algorithm>

const int N = 248 + 10;
int n;
int a[N], memo[N][N];

int main(void) {
    std::cin >> n;

    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        memo[i][i] = a[i];
        ret = std::max(ret, a[i]);
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;

            for(int k = i; k < j; ++k) {
                if(memo[i][k] && memo[i][k] == memo[k + 1][j]) {
                    memo[i][j] = std::max(memo[i][j], memo[i][k] + 1);
                }
            }
            ret = std::max(ret, memo[i][j]);
        }
    }
    std::cout << ret << std::endl;

    return 0;
}