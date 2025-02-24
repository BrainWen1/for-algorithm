//P3367 【模板】并查集
#include <iostream>

const int N = 2e5 + 10;
int n, m;
int fa[N];

int find(int x)
{
    if(fa[x] == x) {//如果此节点的父节点是自己,即该节点为root节点
        return x;
    } else {//递归查找root节点,并将该路径上的所有节点的父节点修改为root节点
        return fa[x] = find(fa[x]);
    }
}

void uni(int x, int y)
{
    int fx = find(x);//查找x的root节点
    int fy = find(y);//查找y的root节点
    fa[fx] = fy;//将x的root节点fx挂到y的root节点fy下成为fy的一棵子树
}

bool is_same(int x, int y)
{
    return find(x) == find(y);//判断两个节点的root节点是否相同
}

int main(void)
{
    std::cin >> n >> m;

    //初始化->所有节点都是root节点
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    while(m--) {
        int op, x, y;
        std::cin >> op >> x >> y;

        if(1 == op) {
            uni(x, y);
        } else {
            if(is_same(x, y)) {
                std::cout << 'Y' << std::endl;
            } else {
                std::cout << 'N' << std::endl;
            }
        }
    }
    return 0;
}

//P1551 亲戚
#include <iostream>

const int N = 5e3 + 10;
int n, m, p, x, y;
int fa[N];

//查找root节点->查找当前亲戚树的代表
int find(int val)
{
    if(fa[val] == val) {
        return val;
    } else {
        return fa[val] = find(fa[val]);
    }
}

//合并两棵树->将两个人组为亲戚,其双方亲戚也互为亲戚,故可合并两颗亲戚树
void uni(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

//判断两个节点是否处在同一棵树->判断两个人是否具有相同的亲戚树代表
bool is_same(int x, int y)
{
    return find(x) == find(y);
}

int main(void)
{
    std::cin >> n >> m >> p;

    //初始化
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    while(m--) {
        std::cin >> x >> y;

        uni(x, y);
    }

    while(p--) {
        std::cin >> x >> y;

        if(is_same(x, y)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}

//P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <queue>
#include <set>

typedef std::pair<int, int> PII;
const int N = 1e3 + 10;
int n, m;
char a[N][N];
bool b[N][N];
PII fa[N][N];

int dx[] = { 0, 0, 1,-1,-1,-1, 1, 1 };
int dy[] = { 1,-1, 0, 0, 1,-1, 1,-1 };

PII find(PII x)
{
    if(fa[x.first][x.second] == x) {
        return x;
    } else {
        return fa[x.first][x.second] = find(fa[x.first][x.second]);
    }
}

void uni(PII x, PII y)
{
    PII fx = find(x);
    PII fy = find(y);
    fa[fx.first][fx.second] = fy;
}

void bfs(int x, int y)
{
    std::queue<PII> que;
    que.push({x, y});
    b[x][y] = true;

    while(que.size()) {
        x = que.front().first;
        y = que.front().second;
        que.pop();

        for(int k = 0; k < 8; k++) {
            int i = x + dx[k];
            int j = y + dy[k];

            if(i < 1 || i > n || j < 1 || j > m || '.' == a[i][j] || true == b[i][j]) {
                continue;
            }

            //将合法位置与原位置uni合并为一棵树
            uni({x, y}, {i, j});
            que.push({i, j});
            b[i][j] = true;
        }
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

    //初始化
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            fa[i][j] = {i, j};
        }
    }

    //遍历矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //找到一块未标记的水坑
            if('W' == a[i][j] && false == b[i][j]) {
                bfs(i, j);
            }
        }
    }

    //统计有几棵树
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(('W' == a[i][j]) && (fa[i][j].first == i && fa[i][j].second == j)) {
                ret++;
            }
        }
    }

    std::cout << ret << std::endl;

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
struct node
{
    int x;
    int y;
    int e;
}a[N];

int find(int x)
{
    if(fa[x] == x) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}

void uni(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

bool is_same(int x, int y)
{
    return find(x) == find(y);
}

int main(void)
{
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