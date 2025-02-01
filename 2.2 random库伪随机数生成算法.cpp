#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

int main(void)
{
	//ʹ�ò�ͬ������(��ǰʱ��)����ʼ������������� gen
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	random_device rd;//����random_device����-> rd
	mt19937 gen(seed);//ʹ�� rd()��ȡ������ֵ��ʼ�� mt19937���͵���������� gen 
	
	int n = 10;//ͨ��ѭ������ gen()���ɲ���� 10��α�����
	while(n--) cout << gen() << endl;
	cout << endl;
	
	//������ֲ� ��Ҫ����������� gen���ʹ��
	//������ gen���ɵ������ gen()ת��Ϊָ����Χ(1, 100)�ڵľ��ȷֲ������
	//�������ȷֲ����� dis������(1, 100)֮��(���� 1 �� 100)�����������
	uniform_int_distribution<> dis(1, 100);//<>�ڿ�ָ����Ҳ���ɱ������Զ��Ƶ� 
	
	n = 20;//���ȷֲ����� dis������������ genʹ�� 
	while(n--) cout << dis(gen) << ' ';
	cout << endl << endl;
	
	//������̬�ֲ����󣬾�ֵΪ 0.0����׼��Ϊ 1.0
	normal_distribution<> dist(0.0, 1.0);
	
	n = 100;//��̬�ֲ����� dist������������ genʹ�� 
	while(n--) cout << left << setw(10) << dist(gen) << endl;
	
	return 0;
}
