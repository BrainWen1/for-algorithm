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