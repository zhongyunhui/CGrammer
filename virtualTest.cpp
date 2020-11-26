#include<iostream>
#include<stdlib.h>
using namespace std;

class Father{
	public :
	virtual void F(){
		cout<<"I am your father"<<endl;
	}
	void F2(){
		cout<<"I am not your father"<<endl;
	}
};
class Son:public Father{
	public:
	void F(){
		cout<<"I am your son"<<endl;
	}
	void F2(){
		cout<<"I am not your son"<<endl;
	}
};
int main(){
	Father *f1=new Son();
	Father *f2=new Father();
	Son *s1=new Son();
	s1->F2();
	f1->F2();//f1->F();
	f2->F2();//f2->F();
	return 0;	
}

