///�ļ�����
//ע�⣺����ÿһ�������󣬲���֮ǰҪȷ����һ�����������������close()�رսӿ������ļ�ָ�� 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ofstream ofs;//�����ļ����������->out/appģʽ�������ļ�������ʱ����һ�����ļ� 
	ofs.open("text.txt", ios_base::out);//open()ָ�����ļ��ʹ�ģʽ(ofstreamĬ��Ϊ ios_base::out)->outģʽ��������ļ�ԭ���� 
	if(!ofs.is_open())//is_open()����Ƿ�ɹ���->�ɹ�����true / ʧ�ܷ���false 
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	
	ofs << "this is something that i have written\r\n";// <<�������ļ��������д���ı� 
	
	ofs.close();//close()�ֶ��ر��ļ� 
//	
//	
	ifstream ifs;//�����ļ�����������->��ȡ�ļ������� 
	ifs.open("text.txt", ios_base::in);//ifstreamĬ��Ϊ ios_base::in 
	if(!ifs.is_open())
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	
	string s;
	while(ifs >> s)
	{
		cout << s << ' ';
	}
	cout << endl;
	
	ifs.close();
	ifs.clear();
//
//	
	fstream fs;
	fs.open("text.txt", ios_base::app);//appģʽ->׷������(fstreamĬ��Ϊ(in | out)) 
	if(!fs.is_open())
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	
	string str = "other thing";
	fs << str << "\r\n";//׷������ 
	
	fs.close();
//
//	
	ifs.open("text.txt");//�����ļ�����������->Ĭ�� ios_base::in 
	while(ifs >> s)
	{
		cout << s << ' ';
	}
	cout << endl;
	
	fs.close(); 
//	
//	
	fs.open("text.txt", ios_base::binary | ios_base::app);//binary�Զ�����ģʽ�򿪣�ͨ�� read�� write������д 
	s = "666";
	fs.write(s.c_str(), s.size());//writeд������ 
	
	fs.close();
//
//
	ifs.open("text.txt", ios_base::binary);//����
	if(!fs.is_open())
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	ifs.seekg(0, ios::beg);//���ļ�ָ�������ļ���ͷ 

	string tmp;
	tmp.resize(100);
	streamsize len = ifs.read(&tmp[0], 100).gcount();//read��ȡ����->gcount����ʵ�ʶ�ȡ���ֽ��� 
	tmp.resize(len);
	cout << tmp << endl;
	
	ifs.close();
//
//
	return 0;
}












