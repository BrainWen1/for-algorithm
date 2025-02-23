//P1886 滑动窗口 /【模板】单调队列
#include <iostream>
#include <deque>

const int N = 1e6 + 10;
int n, k;
int a[N];

//单调递增队列->队头为最小值
void up()
{
    std::deque<int> que;

    //遍历数组
    for(int i = 1; i <= n; i++) {
        //维持队列的单调性
        while(que.size() && a[que.back()] >= a[i]) {
            que.pop_back();
        }

        //窗口右滑
        que.push_back(i);

        //保持窗口内元素数量合法性
        if(que.back() - que.front() + 1 > k) {
            que.pop_front();
        }

        //窗口合法才会输出队头即最小值
        if(i >= k) {
            std::cout << a[que.front()] << ' ';
        }
    }
    std::cout << std::endl;
}

//单调递减队列->最大值
void down()
{
    std::deque<int> que;

    for(int i = 1; i <= n; i++) {
        while(que.size() && a[que.back()] <= a[i]) {
            que.pop_back();
        }

        que.push_back(i);

        if(que.back() - que.front() + 1 > k) {
            que.pop_front();
        }

        if(i >= k) {
            std::cout << a[que.front()] << ' ';
        }
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    up();
    down();

    return 0;
}

//P2251 质量检测
#include <iostream>
#include <deque>

const int N = 1e6 + 10;
int n, m;
int a[N];

int main(void)
{
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    //模拟维护一个单调递增的队列->查找最小值
    std::deque<int> que;

    for(int i = 1; i <= n; i++) {
        while(que.size() && a[que.back()] >= a[i]) {
            que.pop_back();
        }

        que.push_back(i);

        if(que.back() - que.front() + 1 > m) {
            que.pop_front();
        }

        if(i >= m) {
            std::cout << a[que.front()] << std::endl;
        }
    }

    return 0;
}