//P3366 【模板】最小生成树
//Prim算法
#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 5e3 + 10, INF = 0x3f3f3f3f;
int n, m;
int graph[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        int t = 0;
        for(int j = 1; j <= n; ++j) {
            if(st[j] == false && dist[j] < dist[t]) {
                t = j;
            }
        }

        if(dist[t] == INF) {
            return INF;
        }
        st[t] = true;
        ret += dist[t];

        for(int j = 1; j <= n; ++j) {
            dist[j] = std::min(dist[j], graph[t][j]);
        }
    }
    return ret;
}

int main(void) {
    memset(graph, 0x3f, sizeof(graph));

    std::cin >> n >> m;

    //读入图
    int x, y, z;
    for(int i = 1; i <= m; ++i) {
        std::cin >> x >> y >> z;

        graph[x][y] = graph[y][x] = std::min(graph[x][y], z);
    }

    //求出最小生成树并得出带权路径和
    int ret = prim();

    if(ret == INF) {
        std::cout << "orz" << std::endl;
    } else {
        std::cout << ret << std::endl;
    }

    return 0;
}

//Kruskal算法
#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 5e3 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
struct node {
    int x;
    int y;
    int z;
}a[M];
int fa[N];

int find(int x) {
    return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}

int kk() {
    std::sort(a, a + m, [](node& e, node& f)->bool {
        return e.z < f.z;
    });

    int ret = 0, cnt = 0;
    for(int i = 1; i <= m; ++i) {
        int x = a[i].x, y = a[i].y, z = a[i].z;
        int fx = find(x), fy = find(y);

        if(fx != fy) {
            cnt++;
            ret += z;
            fa[fx] = fy;
        }
    }
    return (cnt == (n - 1)) ? ret : INF;
}

int main(void) {
    std::cin >> n >> m;

    int x, y, z;
    for(int i = 1; i <= m; ++i) {
        std::cin >> a[i].x >> a[i].y >> a[i].z;
    }

    //初始化并查集
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    int ret = kk();

    if(ret == INF) {
        std::cout << "orz" << std::endl;
    } else {
        std::cout << ret << std::endl;
    }

    return 0;
}