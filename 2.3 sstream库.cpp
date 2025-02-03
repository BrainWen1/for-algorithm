#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
	istringstream iss("abc123.[6]!");//创建istringstream对象并初始化->输入流对象 
	
	string s1;
	iss >> s1;//使用 >> 操作符将iss对象所存字符串输入到 s1中 
	cout << s1 << endl;
	
	string s2;
	s2 = iss.str();//调用istringstream类函数str()->返回当前对象iss中存在的字符串 
	cout << s2 << endl;
	
	string s3 = "Hello sstream!";
	iss.str(s3);//调用str(s3)->将对象iss中的内容更新为 s3中的字符串(之前内容全部清空) 
	cout << iss.str() << endl << endl;
	
	ostringstream oss;//创建ostringstream对象不初始化->oss为空->输出流对象 
	
	string s4 = "def456.[666]?!?";
	oss.str(s4);//同istringstream 
	cout << oss.str() << endl;//同istringstream 
	
	string s5 = "GoodBye!";
	oss << s5;//使用 << 操作符将 s1所存字符串输入到对象oss中->默认从头部开始覆盖，过长部分仍会保留，若不想保留可提前清空对象 oss.str(""); 
	cout << oss.str() << endl << endl; 
	
	stringstream ss("jiangyi,wangyao,jianghemin");//输入输出流对象->用法综合了输入流对象和输出流对象 
	string token;
	while(getline(ss, token, ','))//ss作为输入流对象在getline函数中类似另一输入流对象 cin的用法->根据流对象的返回值判断是否运行 
	{
		cout << token << endl;
	}
	cout << endl;
	
	//复用流对象->减少性能开销
	ss.str("");
	ss.clear(); 
	
	string s6 = "Yousaywewillbetallerinotherdimension";
	ss << s6;
	cout << ss.str() << endl << endl;
	
	stringstream sss;//为流对象预分配空间->减少性能开销 
	sss << string(100, 0);
	sss.str("");
	
	sss << "Iamachar.";
	
	cout << sss.str() << endl;
	cout << sss.str().size() << endl;//sss.str().size()返回当前流对象中的 已存在的字符数 
	cout << sss.str().capacity() << endl;///sss.str().capacity()返回当前流对象中 可存放的字符数 

	return 0;
}
