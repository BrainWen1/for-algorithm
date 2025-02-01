#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a[10] = { 1, 6, 4, 9, -2, -6, 2, 9, 12, 5 };//10 

int main(void)
{
	//count find
	cout << count(a, a + 10, 9) << endl;//2
	cout << *(find(a, a + 10, 6) + 1) << endl;//4
	cout << count(a, a + 10, 10) << endl;//0
	cout << *find(a, a + 10, 10) << endl;//返回last迭代器，解引用为随机数 
	
	int b[10] = { 0 };
	copy(a, a + 10, b);//copy
	for_each(b, b + 10, [](int& num){//for_each
		cout << num << ' ';
	}); cout << endl;
	
	cout << count_if(b, b + 10, [](int& num)->bool{
		return num % 2 == 0;//count_if
	}) << endl;
	
	sort(b, b + 10);//sort默认升序 
	cout << "b->" << endl;
	for_each(b, b + 10, [](int& num){
		cout << num << ' ';
	}); cout << endl;
	
	sort(b, b + 10, [](int& l, int& r)->bool{//sort自定义降序 
		return l > r;
	});
	cout << "b->" << endl;
	for_each(b, b + 10, [](int& num){
		cout << num << ' ';
	}); cout << endl;
	
	struct node
	{
		int val;
		int index;
	};
	node c[5] = { {1,1}, {6,4}, {4,3}, {6,2}, {12,5} };
	stable_sort(c, c + 5, [](const node& l, const node& r)->bool{//stable_sort需要传入const引用以契合其稳定性排序规则 
		return l.val < r.val;//stable_sort按val值升序排列，并保持相等元素原相对位置 
	});
	cout << "c->" << endl;
	for_each(c, c + 5, [](node& nd){
		cout << nd.val << " -> " << nd.index << endl;//验证稳定性 
	});
	
	sort(a, a + 10);//升序 
	//binary_search默认查找方式为升序(a array) 
	if(binary_search(a, a + 10, 5)) cout << "5 is existing int a array" << endl;
	if(binary_search(a, a + 10, 10)) cout << "10 is existing int a array" << endl;
	//可自定义函数指定binary_search查找方式为降序(b array) 
	if(binary_search(b, b + 10, 1, [](int l, int r)->bool{
		return l > r;
	})) cout << "1 is existing in b array" << endl << endl;
	
	cout << *lower_bound(a, a + 10, 4) << endl;//lower_bound查找大于等于4的值的位置 
	cout << *upper_bound(a, a + 10, 3) << endl;//upper_bound查找大于3的值的位置 
	
	int d[5] = { 1, 5, 6, 8, 12};
	int e[5] = { 2, 4, 5, 7, 12};
	int f[10] = { 0 };
	auto itend = set_union(d, d + 5, e, e + 5, f);//集合操作set_union->分治思想合并两个有序数组(默认升序)为并集，同时去重 
	for(auto it = f; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	int g[5] = { 13, 8, 6, 3, -2 };
	int h[5] = { 23, 14, 8, 3, -1 };
	int j[10] = { 0 };
	itend = set_union(g, g + 5, h, h + 5, j, [](int& l, int& r)->bool{
		return l > r;//set_union可自定义函数调整为降序 
	});
	for(auto it = j; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	itend = set_intersection(d, d + 5, e, e + 5, f);//集合操作set_intersection->合并两个有序数组(默认升序)为交集，同时去重 
	for(auto it = f; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	itend = set_intersection(g, g + 5, h, h + 5, j, [](int& l, int& r)->bool{
		return l > r;//set_intersection也可自定义函数调整为降序 
	});
	for(auto it = j; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	int k[10] = { 8, 3, 5, -2, 12, 5, 2, 9, 13, 12 };
	replace(k, k + 10, 12, 6);//replace将范围内所有 12替换为 6
	for_each(k, k + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int m[10] = { 8, 3, 5, -2, 12, 5, 2, 9, 13, 12 };
	replace_if(m, m + 10, [](int& num)->bool{
		return num % 2 == 1;
	}, 0);//replace_if将范围内所有满足条件(奇数)元素替换为新值(0) 
	for_each(m, m + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int n[7] = { 1, 4, 3, 3, 2, 2, 3 };
	for_each(n, n + 7, [](int& num){
		cout << num << ' ';
	});
	cout << endl;
	reverse(n, n + 7);//reverse反转整型数组 
	for_each(n, n + 7, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	string str = "iloveyoubaby.";
	cout << str << endl;
	reverse(str.begin(), str.end());//reverse反转字符串string 
	cout << str << endl << endl;
	
	return 0;
}
