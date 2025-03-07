//单调栈 Monotonic Stack
//P5788 【模板】单调栈
#include <iostream>
#include <stack>

const int N = 3e6 + 10;
int n;
int a[N], b[N];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //维护一个单调递减的栈
    std::stack<int> st;//存放下标
    for(int i = n; i >= 1; --i) {
        while(st.size() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if(st.size()) {
            b[i] = st.top();
        }

        st.push(i);
    }

    for(int i = 1; i <= n; ++i) {
        std::cout << b[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

//P1901 发射站
#include <iostream>
#include <stack>
#include <algorithm>

const int N = 1e6 + 10;
int n;
struct node {
    int h;
    int v;
}a[N];
int ret[N];

int main(void) {
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].h >> a[i].v;
    }

    std::stack<int> st;
    //先维护从左到右的单调递减栈
    for(int i = 1; i <= n; ++i) {
        while(st.size() && a[st.top()].h <= a[i].h) {
            st.pop();
        }

        if(st.size()) {
            ret[st.top()] += a[i].v;
        }

        st.push(i);
    }
    
    //清空栈
    while(st.size()) {
        st.pop();
    }

    //维护从右到左的单调递减栈
    for(int i = n; i >= 1; --i) {
        while(st.size() && a[st.top()].h <= a[i].h) {
            st.pop();
        }

        if(st.size()) {
            ret[st.top()] += a[i].v;
        }

        st.push(i);
    }

    //遍历结果数组查找最大值
    int maxi = 0;
    for(int i = 1; i <= n; ++i) {
        maxi = std::max(maxi, ret[i]);
    }
    std::cout << maxi << std::endl;

    return 0;
}

//SP1805 HISTOGRA - Largest Rectangle in a Histogram
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

typedef long long LL;
const int N = 1e5 + 10;
int n;
LL a[N], ret[N];

int main(void) {
    while(std::cin >> n && n) {
        memset(ret, 0, sizeof(ret));

        for(int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        //维护一个单调递增的栈
        std::stack<int> st;
        //从左到右
        for(int i = 1; i <= n; ++i) {
            while(st.size() && a[st.top()] >= a[i]) {
                st.pop();
            }

            if(st.size()) { //左侧有比当前位置矮的矩形
                ret[i] += i - st.top();
            } else { //左侧无较矮矩形
                ret[i] += i;
            }

            st.push(i);
        }

        //清空栈
        while(st.size()) {
            st.pop();
        }

        //从右到左
        for(int i = n; i >= 1; --i) {
            while(st.size() && a[st.top()] >= a[i]) {
                st.pop();
            }

            if(st.size()) { //右侧有比当前位置矮的矩形
                ret[i] += st.top() - i;
            } else { //右侧无较矮矩形
                ret[i] += n - i + 1;
            }

            st.push(i);
        }

        //计算并取得最大矩形面积
        LL maxi = 0;
        for(int i = 1; i <= n; ++i) {
            maxi = std::max(maxi, (ret[i] - 1) * a[i]);
        }
        std::cout << maxi << std::endl;
    }

    return 0;
}