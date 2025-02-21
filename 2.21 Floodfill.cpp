//P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <queue>

const int N = 100 + 10;
int n, m;
char a[N][N];
bool st[N][N];

//矩阵移动方向向量
int dx[] = { 0, 0, 1,-1, 1, 1,-1,-1 };
int dy[] = { 1,-1, 0, 0, 1,-1, 1,-1 };

void dfs(int x, int y)
{
    //将搜索到的位置标true
    st[x][y] = true;

    //枚举八种移动方式
    for(int k = 0; k < 8; k++) {
        int i = x + dx[k];
        int j = y + dy[k];

        //可行性剪枝
        if(i < 1 || i > n || j < 1 || j > m || a[i][j] == '.' || st[i][j] == true) {
            continue;
        }

        //对新搜索到的合法位置周围搜索
        dfs(i, j);
    }
}

void bfs(int x, int y)
{
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    st[x][y] = true;

    while(que.size()) {
        //拿出队头元素
        auto tmp = que.front();
        que.pop();

        //枚举八种移动方式
        for(int k = 0; k < 8; k++) {
            int i = tmp.first + dx[k];
            int j = tmp.second + dy[k];

            //可行性剪枝
            if(i < 1 || i > n || j < 1 || j > m || a[i][j] == '.' || st[i][j] == true) {
                continue;
            }

            //将合法位置入队并标true
            que.push({i, j});
            st[i][j] = true;
        }
    }
}

int main(void)
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }

    //遍历矩阵
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //如果遇到W并且此位置在此之前没有被搜索到,即这是一个新的水坑区域
            //则水坑数量加一并对该水坑进行搜索
            if('W' == a[i][j] && false == st[i][j]) {
                sum++;
                //dfs(i, j);
                bfs(i, j);
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

//P1162 填涂颜色
#include <iostream>
#include <queue>

const int N = 30 + 5;
int n;
int a[N][N];
bool st[N][N];

//矩阵移动方向向量
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

void bfs(int x, int y)
{
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    st[x][y] = true;

    while(que.size()) {
        //拿出队头
        auto tmp = que.front();
        que.pop();

        //枚举四种移动方式
        for(int k = 0; k < 4; k++) {
            int i = tmp.first + dx[k];
            int j = tmp.second + dy[k];

            //可行性剪枝
            if(i < 0 || i > n + 1 || j < 0 || j > n + 1 || a[i][j] == 1 || st[i][j] == true) {
                continue;
            }

            //将合法位置入队并标true
            que.push({i, j});
            st[i][j] = true;
        }
    }
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
        }
    }

    //在矩阵外围加一圈0,并从(0, 0)开始BFS,则可以只用一次BFS就能访问所有非圈内0
    bfs(0, 0);

    //遍历矩阵,查找圈内0将其修改为2并输出矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            //将未访问的0,即圈内0全部改为2
            if(0 == a[i][j] && false == st[i][j]) {
                a[i][j] = 2;
            }
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}