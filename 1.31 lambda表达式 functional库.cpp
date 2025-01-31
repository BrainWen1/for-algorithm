#include <iostream>
#include <algorithm>
#include <functional>//functional函数库 

using namespace std;

int main(void)
{
    auto square = [](int num){ return num * num; };//lambda表达式 
    int result = square(4);//square作为变量调用lambda表达式定义的函数 
    cout << result << endl;
    
    cout << sizeof(square) << endl;//无捕获变量->1字节 
    
    int a[5] = { 1,5,-2,12,7 };
    sort(a, a + 5, [](int l, int r)->bool{return l > r;});//在sort函数里使用lambda表达式简化代码 
    
    for_each(a, a + 5, [](int num){//for_each函数->遍历算法,配合lambda表达式遍历输出数组元素
    	cout << num << ' ';
	});
    cout << endl;
    
    function<int(int, int)> add = [](int x, int y)->int{return x + y;};//function->通用多态函数包装器，存储、复制和调用任何可调用对象，包括 lambda 表达式
    cout << add(9, 6) << endl;
    
    cout << sizeof(add) << endl;//无捕获变量->32字节 
    
    return 0;
}
