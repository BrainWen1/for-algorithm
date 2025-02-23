//单调栈
//• 找左侧，正遍历；找右侧，逆遍历；
//• ⽐它⼤，单调减；⽐它⼩，单调增。
#include <iostream>
#include <stack>

const int N = 100;
int n;
int a[N], ret[N];

//寻找当前元素左侧，离它最近，并且⽐它⼤的元素在哪
//维护一个单调递减的栈
void left_greater()
{
    std::stack<int> st;

    for(int i = 1; i <= n; i++) {
        while(st.size() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if(st.size()) {
            ret[i] = st.top();
        }

        st.push(i);
    }
}

//寻找当前元素左侧，离它最近，并且⽐它⼩的元素在哪
//维护一个单调递增的栈
void left_less()
{
    std::stack<int> st;

    for(int i = 1; i <= n; i++) {
        while(st.size() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if(st.size()) {
            ret[i] = st.top();
        }

        st.push(i);
    }
}

//寻找当前元素右侧，离它最近，并且⽐它⼤的元素在哪
//维护一个单调递减的栈
void right_greater()
{
    std::stack<int> st;

    for(int i = n; i >= 1; i--) {
        while(st.size() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if(st.size()) {
            ret[i] = st.top();
        }

        st.push(i);
    }
}

//寻找当前元素右侧，离它最近，并且⽐它⼩的元素在哪
//维护一个单调递增的栈
void right_less()
{
    std::stack<int> st;

    for(int i = n; i >= 1; i--) {
        while(st.size() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if(st.size()) {
            ret[i] = st.top();
        }

        st.push(i);
    }
}

inline void print_ret()
{
    for(int i = 1; i <= n; i++) {
        std::cout << ret[i] << ' ';
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //left_greater();
    //left_less();
    //right_greater();
    right_less();

    print_ret();

    return 0;
}

//P5788 【模板】单调栈
#include <iostream>
#include <stack>

const int N = 3e6 + 10;
int n;
int a[N], ret[N];

//向右找大于数
//维护一个单调递减的栈
void right_greater()
{
    //创建栈
    std::stack<int> st;

    //逆序遍历原数组
    for(int i = n; i >= 1; i--) {
        //维护栈的单调性
        while(st.size() && a[st.top()] <= a[i]) {
            st.pop();
        }

        //如果栈中有元素,则当前位置的结果为栈顶存放的下标
        if(st.size()) {
            ret[i] = st.top();
        }

        //将当前元素压入栈
        st.push(i);
    }

    //正序输出
    for(int i = 1; i <= n; i++) {
        std::cout << ret[i] << ' ';
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    right_greater();

    return 0;
}

//P1901 发射站
#include <iostream>
#include <stack>

const int N = 1e6 + 10;
int n;
int h[N], v[N], ret[N];

void left_greater()
{
    std::stack<int> st;

    for(int i = 1; i <= n; i++) {
        //维护栈的单调性
        while(st.size() && h[st.top()] <= h[i]) {
            st.pop();
        }

        //当前栈顶(若有)对应的发射台应接收当前i对应的发射台的能量
        if(st.size()) {
            ret[st.top()] += v[i];
        }

        //将当前发射台压入栈
        st.push(i);
    }
}

void right_greater()
{
    std::stack<int> st;

    for(int i = n; i >= 1; i--) {
        while(st.size() && h[st.top()] <= h[i]) {
            st.pop();
        }

        if(st.size()) {
            ret[st.top()] += v[i];
        }

        st.push(i);
    }
}

int main(void)
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> h[i] >> v[i];
    }

    //维护两个单调栈,一个左一个右,都为单调递减的栈
    left_greater();
    right_greater();

    //查找ret数组中的最大值
    int maxi = ret[1];
    for(int i = 2; i <= n; i++) {
        if(ret[i] > maxi) {
            maxi = ret[i];
        }
    }
    std::cout << maxi << std::endl;

    return 0;
}

//SP1805 HISTOGRA - Largest Rectangle in a Histogram
#include <iostream>
#include <stack>

typedef long long LL;
const int N = 1e5 + 10;
LL n;
LL a[N], left[N], right[N];

void left_less()
{
    std::stack<int> st;

    //遍历数组计算每一个矩形向此边延伸的最大距离
    for(int i = 1; i <= n; i++) {
        //维护栈的单调性
        while(st.size() && a[st.top()] >= a[i]) {
            st.pop();
        }

        //当前栈顶(若有)对应的矩形则为向此边延伸的最大距离终点
        if(st.size()) {
            left[i] = st.top();
        } else {
            left[i] = 0;//若没有终点则将此边全部用于计算面积
        }

        //压栈
        st.push(i);
    }
}

void right_less()
{
    std::stack<int> st;

    for(int i = n; i >= 1; i--) {
        while(st.size() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if(st.size()) {
            right[i] = st.top();
        } else {
            right[i] = n + 1;
        }

        st.push(i);
    }
}

int main(void)
{
    //多组测试数据
    while(std::cin >> n && n) {
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }

        //向左找最近的小于数
        left_less();
        //向右找最近的小于数
        right_less();

        LL maxi = 0;
        for(int i = 1; i <= n; i++) {
            //计算以当前矩形为中心的最大矩形面积
            LL val = a[i] * (right[i] - left[i] - 1);
            if(val > maxi) {
                maxi = val;
            }
        }

        std::cout << maxi << std::endl;
    }

    return 0;
}