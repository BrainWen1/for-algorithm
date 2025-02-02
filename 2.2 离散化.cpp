// ��ɢ��ģ��һ������ + ȥ�� + ���ֲ���
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int n;
int a[N];//���ԭʼ���� 

int pos;//��¼��ɢ����Ԫ�ظ��� 
int disc[N];//�����ɢ�������� 

int find(int val)
{
	int left = 1, right = pos;//���ֲ��� 
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(disc[mid] >= val) right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];//���� 
	}
	cout << endl;
	
	sort(disc + 1, disc + 1 + n);//���� 
	
	pos = unique(disc + 1, disc + 1 + n) - (disc + 1);//unique�����������ȥ�� 
	
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << ": " << find(a[i]) << endl;
	}
	
	return 0;
}*/

// ��ɢ��ģ��������� + ��ϣ��ʵ��ȥ�غͲ��� 
/*#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

const int N = 1e3 + 10;
int n;
int a[N];//���ԭʼ���� 
int disc[N];//������������ 

unordered_map<int, int> mp;//<ԭʼ����, ��ɢ������>

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[i] = a[i];//���� 
	}
	cout << endl;
	
	sort(disc + 1, disc + 1 + n);//���� 
	int index = 0;//���Ԫ�� 
	for(int i = 1; i <= n; i++)
	{
		int val = disc[i];
		if(mp[val]) continue;//ȥ�� 
		index++;
		mp[val] = index;//��ɢ�� 
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << ": " << mp[a[i]] << endl;
	}
	
	return 0;
}

// P1496 ���ճ��
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10;
int n, pos;
int a[N], b[N];//�������Ҷ˵� 
int f[2 * N];//������� 
int disc[2 * N];//��ɢ������ 
unordered_map<int, int> mp;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}
	
	sort(disc + 1, disc + 1 + pos);//���� 
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);//ȥ�� 
	
	for(int i = 1; i <= pos; i++)//��ɢ�� 
	{
		mp[disc[i]] = i; 
	}
	
	for(int i = 1; i <= n; i++)//��� 
	{
		int left = mp[a[i]], right = mp[b[i]];
		f[left]++;
		f[right]--;
	}
	
	for(int i = 1; i <= pos; i++)//��ԭ���� 
	{
		f[i] = f[i] + f[i - 1];
	}
	
	int ret = 0;
	for(int i = 1; i <= pos; i++)
	{
		int j = i;
		for(; j <= pos; j++)
		{
			if(f[j] == 0) break; 
		}
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;
	
	return 0;
}

// P3740 [HAOI2014] ������
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e3 + 10;
int n, m, pos;
int a[N], b[N];
int disc[4 * N];
unordered_map<int, int> mp;

int wall[4 * N];
bool is_counted[N];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; disc[++pos] = a[i] + 1;
		disc[++pos] = b[i]; disc[++pos] = b[i] + 1;
	}
	
	sort(disc + 1, disc + 1 + pos);//���� 
	
	int index = 0;//�����ɢ�����ж���Ԫ�� 
	for(int i = 1; i <= pos; i++)//��ɢ�� 
	{
		if(mp[disc[i]]) continue;//ȥ�� 
		index++;
		mp[disc[i]] = index;
	}
	
	//ģ��������
	for(int i = 1; i <= m; i++)
	{
		int left = mp[a[i]], right = mp[b[i]];//��ȡ��ɢ����ķ�Χ
		for(int r = left; r <= right; r++)
		{
			wall[r] = i;//���� 
		}
	}
	
	//ͳ�ƽ��
	int ret = 0;
	for(int i = 1; i <= index; i++)
	{
		if(wall[i] == 0 || is_counted[wall[i]]) continue;
		is_counted[wall[i]] = true;//���Ϊ�Ѵ��ڵ����������ظ����� 
		ret++;
	}
	cout << ret << endl;
	
	return 0;
}
