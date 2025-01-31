// P1305 ÐÂ¶þ²æÊ÷
#include <iostream>

using namespace std;

const int N = 26 + 10;
int n;
char root[N], l[N], r[N];

int find(char val)
{
	for (int i = 1; i <= n; i++)
	{
		if (val == root[i])
			return i;
	}
}

void Dfs(char val)
{
	cout << val;
	int pos = find(val);
	if (l[pos] != '*' && l[pos] != 0) Dfs(l[pos]);
	if (r[pos] != '*' && r[pos] != 0) Dfs(r[pos]);
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> root[i] >> l[i] >> r[i];
	}

	Dfs(root[1]);

	return 0;

}
