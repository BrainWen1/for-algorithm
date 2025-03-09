//P3367 【模板】并查集
#include <iostream>

const int N = 2e5 + 10;
int n, m;
int fa[N];

//查询根节点
int find(int x) {
    if(fa[x] == x) {//x 的根节点为自己，说明 x 就是根节点
        return x;
    } else {//继续向上找根节点，并在返回时将根节点赋值给当前节点，完成路径压缩
        return fa[x] = find(fa[x]);
    }
}

//合并两个集合
void uni(int x, int y) {
    int fx = find(x);//查询两个元素的根节点
    int fy = find(y);
    fa[fx] = fy;//并将其中一个根节点挂到另一个根节点下方成为一棵子树
    //注：当两个元素在同一个集合中时不受影响，因为根节点的父亲就是他自己
}

int main(void) {
    std::cin >> n >> m;

    //初始化，开始时每个元素都是一个单独的树（集合），根节点都是自己
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    int op, x, y;
    while(m--) {
        std::cin >> op >> x >> y;

        if(1 == op) {
            uni(x, y);
        } else {
            char ch = 'N';
            if(find(x) == find(y)) {
                ch = 'Y';
            }
            std::cout << ch << std::endl;
        }
     }
     return 0;
}

//P1551 亲戚
#include <iostream>

const int N = 5e3 + 10;
int n, m, p;
int fa[N];

int find(int x) {
    return (fa[x] == x) ? (x) : (fa[x] = find(fa[x]));
}

void uni(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

int main(void) {
    std::cin >> n >> m >> p;

    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    int x, y;
    while(m--) {
        std::cin >> x >> y;
        uni(x, y);
    }

    while(p--) {
        std::cin >> x >> y;
        if(find(x) == find(y)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No"  << std::endl;
        }
    }
    return 0;
}

//P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <set>

typedef std::pair<int, int> PII;
const int N = 100 + 10;
int n, m;
char a[N][N];
PII fa[N][N];

int dx[] = { -1,-1,-1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1,-1, 1,-1, 0, 1 };

PII find(PII tmp) {
    int x = tmp.first, y = tmp.second;
    return (fa[x][y].first == x && fa[x][y].second == y) ? tmp : fa[x][y] = find(fa[x][y]);
}

void uni(PII i, PII j) {
    int x1 = i.first, y1 = i.second;
    int x2 = j.first, y2 = j.second;
    i = find({x1, y1}), j = find({x2, y2});
    fa[i.first][i.second] = {j.first, j.second};
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
            fa[i][j] = {i, j};
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'W') {
                for(int k = 0; k < 8; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if(a[x][y] == 'W') {
                        uni({i, j}, {x, y});
                    }
                }
            }
        }
    }

    std::set<PII> mp;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'W') {
                PII root = find({i, j});
                mp.insert(root);
            }
        }
    }
    std::cout << mp.size() << std::endl;
    
    return 0;
}

//P1955 [NOI2015] 程序自动分析
#include <iostream>
#include <unordered_map>
#include <algorithm>

const int N = 1e5 + 10;
int t, n, pos;
int fa[2 * N], disc[2 * N];
std::unordered_map<int, int> mp;
struct node {
    int x;
    int y;
    int e;
}a[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void uni(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

bool is_same(int x, int y) {
    return find(x) == find(y);
}

int main(void) {
    std::cin >> t;

    while(t--) {
        //重置数据
        pos = 0;
        mp.clear();

        std::cin >> n;

        //读取初始数据
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i].x >> a[i].y >> a[i].e;
            disc[++pos] = a[i].x;
            disc[++pos] = a[i].y;
        }

        //离散化数据
        std::sort(disc + 1, disc + 1 + pos);
        int index = 0;
        for(int i = 1; i <= pos; i++) {
            if(mp.count(disc[i])) {
                continue;
            }

            mp[disc[i]] = ++index;
        }

        //初始化并查集
        for(int i = 1; i <= index; i++) {
            fa[i] = i;
        }

        //将所有相等的树合并
        for(int i = 1; i <= n; i++) {
            if(1 == a[i].e) {
                uni(mp[a[i].x], mp[a[i].y]);
            }
        }

        //查询所有不相等数对是否处于同一棵树
        int flag = 1;
        for(int i = 1; i <= n; i++) {
            if(0 == a[i].e && is_same(mp[a[i].x], mp[a[i].y])) {
                std::cout << "NO"  << std::endl;
                flag = 0;
                break;
            }
        }
        if(flag) {
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}