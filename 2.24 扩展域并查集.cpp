//P1892 [BalticOI 2003] 团伙
#include <iostream>

const int N = 1e3 + 10;
int n, m;
int fa[2 * N];

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
    fa[find(x)] = find(y);
}

int main(void)
{
    std::cin >> n >> m;

    //初始化并查集
    for(int i = 1; i <= n * 2; i++) {
        fa[i] = i;
    }

    char opt;
    int x, y;
    for(int i = 1; i <= m; i++) {
        std::cin >> opt >> x >> y;

        if('F' == opt) {//朋友
            uni(x, y);//将二者的标准域合并
        } else {//敌人
            uni(y + n, x);//将二者各自的标准域与对方的扩展域合并
            uni(x + n, y);//注意要让标准域成为root节点便于统计树的个数
        }
    }

    //统计树的个数
    int ret = 0;
    for(int i = 1; i <= n; i++) {
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
int n, m;
int fa[3 * N];//需要存放三种域: (标准域)->同类域 // (扩展域)->捕食域 被捕食域

int find(int x)
{
    return (fa[x] == x) ? (x) : (fa[x] = find(fa[x]));
}

void uni(int x, int y)
{
    fa[find(x)] = find(y);
}

bool is_same(int x, int y)
{
    return find(x) == find(y);
}

int main(void)
{
    std::cin >> n >> m;

    //初始化
    for(int i = 1; i <= 3 * n; i++) {
        fa[i] = i;
    }

    int ret = 0;
    while(m--) {
        int op, x, y;
        std::cin >> op >> x >> y;

        //判断是否为假话:
        //1.数据范围错误;  2.输入为同类时,二者在现有食物链中已有捕食与被捕食关系;  3.输入为捕食关系时,二者为同一只动物或同类或捕食关系相反
        if(x > n || y > n || (1 == op && (is_same(x + n, y) || is_same(x, y + n))) || (2 == op && (x == y || is_same(x, y) || find(y + n) == find(x)))) {
            ret++;
            continue;
        }

        //维护真话里的信息
        if(1 == op) {
            //同类的同类域和捕食域和被捕食域都需要合并,因为二者的这三种域都是等价的
            uni(x, y);
            uni(x + n, y + n);
            uni(x + 2 * n, y + 2 * n);
        } else {
            //捕食关系(x -> y)中,x的捕食域与y的同类域合并,x的同类域与y的被捕食域合并,x的被捕食域与y的捕食域合并,同样因为它们两两等价
            uni(x + n, y);
            uni(y + 2 * n, x);
            uni(x + 2 * n, y + n);
        }
    }

    std::cout << ret << std::endl;

    return 0;
}