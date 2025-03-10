//P1892 [BalticOI 2003] 团伙
#include <iostream>

const int N = 1e3 + 10;
int n, m;
int fa[N << 1];

int find(int x) {
    if(fa[x] == x) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}

void uni(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    fa[fy] = fx;//始终将朋友域的元素作为根节点，便于后续统计根节点数
}

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= (n << 1); ++i) {
        fa[i] = i;
    }

    char op;
    int x, y;

    for(int i = 1; i <= m; ++i) {
        std::cin >> op >> x >> y;

        if('F' == op) {
            //将二者的朋友域合并
            uni(x, y);
        } else {
            //敌人的敌人是我的朋友
            //故需互相将自己朋友域与对方的敌人域合并
            uni(x, y + n);///始终将朋友域的元素作为根节点
            uni(y, x + n);
        }
    }

    //统计根节点数量，即集合数
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        if(fa[i] == i) {
            ret++;
        }
    }
    std::cout << ret << std::endl;

    return 0;
}

//P2024 [NOI2001] 食物链
#include <iostream>

const int N = 5e4 + 10;
int n, k;
int fa[N * 3];

int find(int x) {
    if(fa[x] == x) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}

void uni(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    fa[fx] = fy;
}

int main(void) {
    std::cin >> n >> k;

    int m = 3 * n;
    for(int i = 1; i <= m; ++i) {
        fa[i] = i;
    }

    int op, x, y;
    int ret = 0;
    while(k--) {
        std::cin >> op >> x >> y;

        //剪枝
        if(x > n || y > n || (op == 2 && x == y)) {
            ret++;
            continue;
        }

        if(op == 1) { //同类
            //使用这种判断可以顺便正确处理 x 或 y 作为新节点的情况
            //若使用 find(x) != find(y) 则需要而外判断，因为新节点的根节点是自己，不可能与其他节点的根节点相同
            if(find(x + n) == find(y) || find(y + n) == find(x)) {
                ret++;
            } else { //维护合法信息
                uni(x, y);
                uni(x + n, y + n);
                uni(x + n + n, y + n + n);
            }
        } else { //x 捕食 y
            if(find(x) == find(y) || find(y + n) == find(x)) {
                ret++;
            } else {
                uni(x + n, y);
                uni(x, y + n + n);
                uni(x + n + n, y + n);
            }
        }
    }
    std::cout << ret << std::endl;

    return 0;
}