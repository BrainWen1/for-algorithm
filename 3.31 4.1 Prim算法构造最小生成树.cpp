//最⼩⽣成树
//prim算法
//邻接矩阵法
#include <iostream>
#include <cstring>

const int N = 5010, INF = 0x3f3f3f3f;
int n, m;
int edges[N][N]; // 邻接矩阵存储图
int dist[N]; // 某个点距离⽣成树的最短距离
bool st[N]; // 标记哪些点已经加⼊到⽣成树

int prim() {
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int ret = 0;

    for(int i = 1; i <= n; i++) {// 循环加⼊ n 个点
        // 1. 找最近点
        int t = 0;
        for(int j = 1; j <= n; j++) {
            if(!st[j] && dist[j] < dist[t])
            t = j;
        }

        // 判断是否联通
        if(dist[t] == INF) {
            return INF;
        }

        st[t] = true;
        ret += dist[t];

        // 2. 更新距离
        for(int j = 1; j <= n; j++) {// 枚举 t 能⾛到哪
            dist[j] = min(dist[j], edges[t][j]);
        }
    }
    return ret;
}

int main(void) {
    std::cin >> n >> m;

    // 初始化 邻接矩阵 
    memset(edges, 0x3f, sizeof edges);

    for(int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        // 注意有重边的情况 
        edges[x][y] = edges[y][x] = min(edges[x][y], z);
    }

    int ret = prim();

    if(ret == INF) {
        std::cout << "orz" << endl;
    } else {
        std::cout << ret << endl;
    }

    return 0;
}

//vector数组
#include <iostream>
#include <vector>
#include <cstring>

typedef std::pair<int, int> PII;
const int N = 5010, INF = 0x3f3f3f3f;
int n, m;
std::vector<PII> edges[N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int ret = 0;

    for(int i = 1; i <= n; i++) {
        // 1. 找最近点 
        int t = 0;
        for(int j = 1; j <= n; j++) {
            if(!st[j] && dist[j] < dist[t])
            t = j;
        }

        // 判断是否联通 
        if(dist[t] == INF) {
            return INF;
        }

        st[t] = true;
        ret += dist[t];

        // 2. 更新距离 
        for(auto& p : edges[t]) {
            int a = p.first;
            int b = p.second;
            
            // t->a 权值是 b 
            dist[a] = min(dist[a], b);
        }
    }
    return ret;
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;

        //有重边 
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }

    int ret = prim();

    if(ret == INF) {
        std::cout << "orz" << std::endl;
    } else {
        std::cout << ret << std::endl;
    }

    return 0;
}