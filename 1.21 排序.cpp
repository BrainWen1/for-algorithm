// 插入排序 Insert sort
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int nums[N];

void insert_sort()
{
	for(int i = 2; i <= n; i++)
	{
		int j = i - 1;
		int tmp = nums[i];
		while(j >= 1 && nums[j] > tmp)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = tmp;
	}
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> nums[i];
	
	insert_sort();
	
	for(int i = 1; i <= n; i++) cout << nums[i] << ' ';
	cout << endl;
	
	return 0;
}*/

// 选择排序 Selection sort
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

void Selection_sort()
{
	for(int i = 1; i < n; i++)
	{
		int min = a[i];
		int k = i;
		for(int j = i + 1; j <= n; j++)
		{
			if(a[j] < min)
			{
				min = a[j];
				k = j;
			}
		}
		int tmp = a[i];
		a[i] = min;
		a[k] = tmp;
	}
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	Selection_sort();
	
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
}*/

// 冒泡排序 Bubble sort
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

void Bubble_sort()
{
	for(int i = n; i > 1; i--)
	{
		for(int j = 1; j < i; j++)
		{
			if(a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void Bubble_sort_pro()
{
	for(int i = n; i > 1; i--)
	{
		int flag = 1;
		for(int j = 1; j < i; j++)
		{
			if(a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = 0;
			}
		}
		if(flag) return;
	}
}

int main(void)
{
	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];

	Bubble_sort_pro();

	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
	
	return 0;
}*/

// 堆排序 Heap sort
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

void down(int parent, int end)
{
	int child = parent * 2;
	
	while(child <= end)
	{
		if(child + 1 <= end && a[child + 1] > a[child]) child++;
		if(a[parent] >= a[child]) return;

		swap(a[parent], a[child]);
		parent = child;
		child = parent * 2;
	}
}

void heap_sort()//O(nlogn)
{
	for(int i = n / 2; i >= 1; i--)//建堆 O(n)
	{
		down(i, n);
	}
	for(int i = n; i > 1; i--)//排序 O(nlogn)
	{
		swap(a[1], a[i]);
		down(1, i - 1);
	}
}

int main(void)
{
	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];

	heap_sort();

	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;

	return 0;
}*/

// 快速排序 Quick sort
/*#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int random_number(int left, int right)//随机获取基准元素
{
	return a[rand() % (right - left + 1) + left];
}

void Quick_sort(int left, int right)
{
	if(left >= right) return;//递归出口
	
	int pivot = random_number(left, right);//获取基准元素
	
	int l = left - 1, i = left, r = right + 1;//划分区间
	while(i < r)
	{
		if(a[i] < pivot) swap(a[++l], a[i++]);
		else if(a[i] == pivot) i++;
		else swap(a[--r], a[i]);
	}
	//[left, l] [l + 1, r - 1] [r, right]
	Quick_sort(left, l);
	Quick_sort(r, right);
}

int main(void)
{
	srand(time(0));
	
	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];

	Quick_sort(1, n);

	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;

	return 0;
}*/

// 归并排序 Merge sort
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int tmp[N];//存放合并的数组

void Merge_sort(int left, int right)
{
	if(left >= right) return;//递归出口
	
	int mid = (right - left + 1) / 2 + left - 1;//二分区间
	Merge_sort(left, mid);//递归处理左区间
	Merge_sort(mid + 1, right);//递归处理右区间
	
	int cur1 = left, cur2 = mid + 1, i = left;
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];//选出较小值存放
		else tmp[i++] = a[cur2++];
	}
	while(cur1 <= mid) tmp[i++] = a[cur1++];//处理未遍历完的数组
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	for(int j = left; j <= right; j++)
	{
		a[j] = tmp[j];//将合并的数组覆盖到原数组中
	}
}

int main(void)
{
	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];

	Merge_sort(1, n);

	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;

	return 0;
}*/
