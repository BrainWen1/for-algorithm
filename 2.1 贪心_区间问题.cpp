// P1803.凌乱的yyy / 线段覆盖
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n;
struct node
{
	int x;
	int y;
}a[N];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	
	sort(a, a + n, [](node& l, node& r)->bool{
		return l.x < r.x;//按左区间升序排列 
	});
	
	node tmp = a[0];//初始化基准 
	int count = 1;
	for(int i = 1; i < n; i++)
	{
		if(a[i].x >= tmp.y)//不重叠 
		{
			count++;
			tmp = a[i];//更新基准 
		}
		else//重叠 
		{
			if(tmp.y <= a[i].y) continue;//保留右区间较小元素 
			else tmp = a[i];
		}
	}
	cout << count << endl;
		
	return 0;
}

// UVA1193.Radar Installation
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e3 + 10;
int n, d;
struct node
{
	double a;
	double b;
}interval[N];

int main(void)
{
	int k = 1;
	while(cin >> n >> d && (n || d))//多组输入数据 
	{
		int flag = 0;
		double x, y;
		for(int i = 0; i < n; i++)//输入所有(x,y)并计算区间 
		{
			cin >> x >> y;
			if(y > d)//无解情况处理 
			{
				cout << "Case " << k++ << ": " << -1 << endl;
				flag = 1;
				break;
			}
			double len = sqrt(d * d - y * y);//二维降一维，转区间问题 
			interval[i].a = x - len;
			interval[i].b = x + len;
		}
		if(flag) continue;
	
		sort(interval, interval + n, [](node& l, node& r)->bool{
			return l.a < r.a;//按区间左端点排序 
		});
		
		node tmp = interval[0];//初始基准 
		int count = 1;
		for(int i = 1; i < n; i++)//计算重叠区间个数->最少雷达个数 
		{
			if(interval[i].a > tmp.b)//不重叠 
			{
				count++;//计数 
				tmp = interval[i];//下一基准 
			}
			else//重叠 
			{
				if(interval[i].b >= tmp.b);//保留靠左的右端点
				else tmp = interval[i];
			}
		}
		cout << "Case " << k++ << ": " << count << endl;
	}
	return 0;
}

// P2887.[USACO07NOV] Sunscreen G
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2500 + 10;
int C, L;
struct node//奶牛 
{
	int minSPFi;//最小阳光强度 
	int maxSPFi;//最大阳光强度 
}a[N];
struct lotion//防晒霜 
{
	int SPFi;//防晒强度 
	int Coveri;//可使用次数 
}b[N];

int main(void)
{
	cin >> C >> L;
	for(int i = 0; i < C; i++) cin >> a[i].minSPFi >> a[i].maxSPFi;
	for(int i = 0; i < L; i++) cin >> b[i].SPFi >> b[i].Coveri;
	
	sort(a, a + C, [](node& l, node& r)->bool{
		return l.minSPFi > r.minSPFi;//按最小阳光强度降序排列 
	});
	sort(b, b + L, [](lotion& l, lotion& r)->bool{
		return l.SPFi > r.SPFi;//按防晒强度降序排列 
	});
	
	int count = 0;
	for(int i = 0; i < C; i++)
	{
		for(int j = 0; j < L; j++)
		{
			if(b[j].Coveri == 0) continue;//防晒霜数量为零
			if(b[j].SPFi < a[i].minSPFi) break;//所有防晒霜都不能满足当前奶牛
			if(b[j].SPFi > a[i].maxSPFi) continue;//当前防晒霜强度太高
			// a[i].minSPFi <= b[j].SPFi <= a[i].maxSPFi
			count++;
			b[j].Coveri--;
			break;
		}
	}
	cout << count << endl;
	
	return 0;
}

// P2859.[USACO06FEB] Stall Reservations S
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 5e4 + 10;
int n;
int ret[N];//存储各个奶牛产奶的牛棚 
struct node//奶牛 
{
	int start;//产奶开始时间 / 牛棚内结束时间 
	int end;//产奶结束时间 / 牛棚编号 
	int index;//奶牛编号 
	
	//重载小于号运算符->存储结构体的小根堆
	bool operator<(const node& other) const
	{
		return this->start > other.start;//按牛棚结束时间建小根堆 
	}
}a[N];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].start >> a[i].end;
		a[i].index = i;//保存下标 
	}
	
	sort(a + 1, a + 1 + n, [](node& l, node& r)->bool{
		return l.start < r.start;//按开始时间升序排列 
	});
	
	//小根堆->快速查询当前所有奶牛中最近产奶结束时间所对应的牛棚 
	priority_queue<node> heap;
	
	ret[a[1].index] = 1; 
	heap.push({a[1].end, 1});//初始化堆 
	int num = 1;//标记牛棚编号
	
	for(int i = 2; i <= n; i++)
	{
		if(a[i].start <= heap.top().start)//没有现成的牛棚
		{
			num++;
			ret[a[i].index] = num;//当前奶牛所在牛棚的编号 
			heap.push({a[i].end, num});
		}
		else//有现成的牛棚
		{
			node tmp = heap.top();
			heap.pop();
			ret[a[i].index] = tmp.end;//当前奶牛所在牛棚编号为堆顶元素牛棚编号 
			heap.push({a[i].end, tmp.end});
		}
	}
	
	cout << num << endl;
	for(int i = 1; i <= n; i++) cout << ret[i] << endl;
	
	return 0;
}
