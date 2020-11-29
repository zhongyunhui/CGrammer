#include<iostream>
using namespace std;

class Base{
public:
	//virtual void doWork();	
	virtual void Base_show1(){
		cout<<"this is base public"<<endl;
	}	
protected:
	void Base_show2(){
		cout<<"this is base protected"<<endl;
	}
private:
	void Base_show3(){
		cout<<"this is base private"<<endl;
	}
};



class Derived:public Base{
public:
	void Derived_show1(){
		cout<<"this is Derived show1"<<endl;
		Base_show1();
		Base_show2();
		//Base_show3();
	}	
	static void Derive_static(){
		cout<<"this is Derived Static"<<endl;
	}
	void Base_show1()const override{
		cout<<"this is virtual Derived show "<<endl;
	}
	void Orientation()& {
		cout<<"this is a left value"<<endl;
	}
	void Orientation()&& {
		cout<<"this is a right value"<<endl;
	}
};

int main(){
	cout<<"Hello World!"<<endl;
	Base *mderived=new Derived();
	//mderived->Base_show1();
	mderived->Orientation();
	return 0;
}
