//P2024 [NOI2001] 食物链
#include <iostream>

const int N = 5e4 + 10;
int n, k;
int fa[N], d[N];//相较于普通并查集，需要额外维护一个距离数组

int find(int x) {
    if(fa[x] == x) {
        return x;
    }

    int tmp = find(fa[x]);
    d[x] += d[fa[x]];//x 到根节点的距离等于它到父节点的距离 d[x] 加上父节点到根节点的距离 d[fa[x]]
    //并且修正距离的操作必须在 find(fa[x]) 之后，因为需要先递归函数修正父节点的距离才能正确修正当前结点的距离

    return fa[x] = tmp;
}

void uni(int x, int y, int w) {
    int fx = find(x);
    int fy = find(y);

    //二者不在同一个关系网时，才会执行合并操作，因为同一个关系网中的任意二者的关系都已经在之前维护过了
    if(fx != fy) {
        fa[fx] = fy;
        d[fx] = w + d[y] - d[x];//x 到 fy 的两条不同的路的距离得出的计算式
    }
}

int main(void) {
	std::cin >> n >> k;

    //初始化并查集
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

	int op, x, y, ret = 0;
	while(k--) {
		std::cin >> op >> x >> y;

        //剪枝初筛
		if(x > n || y > n || (op == 2 && x == y)) {
			ret++;
			continue;
		}

		int fx = find(x), fy = find(y);

		if(op == 1) { //同类
		 	if(fx == fy && ((d[y] - d[x]) % 3 + 3) % 3 != 0) {//存在关系，并且不为同类
				ret++;
			} else {//存在关系，并且为同类，uni 函数内不会重复维护；或者不存在关系，需要维护新关系
				uni(x, y, 0);// x 和 y 之间的权值 w 为 0，表示二者为同类
			}		
		} else { //x 捕食 y
			if(fx == fy && ((d[y] - d[x]) % 3 + 3) % 3 != 1) {//存在关系，并且不为 x 捕食 y
				ret++;
			} else {//存在关系，并且为 x 捕食 y，同样不会重复维护；或者不存在关系，需要维护新关系
				uni(x, y, 2);// x 和 y 之间的权值 w 为 2，表示
			}
		}
	}
	std::cout << ret << std::endl;

	return 0;
}

//P1196 [NOI2002] 银河英雄传说
#include <iostream>
#include <cmath>

const int N = 3e4 + 10;
int n = 3e4, T;
int fa[N], d[N], size[N];

int find(int x) {
    if(fa[x] == x) {
        return x;
    } else {
        int tmp = find(fa[x]);//与上一题相同，先递归修正父亲节点的距离
        d[x] += d[fa[x]]; //再修正当前节点的距离
        return fa[x] = tmp;
    }
}

void uni(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    if(fx != fy) {
        fa[fx] = fy;

        d[fx] = size[fy];//fx 挂在上一列最后，故 fx 到 fy 的距离等于 fy 这一列原来的元素个数

        size[fy] += size[fx];//修正合并后的元素个数
        size[fx] = 0;
    }
}

int is_same(int x, int y) {
    if(find(x) == find(y)) {
        return abs(d[x] - d[y]) - 1;//利用相对距离计算二者中间的元素个数
    } else {
        return -1;
    }
}

int main(void) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
        size[i] = 1;
    }
    
    std::cin >> T;

    char op;
    int x, y;
    while(T--) {
        std::cin >> op >> x >> y;

        if('M' == op) { //合并
            uni(x, y);
        } else { //查询
            std::cout << is_same(x, y) << std::endl;
        }
    }
    return 0;
}