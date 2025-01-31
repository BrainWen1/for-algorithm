// ��
/*#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int n;
int heap[N];//������

void up(int child)//���ϵ����㷨
{
	int parent = child / 2;
	
	while(parent >= 1 && heap[parent] < heap[child])
	{
		swap(heap[parent], heap[child]);
		
		child = parent;
		parent = child / 2;
	}
}

void down(int parent)//���µ����㷨
{
	int child = parent * 2;
	
	while(child <= n)
	{
		if(child + 1 <= n && heap[child + 1] > heap[child])
			child++;
		if(heap[child] <= heap[parent])
			return;

		swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2;
	}
}

void push(int val)//����Ԫ��
{
	heap[++n] = val;
	up(n);
}

void pop()//ɾ���Ѷ�Ԫ��
{
	swap(heap[1], heap[n--]);
	down(1);
}

int top()//��ѯ�Ѷ�Ԫ��
{
	return heap[1];
}

int size()//���ضѴ�С
{
	return n;
}

int main(void)
{
	int nums[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0};

	for(int i = 0; i < 10; i++)
		push(nums[i]);

	while(size())
	{
		cout << top() << ' ';
		pop();
	}
	
	return 0;
}*/

// STL �еĶ� priority_queue
/*#include <iostream>
#include <queue>//priority_queue

using namespace std;

int nums[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0};

void test_1()//�����洢�������͵Ķ�
{
	priority_queue<int> heap;//Ĭ�ϴ����

	for(int i = 0; i < 10; i++)
	{
		heap.push(nums[i]);
	}

	while(!heap.empty())
	{
		cout << heap.top() << ' ' << heap.size() << endl;
		heap.pop();
	}
	cout << endl;
}

void test_2()
{
	priority_queue<int, vector<int>, less<int>> heap1;//less�����
	priority_queue<int, vector<int>, greater<int>> heap2;//greaterС����
	//                      //
	cout << "�����" << endl;
	for(int i = 0; i < 10; i++)
	{
		heap1.push(nums[i]);
	}

	while(!heap1.empty())
	{
		cout << heap1.top() << ' ';
		heap1.pop();
	}
	cout << endl;
	//                      //
	cout << "С����" << endl;
	for(int i = 0; i < 10; i++)
	{
		heap2.push(nums[i]);
	}
	while(heap2.size())
	{
		cout << heap2.top() << ' ';
		heap2.pop();
	}
	cout << endl << endl;
}

struct node//�����洢�ṹ�����͵Ķ�
{
	int data;
	int temp;

	//����С�ڷ���
	bool operator<(const node& x)const
	{
		return data < x.data;//�����
	}
	
	//bool operator<(const node& x)const
	//{
	//	return data > x.data;//С����
	//}
};

void test_3()
{
	priority_queue<node> nodes;
	for(int i = 1; i <= 5; i++)
	{
		nodes.push({i, 5 * i});
	}
	while(nodes.size())
	{
		node tmp = nodes.top();
		nodes.pop();
		cout << tmp.data << ' ';
	}
}

int main(void)
{
	test_1();
	
	test_2();
	
	test_3();
	
	return 0;
}*/
