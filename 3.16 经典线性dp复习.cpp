//B3637 最长上升子序列
#include <iostream>
#include <algorithm>

const int N = 5e3 + 10;
int n;
int a[N], memo[N];

int main(void) {
    std::cin >>  n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    a[0] = -1;
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        memo[i] = 1;
        for(int j = 1; j <= i - 1; ++j) {
            if(a[i] > a[j]) {
                memo[i] = std::max(memo[i], memo[j] + 1);
            }
        }

        ret = std::max(ret, memo[i]);
    }
    std::cout << ret << std::endl;

    return 0;
}

//NC226831【模板】最长上升子序列
#include <iostream>
#include <algorithm>

const int N = 1e5 + 10;
int n, len;
int a[N], memo[N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        if(a[i] > memo[len] || len == 0) {
            memo[++len] = a[i];
        } else {
            int l = 1, r = len;
            while(l < r) {
                int mid = (l + r) / 2;
                if(memo[mid] >= a[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            memo[l] = a[i];
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
int a[N], l[N], r[N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        l[i] = 1;
        for(int j = 1; j < i; ++j) {
            if(a[i] > a[j]) {
                l[i] = std::max(l[i], l[j] + 1);
            }
        }
    }
    for(int i = n; i >= 1; --i) {
        r[i] = 1;
        for(int j = n; j > i; --j) {
            if(a[i] > a[j]) {
                r[i] = std::max(r[i], r[j] + 1);
            }
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        ret = std::max(ret, l[i] + r[i] - 1);
    }
    std::cout << n - ret << std::endl;

    return 0;
}

//NC235624牛可乐和最长公共子序列
#include <iostream>
#include <string>
#include <algorithm>

const int N = 5e3 + 10;
int memo[N][N];
std::string s, t;

int main(void) {
    while(std::cin >> s >> t) {
        int n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        //状态表示
        //状态转移
        //拓扑顺序
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i] == t[j]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                } else {
                    memo[i][j] = std::max(memo[i][j - 1], memo[i - 1][j]);
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
std::string s, t;
int memo[N][N];

int main(void) {
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;

    //状态表示
    //状态转移
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        memo[i][0] = i;
    }
    for(int i = 1; i <= m; ++i) {
        memo[0][i] = i;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i] == t[j]) {
                memo[i][j] = memo[i - 1][j - 1];
            } else {
                memo[i][j] = std::min(memo[i][j - 1], std::min(memo[i - 1][j], memo[i - 1][j - 1])) + 1;
            }
        }
    }
    std::cout << memo[n][m] << std::endl;

    return 0;
}