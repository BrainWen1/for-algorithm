// P1878 Îèµ¸¿Î
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

const int N = 2e5 + 10;
int n;

struct peo
{
	char sex;
	int val;
	bool sign;
}people[N];

int pre[N], nex[N];

struct node
{
	int data;
	int l;
	int r;
	bool operator<(const node& temp)const
	{
		if(data != temp.data) return data > temp.data;
		else if(l != temp.l) return l > temp.l;
		else return r > temp.r;
	}
};

int main(void)
{
	priority_queue<node> heap;
	vector<node> vec;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> people[i].sex;
		pre[i] = i - 1;
		nex[i] = i + 1;
	}
	nex[n] = 0;
	for(int i = 1; i <= n; i++) cin >> people[i].val;
	
	for(int i = 1; i < n; i++)
	{
		if(people[i].sex != people[i + 1].sex)
			heap.push({abs(people[i].val - people[i + 1].val), i, i + 1});
	}
	
	while(heap.size())
	{
		node tmp = heap.top(); heap.pop();
		
		if(people[tmp.l].sign || people[tmp.r].sign)
			continue;
			
		vec.push_back(tmp);
		people[tmp.l].sign = true; people[tmp.r].sign = true;
		
		pre[nex[tmp.r]] = pre[tmp.l];
		nex[pre[tmp.l]] = nex[tmp.r];
		
		int left = pre[tmp.l], right = nex[tmp.r];
		if(left && right && people[left].sex != people[right].sex)
			heap.push({abs(people[left].val - people[right].val), left, right});
	}
	
	cout << vec.size() << endl;
	
	for(auto e : vec)
	{
		if(e.l <= e.r) cout << e.l << ' ' << e.r << endl;
		else cout << e.r << ' ' << e.l << endl;
	}
	
	return 0;
}
