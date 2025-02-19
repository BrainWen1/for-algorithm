//B3622 枚举子集（递归实现指数型枚举）
#include <iostream>
#include <string>

int n;
std::string path;

void dfs(int pos)
{
    //递归出口
    if(pos > n) {
        //输出当前枚举结果
        std::cout << path << std::endl;
        return;
    }

    //不选该学生
    path += "N";
    dfs(pos + 1);//进入下一个学生的选择
    path.pop_back();//回溯

    //选该学生
    path += "Y";
    dfs(pos + 1);
    path.pop_back();
}

int main(void)
{
    std::cin >> n;

    dfs(1);

    return 0;
}

//P10448 组合型枚举
#include <iostream>
#include <vector>

int n, m;
std::vector<int> path;

void dfs(int pos, int val)
{
    //递归出口
    if(pos > m) {
        //输出当前枚举的结果
        for(int i = 0; i < m; i++) {
            std::cout << path[i] << ' ';
        }
        std::cout << std::endl;
        return;
    }

    //枚举当前学生的选择
    for(int i = val; i <= n; i++) {
        path.push_back(i);

        //进入下一个学生的选择
        dfs(pos + 1, i + 1);

        //回溯
        path.pop_back();
    }
}

int main(void)
{
    std::cin >> n >> m;

    dfs(1, 1);

    return 0;
}

//B3623 枚举排列（递归实现排列型枚举）
#include <iostream>
#include <vector>

int n, k;
std::vector<int> path;
bool st[10 + 5];

void dfs(int pos)
{
    //递归出口
    if(pos > k) {
        for(int i = 0; i < k; i++) {
            std::cout << path[i] << ' ';
        }
        std::cout << std::endl;
        return;
    }

    //枚举当前位置的选择
    for(int i = 1; i <= n; i++) {
        //如果当前枚举的数字i已经被选择过,则跳过
        if(st[i]) {
            continue;
        }
        //没有选择则放入path中并标true
        path.push_back(i);
        st[i] = true;

        //进入下一个位置的值的选择
        dfs(pos + 1);

        //回溯
        st[i] = false;
        path.pop_back();
    }
}

int main(void)
{
    std::cin >> n >> k;

    dfs(1);

    return 0;
}

//P1706 全排列问题
#include <iostream>
#include <vector>
#include <iomanip>

int n;
std::vector<int> path;
bool st[10];

void dfs(int pos)
{
    //递归出口
    if(pos > n) {
        for(int i = 0; i < n; i++) {
            std::cout << std::setw(5) << path[i];
        }
        std::cout << std::endl;
        return;
    }

    //枚举当前位置的值的选择
    for(int i = 1; i <= n; i++) {
        //如果该i值已经出现过,则跳过
        if(st[i]) {
            continue;
        }

        //如果没有出现过,则放入当前位置
        path.push_back(i);
        st[i] = true;

        //进入下一个位置的选择
        dfs(pos + 1);

        //回溯
        path.pop_back();
        st[i] = false;
    }
}

int main(void)
{
    std::cin >> n;

    dfs(1);

    return 0;
}