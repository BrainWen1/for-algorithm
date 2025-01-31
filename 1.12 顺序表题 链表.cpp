// 283.移动零
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    auto p1 = nums.begin(), p2 = p1 + 1;
    while(p2 < nums.end())
    {
    	if(*p1 == 0)
    	{
    		if(*p2 != 0)
			{
				swap(*p1, *p2);
				p1++;
			}
		}
		else
		{
			p1++;
		}
		p2++;
	}
};
int main(void)
{
	vector<int> arr = { 0,1,2,0,3,4,5,0,0,6 };

	moveZeroes(arr);
	
	for(auto e : arr)
		cout << e << ' ';
	cout << endl;
	
	return 0;
}

// 75.颜色分类
/*#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
    int count_0 = 0, count_1 = 0, count_2 = 0;
	for(auto e : nums)
	{
		if(e == 0) count_0++;
		if(e == 1) count_1++;
		if(e == 2) count_2++;
	}
	for(int i = 0;i < count_0; i++)
		nums[i] = 0;
	for(int i = 0;i < count_1; i++)
		nums[i + count_0] = 1;
	for(int i = 0;i < count_2; i++)
		nums[i + count_0 + count_1] = 2;
}
int main(void)
{
	vector<int> arr;
	
	int tmp = 0;
	for(int i = 0; i < 7; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sortColors(arr);
	
	for(auto e : arr)
		cout << e << ' ';
	cout << endl;
	
	return 0;
}*/

// 88.合并两个有序数组
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for(auto e : nums2)
	{
		nums1[m++] = e;
	}
	sort(nums1.begin(), nums1.end());
}

int main(void)
{
	vector<int> arr1 = { 1,2,3,0,0,0 };
	vector<int> arr2 = { 2,5,6 };
	
	merge(arr1, arr1.size() - arr2.size(), arr2, arr2.size());
	
	for(auto e : arr1)
		cout << e << ' ';
	cout << endl;
	
	return 0;
}*/

// The Blocks Problem
/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> nums;

void homing(int x)
{
	for(int i = 1; i < nums[x].size(); i++)
	{
		int k = nums[x][i];
		
		nums[k].resize(nums[k].size() + 1);
		nums[k].rotate(nums[k].begin(), nums[k].end() - 1, nums[k].end());
		
		nums[k][0] = k;
	}
	nums[x].resize(1);
}

void move_onto(int a, int b)
{
	homing(a);
	homing(b);
	nums[b].push_back(a);
	nums[a].clear();
}

void move_over(int a, int b)
{
	homing(a);
	nums[b].push_back(a);
	nums[a].clear();
}

void pile_over(int a, int b)
{
	nums[b].insert(nums[b].end(), nums[a].begin(), nums[a].end());
	nums[a].clear();
}

void pile_onto(int a, int b)
{
	homing(b);
	pile_over(a, b);
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> tmp;
	for(int i = 0; i < n; i++)
	{
		tmp.push_back(i);
		nums.push_back(tmp);
		tmp.clear();
	}
	
	string M = "move";
	string P = "pile";
	string On = "onto";
	string Ov = "over";
	string Q = "quit";
	int a, b;
	string input;
	
	while(cin >> input && input != Q)
	{
		if(input == M)
		{
			cin >> a >> input >> b;
			if(input == On)
			{
				move_onto(a, b);//move a onto b
			}
			if(input == Ov)
			{
				move_over(a, b);//move a over b
			}
		}
		else if(input == P)
		{
			cin >> a >> input >> b;
			if(input == On)
			{
				pile_onto(a, b);//pile a onto b
			}
			if(input == Ov)
			{
				pile_over(a, b);//pile a over b
			}
		}
		else
		{
			cin >> a >> input >> b;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << i << ": ";
		for(int j = 0; j < nums[i].size(); j++)
		{
			cout << nums[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}*/

/*#include <iostream>
#include <vector>

using namespace std;

const int N = 30;
typedef pair<int, int> PII;
int n;
vector<int> p[N];

PII find(int x)
{
	for(int i = 0; i < n; i++)
 	{
 		for(int j = 0; j < p[i].size(); j++)
 		{
 			if(p[i][j] == x)
 			{
 				return {i, j};
			}
 		}
 	}
}
void clean(int x, int y)
{
	for(int j = y + 1; j < p[x].size(); j++)
	{
		int t = p[x][j];
		p[t].push_back(t);
	}
	p[x].resize(y + 1);
}
void move(int x1, int y1, int x2)
{
	for(int j = y1; j < p[x1].size(); j++)
	{
		p[x2].push_back(p[x1][j]);
	}
	p[x1].resize(y1);
}
int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		p[i].push_back(i);
	}
	string op1, op2;
	int a, b;
	while(cin >> op1 && op1 != "quit")
	{
		cin >> a >> op2 >> b;
		// 查找 a 和 b 的位置
		PII pa = find(a);
		int x1 = pa.first, y1 = pa.second;
		PII pb = find(b);
		int x2 = pb.first, y2 = pb.second;
		
		if(x1 == x2)
			continue;
		if(op1 == "move") 
		{
			clean(x1, y1);
		}
		if(op2 == "onto")
		{
			clean(x2, y2);
		}
		move(x1, y1, x2);
	}
	 // 打印
	for(int i = 0; i < n; i++)
	{
		cout << i << ':';
		for(int j = 0; j < p[i].size(); j++)
		{
			cout << ' ' << p[i][j];
		}
		cout << endl;
	}
	return 0;
}*/
