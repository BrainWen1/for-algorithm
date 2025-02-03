#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
	istringstream iss("abc123.[6]!");//����istringstream���󲢳�ʼ��->���������� 
	
	string s1;
	iss >> s1;//ʹ�� >> ��������iss���������ַ������뵽 s1�� 
	cout << s1 << endl;
	
	string s2;
	s2 = iss.str();//����istringstream�ຯ��str()->���ص�ǰ����iss�д��ڵ��ַ��� 
	cout << s2 << endl;
	
	string s3 = "Hello sstream!";
	iss.str(s3);//����str(s3)->������iss�е����ݸ���Ϊ s3�е��ַ���(֮ǰ����ȫ�����) 
	cout << iss.str() << endl << endl;
	
	ostringstream oss;//����ostringstream���󲻳�ʼ��->ossΪ��->��������� 
	
	string s4 = "def456.[666]?!?";
	oss.str(s4);//ͬistringstream 
	cout << oss.str() << endl;//ͬistringstream 
	
	string s5 = "GoodBye!";
	oss << s5;//ʹ�� << �������� s1�����ַ������뵽����oss��->Ĭ�ϴ�ͷ����ʼ���ǣ����������Իᱣ���������뱣������ǰ��ն��� oss.str(""); 
	cout << oss.str() << endl << endl; 
	
	stringstream ss("jiangyi,wangyao,jianghemin");//�������������->�÷��ۺ����������������������� 
	string token;
	while(getline(ss, token, ','))//ss��Ϊ������������getline������������һ���������� cin���÷�->����������ķ���ֵ�ж��Ƿ����� 
	{
		cout << token << endl;
	}
	cout << endl;
	
	//����������->�������ܿ���
	ss.str("");
	ss.clear(); 
	
	string s6 = "Yousaywewillbetallerinotherdimension";
	ss << s6;
	cout << ss.str() << endl << endl;
	
	stringstream sss;//Ϊ������Ԥ����ռ�->�������ܿ��� 
	sss << string(100, 0);
	sss.str("");
	
	sss << "Iamachar.";
	
	cout << sss.str() << endl;
	cout << sss.str().size() << endl;//sss.str().size()���ص�ǰ�������е� �Ѵ��ڵ��ַ��� 
	cout << sss.str().capacity() << endl;///sss.str().capacity()���ص�ǰ�������� �ɴ�ŵ��ַ��� 

	return 0;
}
