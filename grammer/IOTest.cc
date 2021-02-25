#include <fstream>
#include <iostream>
using namespace std;

int main(){
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
