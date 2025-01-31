// 复习：封装静态顺序表
/*#include <iostream>
#include <cstring>

using namespace std;

const int N = 101;

class sqlist
{
private:
	int arr[N];
	int n;
public:
	//构造函数
	sqlist()
	{
		memset(arr, 0, sizeof(arr));
		n = 0;
	}
	//析构函数
	~sqlist()
	{
		memset(arr + 1, 0, n * sizeof(int));
		n = 0;
	}
	//自定义函数
	void push_back(int val)
	{
		arr[++n] = val;
	}
	void push_front(int val)
	{
		memcpy(arr + 2, arr + 1, n++ * sizeof(int));
		arr[1] = val;
	}
	void insert(int pos, int val)
	{
		memcpy(arr + pos + 1, arr + pos, (n - pos + 1) * sizeof(int));
		arr[pos] = val;
		n++;
	}
	void pop_back()
	{
		arr[n--] = 0;
	}
	void pop_front()
	{
		memcpy(arr + 1, arr + 2, --n * sizeof(int));
	}
	void erase(int pos)
	{
		memcpy(arr + pos, arr + pos + 1, (n - pos + 1) * sizeof(int));
		n--;
	}
	int find_val(int val)
	{
		for(int i = 1; i <= n; i++)
			if(arr[i] == val)
				return i;
		return 0;
	}
	int find_pos(int pos)
	{
		return arr[pos];
	}
	void modify(int pos, int val)
	{
		arr[pos] = val;
	}
	void print()
	{
		for(int i = 1; i <= n; i++)
			cout << arr[i] << ' ';
		cout << endl << endl;
	}
};

int main(void)
{
	sqlist list;
	for(int i = 1; i <= 10; i++)
		list.push_back(i);
	list.print();
	
	list.push_front(0);
	list.push_front(-1);
	list.print();
	
	list.pop_back();
	list.pop_front();
	list.pop_front();
	list.print();
	
	list.insert(3, 69);
	list.print();
	list.erase(3);
	list.print();
	
	cout << list.find_val(6) << ' ';
	cout << list.find_pos(7) << endl;
	
	list.modify(5, 55);
	list.print();
	
	return 0;
}*/

// P2433 【深基1-2】小学数学 N 合一
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = 3.141593;

int main(void)
{
	int n;
	cin >> n;
	
	switch(n)
	{
		case 1: cout << "I love Luogu!" << endl; break;
		case 2: cout << "6 4" << endl; break;
		case 3: cout << "3 12 2" << endl; break;
		case 4: cout << fixed << setprecision(6) << 500 / 3.0 << endl; break;
		case 5:
		case 6: cout << sqrt(6 * 6 + 9 * 9) << endl; break;
		case 7: cout << "110 90 0" << endl; break;
		case 8: 
		{
			const int r = 5;
			cout << 2 * pi * r << ' ' << pi * pow(r, 2) << ' ' << (4.0 / 3) * pi * pow(r, 3) << endl;
			break;
		}
		case 9: cout << "22" << endl; break;
		case 10:
		case 11: cout << 100 / 3.0 << endl; break;
		case 12: cout << (int)('M' - 'A' + 1) << endl << (char)('A' + 17) << endl; break;
		case 13: 
		{
			const int r1 = 4, r2 = 10;
			cout << pow((4.0 / 3) * pi * (pow(r1, 3) + pow(r2, 3)), 1.0 / 3) << endl;
			break;
		}
		case 14: 
		{
			int ret = 1100, price = 110, prices[2], peo = 10, count = 0;
			while(1)
			{
				ret = price-- * peo++;
				if(ret == 3500)
				{
					prices[count++] = price;
					if(count == 2)
						break;
				}
			}
			cout << (int)(min(prices[0], prices[1]) + 0.5) << endl;
			break;
		}
		default: break;
	}
	return 0;
}






























