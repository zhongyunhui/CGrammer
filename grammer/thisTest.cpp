#include<iostream>
class A{
	public:
		static const int i=0;
	    void hello(){
		std::cout<<"hello"<<i<<std::endl;
		}
	int y;
	A(int a):y(a){}
	A* add(){
		this->y++;
		return this;
	}
};

int main(){
	A p(0);
	A *Q=new A(12);
	Q=p.add();
	std::cout<<Q->y<<std::endl;
}
