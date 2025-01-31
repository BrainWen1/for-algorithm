// P1601 A+B Problem（高精）
/*include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 500 + 10;
int a[N], b[N];
int ret[N];
string s;

int main(void)
{
	cin >> s;
	int len1 = s.size();
	for(int i = 1; i <= len1; i++)
	{
		a[i] = s.back() - '0';
		s.pop_back();
	}
	
	cin >> s;
	int len2 = s.size();
	for(int i = 1; i <= len2; i++)
	{
		b[i] = s.back() - '0';
		s.pop_back();
	}
	
	int len = max(len1, len2);
	for(int i = 1; i <= len; i++)
	{
		ret[i] = ret[i] + a[i] + b[i];
		if(ret[i] >= 10)
		{
			ret[i + 1]++;
			ret[i] -= 10;
		}
	}
	
	if(ret[len + 1]) len++;
	
	for(int i = len; i >= 1; i--)
		cout << ret[i];
	cout << endl;
	
	return 0;
}*/

// P2142 高精度减法
/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10086 + 10;
int a[N], b[N];
int ret[N];
string s1, s2;

int main(void)
{
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	
	if(len1 < len2)
	{
		cout << '-';
		swap(s1, s2);
		swap(len1, len2);
	}
	else if(len1 == len2)
	{
		if(s1 > s2);
		else if(s1 < s2)
		{
			cout << '-';
			swap(s1, s2);
			swap(len1, len2);
		}
		else
		{
			cout << '0' << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= len1; i++) a[i] = s1[len1 - i] - '0';
	for(int i = 1; i <= len2; i++) b[i] = s2[len2 - i] - '0';
	
	int len = max(len1, len2);
	for(int i = 1; i <= len; i++)
	{
		ret[i] += a[i] - b[i];
		if(ret[i] < 0)
		{
			a[i + 1]--;
			ret[i] += 10;
		}
	}
	
	while(len > 1 && ret[len] == 0) len--;
	
	for(int i = len; i >= 1; i--)
		cout << ret[i];
	cout << endl;
	
	return 0;
}*/

// P1303 A*B Problem
/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 4000 + 10;
int a[N], b[N];
int ret[N];
string s1, s2;

int main(void)
{
	cin >> s1 >> s2;
	
	int len1 = s1.size(), len2 = s2.size();
	for(int i = 0; i < len1; i++) a[i] = s1[len1 - 1 - i] - '0';
	for(int i = 0; i < len2; i++) b[i] = s2[len2 - 1 - i] - '0';
	
	for(int i = 0; i < len1; i++)
		for(int j = 0; j < len2; j++)
			ret[i + j] += a[i] * b[j];
	
	int len = len1 + len2;
	for(int i = 0; i < len; i++)
	{
		if(ret[i] >= 10)
		{
			ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
	}
	
	while(len > 1 && ret[len - 1] == 0) len--;
	
	for(int i = len - 1; i >= 0; i--)
		cout << ret[i];
	cout << endl;
	
	return 0;
}*/

// P1480 A/B Problem
/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 5000 + 10;
int a[N], b;
int ret[N];
string s;

int main(void)
{
	cin >> s >> b;
	
	int len = s.size();
	for(int i = 1; i <= len; i++) a[i] = s[len - i] - '0';
	
	long long tmp = 0;
	for(int i = len; i >= 1; i--)
	{
		tmp = tmp * 10 + a[i];
		ret[i] = tmp / b;
		tmp %= b;
	}
	
	while(len > 1 && ret[len] == 0) len--;
	
	for(int i = len; i >= 1; i--) cout << ret[i];
	cout << endl;
	
	return 0;
}*/
