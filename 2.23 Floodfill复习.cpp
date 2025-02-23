//Floodfill
//P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <queue>

typedef std::pair<int, int> PII;
const int N = 100 + 10;
int n, m, ret;
char a[N][N];
bool st[N][N];

int dx[] = { 0, 0, 1, 1, 1,-1,-1,-1 };
int dy[] = { 1,-1, 0, 1,-1, 0, 1,-1 };

void bfs(int x, int y)
{
    std::queue<PII> que;
    que.push({x, y});
    st[x][y] = true;

    while(que.size()) {
        x = que.front().first;
        y = que.front().second;
        que.pop();

        for(int k = 0; k < 8; k++) {
            int i = x + dx[k];
            int j = y + dy[k];

            if(i < 1 || i > n || j < 1 || j > m || '.' == a[i][j] || true == st[i][j]) {
                continue;
            }

            que.push({i, j});
            st[i][j] = true;
        }
    }
}

void dfs(int x, int y)
{
    st[x][y] = true;

    for(int k = 0; k < 8; k++) {
        int i = x + dx[k];
        int j = y + dy[k];

        if(i < 1 || i > n || j < 1 || j > m || '.' == a[i][j] || true == st[i][j]) {
            continue;
        }

        st[i][j] = true;
        dfs(i, j);
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

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if('W' == a[i][j] && false == st[i][j]) {
                //bfs(i, j);
                dfs(i, j);
                ret++;
            }
        }
    }

    std::cout << ret << std::endl;

    return 0;
}