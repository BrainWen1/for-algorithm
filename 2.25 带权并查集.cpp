//P2024 [NOI2001] 食物链
#include <iostream>

const int N = 5e4 + 10;
int n, m;
int fa[N];//存放父亲节点
int dist[N];//存放当前节点到root节点的距离，但是实际上合并时不会修改除了root节点之外的值
//所以实际存放的是到父亲节点的信息，但是该信息会在find的过程中通过路径压缩修正

int find(int x)
{
    if(fa[x] == x) {
        return x;
    }

    int fx = find(fa[x]);
    dist[x] = (dist[x] + dist[fa[x]]) % 3;//修正距离
    return fa[x] = fx;//路径压缩
}

void uni(int x, int y, int we)
{
    int fx = find(x), fy = find(y);

    //若已经在同一棵树中则无需额外操作
    if(fx == fy) {
        return;
    } else {//不在一棵树中 -> 将左边的root节点fx挂到右边的root节点fy下,并修正fx到fy的dist距离
        fa[fx] = fy;
        dist[fx] = (dist[y] + we - dist[x] + 3) % 3;
    }
}

int main(void)
{
    std::cin >> n >> m;

    //初始化并查集
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    //读取每一句话中的信息并处理
    int ret = 0;
    while(m--) {
        int op, x, y;
        std::cin >> op >> x >> y;

        //先特判数据范围和自己吃自己的情况
        if(x > n || y > n || (2 == op && x == y)) {
            ret++;
            continue;
        }

        //找出root节点并修正dist数组中的值
        int fx = find(x);
        int fy = find(y);
        
        //判断假话或处理关系
        if(1 == op) {
            //输入关系为同类,但是他们之间的关系已经存在并且不是同类关系
            if(fx == fy && (dist[x] - dist[y] + 3) % 3 != 0) {
                ret++;
                continue;
            }

            //真话则维护信息
            uni(x, y, 0);
        } else if(2 == op) {
            //输入关系为 x 捕食 y ,但是他们之间的关系已经存在并且不是 x 捕食 y的关系
            if(fx == fy && (dist[x] - dist[y] + 3) % 3 != 1) {
                ret++;
                continue;
            }

            //维护信息
            uni(x, y, 1);
        }
    }
    std::cout << ret << std::endl;

    return 0;
}

//P1196 [NOI2002] 银河英雄传说
#include <iostream>
#include <cmath>

const int N = 3e4 + 10;
int n;
int fa[N];
int dist[N], size[N];
//dist数组维护的是每一个元素到root节点的距离,实际意义则是包括二者以及二者间的元素个数减一
//size数组维护的是每一个root节点所在的队伍的元素总个数

int find(int x)
{
    if(fa[x] == x) {//查找到root节点则返回
        return x;
    }

    int fx = find(fa[x]);
    dist[x] += dist[fa[x]];//修正距离
    return fa[x] = fx;//路径压缩后返回
}

void uni(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    if(fx != fy) {
        fa[fx] = fy;//将fx挂到fy下方
        dist[fx] = size[fy];//修改fx的dist值(dist[fx])为fy的原size大小(size[fy])
        size[fy] += size[fx];//将size[fy]增加size[fx]
        size[fx] = 0;//将size[fx]置0
    }
}

int main(void)
{
    std::cin >> n;

    //初始化并查集
    for(int i = 1; i <= N; i++) {
        fa[i] = i;//初始时所有元素都是一棵孤立的树
        size[i] = 1;//初始时所有位置都只有一个元素
    }

    char op;
    int x, y;
    while(n--) {
        std::cin >> op >> x >> y;

        if('M' == op) {//合并操作
            //合并集合并修正dist和size值
            uni(x, y);
        } else if('C' == op) {//查询操作
            //查找root节点同时修正dist值
            int fx = find(x);
            int fy = find(y);

            //两者dist值相减后再减一即为二者距离
            if(fx == fy) {
                std::cout << std::abs(dist[y] - dist[x]) - 1 << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }
}