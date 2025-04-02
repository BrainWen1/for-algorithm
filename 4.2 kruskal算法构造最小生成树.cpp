#include <iostream>
#include <algorithm>

const int N = 5010, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
struct node {
    int x, y, z;
}a[M];
int fa[N]; //并查集 

int find(int x) {
    return (x == fa[x]) ? (fa[x]) : (fa[x] = find(fa[x]));
}

int kk() {
    std::sort(a + 1, a + 1 + m, [](node& a, node& b)->bool {
        return a.z < b.z;
    });

    int cnt = 0, ret = 0;

    for(int i = 1; i <= m; i++) {
        int x = a[i].x, y = a[i].y, z = a[i].z;
        int fx = find(x), fy = find(y);

        if(fx != fy) {
            cnt++;
            ret += z;
            fa[fx] = fy;
        }
    }
    return (cnt == n - 1) ? ret : INF;
}

int main(void) {
    std::cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].z;
    }

    // 初始化并查集 
    for(int i = 1; i <= n; i++) {
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