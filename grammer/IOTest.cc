#include <fstream>
#include <iostream>
using namespace std;

int main(){
	char* str1="hello,world";
	char* str2="hello,world";
	cout<<(size_t)str1<<" "<<(size_t)str2<<endl;
	str1[5]='i';
	cout<<(size_t)str1<<" "<<(size_t)str2<<endl;
	fstream ofs;
	ofs.open("test.txt",ios::in|ios::out);
	if(!ofs.is_open()){
		cout<<"cannot open file"<<endl;
	}
	ofs<<"hello,world!";
	string txt;
	ofs>>txt;
	cout<<txt;
	ofs.close();
	return 0;
}
