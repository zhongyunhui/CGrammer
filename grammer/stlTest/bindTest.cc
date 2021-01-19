#include <iostream>
#include <vector>
#include <functional>
using namespace std;

function< int(int) >Func;

int TestFunc(int a){
	return a;
}
//
auto lambda=[](int a)->int{return a;};

//仿函数
class Functor{
public:
	int operator()(int a){
		return a;
	}
};

class TestClass{
public:
	int normalMethod(int a){return a;}
	static int staticMethod(int a){return a;}
};
function< int(TestClass,int)>thisFunc;
	
int main(){
	Func=TestFunc;
	cout<<"TestFunc: "<<Func(1)<<endl;
	Func=lambda;
	cout<<"lamda: "<<Func(2)<<endl;
	Functor testFunctor;
	Func=testFunctor;
	cout<<"Functor: "<<Func(3)<<endl;
	TestClass testobj;
	//绑定类的成员变量时需要bind帮助，或者传入this指针
	Func=bind(&TestClass::normalMethod,testobj,std::placeholders::_1);//_1为延迟绑定符
	//cout<<"成员函数: "<<Func(4)<<endl;
	thisFunc=&TestClass::normalMethod;
	cout<<"this 指针调用: " <<thisFunc(testobj,13)<<endl;

	Func=TestClass::staticMethod;
	cout<<"static方法: "<<Func(5)<<endl;
	vector< vector<int> >vec(100,vector<int>(100));
	return 0;
}

	

	
