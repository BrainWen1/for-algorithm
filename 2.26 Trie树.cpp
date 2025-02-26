//静态数组实现字典树
#include <iostream>
#include <string>

const int N = 1e3 + 10;
int n, index;
int trie[N][26], pass[N], end[N];

void insert(std::string& str)
{
    int cur = 0;
    pass[cur]++;//一定会经过头节点一次

    for(char ch : str) {
        int path = ch - 'a';//获取二维数组的下标

        if(0 == trie[cur][path]) {//不存在路径,新建一条路
            trie[cur][path] = ++index;
        }

        //走到下一个节点,并让 pass 值加一
        cur = trie[cur][path];
        pass[cur]++;
    }
    end[cur]++;//将最后一个节点的 end 值加一
}

int find(std::string& str)
{
    int cur = 0;

    for(char ch : str) {
        int path = ch - 'a';//获取二维数组的下标

        if(0 == trie[cur][path]) {//不存在当前节点,即不存在当前字符串
            return 0;
        } else {//存在则走向下一个节点
            cur = trie[cur][path];
        }
    }
    return end[cur];//返回末节点的 end 值,即此字符串的数量
}

int PreFix(std::string& str)
{
    int cur = 0;

    for(char ch : str) {
        int path = ch - 'a';//获取二维数组的下标

        if(0 == trie[cur][path]) {//不存在当前节点,即不存在当前字符串
            return 0;
        } else {//存在则走向下一个节点
            cur = trie[cur][path];
        }
    }
    return pass[cur];//返回末节点的 pass 值,即此以字符串为前缀的字符串数量
}

int main(void)
{
    std::cin >> n;
    std::string str;

    for(int i = 1; i <= n; i++) {
        std::cin >> str;

        insert(str);
    }

    std::cin >> str;
    std::cout << find(str) << std::endl;

    return 0;
}

//P8306 【模板】字典树
#include <iostream>
#include <string>

const int N = 3e6 + 10, M = 26 + 26 + 10;
int T, n, q, idx;
int trie[N][M], pass[N];

int get_num(char& ch)
{
    if(ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    } else if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 26;
    } else {
        return ch - '0' + 26 + 26;
    }
}

void insert(std::string& str)
{
    int cur = 0;
    pass[cur]++;

    for(char ch : str) {
        int path = get_num(ch);

        if(0 == trie[cur][path]) {
            trie[cur][path] = ++idx;
        }

        cur = trie[cur][path];
        pass[cur]++;
    }
}

int PreFix(std::string& str)
{
    int cur = 0;

    for(char ch : str) {
        int path = get_num(ch);

        if(0 == trie[cur][path]) {
            return 0;
        } else {
            cur = trie[cur][path];
        }
    }
    return pass[cur];
}

int main(void)
{
    std::cin >> T;

    while(T--) {
        std::cin >> n >> q;

        //插入新字符串
        std::string str;
        for(int i = 1; i <= n; i++) {
            std::cin >> str;
            insert(str);
        }

        //查询前缀字符串
        while(q--) {
            std::cin >> str;
            std::cout << PreFix(str) << std::endl;
        }

        //清空数据
        for(int i = 0; i <= idx; i++) {
            for(int j = 0; j < 62; j++) {
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
int trie[N][26], end[N];

void insert(std::string& str)
{
    int cur = 0;

    for(char ch : str) {
        int path = ch - 'a';

        if(0 == trie[cur][path]) {
            trie[cur][path] = ++idx;
        }

        cur = trie[cur][path];
    }
    end[cur]++;
}

int find(std::string& str)
{
    int cur = 0;

    for(char ch : str) {
        int path = ch - 'a';

        if(0 == trie[cur][path]) {
            return 0;
        } else {
            cur = trie[cur][path];
        }
    }
    //关键点：第一次查找后返回对应值并将该数组中的值修改为 -1 或其他不可能值
    if(end[cur] > 0)
    {
        int ret = end[cur];
        end[cur] = -1;
        return ret;
    }

    return end[cur];
}

int main(void)
{
    std::cin >> n;

    std::string str;

    while(n--) {
        std::cin >> str;
        insert(str);
    }

    std::cin >> m;

    while(m--) {
        std::cin >> str;

        int ret = find(str);
        if(-1 == ret) {
            std::cout << "REPEAT" << std::endl;
        } else if(0 == ret) {
            std::cout << "WRONG" << std::endl;
        } else {
            std::cout << "OK" << std::endl;
        }
    }
    return 0;
}

//P10471 最大异或对 The XOR Largest Pair
#include <iostream>

const int N = 1e5 + 10;
int n, idx;
int trie[N * 32][2], a[N];

void insert(int val)
{
    int cur = 0;

    for(int i = 31; i >= 0; i--) {
        //从高到低获取每一位的 0 或 1
        int path = (val >> i) & 1;

        if(0 == trie[cur][path]) {
            trie[cur][path] = ++idx;
        }

        cur = trie[cur][path];
    }
}

int find_max(int val)
{
    int cur = 0, ret = 0;

    for(int i = 31; i >= 0; i--) {
        //从高到低获取每一位的 0 或 1
        int path = (val >> i) & 1;

        if(trie[cur][path ^ 1]) {//先查找是否有相反位的路径
            ret |= (1 << i);//有则将结果该位置为 1
            cur = trie[cur][path ^ 1];
        } else {//没有则保持 0
            cur = trie[cur][path];
        }
    }
    return ret;
}

int main(void)
{
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        insert(a[i]);
    }

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        int x = find_max(a[i]);
        if(x > ret) {
            ret = x;
        }
    }
    std::cout << ret << std::endl;

    return 0;
}