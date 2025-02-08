// P1591 �׳�����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int t, n, val;
vector<int> ret;

void multiply(int num)//���� ret�е�ֵ�� num�ĳ˻� 
{
	int carry = 0;//��λ�� 
    for (int i = 0; i < ret.size(); i++)//ret��ÿһ����� num 
	{
        int prod = ret[i] * num + carry;
        ret[i] = prod % 10;
        carry = prod / 10;
    }
	while(carry)//����ʣ��Ľ�λ�� 
	{
        ret.push_back(carry % 10);//vector�ڹ����ϵ���Խ�� 
        carry /= 10;
    }
}

int main(void)
{
	cin >> t;
	
	while(t--)
	{
		ret.clear();//����ϴ����� 
		cin >> n >> val;
		ret.push_back(1);
		for(int i = n; i >= 2; i--)//���� n!
		{
			multiply(i); 
		}
		cout << count(ret.begin(), ret.end(), val) << endl;//ͳ�� valֵ���ִ��� 
	}
	
	return 0;
}

// P4942 С��������
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

// P1009 [NOIP 1998 �ռ���] �׳�֮��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorial(int num)//�߾��ȼ��㵥�� num!��ֵ 
{
	vector<int> ret;
	ret.push_back(1);
	for (int i = 2; i <= num; i++)// 1 * 2 * ... * num 
	{
		int carry = 0;//��λ�� 
		for(int k = 0; k < ret.size(); k++)
		{
			int prod = ret[k] * i + carry;//��ǰλ��ֵ 
			ret[k] = prod % 10;//���� 
			carry = prod / 10;//���½�λ�� 
		}
		while(carry)//����ʣ���λ�� 
		{
			ret.push_back(carry % 10);//vector��������������Խ�� 
			carry /= 10;
		}
	}
	return ret;
}

vector<int> add(vector<int>& a, vector<int>& b)//�߾��ȼ������������ĺ� 
{
	vector<int> sum;
	int i = 0, j = 0, carry = 0;
	
	while(i < a.size() || j < b.size() || carry)//��ֵ������ 
	{
		int x = (i < a.size()) ? a[i] : 0;
		int y = (j < b.size()) ? b[j] : 0;
		int ret = x + y + carry;
		sum.push_back(ret % 10);
		carry = ret / 10;
		i++;
		j++;
	}
	
	while(sum.back() == 0 && sum.size() > 1) sum.pop_back();//����ǰ���㣬Ҳ���������ǰͳһ����һ�� 
	
	return sum;
}

int main(void)
{
	int n; cin >> n;
	
	vector<int> sum;
	for(int i = 1; i <= n; i++)//����׳˺� 
	{
		vector<int> ret = factorial(i);
		sum = add(sum, ret);
	}
	
	for(int i = sum.size() - 1; i >= 0; i--) cout << sum[i];//������� 
	cout << endl;
	
	return 0;
}
