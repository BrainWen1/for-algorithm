//P1910 L 国的战斗之间谍
#include <iostream>
#include <algorithm>

const int N = 100 + 10, M = 1e3 + 10;
int n, m, x;
class node{
public:
    int a;
    int b;
    int c;
}peo[N];
int memo[M][M];

int main(void) {
    std::cin >> n >> m >> x;

    for(int i = 1; i <= n; ++i) {
        std::cin >> peo[i].a >> peo[i].b >> peo[i].c;
    }

    //无非就是在 01背包 的基础上多加了一层限制, 只需多考虑一个元素即可
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= peo[i].b; --j) {
            for(int k = x; k >= peo[i].c; --k) {
                memo[j][k] = std::max(memo[j][k], memo[j - peo[i].b][k - peo[i].c] + peo[i].a);
            }
        }
    }
    std::cout << memo[m][x] << std::endl;

    return 0;
}