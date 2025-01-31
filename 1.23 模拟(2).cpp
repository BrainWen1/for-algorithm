// P1098 [NOIP2007 提高组] 字符串的展开
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int p1, p2, p3;
string str;
string ret;

void add(char& left, char& right)
{
	string s;
	for(char ch = left + 1; ch < right; ch++)
	{
		char tmp = ch;
		if(p1 == 2 && isalpha(left)) tmp -= 32;
		else if(p1 == 3) tmp = '*';
		
		for(int i = 0; i < p2; i++)
		{
			s += tmp;
		}
	}
	if(p3 == 2) reverse(s.begin(), s.end());

	ret += s;
}

int main(void)
{
	cin >> p1 >> p2 >> p3 >> str;
	int n = str.size();
	
	for(int i = 0; i < n; i++)
	{
		char ch = str[i];
		if(ch != '-' || i == 0 || i == n - 1) ret += ch;
		else
		{
			char left = str[i - 1], right = str[i + 1];
			if((isdigit(left) && isdigit(right) && left < right) ||
			   (isalpha(left) && isalpha(right) && left < right))
			{
				add(left, right);
			}
			else ret += ch;
		}
	}
	cout << ret << endl;
	
	return 0;
}

/*#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;//不懂为什么全错

int main(void)
{
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	getchar();

	char ch = 0;
	string str;
	while(scanf("%c", &ch) != EOF)
	{
		if(ch == '-')
		{
			char left = str.back();
			char right = getchar();
			char r = right;
			if((isdigit(left) && isalpha(right)) || (isalpha(left) && isdigit(right)))
			if(left == right - 1) str += right;
			else if(left >= right) str += ch + right;
			else
			{
				string fill;
				char tmp;
				if(p1 == 1) tmp = left + 1;
				else if(p1 == 2 && isalpha(left) && isalpha(right))
				{
					tmp = left - 32 + 1;
					r -= 32;
				}
				else tmp = '*';

				if(tmp != '*')
				{
					for(tmp; tmp < r; tmp++)
					{
						for(int i = 0; i < p2; i++)
							fill += tmp;
					}
				}
				else
				{
					for(char i = left + 1; i < right; i++)
					{
						for(int j = 0; j < p2; j++)
							fill += tmp;
					}
				}

				if(p3 == 2)
					reverse(fill.begin(), fill.end());

				str += fill;
				str += right;
			}
		}
		else if(ch == '\n') break;
		else
			str += ch;
	}

	cout << str << endl;

	return 0;
}*/
