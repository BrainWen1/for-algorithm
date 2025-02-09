// P1007 ��ľ��
#include <iostream>
#include <algorithm>

using namespace std;

int len, n;

int main(void)
{
	cin >> len >> n;
	
	int minimum = 0, maximum = 0;
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		minimum = max(minimum, min(tmp, len - tmp + 1));
		maximum = max(maximum, max(tmp, len - tmp + 1));
	}
	cout << minimum << ' ' << maximum << endl;
	
	return 0;
}

// P1008 [NOIP 1998 �ռ���] ������
#include <iostream>

using namespace std;

bool check(int a, int b, int c)
{
	int count[10] = { 0 };//ͳ��ÿ�����ֳ��ֵĴ��� 
	
	while(a)
	{
		count[a % 10]++;
		a /= 10;
	}
	while(b)
	{
		count[b % 10]++;
		b /= 10;
	}
	while(c)
	{
		count[c % 10]++;
		c /= 10;
	}
	
	if(count[0]) return false;//���� count�����ѯ�Ϸ���
	for(int i = 1; i <= 9; i++) 
	{
		if(count[i] != 1) return false;
	}
	return true;
}

int main(void)
{
	for(int i = 123; i <= 329; i++)//ö��һ���������п��� 
	{
		if(check(i, 2 * i, 3 * i))
			cout << i << ' ' << 2 * i << ' ' << 3 * i << endl;
	}
	
	return 0;
}

// P1980 [NOIP 2013 �ռ���] ��������
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	char val;
	cin >> n >> val;
	
	string str;
	for(int i = 1; i <= n; i++) str += to_string(i);
	
	cout << count(str.begin(), str.end(), val) << endl;
	
	return 0;
}

// P5016 [NOIP 2018 �ռ���] ������
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m, p1;
LL s1, s2;
LL a[N];

int main(void)
{
	//���ݴ��� 
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	cin >> m >> p1 >> s1 >> s2;
	
	LL leftsum = 0, rightsum = 0;
	
	for(int i = 1; i < m; i++) leftsum += a[i] * (m - i);
	for(int i = m + 1; i <= n; i++) rightsum += a[i] * (i - m);

	if(p1 < m) leftsum += s1 * (m - p1);
	else if(p1 > m) rightsum += s1 * (p1 - m);

	//ö��ÿһ��λ�ò����¶�����С��ֵ
	LL minimum = abs(leftsum - rightsum);
	int index = m;
	for(int i = 1; i <= n; i++)
	{	
		LL l = leftsum, r = rightsum;
		if(i < m) l += s2 * (m - i);
		else if(i > m)r += s2 * (i - m);
			
		if(minimum > abs(l - r) || (minimum == abs(l - r) && i < index))
		{
			minimum = abs(l - r);
			index = i;
		}
	}
	cout << index << endl;
	
	return 0;
}
