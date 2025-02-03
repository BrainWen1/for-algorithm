//递归初阶 
void Dfs(int root)//深度优先搜索->前序遍历 
{
	if(0 == root) return;//递归出口 
	
	cout << root <<  ' ';//根 
	Dfs(left[root]);//左子树 
	Dfs(right[root]);//右子树 
}

void merge_sort(int left, int right)//归并排序 
{
	if(left >= right) return;
	
	int mid = (right - left) / 2 + left;
	merge_sort(left, mid);//左区间 
	merge_sort(mid + 1, right);//右区间 
	
	inplace_merge(a + left, a + mid + 1, a + right + 1);//原地合并函数 
}

// 1205：汉诺塔问题 
#include <iostream>

using namespace std;

int n;
char ch1, ch2, ch3

void HannuoTa(int high, char x, char y, char z)
{
	if(0 == high) return;//递归出口 
	
	HannuoTa(high - 1, x, z, y);//将上面(high - 1)的圆盘放到右边 
	printf("%c->%d->%c\n", x, high, z);//将下面最大的一个放到中间 
	HannuoTa(high - 1, y, x, z);//将右边的堆到中间上面 
}

int main(void)
{
	cin >> n >> ch1 >> ch2 >> ch3;//ch1 --> ch2 <-- ch3
	
	HannuoTa(n, ch1, ch3, ch2);
	
	return 0;
}

// P10457.占卜DIY
#include <iostream>

using namespace std;

int a[14][5];
int token[14];//标记当前牌堆被操作了几次->初始化为 4->为 0则为一对 

void Game(int val)
{
	if(13 == val) return;//递归出口 
	
	Game(a[val][token[val]--]); 
}

int main(void)
{
	for(int i = 1; i <= 13; i++)
	{
		token[i] = 4;//初始化为 4 
		for(int j = 1; j <= 4; j++)
		{
			char ch = 0;
			cin >> ch;
			if(ch >= '2' && ch <= '9') a[i][j] = ch - '0';
			else if(ch == '0') a[i][j] = 10;//转换数据类型方便处理 
			else if(ch == 'J') a[i][j] = 11;
			else if(ch == 'Q') a[i][j] = 12;
			else if(ch == 'K') a[i][j] = 13;
			else if(ch == 'A') a[i][j] = 1;
		}
	}
	
	for(int i = 1; i <= 4; i++) Game(a[13][i]);//迭代->递归 
	
	int ret = 0;
	for(int i = 1; i <= 13; i++) if(0 == token[i]) ret++;//统计 
	cout << ret << endl;
	
	return 0;
}

// P1087 [NOIP 2004 普及组] FBI 树
#include <iostream>

using namespace std;

const int N = 10 + 1;
int n;
int f[1 << N];//前缀和数组 

void Dfs(int left, int right)//后序遍历 
{
	if(left > right) return;//递归出口(1) 
	
	char ret = 0;
	int sum = f[right] - f[left - 1];//利用前缀和快速计算 
	
	if(sum == right - left + 1) ret = 'I';
	else if(sum == 0) ret = 'B';
	else ret = 'F';
	
	if(left == right)//递归出口(2) 
	{
		cout << ret;
		return;
	}
	
	Dfs(left, (left + right) / 2);//左子树 
	Dfs((left + right) / 2 + 1, right);//右子树 
	
	cout << ret;
}

int main(void)
{
	cin >> n;
	n = (1 << n);//快速计算 2 ^ n
	
	for(int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		if(ch == '1') f[i] = f[i - 1] + 1;//前缀和->方便判断是哪种串 
		else f[i] = f[i - 1];
	}
	
	Dfs(1, n);//后序遍历并输出值 
	
	return 0;
}
