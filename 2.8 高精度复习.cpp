// P1591 阶乘数码
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int t, n, val;
vector<int> ret;

void multiply(int num)//计算 ret中的值与 num的乘积 
{
	int carry = 0;//进位数 
    for (int i = 0; i < ret.size(); i++)//ret中每一项乘上 num 
	{
        int prod = ret[i] * num + carry;
        ret[i] = prod % 10;
        carry = prod / 10;
    }
	while(carry)//处理剩余的进位数 
	{
        ret.push_back(carry % 10);//vector在功能上的优越性 
        carry /= 10;
    }
}

int main(void)
{
	cin >> t;
	
	while(t--)
	{
		ret.clear();//清空上次数据 
		cin >> n >> val;
		ret.push_back(1);
		for(int i = n; i >= 2; i--)//计算 n!
		{
			multiply(i); 
		}
		cout << count(ret.begin(), ret.end(), val) << endl;//统计 val值出现次数 
	}
	
	return 0;
}

// P4942 小凯的数字
#include <iostream>

using namespace std;

int q, l, r;

//int modulo(string& s, int num)
//{
//	int ret = 0;
//	for(char ch : s)
//	{
//		ret = (ch - '0' + ret * 10) % num;
//	}
//	return ret;
//}

int digitsum(int num)
{
	int ret = 0;
	while(num)
	{
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int totalsum()
{
	int ret = 0;
	for(int i = l; i <= r; i++)
	{
		ret += digitsum(i);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> q;
	
	while(q--)
	{
		cin >> l >> r;
		
		cout << totalsum() % 9 << endl;
	}
	
	return 0;
}

// P1009 [NOIP 1998 普及组] 阶乘之和
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorial(int num)//高精度计算单个 num!的值 
{
	vector<int> ret;
	ret.push_back(1);
	for (int i = 2; i <= num; i++)// 1 * 2 * ... * num 
	{
		int carry = 0;//进位数 
		for(int k = 0; k < ret.size(); k++)
		{
			int prod = ret[k] * i + carry;//当前位总值 
			ret[k] = prod % 10;//余数 
			carry = prod / 10;//更新进位数 
		}
		while(carry)//处理剩余进位数 
		{
			ret.push_back(carry % 10);//vector解决此类问题的优越性 
			carry /= 10;
		}
	}
	return ret;
}

vector<int> add(vector<int>& a, vector<int>& b)//高精度计算两个大数的和 
{
	vector<int> sum;
	int i = 0, j = 0, carry = 0;
	
	while(i < a.size() || j < b.size() || carry)//有值待处理 
	{
		int x = (i < a.size()) ? a[i] : 0;
		int y = (j < b.size()) ? b[j] : 0;
		int ret = x + y + carry;
		sum.push_back(ret % 10);
		carry = ret / 10;
		i++;
		j++;
	}
	
	while(sum.back() == 0 && sum.size() > 1) sum.pop_back();//处理前导零，也可以在输出前统一处理一次 
	
	return sum;
}

int main(void)
{
	int n; cin >> n;
	
	vector<int> sum;
	for(int i = 1; i <= n; i++)//计算阶乘和 
	{
		vector<int> ret = factorial(i);
		sum = add(sum, ret);
	}
	
	for(int i = sum.size() - 1; i >= 0; i--) cout << sum[i];//逆序输出 
	cout << endl;
	
	return 0;
}
