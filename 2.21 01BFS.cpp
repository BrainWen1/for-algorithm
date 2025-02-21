//P4554 小明的游戏
#include <iostream>
#include <deque>
#include <cstring>

const int N = 500 + 10;
int n, m;
std::pair<int, int> sta, aim;
char a[N][N];
int b[N][N];

//矩阵移动方向向量
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

void bfs()
{
    //最优性剪枝
    if(sta.first == aim.first && sta.second == aim.second) {
        b[aim.first][aim.second] = 0;
        return;
    }

    //双端队列
    std::deque<std::pair<int, int>> que;
    que.push_back({sta.first, sta.second});
    b[sta.first][sta.second] = 0;

    //BFS
    while(que.size()) {
        //拿出队头元素
        std::pair<int, int> tmp = que.front();
        que.pop_front();

        //枚举四种移动方式
        for(int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];

            //可行性剪枝
            if(x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }

            //计算下一次扩散应赋予的值
            int val = b[tmp.first][tmp.second] + (a[tmp.first][tmp.second] == a[x][y] ? 0 : 1);
            
            //(x, y)此前未被访问过
            if(b[x][y] == -1) {
                b[x][y] = val;//更新值

                //如果路权为0则插入队头
                if(val == b[tmp.first][tmp.second]) {
                    que.push_front({x, y});
                } else {
                    //否则插入队尾
                    que.push_back({x, y});
                }
            } else if(val < b[x][y]) {
                //此位置已被访问过,但此前的值不是最优解则更新为新最优解
                b[x][y] = val;
            }

            //最优性剪枝
            if(x == aim.first && y == aim.second) {
                return;
            }
        }
    }
}

int main(void)
{
    while(std::cin >> n >> m && (n || m)) {
        memset(b, -1, sizeof(b));//每组数据重置b数组

        //下标从0开始
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                std::cin >> a[i][j];
            }
        }

        std::cin >> sta.first >> sta.second >> aim.first >> aim.second;

        bfs();

        std::cout << b[aim.first][aim.second] << std::endl;
    }

    return 0;
}

//CF590C Three States
#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

const int N = 1e3 + 10;
int n, m;
char a[N][N];
int state[4][N][N];

//矩阵移动方向向量
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

//多源BFS: 有一块或多块领地
//01 Bfs: 自己和盟友的领地上移动权值为0,荒地为1
void bfs(int num)
{
    //将当前国家的值置为-1
    memset(state[num], -1, sizeof(state[num]));

    std::deque<std::pair<int, int>> que;
    
    //将当前国家的所有领地入队
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] - '0' == num) {
                que.push_back({i, j});
                state[num][i][j] = 0;
            }
        }
    }

    //01 BFS
    while(que.size()) {
        auto tmp = que.front();
        que.pop_front();

        for(int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];

            //可行性剪枝
            if(x < 1 || x > n || y < 1 || y > m || a[x][y] == '#') {
                continue;
            }

            int val = 0;
            //走在荒地上
            if(a[x][y] == '.') {
                val++;
            }

            //当前位置未被访问
            if(state[num][x][y] == -1) {
                state[num][x][y] = state[num][tmp.first][tmp.second] + val;
                
                if(0 == val) {
                    que.push_front({x, y});//权值为0则插入队头
                } else {
                    que.push_back({x, y});//权值为1则插入队尾
                }
            } else if(state[num][tmp.first][tmp.second] + val < state[num][x][y]) {
                state[num][x][y] = state[num][tmp.first][tmp.second] + val;
            }//当前位置已被访问但有新的最短路径则更新值
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

    //多源BFS分别计算三个国家所有领地到所有可到达的位置的最短路径
    bfs(1);
    bfs(2);
    bfs(3);

    int ret = 1e9;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //石头直接跳过
            if(a[i][j] == '#') {
                continue;
            }

            //分别拿到三个国家到此位置的最短路径
            int x = state[1][i][j], y = state[2][i][j], z = state[3][i][j];

            //该位置无法将三个国家连通
            if(-1 == x || -1 == y || -1 == z) {
                continue;
            }

            //计算并更新所有最短路径中的最短路径
            if(a[i][j] == '.') {
                ret = std::min(ret, x + y + z - 2);
            } else {
                ret = std::min(ret, x + y + z);
            }
        }
    }

    if(1e9 == ret) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ret << std::endl;
    }

    return 0;
}