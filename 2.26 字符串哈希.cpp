//P3370 【模板】字符串哈希
#include <iostream>
#include <string>
#include <algorithm>

//C++中ULL类型溢出时会自动取模
typedef unsigned long long ULL;
const int N = 1e4 + 10, P = 131;
int n;
ULL hash[N];//存放每一个字符串映射的哈希值

//获取当前字符串的哈希值
ULL get_hash(std::string& str)
{
    ULL ret = 0;
    int n = str.size();
    for(int i = 0; i < n; i++) {
        ret = ret * P + (ULL)str[i];//递推公式
    }
    return ret;
}

int main(void)
{
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::string str;
        std::cin >> str;

        //获取每个字符串的哈希值
        hash[i] = get_hash(str);
    }

    //对所有哈希值排序,便于从前往后遍历一遍得到结果
    std::sort(hash + 1, hash + 1 + n);

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        //相等元素不计数
        if(hash[i] != hash[i - 1]) {
            ret++;
        }
    }
    std::cout << ret << std::endl;

    return 0;
}

//P10468 兔子与兔子
#include <iostream>
#include <string>

typedef unsigned long long ULL;
const int N = 1e6 + 10, P = 131;
int n, len;
char a[N];
ULL f[N], p[N];
// f 前缀和数组,第 i 个值表示前 i 个字符组成的字符串所映射的哈希值
// p 数组中,第 i 个值表示模数 P 的 i 次方

//字符串快读模板
void read(char* str)
{
    char ch;
    // 跳过前导空白字符
    while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t') {}
    do {
        str[++len] = ch;
    } while ((ch = getchar()) != ' ' && ch != '\n' && ch != '\t' && ch != EOF);
    str[len + 1] = '\0'; // 字符串结尾添加空字符
}

//处理字符串前缀和哈希表
void init_hash()
{
    f[0] = 0, p[0] = 1;
    for(int i = 1; i <= len; i++) {
        f[i] = f[i - 1] * P + (ULL)a[i];//字符串哈希值递推公式
        p[i] = p[i - 1] * P;//存下 P 的 i 次方的值
    }
}

//获取某个区间的字符串对应的哈希值
ULL get_hash(int l, int r)
{
    return f[r] - f[l - 1] * p[r - l + 1];
}

int main(void)
{
    read(a);
    init_hash();

    std::cin >> n;

    while(n--) {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;

        ULL hash_1 = get_hash(l1, r1);
        ULL hash_2 = get_hash(l2, r2);

        if(hash_1 == hash_2) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No"  << std::endl;
        }
    }

    return 0;
}