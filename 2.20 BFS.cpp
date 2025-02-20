//P1443 马的遍历
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstring>

const int N = 400 + 10;
int n, m, x, y;
int a[N][N];

//马的矩阵移动方向向量
int dx[] = { 2, 2, 1, 1,-1,-1,-2,-2 };
int dy[] = { 1,-1, 2,-2, 2,-2, 1,-1 };

void bfs()
{
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    a[x][y] = 0;//马的初始位置

    //层序遍历
    while(que.size()) {
        //拿出队头
        std::pair<int, int> tmp = que.front();
        que.pop();

        //查找队头位置下一步可到达的位置
        for(int k = 0; k < 8; k++) {
            int i = tmp.first + dx[k], j = tmp.second + dy[k];

            //可行性剪枝
            if(i < 1 || i > n || j < 1 || j > m) {//越界
                continue;
            }
            if(a[i][j] != -1) {//位置已有最小路径
                continue;
            }

            //合法位置最短路径更新为当前位置最短路径加1
            a[i][j] = a[tmp.first][tmp.second] + 1;

            //将该合法位置入队以进行下一轮查找
            que.push({i, j});
        }
    }
}

int main(void)
{
    std::cin >> n >> m >> x >> y;

    //初始值设为-1,没有在BFS中遍历到的位置的值不变,保持为-1
    memset(a, -1, sizeof(a));

    bfs();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cout << std::setw(5) << std::left << a[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}

//NC50041.kotori和迷宫
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

const int N = 30 + 10;
int n, m, x, y;
char a[N][N];//存迷宫
int b[N][N];//存BFS过程中的到达某点的最短路径

//矩阵移动方向向量
int dx[] = {0, 0, 1,-1};
int dy[] = {1,-1, 0, 0};

void bfs()
{
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    b[x][y] = 0;//出发位置

    //BFS
    while(que.size()) {
        //拿出队头元素
        std::pair<int, int> tmp = que.front();
        que.pop();

        //查找队头元素的上下左右位置
        for(int k = 0; k < 4; k++) {
            int i = tmp.first + dx[k], j = tmp.second + dy[k];

            //可行性剪枝:
            //矩阵边界 墙壁 当前位置已有最短路径
            if(i < 1 || i > n || j < 1 || j > m || a[i][j] == '*' || b[i][j] != -1) {
                continue;
            }

            //对合法位置存入当前位置存放的最短路径加1
            b[i][j] = b[tmp.first][tmp.second] + 1;

            //如果是出口则不需要入队
            if('e' == a[i][j]) {
                continue;
            }

            //将该合法位置入队以进行下一轮查找
            que.push({i, j});
        }
    }
}

int main(void)
{
    //将所有位置的最短路径存入-1以判断某个位置是否未被访问
    memset(b, -1, sizeof(b));

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];

            //找到出发位置的下标
            if('k' == a[i][j]) {
                x = i;
                y = j;
            }
        }
    }

    bfs();

    int count = 0, ret = 1e9;

    //统计可到达的出口数及其中的最短路径
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if('e' == a[i][j] && -1 != b[i][j]) {
                count++;
                ret = std::min(ret, b[i][j]);
            }
        }
    }

    //若不可到达任一出口,输出-1
    if(0 == count) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << count << ' ' << ret << std::endl;
    }

    return 0;
}

//P1588 [USACO07OPEN] Catch That Cow S
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

const int N = 1e5 + 10;
int t, x, y;
int b[N];//记录到达某个位置的最短路径

void bfs()
{
    std::queue<int> que;
    que.push(x);
    b[x] = 0;//起点置为0

    while(que.size()) {
        //拿出队头元素
        int tmp = que.front();
        que.pop();

        //枚举三种运动方式
        int x1 = tmp + 1, x2 = tmp - 1, x3 = tmp * 2;

        //可行性剪枝:
        if(x1 <= 1e5 && b[x1] == -1) {//向右走一步
            b[x1] = b[tmp] + 1;
            que.push(x1);
        }

        if(x2 >= 1 && b[x2] == -1) {//向左走一步
            b[x2] = b[tmp] + 1;
            que.push(x2);
        }

        if(x3 <= 1e5 && b[x3] == -1) {//走到当前位置的两倍
            b[x3] = b[tmp] + 1;
            que.push(x3);
        }

        //最优性剪枝:
        //第一次遇见y则return
        if(x1 == y || x2 == y || x3 == y) {
            return;
        }
    }
}

int main(void)
{
    std::cin >> t;

    while(t--) {
        memset(b, -1, sizeof(b));//每组数据都将数组b全部置为-1表示未访问

        std::cin >> x >> y;
        bfs();

        std::cout << b[y] << std::endl;//输出第一次算出的b[y]即为最短路径
    }

    return 0;
}

//P1379 八数码难题
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>

const std::string aim = "123804765";//目标状态
std::string str;//初始状态
std::unordered_map<std::string, int> mp;//<某种状态, 最短路径>

//矩阵移动单位向量
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

void bfs()
{
    std::queue<std::string> que;//存放二维坐标映射的一维坐标组成的string
    que.push(str);
    mp[str] = 0;//起点

    while(que.size()) {
        //拿出队头元素
        std::string tmp = que.front();
        que.pop();

        //拿到空位0的一维坐标
        int pos = 0;
        while(tmp[pos] != '0') {
            pos++;
        }

        //计算空位0的二维坐标
        int x = pos / 3, y = pos % 3;

        //枚举四种交换方式
        for(int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];

            //可行性剪枝: 越界
            if(i < 0 || i > 2 || j < 0 || j > 2) {
                continue;
            }

            //计算出交换后的字符串
            std::string next = tmp;
            int newpos = 3 * i + j;
            std::swap(next[pos], next[newpos]);
            
            //可行性剪枝:
            //交换后状态已经访问过,避免陷入死循环或造成极大的开销
            if(mp.count(next)) {
                continue;
            }

            //交换后状态未访问,将其加入哈希表并设置其最短路径为交货前状态的最短路径加1
            mp[next] = mp[tmp] + 1;
            que.push(next);

            //最优性剪枝
            if(next == aim) {
                return;
            }
        }
    }
}

int main(void)
{
    std::getline(std::cin, str);

    bfs();

    std::cout << mp[aim] << std::endl;

    return 0;
}