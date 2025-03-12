//P8306 【模板】字典树
#include <iostream>
#include <string>
#include <cstring>

const int N = 3e6 + 10;
int T, n, q, idx;
int trie[N][26 + 26 + 10], pass[N]; //只需维护一个 pass 数组，用来操作前缀字符串

inline int get_num(char ch) { //获取字符的 ASCII 码值
    if(ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    } else if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 26;
    } else { //这块映射 ASCII 码值时需要加上 26 或 52，避免将多个字符映射到 0 ~ 25 上的相同位置
        return ch - '0' + 26 + 26;
    }
}

inline void insert(std::string& str) {
    int cur = 0;
    pass[cur]++;//根节点的 pass 加一

    for(char ch : str) {
        int path = get_num(ch);

        if(trie[cur][path] == 0) { //没有现成的路径，创建新路径
            trie[cur][path] = ++idx;
        }

        cur = trie[cur][path]; //找到下一个节点
        pass[cur]++; //途经的节点的 pass 值加一
    }
}

inline int query(std::string& str) {
    int cur = 0;

    for(char ch : str) {
        int path = get_num(ch);

        if(trie[cur][path] == 0) { //该字符串不存在于字典树中
            return 0;
        } else { //找到下一个节点
            cur = trie[cur][path];
        }
    }
    return pass[cur]; //str 为前缀串的数量，返回的是 str 串的最后一个字符的节点处的 pass 值
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> T;

    while(T--) {
        std::cin >> n >> q;

        std::string str;

        //n 次插入字符串
        while(n--) {
            std::cin >> str;
            insert(str);
        }

        //q 次查询前缀数
        while(q--) {
            std::cin >> str;
            std::cout << query(str) << std::endl;
        }

        //重置数组
        for(int i = 0; i <= idx; ++i) { //要从 0 开始到 idx，因为 0 位置代表第一个字符的选取，也需要重置
            for(int j = 0; j < 62; ++j) {
                trie[i][j] = 0;
            }
            pass[i] = 0;
        }
        idx = 0;
    }
    return 0;
}

//P2580 于是他错误的点名开始了
#include <iostream>
#include <string>

const int N = 5e5 + 10;
int n, m, idx;
int trie[N][26], end[N]; //只需维护一个 end 数组，用来操作完整的字符串

inline void insert(std::string& str) {
    int cur = 0;

    for(char ch : str) {
        int path = ch - 'a';

        if(trie[cur][path] == 0) {
            trie[cur][path] = ++idx;
        }

        cur = trie[cur][path];
    }
    end[cur]++;
}

inline int query(std::string& str) {
    int cur = 0;

    for(char ch : str) {
        int path = ch - 'a';

        if(trie[cur][path] == 0) {
            return 0;
        } else {
            cur = trie[cur][path];
        }
    }
    int ret = end[cur]; //保存结果
    end[cur] = -1; //第一次查询后将该位置置为 -1，便于判断是否重复查询

    return ret;
}

int main(void) {
    std::cin >> n;

    std::string str;

    //插入 n 个字符串
    while(n--) {
        std::cin >> str;
        insert(str);
    }

    std::cin >> m;

    //查询 m 次字符串
    while(m--) {
        std::cin >> str;

        int val = query(str); //按返回值判断结果

        if(val > 0) { //第一次查询到
            std::cout << "OK" << std::endl;
        } else if(val == 0) { //未查询到
            std::cout << "WRONG" << std::endl;
        } else { //重复查询
            std::cout << "REPEAT" << std::endl;
        }
    }
    return 0;
}

//P10471 最大异或对 The XOR Largest Pair
#include <iostream>

const int N = 1e5 + 10;
int n, idx;
int trie[N * 32][2], a[N]; //因为保存的是二进制位，故每个数字都要有 32 (4 bytes * 8 bits) 个位置

void insert(int x) {
    int cur = 0;

    //将 x 的二进制表示插入字典树中
    for(int i = 31; i >= 0; --i) {
        int path = (x >> i) & 1;

        if(trie[cur][path] == 0) {
            trie[cur][path] = ++idx;
        }

        cur = trie[cur][path];
    }
}

int find(int x) {
    int cur = 0, ret = 0;

    //从最高位按位查找
    for(int i = 31; i >= 0; --i) {
        int path = (x >> i) & 1;

        if(trie[cur][path ^ 1] != 0) { //当前位的值为 path，尝试寻找 path ^ 1 之后的结果，也就是 0 -> 1, 1 -> 0，因为这样就能得到异或后的该位为 1
            ret = ret | (1 << i); //将该位置为 1
            cur = trie[cur][path ^ 1]; //找到下一个节点
        } else {
            cur = trie[cur][path]; //没有相反位，则保持该位为 0，继续找下一个节点
        }
    }
    return ret;
}

int main(void) {
    std::cin >> n;

    //读取序列保存，并插入字典树中
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        insert(a[i]);
    }

    //查找最大异或对
    int maxi = 0;
    for(int i = 1; i <= n; ++i) {
        maxi = std::max(maxi, find(a[i]));
    }
    std::cout << maxi << std::endl;

    return 0;
}