//图的遍历
//DFS
//邻接矩阵
#include <iostream>
#include <cstring>

const int N = 1e3 + 10;
int n, m;
int graph[N][N];
bool st[N];

void dfs(int root) {
    std::cout << root << std::endl;
    st[root] = true;

    for(int i = 1; i <= n; ++i) {
        if(graph[root][i] != -1 && st[i] == false) {
            dfs(i);
        }
    }
}

int main(void) {
    memset(graph, -1, sizeof(graph));

    std::cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int a, b, val;
        std::cin >> a >> b >> val;

        graph[a][b] = val;
        graph[b][a] = val;
    }

    dfs(1);

    return 0;
}

//vector数组
#include <iostream>
#include <vector>

typedef std::pair<int, int> pii;
const int N = 1e3 + 10;
int n, m;
std::vector<pii> graph[N];
bool st[N];

void dfs(int root) {
    std::cout << root << std::endl;
    st[root] = true;

    for(auto& e : graph[root]) {
        if(st[e.first] == false) {
            dfs(e.first);
        }
    }
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int a, b, val;
        std::cin >> a >> b >> val;

        graph[a].push_back({b, val});
        graph[b].push_back({a, val});
    }

    dfs(1);

    return 0;
}

//链式前向星
#include <iostream>

const int N = 1e3 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], id;
bool st[N];

void add(int a, int b, int val) {
    id++;
    e[id] = b;
    w[id] = val;
    ne[id] = h[a];
    h[a] = id;
}

void dfs(int root) {
    std::cout << root << std::endl;
    st[root] = true;

    for(int i = h[root]; i > 0; i = ne[i]) {
        if(st[e[i]] == false) {
            dfs(e[i]);
        }
    }
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int a, b, val;
        std::cin >> a >> b >> val;

        add(a, b, val);
        add(b, a, val);
    }

    dfs(1);

    return 0;
}