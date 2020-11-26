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

class B{
	public:
		int a,b;
};

int main(){
	A* a=new A(1,2);
	a=reinterpret_cast<B*>(a);
	a=reinterpret_cast<A*>(a);
	a->Test();
}
