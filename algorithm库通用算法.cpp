#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <random>

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
	
	int p[10] = { 1, 4, 4, 6, 7, 7, 8, 12, 13, 12};//12 13 12 无序，故无法正确去重 
	itend = unique(p, p + 10);//unique去重函数->要求范围内为有序序列->将重复元素移至末尾，最终返回last迭代器 
	for(auto it = p; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	int q[10] = { -4, -1, 1, 4, 5, 9, 9, 12, 13, 12 };
	itend = unique(q, q + 10, [](int& a, int& b)->bool{
		return abs(a) == abs(b);//unique自定义函数调整对'重'的定义->绝对值相等 
	});
	for(auto it = q; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	//与set_union对应的 merge(合并有序数组到指定位置)和 inplace_merge(原地合并连续有序数组) -> set_union会去重, 后两个不会去重 
	int r[10], s[10];
	merge(d, d + 5, e, e + 5, r);//默认升序 
	merge(g, g + 5, h, h + 5, s, [](int& l, int& r)->bool{//自定义函数调整为降序 
		return l > r;
	});
	for_each(r, r + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl;
	for_each(s, s + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int t[10] = { 1, 4, 9, 12, 67, 3, 6, 9, 11, 12 };//inplace_merge原地合并->默认为升序，也可以使用自定义函数调整为降序，不赘述 
	inplace_merge(t, t + 5, t + 10);//注意三个参数 
	for_each(t, t + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int u[5] = { 9, -1, 3, 3, 4 };
	
	auto endit = remove(u, u + 5, 3);//remove->将不匹配的元素向前覆盖，不会真正改变容器大小，返回新的逻辑末尾 
	
	for_each(u, endit, [](int& num){// 9 -1 4
		cout << num << ' ';
	});
	cout << endl;
	
	int  v[6] = { 8, -2, 3, 4, 1, 0 };
	
	rotate(v, v + 2, v + 6);//rotate(left, mid, right)->旋转->交换[left, mid)和[mid + 1, right) 
	
	for_each(v, v + 6, [](int& num){// 3 4 1 0 | 8 -2 
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int w[10] = { 5, 0, 1, 6, -3, 12, 9, 66, 2, -11 };
	int N = 5;
	
	random_device rd;
    mt19937 seed(rd());
    
	while(N--)
	{
		for_each(w, w + 10, [](int& num){
			cout << num << ' ';
		});
		cout << endl;
		
		shuffle(w, w + 10, seed);//shuffle->随机重排算法->seed为随机生成算法对象 
	}
	cout << endl << endl;
	
	if(is_sorted(w, w + 10)) cout << "w array: is sorted" << endl;//is_sorted->判断范围内元素是否有序(默认升序，可借助自定义函数调整) 
	else cout << "w array: is not sorted" << endl;
	
	if(is_sorted(t, t + 10)) cout << "t array: is sorted" << endl;
	else cout << "t array: is not sorted" << endl;
	
	return 0;
}









