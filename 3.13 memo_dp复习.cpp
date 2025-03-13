//P10250 [GESP样题 六级] 下楼梯
#include <iostream>

typedef long long LL;
const int N = 60 + 10;
int n;
LL memo[N];

int main(void) {
    std::cin >> n;

    //状态表示
    //状态转移
    //拓扑顺序
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for(int i = 4; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    std::cout << memo[n] << std::endl;

    return 0;
}
//空间优化
#include <iostream>

typedef long long LL;
int n;

int main(void) {
    std::cin >> n;

    //状态表示
    //状态转移
    //拓扑顺序
    LL a = 1, b = 2, c = 4;
    for(int i = 4; i <= n; ++i) {
        int tmp = a + b + c;
        a = b;
        b = c;
        c = tmp;
    }
    if(n == 2) {
        std::cout << b << std::endl;
    } else if(n == 1) {
        std::cout << a << std::endl;
    } else {
        std::cout << c << std::endl;
    }

    return 0;
}

//P1216 [IOI 1994] 数字三角形 Number Triangles
#include <iostream>

const int N = 1e3 + 10;
int n;
int a[N][N], memo[N][N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            std::cin >> a[i][j];
        }
    }

    //状态表示
    //状态表示
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            memo[i][j] = std::max(memo[i - 1][j], memo[i - 1][j - 1]) + a[i][j];
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        ret = std::max(ret, memo[n][i]);
    }

    std::cout << ret << std::endl;

    return 0;
}
//空间优化
#include <iostream>

const int N = 1e3 + 10;
int n;
int a[N][N], memo[N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            std::cin >> a[i][j];
        }
    }

    //状态表示
    //状态表示
    //拓扑顺序
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j >= 1; --j) {
            memo[j] = std::max(memo[j], memo[j - 1]) + a[i][j];
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        ret = std::max(ret, memo[i]);
    }

    std::cout << ret << std::endl;

    return 0;
}