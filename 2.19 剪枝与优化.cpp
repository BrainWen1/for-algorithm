//P1025 [NOIP 2001 提高组] 数的划分
#include <iostream>

int n, k, sum, ret;

void dfs(int pos, int val)
{
    //递归出口
    if(pos > k) {
        if(sum == n) {
            ret++;
        }
        return;
    }

    //枚举当前位置的所有可行选择
    for(int i = val; i <= n - k + 1; i++) {
        //可行性剪枝
        if(sum + i * (k - pos + 1) > n) {
            return;
        }

        sum += i;//加上当前值

        dfs(pos + 1, i);//等效性剪枝

        sum -= i;//回溯
    }
}

int main(void)
{
    std::cin >> n >> k;

    dfs(1, 1);

    std::cout << ret << std::endl;

    return 0;
}

//P10483 小猫爬山
#include <iostream>
#include <algorithm>

const int N = 18 + 5;
int n, w, car, ret = N;
int cat[N], sum[N];

void dfs(int pos)
{
    //递归出口
    if(car >= ret) {//最优性剪枝
        return;
    } else if(pos > n) {//更新答案与否
        ret = car;
        return;
    }

    //尝试找到一辆现成的车放置小猫
    for(int i = 1; i <= car; i++) {
        //可行性剪枝
        if(sum[i] + cat[pos] > w) {
            continue;
        }
        sum[i] += cat[pos];

        dfs(pos + 1);

        sum[i] -= cat[pos];//回溯
    }

    //重新开一辆车放置小猫
    sum[++car] = cat[pos];
    
    dfs(pos + 1);

    sum[car--] = 0;
}

int main(void)
{
    std::cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        std::cin >> cat[i];
    }

    //优化搜索顺序: 按小猫的重量从大到小枚举
    std::sort(cat + 1, cat + 1 + n, [](int& l, int& r)->bool {
        return l > r;
    });

    dfs(1);

    std::cout << ret << std::endl;

    return 0;
}