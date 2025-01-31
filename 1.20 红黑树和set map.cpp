// set multiset
/*#include <iostream>
#include <set>

using namespace std;

void print(set<int>& mp)
{
	for(auto p = mp.begin(); p != mp.end(); p++)
	{
		cout << *p << ' ';
	}
	cout << endl;
}

int main(void)
{
	set<int> mp1;
	set<string> mp2;
	
	for(int i = 1; i <= 10; i++)
		mp1.insert(i);
		
	print(mp1);
	
//	for(int i = 1; i <= 10; i++)
//	{
//		cout << mp1.size() << ' ';
//		mp1.erase(i);
//	}
	
	cout << mp1.count(1) << endl;
	cout << mp1.count(4) << endl;
	cout << mp1.count(9) << endl;
	cout << mp1.count(12) << endl << endl;
	
	cout << *mp1.lower_bound(3) << endl;
	cout << *mp1.lower_bound(7) << endl;
	cout << *mp1.upper_bound(3) << endl << endl;
	
	multiset<int> mp3;
	
	mp3.insert(1);
	mp3.insert(2);
	mp3.insert(2);
	mp3.insert(2);
	mp3.insert(3);
	mp3.insert(4);
	mp3.insert(4);
	
	cout << mp3.count(1) << endl;
	cout << mp3.count(2) << endl;
	cout << mp3.count(3) << endl;
	cout << mp3.count(4) << endl;
	cout << mp3.count(10) << endl;
	
	return 0;
}*/


// map multimap
/*#include <iostream>
#include <map>

using namespace std;

void print(map<string, int>& mp)
{
	for(auto p = mp.begin(); p != mp.end(); p++)
	{
		cout << (*p).first << ' ' << (*p).second << endl;
	}
	cout << endl;
}

int main(void)
{
	map<string, int> mp1;
	map<int, int> mp2;
	map<string, string> mp3;
	map<int, int[10]> mp4;
	
	mp1.insert({"zhangsan", 1});
	mp1.insert({"lisi", 2});
	mp1.insert({"wangwu", 3});
	mp1.insert({"zhaoliu", 4});
	mp1.insert({"wenbin", 5});
	
	cout << mp1.size() << endl;
	mp1.erase("wenbin");
	cout << mp1.size() << endl;
	
	cout << mp1.count("zhangsan") << ' ';
	cout << mp1.count("zhaoliu") << ' ';
	cout << mp1.count("wenbin") << ' ';
	cout << endl << endl;
	
	cout << (*mp1.lower_bound("zhangsan")).first << endl;
	cout << (*mp1.lower_bound("wangwu")).first << endl;
	cout << (*mp1.upper_bound("zhangsan")).first << endl << endl;
	cout << mp1.upper_bound("zhangsan")->second << endl << endl;
	
	cout << mp1["lisi"] << endl;
	if(mp1.count("wenbin") && mp1["wenbin"] == 2)
		cout << "yes" << endl << endl;
	else
		cout << "no" << endl << endl;
		
	mp1["lisi"] = 99;
	cout << mp1["lisi"] << endl;
	cout << mp1.find("lisi")->second << endl << endl;
	
	print(mp1);
	
	multimap<string, int> mp5;
	
	mp5.insert({"zhangsan", 1});
	mp5.insert({"lisi", 2});
	mp5.insert({"wangwu", 3});
	mp5.insert({"lisi", 2});
	mp5.insert({"zhangsan", 5});
	
	cout << mp5.count("zhangsan") << endl;
	cout << mp5.count("lisi") << endl;
	cout << mp5.count("wangwu") << endl;
	cout << mp5.count("wenbin") << endl;
	
	return 0;
}*/
