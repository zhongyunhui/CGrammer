#include <iostream>
#include <memory>
#include "people.h"

using namespace std;

People getPeople(int a){
	return People(a);
}

void show( unique_ptr<People>tmp){
	cout<<"getAge: "<<tmp->getage()<<endl;
}

int main(){
	unique_ptr<People> test(make_unique<People>(6));
	show(std::move(test));
	//People test1=test;//赋值构造函数
	//test1=test;//只用复制赋值运算符
	
	int a=1;
	int &b=a;
	b=2;
	cout<<"a= "<<a<<endl;
	const int &c=10;
	int &&r=0;
	r=1;
}
		
