// P1226【模板】快速幂
#include <iostream>

using namespace std;

long long fastpower(long long a, long long b, long long p)
{
	long long ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}

int main(void)
{
	int a, b, p;
	cin >> a >> b >> p;
	
	cout << a << '^' << b << " mod " << p << '=' << fastpower(a, b, p) << endl;
	
	return 0;
}

// P10446.64位整数乘法
#include <iostream>

using namespace std;

long long fastmultip(long long a, long long b, long long p)
{
	long long ret = 0;
	while(b)
	{
		if(b & 1) ret = (ret + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ret;
}

int main(void)
{
	long long a, b, p;
	cin >> a >> b >> p;
	
	cout << fastmultip(a, b, p) << endl;
	
	return 0;
}
