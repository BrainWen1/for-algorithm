//P1036 [NOIP 2002 普及组] 选数
#include <iostream>
#include <cmath>

const int N = 20 + 5;
int n, k;
int a[N];
int path, sum;

//判断是否为素数(或质数)
bool is_prime(int num)
{
    //初筛
    if(num <= 1) {
        return false;
    }
    else if(num <= 3) {
        return true;
    }
    else if(num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    //枚举
    int i = 5;
    int z = sqrt(num);
    while(i <= z) {
        if(num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

void dfs(int pos, int index)//从当前index开始向后枚举,可以保证枚举的数字不重复
{
    //递归出口
    if(pos > k) {
        //如果当前和为素数,结果加1
        if(is_prime(path)) sum++;
        return;
    }

    //枚举当前位置的值的选择
    for(int i = index; i <= n; i++) {
        path += a[i];
        dfs(pos + 1, i + 1);//进入下一个位置的选择
        path -= a[i];
    }
}

int main(void)
{
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    dfs(1, 1);

    std::cout << sum << std::endl;

    return 0;
}

//P9241 [蓝桥杯 2023 省 B] 飞机降落
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 10 + 5;
int T, n;
struct node
{
    int t;
    int d;
    int l;
}a[N];
bool st[N];

bool dfs(int pos, int end)
{
    //所有飞机都放进去了
    if(pos > n) {
        return true;
    }

    //枚举当前位置的飞机的选择
    for(int i = 1; i <= n; i++) {
        //此飞机已经选择过
        if(st[i]) {
            continue;
        }

        //此飞机坚持不到上一架飞机离开跑道
        if(end > a[i].t + a[i].d) {
            continue;
        }

        //将此飞机放入队列
        st[i] = true;

        //计算当前飞机的结束时间
        int newend = std::max(end, a[i].t) + a[i].l;

        //进入下一架飞机的选择
        if(dfs(pos + 1, newend)) {
            return true;
        }

        //回溯
        st[i] = false;
    }

    //若循环结束还没有退出当前层次的函数递归并返回true,则此位置后无法将所有飞机放入队列
    return false;
}

int main(void)
{
    std::cin >> T;

    while(T--) {
        std::cin >> n;

        for(int i = 1; i <= n; i++) {
            std::cin >> a[i].t >> a[i].d >> a[i].l;
        }

        if(dfs(1, 0)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }

        //bool数组st不会被覆盖,应手动重置为全false
        memset(st, false, sizeof(st));
    }
    return 0;
}

//P1219 [USACO1.5] 八皇后 Checker Challenge
#include <iostream>
#include <vector>

const int N = 13 + 5;
int n, sum;
std::vector<int> path;
//   列      主对角线     副对角线
bool st1[N], st2[2 * N], st3[2 * N];

void dfs(int pos)
{
    //递归出口
    if(pos > n) {
        sum++;

        //只输出字典序前三的排列组合
        if(sum <= 3) {
            for(int i = 0; i < n; i++) {
                std::cout << path[i] << ' ';
             }
             std::cout << std::endl;
        }
        return;
    }

    for(int i = 1; i <= n; i++) {
        //剪枝
        if(st1[i] || st2[i - pos + n] || st3[i + pos]) {
            continue;
        }

        //选取当前位置(pos, i)放置棋子
        path.push_back(i);
        st1[i] = st2[i - pos + n] = st3[i + pos] = true;

        //进入下一行的棋子位置选择
        dfs(pos + 1);

        //回溯
        path.pop_back();
        st1[i] = st2[i - pos + n] = st3[i + pos] = false;
    }
}

int main(void)
{
    std::cin >> n;

    dfs(1);

    std::cout << sum << std::endl;

    return 0;
}

//P1784 数独
#include <iostream>

const int N = 10;
int a[N][N];
bool row[N][N], col[N][N], matrix[N][N][N];

bool dfs(int x, int y)
{
    //先处理换行
    if(y >= 9) {
        x++;
        y = 0;
    }

    //判断是否填满棋盘
    if(x >= 9) {
        return true;
    }

    //如果当前位置原本就有值,直接进入下一个位置的判断
    if(a[x][y]) {
        return dfs(x, y + 1);
    }

    for(int i = 1; i <= 9; i++) {
        //剪枝
        if(row[x][i] || col[y][i] || matrix[x / 3][y / 3][i]) {
            continue;
        }

        //在当前位置放入i
        row[x][i] = col[y][i] = matrix[x / 3][y / 3][i] = true;
        a[x][y] = i;

        //进入下一个位置的判断
        if(dfs(x, y + 1)) {
             return true;
         }

         //回溯
        row[x][i] = col[y][i] = matrix[x / 3][y / 3][i] = false;
        a[x][y] = 0;
    }
    return false;
}

int main(void)
{
    int val = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cin >> val;
            if(0 == val) {
                continue;
            }

            //填充原始值,并将相应行列和矩阵的对应值标true
            a[i][j] = val;
            row[i][val] = true;
            col[j][val] = true;
            matrix[i / 3][j / 3][val] = true;
        }
    }

    dfs(0, 0);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}