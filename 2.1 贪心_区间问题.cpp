// P1803.���ҵ�yyy / �߶θ���
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
		return l.x < r.x;//���������������� 
	});
	
	node tmp = a[0];//��ʼ����׼ 
	int count = 1;
	for(int i = 1; i < n; i++)
	{
		if(a[i].x >= tmp.y)//���ص� 
		{
			count++;
			tmp = a[i];//���»�׼ 
		}
		else//�ص� 
		{
			if(tmp.y <= a[i].y) continue;//�����������СԪ�� 
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
	while(cin >> n >> d && (n || d))//������������ 
	{
		int flag = 0;
		double x, y;
		for(int i = 0; i < n; i++)//��������(x,y)���������� 
		{
			cin >> x >> y;
			if(y > d)//�޽�������� 
			{
				cout << "Case " << k++ << ": " << -1 << endl;
				flag = 1;
				break;
			}
			double len = sqrt(d * d - y * y);//��ά��һά��ת�������� 
			interval[i].a = x - len;
			interval[i].b = x + len;
		}
		if(flag) continue;
	
		sort(interval, interval + n, [](node& l, node& r)->bool{
			return l.a < r.a;//��������˵����� 
		});
		
		node tmp = interval[0];//��ʼ��׼ 
		int count = 1;
		for(int i = 1; i < n; i++)//�����ص��������->�����״���� 
		{
			if(interval[i].a > tmp.b)//���ص� 
			{
				count++;//���� 
				tmp = interval[i];//��һ��׼ 
			}
			else//�ص� 
			{
				if(interval[i].b >= tmp.b);//����������Ҷ˵�
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
struct node//��ţ 
{
	int minSPFi;//��С����ǿ�� 
	int maxSPFi;//�������ǿ�� 
}a[N];
struct lotion//��ɹ˪ 
{
	int SPFi;//��ɹǿ�� 
	int Coveri;//��ʹ�ô��� 
}b[N];

int main(void)
{
	cin >> C >> L;
	for(int i = 0; i < C; i++) cin >> a[i].minSPFi >> a[i].maxSPFi;
	for(int i = 0; i < L; i++) cin >> b[i].SPFi >> b[i].Coveri;
	
	sort(a, a + C, [](node& l, node& r)->bool{
		return l.minSPFi > r.minSPFi;//����С����ǿ�Ƚ������� 
	});
	sort(b, b + L, [](lotion& l, lotion& r)->bool{
		return l.SPFi > r.SPFi;//����ɹǿ�Ƚ������� 
	});
	
	int count = 0;
	for(int i = 0; i < C; i++)
	{
		for(int j = 0; j < L; j++)
		{
			if(b[j].Coveri == 0) continue;//��ɹ˪����Ϊ��
			if(b[j].SPFi < a[i].minSPFi) break;//���з�ɹ˪���������㵱ǰ��ţ
			if(b[j].SPFi > a[i].maxSPFi) continue;//��ǰ��ɹ˪ǿ��̫��
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
int ret[N];//�洢������ţ���̵�ţ�� 
struct node//��ţ 
{
	int start;//���̿�ʼʱ�� / ţ���ڽ���ʱ�� 
	int end;//���̽���ʱ�� / ţ���� 
	int index;//��ţ��� 
	
	//����С�ں������->�洢�ṹ���С����
	bool operator<(const node& other) const
	{
		return this->start > other.start;//��ţ�����ʱ�佨С���� 
	}
}a[N];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].start >> a[i].end;
		a[i].index = i;//�����±� 
	}
	
	sort(a + 1, a + 1 + n, [](node& l, node& r)->bool{
		return l.start < r.start;//����ʼʱ���������� 
	});
	
	//С����->���ٲ�ѯ��ǰ������ţ��������̽���ʱ������Ӧ��ţ�� 
	priority_queue<node> heap;
	
	ret[a[1].index] = 1; 
	heap.push({a[1].end, 1});//��ʼ���� 
	int num = 1;//���ţ����
	
	for(int i = 2; i <= n; i++)
	{
		if(a[i].start <= heap.top().start)//û���ֳɵ�ţ��
		{
			num++;
			ret[a[i].index] = num;//��ǰ��ţ����ţ��ı�� 
			heap.push({a[i].end, num});
		}
		else//���ֳɵ�ţ��
		{
			node tmp = heap.top();
			heap.pop();
			ret[a[i].index] = tmp.end;//��ǰ��ţ����ţ����Ϊ�Ѷ�Ԫ��ţ���� 
			heap.push({a[i].end, tmp.end});
		}
	}
	
	cout << num << endl;
	for(int i = 1; i <= n; i++) cout << ret[i] << endl;
	
	return 0;
}
