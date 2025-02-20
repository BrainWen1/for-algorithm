//509. 斐波那契数
#include <iostream>
#include <vector>

std::vector<int> mp(31, -1);

int fib(int n)
{
    //递归出口
    if(1 == n || 2 == n) {
        return 1;
    } else if(0 == n) {
        return 0;
    }

    //记忆化搜索:
    //查找该值是否已经计算过//未计算则计算赋值给数组后返回该值//计算过则直接返回该值
    if(-1 == mp[n]) {
        mp[n] = fib(n - 1) + fib(n - 2);
    }
    return mp[n];
}

int main(void)
{
    int n = 0;
    
    std::cin >> n;

    std::cout << fib(n) << std::endl;

    return 0;
}

//P1464 Function
#include <iostream>
#include <unordered_map>
#include <string>

//数据范围: [−9223372036854775808, 9223372036854775807] 
typedef long long LL;
std::unordered_map<std::string, LL> mp;//使用<string, LL> 存放计算过的答案以实现记忆化搜索

LL Function(LL a, LL b, LL c)
{
    //转为string类型,注意两个数中间加非数字字符以区分不同字符串
    std::string str = std::to_string(a) + " " + std::to_string(b) + " " + std::to_string(c);

    if(a <= 0 || b <= 0 || c <= 0) {//直接返回
        return 1;
    } else if(mp.count(str)) {//已经计算过,直接返回
        return mp[str];
    } else if(a > 20 || b > 20 || c > 20) {//未计算,计算后存入哈希表中
        mp[str] = Function(20, 20, 20);
    } else if(a < b && b < c) {
        mp[str] = Function(a, b, c - 1) + Function(a, b - 1, c - 1) - Function(a, b - 1, c);
    } else {
        mp[str] = Function(a - 1, b, c) + Function(a - 1, b - 1, c) + Function(a - 1, b, c - 1) - Function(a - 1, b - 1, c - 1);
    }
    return mp[str];//返回对应值
}

int main(void)
{
    LL a, b, c;
    while(std::cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)) {
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, Function(a, b, c));
    }

    return 0;
}

//P5635 【CSGRound1】天下第一
#include <iostream>

const int N = 1e4;
int T, p, x, y;
char memo[N][N];

int dfs(int x, int y)
{
    //记忆化搜索
    if(memo[x][y]) return memo[x][y];

    //标记当前状态已经访问过,如果下次再访问到这对(x,y),则说明陷入死循环无法分出胜负
    memo[x][y] = '3';

    //进入递归后最终返回的必然是表示胜负的1或2,或者表示平局的3
    //将答案记忆化后再返回
    if(0 == x) {
        return memo[x][y] = '1';
    } else if(0 == y) {
        return memo[x][y] = '2';
    } else {
        return memo[x][y] = dfs((x + y) % p, ((x + y) % p + y) % p);
    }
}

int main(void)
{
    std::cin >> T >> p;

    while(T--) {
        std::cin >> x >> y;
        int token = dfs(x, y);
        if(token == '1' || token == '2') {
            std::cout << token - '0' << std::endl;
        } else {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>

int T, p, x, y;
//使用STL:
//方案1: map<pair, int>哈希表不允许pair作为key,红黑树会超时
//方案2: unordered_map<string, int>哈希表配string同样会超时
std::unordered_map<std::string, int> memo;

int dfs(int x, int y)
{
    std::string str = std::to_string(x) + " " + std::to_string(y);
    //记忆化搜索
    if(memo[str]) return memo[str];

    //标记当前状态已经访问过,如果下次再访问到这对(x,y),则说明陷入死循环无法分出胜负
    memo[str] = 3;

    //进入递归后最终返回的必然是表示胜负的1或2,或者表示平局的3
    //将答案记忆化后再返回
    if(0 == x) {
        return memo[str] = 1;
    } else if(0 == y) {
        return memo[str] = 2;
    } else {
        return memo[str] = dfs((x + y) % p, ((x + y) % p + y) % p);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> T >> p;

    while(T--) {
        std::cin >> x >> y;
        int token = dfs(x, y);
        if(token == 1 || token == 2) {
            std::cout << token << std::endl;
        } else {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}

//P1434 [SHOI2002] 滑雪
#include <iostream>
#include <algorithm>

const int N = 100 + 10;
int n, m;
int a[N][N];//存放原始数据
int mp[N][N];//存放每个点的最长路径

//矩阵搜索方向向量
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y)
{
    //记忆化搜索
    if(mp[x][y]) {
        return mp[x][y];
    }

    int sum = 1;//一个点本身就是一个单位长度
    for(int i = 0; i < 4; i++) {
        int k = x + dx[i], p = y + dy[i];//方向向量计算上下左右的偏移量

        //可行性剪枝
        if(k < 1 || k > n || p < 1 || p > m) continue;//矩阵边界
        if(a[k][p] >= a[x][y]) continue;//向低处移动

        sum = std::max(sum, dfs(k, p) + 1);
    }

    //存放答案后再返回
    return mp[x][y] = sum;
}

int main(void)
{
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ret = std::max(ret, dfs(i, j));
        }
    }
    std::cout << ret << std::endl;

    return 0;
}