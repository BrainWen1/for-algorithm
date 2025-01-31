// 复习：封装静态顺序表
#include <iostream>
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
}
