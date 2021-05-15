#include<iostream>

using namespace std;

class A{
	public:
		int a,b;
		A(int x,int y):a(x),b(y){}
		void Test(){
			printf("hello");
		}
};

class C:public A{
	public:
		int c;
		C(int x, int y, int z):A(x,y), c(z){}
};
class B{
	public:
		int a,b;
};

int main(){
	A* a=new A(1,2);
//	a=reinterpret_cast<B*>(a);
	a=new C(1,2,3);
	a->Test();
	C *c=nullptr;
	//	c=(A*) new A(1,2);//无法讲基类强转为派生类
}
