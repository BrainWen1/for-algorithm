//P3370 【模板】字符串哈希
#include <iostream>
#include <string>
#include <algorithm>

//unsigned long long 在溢出时会自动取模
typedef unsigned long long ULL;
const int N = 1e4 + 10, P = 131; //模数 P 选择 131
int n, sum;
int ret[N]; //存储哈希值

ULL get_hash(std::string& str) {
    ULL ret = 0;
    int len = str.size();

    for(int i = 0; i < len; ++i) {
        ret = ret * P + str[i]; //计算哈希值公式
    }
    return ret;
}

int main(void) {
    std::cin >> n;
    
    std::string str;

    //读入所有字符串，并且获取其哈希值并存储
    for(int i = 1; i <= n; ++i) {
        std::cin >> str;

        ret[i] = get_hash(str);
    }

    //排序便于后续统计不相等数的数量
    std::sort(ret + 1, ret + 1 + n);

    for(int i = 1; i <= n; ++i) {
        if(ret[i] != ret[i - 1]) { //不重复则数量加一
            sum++;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}

//P10468 兔子与兔子
#include <iostream>
#include <string>

typedef unsigned long long ULL;
const int N = 1e6 + 10, P = 13331; //在数据量大的场景下，优先选择 13331 作为基数，因其质数性、较大的数值和与常见基数的互质性，能提供更优的哈希效果。
int m, l1, r1, l2, r2, len;
ULL prefix[N]; //前缀和数组，便于多次询问同一个字符串的特定区间的哈希值
ULL p[N]; //记录每个位置的 P 的次方数
std::string str;

inline void init_hash() {
    prefix[0] = 0, p[0] = 1; //初始化两个数组

    for(int i = 1; i <= len; ++i) {
        prefix[i] = prefix[i - 1] * P + str[i]; //前缀哈希值计算公式
        p[i] = p[i - 1] * P; //P 的次方数加一
    }
}

ULL get_hash(int l, int r) {
    return prefix[r] - (prefix[l - 1] * p[r - l + 1]); //特定区间哈希值计算公式
}

int main(void) {
    std::cin >> str >> m;

    len = str.size();
    str = " " + str;

    init_hash();

    while(m--) {
        std::cin >> l1 >> r1 >> l2 >> r2;

        //获取两个区间的哈希值并判断结果
        if(get_hash(l1, r1) == get_hash(l2, r2)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No"  << std::endl;
        }
    }
    return 0;
}