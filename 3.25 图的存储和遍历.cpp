//图的存储
//邻接矩阵
#include <iostream>
#include <cstring>

const int N = 1e3 + 10;
int n, m;
int graph[N][N];

int main(void) {
    memset(graph, -1, sizeof(graph));

    //读入 节点个数 / 边数
    std::cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b, val;
        std::cin >> a >> b >> val;

        // a -> b
        graph[a][b] = val;

        //若为无向图
        graph[b][a] = val;
    }
    return 0;
}