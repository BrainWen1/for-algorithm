// NC233601.【模板】哈夫曼编码
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

int main(void)
{
	priority_queue<LL, vector<LL>, greater<LL>> heap;//创建小根堆 
	int n; cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		heap.push(tmp);//小根堆自动调整 
	}
	
	LL ret = 0;
	while(heap.size() > 1)//最后只有一颗树包含所有元素时退出循环 
	{
		LL a = heap.top();//取出最小的两种字符个数 
		heap.pop();
		LL b = heap.top();
		heap.pop();
		heap.push(a + b);//合并插入小根堆中自动调整 
		ret += a + b;//累加计算带权路径长度 
	}
	cout << ret << endl;
	
	return 0;
}

// P1090 [NOIP 2004 提高组] 合并果子
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int>> heap;
	int n; cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		heap.push(tmp);
	}
	
	int ret = 0; 
	while(heap.size() > 1)
	{
		int a = heap.top(); heap.pop();
		int b = heap.top(); heap.pop();
		heap.push(a + b);
		ret += a + b;
	}
	cout << ret << endl;
	
	return 0;
}
