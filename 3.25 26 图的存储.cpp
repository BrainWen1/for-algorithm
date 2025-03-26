//图的存储
//邻接矩阵(二维数组)
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

        //若为无向图 b -> a
        graph[b][a] = val;
    }
    return 0;
}

//vector数组
#include <iostream>
#include <vector>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10;
int n, m;
std::vector<PII> graph[N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int a, b, val;
        std::cin >> a >> b >> val;

        // a -> b
        graph[a].push_back({b, val});

        //若为无向图 b -> a
        graph[b].push_back({a, val});
    }
    return 0;
}

//链式前向星
#include <iostream>

const int N = 1e3 + 10;
int n, m;
int id, h[N << 1], e[N], ne[N], w[N];

void insert(int a, int b, int val) {
    id++;
    e[id] = b;
    w[id] = val;
    ne[id] = h[a];
    h[a] = id;
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> val;

        insert(a, b, val);
        insert(b, a, val);
    }
    return 0;
}