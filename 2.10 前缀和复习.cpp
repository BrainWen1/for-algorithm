//P1719 最大加权矩形
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 120 + 10;
int n;
int f[N][N]; 

int main(void)
{
    cin >> n;

    //前缀和数组预处理数据
    int val;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> val;
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] +  val;
        }
    }

    //枚举
    int ret = -1e9;
    for(int x1 = 1; x1 <= n; x1++)
    {
        for(int y1 = 1; y1 <= n; y1++)
        {
            for(int x2 = x1; x2 <= n; x2++)
            {
                for(int y2 = y1; y2 <= n; y2++)
                {
                    int sum = f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
                    ret = max(ret, sum);
                }
            }
        }
    }
    cout << ret << endl;

    return 0;
}

//P9532 [YsOI2023] 前缀和
#include <iostream>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, x;
        cin >> n >> x;

        //计算x中2的最高次幂
        int power = 0;
        int temp = x;
        while (temp % 2 == 0)
        {
            temp /= 2;
            power++;
        }

        //确保幂次不超过 n - 2
        if (power > n - 2)
        {
            power = n - 2;
        }
        // 计算最小的a1
        long long minA1 = x / (1 << power);

        cout << minA1 * (1 << (n - 2)) << endl;
    }

    return 0;
}

//B3612 【深进1.例1】求区间和
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, val, m;
int f[N];

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> val;
        f[i] = f[i - 1] + val;
    }

    cin >> m;
    int left, right;
    while(m--)
    {
        cin >> left >> right;
        cout << f[right] - f[left - 1] << endl;
    }

    return 0;
}

//P8772 [蓝桥杯 2022 省 A] 求和
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;
LL a[N], f[N];

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //前缀和数组预处理
        f[i] = f[i - 1] + a[i];
    }

    long long ret = 0;
    for(int i = 1; i < n; i++)
    {
        //a[i]乘上(a[i + 1] + ... + a[n])
        ret += a[i] * (f[n] - f[i]);
    }

    cout << ret << endl;

    return 0;
}

//P8780 [蓝桥杯 2022 省 B] 刷题统计
//(模拟)
#include <iostream>

using namespace std;

typedef long long LL;
LL a, b, n;

int main(void)
{
    cin >> a >> b >> n;
    
    LL week = a * 5 + b * 2;
    
    LL cont = n / week;
    LL rest = n % week;
    
    LL days = cont * 7;
    if(rest <= 5 * a && rest > 0)
    {
        days += rest / a;
        if(rest % a) days++;
    }
    else if(rest > 5 * a && rest < 5 * a + 2 * b)
    {
        rest -= 5 * a;
        days += 5 + rest / b;
        if(rest % b) days++;
    }
    cout << days << endl;
    
    return 0;
}

//P2004 领地选择
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e3 + 10;
int n, m, d;
LL f[N][N];

int main(void)
{
    cin >> n >> m >> d;
    LL val = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> val;
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + val;
        }
    }

    LL ret = -1e10, index_x = -1, index_y = -1;
    for(int x1 = 1; x1 <= n - d + 1; x1++)
        for(int y1 = 1; y1 <= m - d + 1; y1++) 
        {
            int x2 = x1 + d - 1, y2 = y1 + d - 1;
             val = f[x2][y2] -f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
             if(val > ret)
             {
                ret = val;
                index_x = x1;
                index_y = y1;
            }
        }
    cout << index_x << ' ' << index_y << endl;

    return 0;
}