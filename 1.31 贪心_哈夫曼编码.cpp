// NC233601.��ģ�塿����������
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

int main(void)
{
	priority_queue<LL, vector<LL>, greater<LL>> heap;//����С���� 
	int n; cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		heap.push(tmp);//С�����Զ����� 
	}
	
	LL ret = 0;
	while(heap.size() > 1)//���ֻ��һ������������Ԫ��ʱ�˳�ѭ�� 
	{
		LL a = heap.top();//ȡ����С�������ַ����� 
		heap.pop();
		LL b = heap.top();
		heap.pop();
		heap.push(a + b);//�ϲ�����С�������Զ����� 
		ret += a + b;//�ۼӼ����Ȩ·������ 
	}
	cout << ret << endl;
	
	return 0;
}

// P1090 [NOIP 2004 �����] �ϲ�����
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
