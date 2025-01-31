#include <iostream>
#include <algorithm>
#include <functional>//functional������ 

using namespace std;

int main(void)
{
    auto square = [](int num){ return num * num; };//lambda���ʽ 
    int result = square(4);//square��Ϊ��������lambda���ʽ����ĺ��� 
    cout << result << endl;
    
    cout << sizeof(square) << endl;//�޲������->1�ֽ� 
    
    int a[5] = { 1,5,-2,12,7 };
    sort(a, a + 5, [](int l, int r)->bool{return l > r;});//��sort������ʹ��lambda���ʽ�򻯴��� 
    
    for_each(a, a + 5, [](int num){//for_each����->�����㷨,���lambda���ʽ�����������Ԫ��
    	cout << num << ' ';
	});
    cout << endl;
    
    function<int(int, int)> add = [](int x, int y)->int{return x + y;};//function->ͨ�ö�̬������װ�����洢�����ƺ͵����κοɵ��ö��󣬰��� lambda ���ʽ
    cout << add(9, 6) << endl;
    
    cout << sizeof(add) << endl;//�޲������->32�ֽ� 
    
    return 0;
}
