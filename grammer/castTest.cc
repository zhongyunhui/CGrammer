#include <iostream>
#include "point.h"
#include <typeinfo>
using namespace std;
int main(){
	point * A=new point3D(1,2,3);
	point3D * B=dynamic_cast<point3D* >(A);
	B->::point::disp();
	cout<<typeid(*A).name()<<endl;
	cout<<typeid(*B).name()<<endl;
	A=new point(1,2);
	cout<<typeid(*A).name()<<endl;
	B=dynamic_cast<point3D*> (A);
	if(B!=nullptr)B->disp();  //转换时会动态检测，如果无法cast,则返回nullptr
	else cout<<"dynamic_cast failed"<<endl;
}
