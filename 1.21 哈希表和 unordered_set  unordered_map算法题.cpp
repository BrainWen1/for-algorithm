// P5266 【深基17.例6】学籍管理
/*#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	unordered_map<string, int> mp;
	int n;
	cin >> n;
	
	int op, score;
	string name;
	while(n--)
	{
		cin >> op;
		if(1 == op)
		{
			cin >> name >> score;
			mp[name] = score;
			cout << "OK" << endl;
		}
		if(2 == op)
		{
			cin >> name;
			if(mp.count(name)) cout << mp[name] << endl;
			else cout << "Not found" << endl;
		}
		if(3 == op)
		{
			cin >> name;
			if(mp.count(name))
			{
				mp.erase(name);
				cout << "Deleted successfully" << endl;
			}
			else cout << "Not found" << endl;
		}
		if(4 == op)
		{
			cout << mp.size() << endl;
		}
	}
	
	return 0;
}*/

// P4305 [JLOI2011] 不重复数字
/*#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T, n;
	cin >> T;
	
	while(T--)
	{
		unordered_set<int> mp;
		cin >> n;
		
		int x;
		while(n--)
		{
			cin >> x;
			if(mp.count(x));
			else cout << x << ' ';
			mp.insert(x);
		}
		cout << endl;
	}
	
	return 0;
}*/

// P3879 [TJOI2010] 阅读理解
/*#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(void)
{
	unordered_map<string, set<int>> mp;
	int n, l, m;
	cin >> n;
	
	string word;
	for(int i = 1; i <= n; i++)
	{
		cin >> l;
		while(l--)
		{
			cin >> word;
			mp[word].insert(i);
		}
	}
	
	cin >> m;
	while(m--)
	{
		cin >> word;
		for(auto& e : mp[word])
		{
			cout << e << ' ';
		}
		cout << endl;
	}
	
	return 0;
}*/

/*#include <iostream>// 不知道为什么全 WA
#include <map>
#include <string>

using namespace std;

multimap<string, int> mp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, L, n;
	cin >> N;
	
	string word;
	int k = 0;
	while(N--)
	{
		cin >> L;
		k++;
		while(L-- && cin >> word)
		{
			mp.insert({word, k});
		}
	}
	
	cin >> n;
	while(n--)
	{
		cin >> word;
		N = mp.count(word);
		
		if(0 == N)
		{
			cout << endl;
			continue;
		}
		
		while(N--)
		{
			auto it = mp.find(word);
			cout << it->second << ' ';
			mp.erase(it);
		}
		cout << endl;
	}
	
	return 0;
}*/

// P1102 A-B 数对
/*#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 10;
int nums[N];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	unordered_map<int, int> mp;
	int n, val;
	cin >> n >> val;
	
	for(int i = 0; i < n; i++)
	{
		cin >> nums[i];
		mp[nums[i]]++;
	}
	
	long long ret = 0;
	for(int i = 0; i < n; i++)
	{
		ret += mp[val + nums[i]];
	}
	
	cout << ret << endl;
	
	return 0;
}*/

// P3405 [USACO16DEC] Cities and States S
/*#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
	unordered_map<string, int> mp;
	
	int n;
	cin >> n;
	
	string city, state;
	int ret = 0;
	while(n--)
	{
		cin >> city >> state;
		city = city.substr(0, 2);
		
		if(city + state == state + city) continue;
		
		mp[city + state]++;
		ret += mp[state + city];
	}
	cout << ret << endl;
	
	return 0;
}*/
