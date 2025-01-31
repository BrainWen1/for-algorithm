// ���������� -- ����̽�ⷨ
/*#include <iostream>
#include <cstring>

using namespace std;

const int N = 23, INF = 0x3f3f3f3f;//ģ�� N  ���� INF��ǿ�λ

int ha[N];//��ϣ��

void initiate()
{
	memset(ha, 0x3f, sizeof(ha));//��ʼ����ϣ����ÿ��Ԫ��Ϊ INF
}

int f(int val)//��ϣ����
{
	int id = (val % N + N) % N;//���ϣ��
	
	while(ha[id] != INF && ha[id] != val)//����̽�ⷨ
	{
		id++;
		if(id == N) id = 0;//�ػ�
	}
	return id;
}

void insert(int x)//����Ԫ��
{
	int id = f(x);
	ha[id] = x;
}

bool find(int x)//����Ԫ��
{
	int id = f(x);
	return ha[id] == x;
}

int main(void)
{
	initiate();
	int n;
	cin >> n;
	
	int option, val;
	while(n--)
	{
		cin >> option >> val;
		if(1 == option)
		{
			insert(val);
		}
		else
		{
			if(find(val)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	
	return 0;
}*/


// ���������� -- ����ַ��
/*#include <iostream>
#include <cstring>

using namespace std;

const int N = 23;//ģ�� N
int ha[N];//��ϣ��
int nums[N], nex[N], id;//����

int f(int val)
{
	return (val % N + N) % N;//��ģ��
}

bool find(int x)
{
	int idx = f(x);
	
	for(int i = ha[idx]; i > 0; i = nex[i])
	{
		if(nums[i] == x) return true;
	}
	return false;
}

void insert(int x)
{
	if(find(x)) return;
	
	int idx = f(x);
	
	id++;
	nums[id] = x;
	nex[id] = ha[idx];
	ha[idx] = id;
}

int main(void)
{
	int n;
	cin >> n;
	
	int op, val;
	while(n--)
	{
		cin >> op >> val;
		if(1 == op)
		{
			insert(val);
		}
		else
		{
			if(find(val)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}*/


// unordered_set  unordered_multiset
/*#include <iostream>
#include <unordered_set>

using namespace std;

int nums[] = { 90,60,30,50,80,70,10,40,20 };//9

int main(void)
{
	unordered_set<int> mp;
	
	for(auto& e : nums)
		mp.insert(e);
		
	for(auto& e : mp)
		cout << e << ' ';
	cout << endl;
	for(auto p = mp.begin(); p != mp.end(); p++)
		cout << *p << ' ';
	cout << endl;
	
	cout << mp.size() << ' ';
	mp.erase(50);
	cout << mp.size() << endl;
	
	mp.insert(50);
	
	cout << mp.count(10) << ' ';
	cout << mp.count(50) << ' ';
	cout << mp.count(90) << ' ';
	cout << mp.count(120) << ' ' << endl << endl;
	
	int i = 10;
	while(!mp.empty())
	{
		cout << mp.size() << ' ';
		mp.erase(i);
		i+=10;
	}
	cout << endl;
	
	unordered_multiset<int> mp1;
	
	for(auto& e : nums)
		mp1.insert(e);
		
	mp1.insert(10);
	mp1.insert(50);
	mp1.insert(50);
	mp1.insert(90);
	
	for(int i = 10; i <= 90; i+=10)
	{
		cout << i << ": " << mp1.count(i) << endl;
	}
	
	return 0;
}*/


// unordered_map  unordered_multimap
/*#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
	unordered_map<string, int> mp;

	mp.insert({"zhangsan", 1});
	mp.insert({"lisi", 2});
	mp.insert({"wangwu", 3});
	mp.insert({"zhaoliu", 4});
	mp.insert({"wenbin", 5});

	for(auto& e : mp)
		cout << e.first << ' ' << e.second << endl;
	cout << endl;
	for(auto p = mp.begin(); p != mp.end(); p++)
		cout << (*p).first << ' ' << (*p).second << endl;
	cout << endl;

	cout << mp.size() << ' ';
	mp.erase("lisi");
	cout << mp.size() << endl;

	mp.insert({"lisi", 2});
	cout << mp["lisi"] << endl;

	cout << mp.count("zhangsan") << ' ';
	cout << mp.count("lisi") << ' ';
	cout << mp.count("wenbin") << ' ';
	cout << mp.count("goat") << ' ' << endl << endl;

	unordered_multimap<string, int> mp1;

	mp1.insert({"zhangsan", 1});
	mp1.insert({"lisi", 2});
	mp1.insert({"wangwu", 3});
	mp1.insert({"zhaoliu", 4});
	mp1.insert({"wenbin", 5});

	mp1.insert({"zhangsan", 9});
	mp1.insert({"zhangsan", 1});
	mp1.insert({"zhaoliu", 4});
	mp1.insert({"wenbin", 5});

	cout << "zhangsan " << ": " << mp1.count("zhangsan") << endl;
	cout << "lisi " << ": " << mp1.count("lisi") << endl;
	cout << "wangwu " << ": " << mp1.count("wangwu") << endl;
	cout << "zhaoliu " << ": " << mp1.count("zhaoliu") << endl;
	cout << "wenbin " << ": " << mp1.count("wenbin") << endl;
	cout << "goat " << ": " << mp.count("goat") <<endl;

	return 0;
}*/
