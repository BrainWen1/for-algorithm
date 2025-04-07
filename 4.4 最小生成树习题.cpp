//P3366 【模板】最小生成树
#include <iostream>
#include <cstring>

const int N = 5e3 + 10, M = 2e5 + 10;
int n, m, ret;
int graph[N][N];
bool st[N];

void dfs(int root) {

}

int main(void) {
    memset(graph, -1, sizeof(graph));

    std::cin >> n >> m;

    int x, y, z;
    for(int i = 1; i <= m; ++i) {
        std::cin >> x >> y >> z;

        graph[x][y] = z;
        graph[y][x] = z;
    }

    dfs(x);

    return 0;
}