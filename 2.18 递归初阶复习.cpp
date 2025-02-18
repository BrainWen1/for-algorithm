//1205: 汉诺塔问题
#include <iostream>

void HanNuoTa(int n, char F, char A, char T)
{
    if(0 == n) {//没有圆盘时退出递归
        return;
    }
    HanNuoTa(n - 1, F, T, A);//将上面(n - 1)个圆盘放到辅助杆上
    printf("%c->%d->%c\n", F, n, T);//将最下面的一个放到终点杆上
    HanNuoTa(n - 1, A, F, T);//将辅助杆上的圆盘放到终点杆上
}

int main(void)
{
    int n;
    char F, A, T;
    scanf("%d %c %c %c", &n, &F, &T, &A);

    HanNuoTa(n, F, A, T);

    return 0;
}

//P10457 占卜DIY
#include <iostream>

const int N = 13 + 5;
int pile[N][5];
int count[N];

void Game(int val)
{
    //拿到K时这一轮结束
    if(13 == val) {
        return;
    }

    //表示当前堆里存在几张朝上的牌数
    count[val]++;

    //拿出当前堆最下面那张牌并加入下一个判断
    Game(pile[val][5 - count[val]]);
}

int main(void)
{
    for(int i = 1; i <= 13; i++) {
        for(int j = 1; j <= 4; j++) {
            char ch;
            std::cin >> ch;

            //预处理所有牌的值,便于当作数组下标查询堆序
            if(ch >= '2' && ch <= '9') pile[i][j] = ch - '0';
            else if('A' == ch) pile[i][j] = 1;
            else if('0' == ch) pile[i][j] = 10;
            else if('J' == ch) pile[i][j] = 11;
            else if('Q' == ch) pile[i][j] = 12;
            else if('K' == ch) pile[i][j] = 13;
        }
    }

    //一共有4条命
    for(int i = 1; i <= 4; i++) {
        Game(pile[13][i]);
    }

    //统计count数组中4的数量,即有四张牌面朝上的牌的堆数
    int res = 0;
    for(int i = 1; i <= 13; i++) {
        if(4 == count[i]) res++;
    }
    std::cout << res << std::endl;

    return 0;
}

//P1087 [NOIP 2004 普及组] FBI 树
#include <iostream>

const int N = 10 + 5;
int n;
int f[1 << N];//前缀和数组,便于判断某一段是什么类型的字符串

void dfs(int left, int right)
{
    //因为所有值只有0和1两种,故可以根据sum的值判断字符串类型
    char ch = 0;
    int sum = f[right] - f[left - 1];
    if(sum == 0) ch = 'B';
    else if(sum == right - left + 1) ch = 'I';
    else ch = 'F';

    //递归出口
    if(left >= right) {
        std::cout << ch;
        return;
    }

    //后序遍历
    int mid = (left + right) / 2;
    dfs(left, mid);//左子树
    dfs(mid + 1, right);//右子树
    
    std::cout << ch;//根节点
}

int main(void)
{
    std::cin >> n;
    n = (1 << n);

    for(int i = 1; i <= n; i++) {
        //因为输入一行字符串没有空格,所以需要使用char类型来读取数据
        char tmp = 0;
        std::cin >> tmp;
        
        //处理前缀和数组
        if(tmp == '1') f[i] = f[i - 1] + 1;
        else f[i] = f[i - 1];
    }

    dfs(1, n);

    return 0;
}

//P1427 小鱼的数字游戏
//题解1: 递归
#include <iostream>

void dfs()
{
    int val;
    std::cin >> val;

    //结束值为0
    if(0 == val) {
        return;
    }

    //未结束则进入递归
    dfs();

    //上一个递归结束再输出先输入的值
    std::cout << val << ' ';
}

int main(void)
{
    dfs();
    std::cout << std::endl;

    return 0;
}

//题解2: 栈
#include <iostream>
#include <stack>

int main(void)
{
    std::stack<int> st;
    int val = 0;

    //当正常读取并且读取值不为结束值0时,进栈
    while(std::cin >> val && val != 0) {
        st.push(val);
    }

    //当栈不为空时,依次输出栈顶元素并pop掉栈顶元素
    while(!st.empty()) {
        std::cout << st.top() << ' ';
        st.pop();
    }
    std::cout << std::endl;

    return 0;
}

//B2064 斐波那契数列: 记忆化搜索优化
#include <iostream>
#include <vector>

const int N = 30 + 5;
std::vector<int> memo(N, -1);//记忆数组

int fibonacci(int n)
{
    //递归出口
    if(1 == n || 2 == n) {
        return 1;
    }

    //判断当前斐波那契数是否已经计算过,如果没有,计算后存储并返回;否则直接返回
    if(memo[n] == -1) {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return memo[n];
}

int main(void)
{
    int T = 0, n = 0;
    std::cin >> T;

    while(T--) {
        std::cin >> n;
        std::cout << "Answer: " << fibonacci(n) << std::endl;
    }

    return 0;
}