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
	cout << *find(a, a + 10, 10) << endl;//����last��������������Ϊ����� 
	
	int b[10] = { 0 };
	copy(a, a + 10, b);//copy
	for_each(b, b + 10, [](int& num){//for_each
		cout << num << ' ';
	}); cout << endl;
	
	cout << count_if(b, b + 10, [](int& num)->bool{
		return num % 2 == 0;//count_if
	}) << endl;
	
	sort(b, b + 10);//sortĬ������ 
	cout << "b->" << endl;
	for_each(b, b + 10, [](int& num){
		cout << num << ' ';
	}); cout << endl;
	
	sort(b, b + 10, [](int& l, int& r)->bool{//sort�Զ��彵�� 
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
	stable_sort(c, c + 5, [](const node& l, const node& r)->bool{//stable_sort��Ҫ����const�������������ȶ���������� 
		return l.val < r.val;//stable_sort��valֵ�������У����������Ԫ��ԭ���λ�� 
	});
	cout << "c->" << endl;
	for_each(c, c + 5, [](node& nd){
		cout << nd.val << " -> " << nd.index << endl;//��֤�ȶ��� 
	});
	
	sort(a, a + 10);//���� 
	//binary_searchĬ�ϲ��ҷ�ʽΪ����(a array) 
	if(binary_search(a, a + 10, 5)) cout << "5 is existing int a array" << endl;
	if(binary_search(a, a + 10, 10)) cout << "10 is existing int a array" << endl;
	//���Զ��庯��ָ��binary_search���ҷ�ʽΪ����(b array) 
	if(binary_search(b, b + 10, 1, [](int l, int r)->bool{
		return l > r;
	})) cout << "1 is existing in b array" << endl << endl;
	
	cout << *lower_bound(a, a + 10, 4) << endl;//lower_bound���Ҵ��ڵ���4��ֵ��λ�� 
	cout << *upper_bound(a, a + 10, 3) << endl;//upper_bound���Ҵ���3��ֵ��λ�� 
	
	int d[5] = { 1, 5, 6, 8, 12};
	int e[5] = { 2, 4, 5, 7, 12};
	int f[10] = { 0 };
	auto itend = set_union(d, d + 5, e, e + 5, f);//���ϲ���set_union->����˼��ϲ�������������(Ĭ������)Ϊ������ͬʱȥ�� 
	for(auto it = f; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	int g[5] = { 13, 8, 6, 3, -2 };
	int h[5] = { 23, 14, 8, 3, -1 };
	int j[10] = { 0 };
	itend = set_union(g, g + 5, h, h + 5, j, [](int& l, int& r)->bool{
		return l > r;//set_union���Զ��庯������Ϊ���� 
	});
	for(auto it = j; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	itend = set_intersection(d, d + 5, e, e + 5, f);//���ϲ���set_intersection->�ϲ�������������(Ĭ������)Ϊ������ͬʱȥ�� 
	for(auto it = f; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	itend = set_intersection(g, g + 5, h, h + 5, j, [](int& l, int& r)->bool{
		return l > r;//set_intersectionҲ���Զ��庯������Ϊ���� 
	});
	for(auto it = j; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	int k[10] = { 8, 3, 5, -2, 12, 5, 2, 9, 13, 12 };
	replace(k, k + 10, 12, 6);//replace����Χ������ 12�滻Ϊ 6
	for_each(k, k + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int m[10] = { 8, 3, 5, -2, 12, 5, 2, 9, 13, 12 };
	replace_if(m, m + 10, [](int& num)->bool{
		return num % 2 == 1;
	}, 0);//replace_if����Χ��������������(����)Ԫ���滻Ϊ��ֵ(0) 
	for_each(m, m + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int n[7] = { 1, 4, 3, 3, 2, 2, 3 };
	for_each(n, n + 7, [](int& num){
		cout << num << ' ';
	});
	cout << endl;
	reverse(n, n + 7);//reverse��ת�������� 
	for_each(n, n + 7, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	string str = "iloveyoubaby.";
	cout << str << endl;
	reverse(str.begin(), str.end());//reverse��ת�ַ���string 
	cout << str << endl << endl;
	
	int p[10] = { 1, 4, 4, 6, 7, 7, 8, 12, 13, 12};//12 13 12 ���򣬹��޷���ȷȥ�� 
	itend = unique(p, p + 10);//uniqueȥ�غ���->Ҫ��Χ��Ϊ��������->���ظ�Ԫ������ĩβ�����շ���last������ 
	for(auto it = p; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	int q[10] = { -4, -1, 1, 4, 5, 9, 9, 12, 13, 12 };
	itend = unique(q, q + 10, [](int& a, int& b)->bool{
		return abs(a) == abs(b);//unique�Զ��庯��������'��'�Ķ���->����ֵ��� 
	});
	for(auto it = q; it != itend; it++) cout << *it << ' ';
	cout << endl << endl;
	
	//��set_union��Ӧ�� merge(�ϲ��������鵽ָ��λ��)�� inplace_merge(ԭ�غϲ�������������) -> set_union��ȥ��, ����������ȥ�� 
	int r[10], s[10];
	merge(d, d + 5, e, e + 5, r);//Ĭ������ 
	merge(g, g + 5, h, h + 5, s, [](int& l, int& r)->bool{//�Զ��庯������Ϊ���� 
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
	
	int t[10] = { 1, 4, 9, 12, 67, 3, 6, 9, 11, 12 };//inplace_mergeԭ�غϲ�->Ĭ��Ϊ����Ҳ����ʹ���Զ��庯������Ϊ���򣬲�׸�� 
	inplace_merge(t, t + 5, t + 10);//ע���������� 
	for_each(t, t + 10, [](int& num){
		cout << num << ' ';
	});
	cout << endl << endl;
	
	int u[5] = { 9, -1, 3, 3, 4 };
	
	auto endit = remove(u, u + 5, 3);//remove->����ƥ���Ԫ����ǰ���ǣ����������ı�������С�������µ��߼�ĩβ 
	
	for_each(u, endit, [](int& num){// 9 -1 4
		cout << num << ' ';
	});
	cout << endl;
	
	int  v[6] = { 8, -2, 3, 4, 1, 0 };
	
	rotate(v, v + 2, v + 6);//rotate(left, mid, right)->��ת->����[left, mid)��[mid + 1, right) 
	
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
		
		shuffle(w, w + 10, seed);//shuffle->��������㷨->seedΪ��������㷨���� 
	}
	cout << endl << endl;
	
	if(is_sorted(w, w + 10)) cout << "w array: is sorted" << endl;//is_sorted->�жϷ�Χ��Ԫ���Ƿ�����(Ĭ�����򣬿ɽ����Զ��庯������) 
	else cout << "w array: is not sorted" << endl;
	
	if(is_sorted(t, t + 10)) cout << "t array: is sorted" << endl;
	else cout << "t array: is not sorted" << endl;
	
	return 0;
}