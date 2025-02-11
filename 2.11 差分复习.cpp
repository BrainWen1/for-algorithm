//P3717 [AHOI2017初中组] cover
#include <iostream>
#include <cmath>

using namespace std;

const int N = 100 + 10;
int n, m, r;
int a[N][N];

int main(void)
{
    cin >> n >> m >> r;

    int x, y;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x][y] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                double len = sqrt((i - x) * (i - x) + (j - y) * (j - y));
                if(len <= r) a[i][j] = 1;
            }
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j]) count++;
        }
    }
    cout << count << endl;

    return 0;
}

//P2367 语文成绩
#include <iostream>

using namespace std;

const int N = 5e6 + 10;
int n, p;
int a[N];
int diff[N];

void add(int left, int right, int val)
{
    diff[left] += val;
    diff[right + 1] -= val;
}

int main(void)
{
    cin >> n >> p;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) diff[i] = a[i] - a[i - 1];

    while(p--)
    {
        int x, y, val;
        cin >> x >> y >> val;

        add(x, y, val);
    }

    int min = 100;
    for(int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        if(diff[i] < min) min = diff[i];
    }
    cout << min << endl;

    return 0;
}

//P9094 [PA 2020] Mieszanie kolorów
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, m;
int l, r, k;
int diff[N][4];

void add(int left, int right, int val)
{
    diff[left][val]++;
    diff[right + 1][val]--;
}

int main(void)
{
    cin >> n >> m;

    while(m--)
    {
        cin >> l >> r >> k;
        add(l, r, k);
    }

    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
            diff[i][j] += diff[i - 1][j];
        if(diff[i][1] && diff[i][2] && !diff[i][3]) count++;
    }
    cout << count << endl;
    
    return 0;
}

//P1672 [USACO05FEB] Feed Accounting S
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 2e3 + 10;
int c, f1, f2, d;
int diff[N];
int pre[N];

int main(void)
{
    cin >> c >> f1 >> f2 >> d;

    int left, right;
    int mini = d, maxi = d;
    for(int i = 1; i <= c; i++)
    {
        cin >> left >> right;
        diff[left]++;
        diff[right + 1]--;
        mini = min(mini, left);
        maxi = max(maxi, right);
    }
    
    for(int i = mini; i <= maxi; i++)
    {
        diff[i] += diff[i - 1];
        pre[i] = diff[i];
    }

    int index = d;
    for(int i = d; i >= mini; i--)
    {
        f2 += pre[i];
        if(f2 >= f1)
        {
            index = i;
            break;
        }
    }
    cout << index << endl;

    return 0;
}