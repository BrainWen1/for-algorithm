#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

int main(void)
{
	//使用不同的种子(当前时间)来初始化随机数生成器 gen
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	random_device rd;//创建random_device对象-> rd
	mt19937 gen(seed);//使用 rd()获取的种子值初始化 mt19937类型的随机数引擎 gen 
	
	int n = 10;//通过循环调用 gen()生成并输出 10个伪随机数
	while(n--) cout << gen() << endl;
	cout << endl;
	
	//随机数分布 需要和随机数引擎 gen配合使用
	//将引擎 gen生成的随机数 gen()转换为指定范围(1, 100)内的均匀分布随机数
	//创建均匀分布对象 dis，生成(1, 100)之间(包含 1 和 100)的整数随机数
	uniform_int_distribution<> dis(1, 100);//<>内可指定，也可由编译器自动推导 
	
	n = 20;//均匀分布对象 dis配合随机数引擎 gen使用 
	while(n--) cout << dis(gen) << ' ';
	cout << endl << endl;
	
	//创建正态分布对象，均值为 0.0，标准差为 1.0
	normal_distribution<> dist(0.0, 1.0);
	
	n = 100;//正态分布对象 dist配合随机数引擎 gen使用 
	while(n--) cout << left << setw(10) << dist(gen) << endl;
	
	return 0;
}
