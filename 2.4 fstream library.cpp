///文件操作
//注意：对于每一个流对象，操作之前要确保上一个操作的流对象调用close()关闭接口重置文件指针 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ofstream ofs;//创建文件输出流对象->out/app模式都会在文件不存在时创建一个新文件 
	ofs.open("text.txt", ios_base::out);//open()指定打开文件和打开模式(ofstream默认为 ios_base::out)->out模式会先清除文件原内容 
	if(!ofs.is_open())//is_open()检查是否成功打开->成功返回true / 失败返回false 
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	
	ofs << "this is something that i have written\r\n";// <<用于向文件输出流中写入文本 
	
	ofs.close();//close()手动关闭文件 
//	
//	
	ifstream ifs;//创建文件输入流对象->读取文件中内容 
	ifs.open("text.txt", ios_base::in);//ifstream默认为 ios_base::in 
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
	fs.open("text.txt", ios_base::app);//app模式->追加内容(fstream默认为(in | out)) 
	if(!fs.is_open())
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	
	string str = "other thing";
	fs << str << "\r\n";//追加内容 
	
	fs.close();
//
//	
	ifs.open("text.txt");//复用文件输入流对象->默认 ios_base::in 
	while(ifs >> s)
	{
		cout << s << ' ';
	}
	cout << endl;
	
	fs.close(); 
//	
//	
	fs.open("text.txt", ios_base::binary | ios_base::app);//binary以二进制模式打开，通过 read和 write操作读写 
	s = "666";
	fs.write(s.c_str(), s.size());//write写入数据 
	
	fs.close();
//
//
	ifs.open("text.txt", ios_base::binary);//复用
	if(!fs.is_open())
	{
		cerr << "file opeing is failing" << endl; return 1;
	}
	ifs.seekg(0, ios::beg);//将文件指针移至文件开头 

	string tmp;
	tmp.resize(100);
	streamsize len = ifs.read(&tmp[0], 100).gcount();//read读取数据->gcount返回实际读取的字节数 
	tmp.resize(len);
	cout << tmp << endl;
	
	ifs.close();
//
//
	return 0;
}












