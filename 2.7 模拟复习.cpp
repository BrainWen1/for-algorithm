// P1068 [NOIP 2009 普及组] 分数线划定
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e3 + 10;
int n, m;
struct node
{
	int id;
	int  score;
}a[N];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i].id >> a[i].score;
	
	sort(a + 1, a + 1 + n, [](node& l, node& r)->bool{
		if(l.score != r.score) return l.score > r.score;
		else return l.id < r.id;
	});//按笔试成绩降序排列，成绩相同按报名号升序排列 
	
	int k = m * 1.5;
	int floor = a[k].score;
	
	int i = 1, count = 0;
	while(a[i].score >= floor)
	{
		count++;
		i++;
	}
	cout << floor << ' ' << count << endl;
	
	i = 1;
	while(a[i].score >= floor)
	{
		cout << a[i].id << ' ' << a[i].score << endl;
		i++;
	}
	
	return 0;
}

// P1328 [NOIP 2014 提高组] 生活大爆炸版石头剪刀布
#include <iostream>

using namespace std;

const int N = 200 + 10;
int n, x, y;
int a[N], b[N];

int main(void)
{	
	cin >> n >> x >> y;
	for(int i = 1; i <= x; i++) cin >> a[i];
	for(int i = 1; i <= y; i++) cin >> b[i];
	
	int cnt1 = 0, cnt2 = 0;
	int cur1 = 1, cur2 = 1;
	for(int i = 1; i <= n; i++)
	{
		int val = b[cur2];
		if(a[cur1] == 0)
		{
			if(val == 1 || val == 4) cnt2++;
			else if(val == 2 || val == 3) cnt1++;
		}
		else if(a[cur1] == 1)
		{
			if(val == 0 || val == 3) cnt1++;
			else if(val == 2 || val == 4) cnt2++;
		}
		else if(a[cur1] == 2)
		{
			if(val == 0 || val == 3) cnt2++;
			else if(val == 1 || val == 4) cnt1++;
		}
		else if(a[cur1] == 3)
		{
			if(val == 0 || val == 1) cnt2++;
			else if(val == 2 || val == 4) cnt1++;
		}
		else if(a[cur1] == 4)
		{
			if(val == 0 || val == 1) cnt1++;
			else if(val == 2 || val == 3) cnt2++;
		}
		cur1++;
		cur2++;
		if(cur1 == x + 1) cur1 = 1;
		if(cur2 == y + 1) cur2 = 1; 
	}
	
	cout << cnt1 << ' ' << cnt2 << endl;
	
	return 0;
}

// P1789 【Mc生存】插火把
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 102 + 10;
int n, m, k;
int a[N][N];

//火把方向向量 
int dx1[13] = {  0,  0, 0, 0, 0, -2, -1, 1, 2, -1, 1,  1, -1};
int dy1[13] = { -2, -1, 0, 1, 2,  0,  0, 0, 0, -1, 1, -1,  1};
//萤石方向向量 
int dx2[25]={ -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
int dy2[25]={ -2, -1,  0,  1,  2, -2, -1,  0,  1,  2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2 };

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		for(int j = 0; j < 13; j++)
		{
			if(x + dx1[j] < 1 || x + dx1[j] > n || y + dy1[j] < 1 || y + dy1[j] > n) continue;
			a[x + dx1[j]][y + dy1[j]] = 1;
		}
	}
	
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		for(int j = 0; j < 25; j++)
		{
			if(x + dx2[j] < 1 || x + dx2[j] > n || y + dy2[j] < 1 || y + dy2[j] > n) continue;
			a[x + dx2[j]][y + dy2[j]] = 1;
		}
	}
	
	int o;
	for(int i = 1; i <= n; i++) o += count(a[i] + 1, a[i] + 1 + n, 0);
	cout << o << endl;
	
	return 0;
}

// P1319 压缩技术
#include <iostream>

using namespace std;

int n;

int main(void)
{
	cin >> n;

	int val = 0;
	int len = 0;
	int sum = 0;
	while(cin >> val)
	{
	    sum += val;
		for(int i = 0; i < val; i++)
		{
			if(len == n)
			{
				cout << endl;
				len = 0;
			}
			cout << 0;
			len++;
		}
		
		if(sum == n * n) break;
		
		cin >> val;
		sum += val;
		for(int i = 0; i < val; i++)
		{
			if(len == n)
			{
				cout << endl;
				len = 0;
			}
			cout << 1;
			len++;
		}
	}
	
	return 0;
}

// P1320 压缩技术（续集版）
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> grid;
string line;

int main(void)
{
    cin >> line;
    grid.push_back(line);
    
    int n = line.size();
    
    for(int i = 1; i < n; ++i)
	{
        cin >> line;
        grid.push_back(line);
    }

    string flattened;
    for(auto row : grid)
	{
        flattened += row;
    }

    vector<int> result;
    result.push_back(n);

    int current = 0;//0表示当前统计 0的个数，1表示统计 1的个数
    int count = 0;

    for(char ch : flattened)
	{
        if (current == 0)
		{
            if (ch == '0')
			{
                count++;
            }
			else
			{
                result.push_back(count);
                count = 1;
                current = 1;
            }
        }
		else
		{
            if (ch == '1') 
            {
                count++;
            }
			else
			{
                result.push_back(count);
                count = 1;
                current = 0;
            }
        }
    }

    if (count > 0)
	{
        result.push_back(count);
    }

	int len = result.size();
    for (int i = 0; i < len; i++)
	{
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}
