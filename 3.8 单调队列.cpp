//单调队列 Monotonic Queue
//P1886 滑动窗口 /【模板】单调队列
#include <iostream>
#include <deque>

const int N = 1e6 + 10;
int n, k;
int a[N], mini[N], maxi[N];

int main(void) {
    std::cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //维护一个单调递增的队列
    std::deque<int> que;
    for(int i = 1; i <= n; ++i) {
        while(que.size() && a[que.back()] >= a[i]) {
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

    //清空队列
    que.clear();

    //维护一个单调递减的队列
    for(int i = 1; i <= n; ++i) {
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

    return 0;
}

//P2251 质量检测
#include <iostream>
#include <deque>

const int N = 1e6 + 10;
int n, m;
int a[N];

int main(void) {
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    //维护一个单调递增的队列
    std::deque<int> que;
    for(int i = 1; i <= n; ++i) {
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