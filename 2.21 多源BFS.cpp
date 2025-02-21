//NC51024.矩阵距离
#include <iostream>
#include <queue>
#include <cstring>

const int N = 1e3 + 10;
int n, m;
char a[N][N];
int b[N][N];
std::queue<std::pair<int, int>> que;

//矩阵移动方向向量
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

void bfs()
{
    while(que.size()) {
        //拿出队头元素
        std::pair<int, int> tmp = que.front();
        que.pop();

        //枚举四种移动方式
        for(int k = 0; k < 4; k++) {
            int x = tmp.first + dx[k];
            int y = tmp.second + dy[k];

            //可行性剪枝
            if(x < 1 || x > n || y < 1 || y > m || b[x][y] != -1) {
                continue;
            }

            //将合法位置的最短路径置为当前位置的最短路径加1,并加入队列
            b[x][y] = b[tmp.first][tmp.second] + 1;
            que.push({x, y});
        }
    }
}

int main(void)
{
    //将表示最短路径的b数组全置为-1表示未访问
    memset(b, -1, sizeof(b));

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];

            //将所有1的位置作为第一层的起点加入队列
            if('1' == a[i][j]) {
                b[i][j] = 0;
                que.push({i, j});
            }
        }
    }

    bfs();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cout << b[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

//P1902 刺杀大使
#include <iostream>
#include <queue>

const int N = 1e3 + 10;
int n, m;
int a[N][N];

//矩阵移动方向向量
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

bool bfs(int val)
{
    //最优性剪枝
    if(n == 1) {
        return true;
    }

    //bool数组用于标记每次bfs过程中哪些位置已经走过
    bool b[N][N] = { false };

    //将所有入口入队并标true
    std::queue<std::pair<int, int>> que;
    for(int i = 1; i <= m; i++) {
        que.push({1, i});
        b[1][i] = true;
    }

    while(que.size()) {
        //拿出队头元素
        std::pair<int, int> tmp = que.front();
        que.pop();

        //枚举四种移动方式
        for(int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];

            //可行性剪枝
            if(x < 1 || x > n || y < 1 || y > m || b[x][y] == true || a[x][y] > val) {
                continue;
            }

            //对合法位置标true并入队
            b[x][y] = true;
            que.push({x, y});

            //最优性剪枝
            if(x == n) {
                return true;
            }
        }
    }
    //bfs遍历整个地图都无法找到以该(val)mid为最大值的一条路径
    return false;
}

int main(void)
{
    std::cin >> n >> m;
    int left = 0, right = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];

            //找出答案可能的最大值
            if(a[i][j] > right) {
                right = a[i][j];
            }
        }
    }

    //二分答案
    //bfs用于判断是否能找到以mid为最大值的路径
    while(left < right) {
        int mid = (left + right) / 2;
        if(bfs(mid)) right = mid;//如果可以则继续向更小压缩
        else left = mid + 1;//如果不可以则向更大查询
    }

    std::cout << left << std::endl;

    return 0;
}