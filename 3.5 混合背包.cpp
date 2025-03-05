//P1833 樱花
#include <iostream>
#include <algorithm>

const int N = 1e4 + 10, T = 1e3 + 10;
int n, m;
class node {
public:
    int t;
    int c;
    int p;
}a[N];
int memo[T];

int get_time() {
    int t1, t2, t3, t4;
    char ch;
    std::cin >> t1 >> ch >> t2 >> t3 >> ch >> t4;

    int hour = t3 - t1;
    int minu = t4 - t2;
    if(minu < 0) {
        hour--;
        minu += 60;
    }
    return hour * 60 + minu;
}

int main(void) {
    m = get_time();

    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].t >> a[i].c >> a[i].p;
    }

    //状态表示：memo[j] -> 在前 i 棵树中挑选总时间不超过 j 的最大价值方案
    //状态转移：memo[j] -> 根据可观看次数不同划分为不同情况处理
    //拓扑顺序：由于要使用上一行的数据, 故从上往下即可
    for(int i = 1; i <= n; ++i) {
        if(0 == a[i].p) {//完全背包
            for(int j = a[i].t; j <= m; ++j) {
                memo[j] = std::max(memo[j], memo[j - a[i].t] + a[i].c);
            }
        } else {//01背包和多重背包
            for(int j = m; j >= a[i].t; --j) {
                for(int k = 0; k <= a[i].p && j >= k * a[i].t; ++k) {
                    memo[j] = std::max(memo[j], memo[j - k * a[i].t] + k * a[i].c);
                }
            }
        }
    }
    std::cout << memo[m] << std::endl;

    return 0;
}