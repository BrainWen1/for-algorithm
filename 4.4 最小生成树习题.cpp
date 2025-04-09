//P3366 【模板】最小生成树
#include <iostream>
#include <cstring>

const int N = 5e3 + 10, M = 2e5 + 10;
int n, m, ret;
int graph[N][N];
bool st[N];

void prim() {
    int t = 0;
}

int main(void) {
    memset(graph, -1, sizeof(graph));

    std::cin >> n >> m;

    //读入图
    int x, y, z;
    for(int i = 1; i <= m; ++i) {
        std::cin >> x >> y >> z;

        graph[x][y] = z;
        graph[y][x] = z;
    }

    //求出最小生成树并得出带权路径和
    int ret = prim();

    return 0;
}