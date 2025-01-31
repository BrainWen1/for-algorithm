// P2786 英语1（eng1）- 英语作文
/*#include <iostream>
#include <map>
#include <cctype>

using namespace std;

int n, p;
map<string, int> words;

int main(void)
{
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	
	cin >> n >> p;
	
	for(int i = 0; i < n; i++)
	{
		string word;
		int val;
		cin >> word >> val;
		words.insert({word, val});
	}

	char ch;
	string word;
	long long ret = 0;
	while(scanf("%c", &ch) != EOF)
	{
		if(isdigit(ch) || isalpha(ch))
		{
			word += ch;
		}
		else
		{
			ret += words[word];
			word = "";
		}
	}
	
	cout << ret % p << endl;
	
	return 0;
}*/

// P2234 [HNOI2002] 营业额统计
/*#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e7 + 10;

set<int> mp;
int n;
int ret;

int main(void)
{
	mp.insert(-N); mp.insert(N);
	
	cin >> n;
	
	int tmp;
	cin >> tmp;
	mp.insert(tmp);
	ret += tmp;
	
	int left, right;
	for(int i = 1; i < n; i++)
	{
		cin >> tmp;
		auto it = mp.lower_bound(tmp);
		
		if(*it == tmp);
        else
        {
        	right = *it;
        	left = *--it;
			ret += min(tmp - left, right - tmp);
			mp.insert(tmp);
		}
	}
	
	cout << ret << endl;
	
	return 0;
}*/

// P5250 【深基17.例5】木材仓库
/*#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<long long> timber;
int n, option, length;

const long long N = 1e10 + 10;

int main(void)
{
	timber.insert(-N); timber.insert(N);
	
	cin >> n;
	
	while(n--)
	{
		cin >> option >> length;
		if(1 == option)
		{
			if(timber.count(length))
				cout << "Already Exist" << endl;
			else
				timber.insert(length);
		}
		else if(2 == option)
		{
			if(timber.size() == 2)
			{
				cout << "Empty" << endl;
				continue;
			}
			else if(timber.count(length))
			{
				timber.erase(length);
				cout << length << endl;
			}
			else
			{
				auto it = timber.upper_bound(length); auto it_ = it;
				it_--;
				if(*it - length >= length - *it_)
				{
					cout << *it_ << endl;
					timber.erase(*it_);
				}
				else
				{
					cout << *it << endl;
					timber.erase(*it);
				}
 			}
		}
	}
	return 0;
}*/
