// ����ģ��ʵ�־�̬������
#include <iostream>

using namespace std;

//struct node//�ṹ��ʵ�� 
//{
//	int data;
//	node* next;
//}list[N];

//��������
const int N = 1e3 + 10;//����ģ��ʵ�� 
int Nums[N];
int Next[N];
int h, id;
int map[N];

void push_front(int val)//ͷ��
{
	id++;
	Nums[id] = val;
	map[val] = id;

	Next[id] = Next[h];
	Next[h] = id;
}
void print()//������ӡ����
{
	for (int i = Next[h]; i > 0; i = Next[i])
	{
		cout << Nums[i] << ' ';
	}
	cout << endl << endl;
}
int find(int val)//��ֵ����
{
	return map[val];
}
void insert(int pos, int val)//������λ��֮�����Ԫ��
{
	id++;
	Nums[id] = val;
	map[val] = id;

	Next[id] = Next[pos];
	Next[pos] = id;
}
void erase(int pos)//ɾ������λ��֮���Ԫ��
{
	if (Next[pos])
	{
		map[Nums[Next[pos]]] = 0;
		Next[pos] = Next[Next[pos]];
	}
}
int main(void)
{
	for (int i = 1; i <= 5; i++)
		push_front(i);
	print();

	cout << find(2) << ' ' << find(5) << ' ' << find(6) << endl;

	insert(3, 33);
	insert(5, 55);
	print();

	erase(2);
	print();

	return 0;
}


// ����ģ��ʵ�־�̬˫����
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int Nums[N];
int pre[N], Next[N];
int map[N];
int h, id;

void push_front(int val)//ͷ��
{
	id++;
	Nums[id] = val;
	map[val] = id;
	
	pre[id] = h;
	Next[id] = Next[h];
	pre[Next[h]] =id;
	Next[h] = id;
}

void print()
{
	for(int i = Next[h]; i > 0; i = Next[i])
	{
		cout << Nums[i] << ' ';
	}
	cout << endl << endl;
}

int find(int val)
{
	return map[val];
}

void insert_back(int pos, int val)
{
	id++;
	Nums[id] = val;
	map[val] = id;
	
	pre[id] = pos;
	Next[id] = Next[pos];
	pre[Next[pos]] = id;
	Next[pos] = id;
}

void insert_front(int pos, int val)
{
	id++;
	Nums[id] = val;
	map[val] = id;
	
	pre[id] = pre[pos];
	Next[id] = pos;
	Next[pre[pos]] = id;
	pre[pos] = id;
}

void erase(int pos)
{
	map[Nums[pos]] = 0;
	Next[pre[pos]] = Next[pos];
	pre[Next[pos]] = pre[pos];
}

int main(void)
{
	for(int i = 1; i <= 5; i++)
		push_front(i);
	print();
	
	cout << find(2) << ' ' << find(5) << ' ' << find(6) << endl;
	
	insert_back(2, 22);
	print();
	
	insert_front(4, 44);
	print();
	
	erase(2);
	print();
	
	return 0;
}*/


// ����ģ��ʵ��ѭ������
/*#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int Nums[N];
int Next[N];
int map[N];
int h, id;

void print()
{
	int count = 0;
	for(int i = Next[h];; i = Next[i])
	{
		printf("%d ", Nums[i]);
		if(i == 0)
			count++;
		if(count == 2)
		{
			cout << endl << endl;
			return;
		}
	}
}

void push_front(int val)
{
	id++;
	Nums[id] = val;
	map[val] = id;
	
	Next[id] = Next[h];
	Next[h] = id;
}

int main(void)
{
	for(int i = 1; i <= 5; i++)
		push_front(i);
	
	print();
	
	return 0;
}*/


// STL���еĶ�̬����list
/*#include <iostream>
#include <list>

using namespace std;

void print(list& L)
{
	for(int i = 0; i < L.size(); i++)
		cout << L[i].data << ' ';
	cout << endl << endl;
}

int main(void)
{
	list L;
	
	for(int i = 1; i <= 5; i++)
		L.push_front(i);
	print(L);
	
	cout << List.size() << endl;
	
	L.push_back(0);
	print(L);
}*/
