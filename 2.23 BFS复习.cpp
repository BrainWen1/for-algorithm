//BFS
//P1443 马的遍历
#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>

typedef std::pair<int, int> PII;
const int N = 400 + 10;
int n, m, x, y;
int a[N][N];

int dx[] = { 2, 2, 1, 1,-1,-1,-2,-2 };
int dy[] = { 1,-1, 2,-2, 2,-2, 1,-1 };

void bfs()
{
    memset(a, -1, sizeof(a));

    std::queue<PII> que;
    que.push({x, y});
    a[x][y] = 0;

    while(que.size()) {
        x = que.front().first;
        y = que.front().second;
        que.pop();

        for(int k = 0; k < 8; k++) {
            int i = x + dx[k];
            int j = y + dy[k];

            if(i < 1 || i > n || j < 1 || j > m || a[i][j] != -1) {
                continue;
            }

            que.push({i, j});
            a[i][j] = a[x][y] + 1;
        }
    }
}

int main(void)
{
    std::cin >> n >> m >> x >> y;

    bfs();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cout << std::setw(5) << std::left << a[i][j];
        }
        std::cout << std::endl;
    }
    
    return 0;
}

//多源BFS
//NC51024.矩阵距离
#include <iostream>
#include <queue>
#include <cstring>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10;
int n, m;
int a[N][N];
int b[N][N];

int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

void bfs()
{
    memset(b, -1, sizeof(b));

    std::queue<PII> que;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(1 == a[i][j]) {
                que.push({i, j});
                b[i][j] = 0;
            }
        }
    }

    while(que.size()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];

            if(i < 1 || i > n || j < 1 || j > m || b[i][j] != -1) {
                continue;
            }

            que.push({i, j});
            b[i][j] = b[x][y] + 1;
        }
    }
}

int main(void)
{
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char ch = 0;
            std::cin >> ch;
            a[i][j] = ch - '0';
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

//01BFS
//P4554 小明的游戏
#include <iostream>
#include <deque>
#include <cstring>

typedef std::pair<int, int> PII;
const int N = 500 + 10;
int n, m;
int x1, y1, x2, y2;
char a[N][N];
int b[N][N];

int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };

void bfs()
{
    if(x1 == x2 && y1 == y2) {
        b[x2][y2] = 0;
        return;
    }

    memset(b, -1, sizeof(b));

    std::deque<PII> que;
    que.push_back({x1, y1});
    b[x1][y1] = 0;

    while(que.size()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop_front();

        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];

            if(i < 0 || i >= n || j < 0 || j >= m) {
                continue;
            }

            int val = (a[i][j] == a[x][y] ? 0 : 1);

            if(-1 == b[i][j]) {
                b[i][j] = b[x][y] + val;

                if(0 == val) {
                    que.push_front({i, j});
                } else {
                    que.push_back({i, j});
                }
            } else if(b[x][y] + val < b[i][j]) {
                b[i][j] = b[x][y] + val;
            }

            if(i == x2 && j == y2) {
                return;
            }
        }
    }
}

int main(void)
{
    while(std::cin >> n >> m && (n || m)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                std::cin >> a[i][j];
            }
        }
        std::cin >> x1 >> y1 >> x2 >> y2;

        bfs();

        std::cout << b[x2][y2] << std::endl;
    }
    return 0;
}