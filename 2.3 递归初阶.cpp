//�ݹ���� 
void Dfs(int root)//�����������->ǰ����� 
{
	if(0 == root) return;//�ݹ���� 
	
	cout << root <<  ' ';//�� 
	Dfs(left[root]);//������ 
	Dfs(right[root]);//������ 
}

void merge_sort(int left, int right)//�鲢���� 
{
	if(left >= right) return;
	
	int mid = (right - left) / 2 + left;
	merge_sort(left, mid);//������ 
	merge_sort(mid + 1, right);//������ 
	
	inplace_merge(a + left, a + mid + 1, a + right + 1);//ԭ�غϲ����� 
}

// 1205����ŵ������ 
#include <iostream>

using namespace std;

int n;
char ch1, ch2, ch3

void HannuoTa(int high, char x, char y, char z)
{
	if(0 == high) return;//�ݹ���� 
	
	HannuoTa(high - 1, x, z, y);//������(high - 1)��Բ�̷ŵ��ұ� 
	printf("%c->%d->%c\n", x, high, z);//����������һ���ŵ��м� 
	HannuoTa(high - 1, y, x, z);//���ұߵĶѵ��м����� 
}

int main(void)
{
	cin >> n >> ch1 >> ch2 >> ch3;//ch1 --> ch2 <-- ch3
	
	HannuoTa(n, ch1, ch3, ch2);
	
	return 0;
}

// P10457.ռ��DIY
#include <iostream>

using namespace std;

int a[14][5];
int token[14];//��ǵ�ǰ�ƶѱ������˼���->��ʼ��Ϊ 4->Ϊ 0��Ϊһ�� 

void Game(int val)
{
	if(13 == val) return;//�ݹ���� 
	
	Game(a[val][token[val]--]); 
}

int main(void)
{
	for(int i = 1; i <= 13; i++)
	{
		token[i] = 4;//��ʼ��Ϊ 4 
		for(int j = 1; j <= 4; j++)
		{
			char ch = 0;
			cin >> ch;
			if(ch >= '2' && ch <= '9') a[i][j] = ch - '0';
			else if(ch == '0') a[i][j] = 10;//ת���������ͷ��㴦�� 
			else if(ch == 'J') a[i][j] = 11;
			else if(ch == 'Q') a[i][j] = 12;
			else if(ch == 'K') a[i][j] = 13;
			else if(ch == 'A') a[i][j] = 1;
		}
	}
	
	for(int i = 1; i <= 4; i++) Game(a[13][i]);//����->�ݹ� 
	
	int ret = 0;
	for(int i = 1; i <= 13; i++) if(0 == token[i]) ret++;//ͳ�� 
	cout << ret << endl;
	
	return 0;
}

// P1087 [NOIP 2004 �ռ���] FBI ��
#include <iostream>

using namespace std;

const int N = 10 + 1;
int n;
int f[1 << N];//ǰ׺������ 

void Dfs(int left, int right)//������� 
{
	if(left > right) return;//�ݹ����(1) 
	
	char ret = 0;
	int sum = f[right] - f[left - 1];//����ǰ׺�Ϳ��ټ��� 
	
	if(sum == right - left + 1) ret = 'I';
	else if(sum == 0) ret = 'B';
	else ret = 'F';
	
	if(left == right)//�ݹ����(2) 
	{
		cout << ret;
		return;
	}
	
	Dfs(left, (left + right) / 2);//������ 
	Dfs((left + right) / 2 + 1, right);//������ 
	
	cout << ret;
}

int main(void)
{
	cin >> n;
	n = (1 << n);//���ټ��� 2 ^ n
	
	for(int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		if(ch == '1') f[i] = f[i - 1] + 1;//ǰ׺��->�����ж������ִ� 
		else f[i] = f[i - 1];
	}
	
	Dfs(1, n);//������������ֵ 
	
	return 0;
}
