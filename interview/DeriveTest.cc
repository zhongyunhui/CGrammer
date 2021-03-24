#include <iostream>
using namespace std;

class A{
public:
	virtual void pri(){cout<<"A"<<endl;}
	void call(){
		cout<<"Call A"<<endl;
		pri();
	}
	virtual ~A(){pri();}
};
class C:public A{
public:
	void pri(){cout<<"C"<<endl;}
	void call(){
		cout<<"call C"<<endl;
		pri();
	}
	~C(){
		pri();
	}
};

int main(){
	A* p=new C();
	p->call();
	delete p;
}
