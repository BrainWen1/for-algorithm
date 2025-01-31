// �������� Insert sort
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

// ѡ������ Selection sort
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

// ð������ Bubble sort
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

// ������ Heap sort
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
	for(int i = n / 2; i >= 1; i--)//���� O(n)
	{
		down(i, n);
	}
	for(int i = n; i > 1; i--)//���� O(nlogn)
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

// �������� Quick sort
/*#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int random_number(int left, int right)//�����ȡ��׼Ԫ��
{
	return a[rand() % (right - left + 1) + left];
}

void Quick_sort(int left, int right)
{
	if(left >= right) return;//�ݹ����
	
	int pivot = random_number(left, right);//��ȡ��׼Ԫ��
	
	int l = left - 1, i = left, r = right + 1;//��������
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

// �鲢���� Merge sort
/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int tmp[N];//��źϲ�������

void Merge_sort(int left, int right)
{
	if(left >= right) return;//�ݹ����
	
	int mid = (right - left + 1) / 2 + left - 1;//��������
	Merge_sort(left, mid);//�ݹ鴦��������
	Merge_sort(mid + 1, right);//�ݹ鴦��������
	
	int cur1 = left, cur2 = mid + 1, i = left;
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];//ѡ����Сֵ���
		else tmp[i++] = a[cur2++];
	}
	while(cur1 <= mid) tmp[i++] = a[cur1++];//����δ�����������
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	for(int j = left; j <= right; j++)
	{
		a[j] = tmp[j];//���ϲ������鸲�ǵ�ԭ������
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
