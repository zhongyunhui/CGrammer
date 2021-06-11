#include <iostream>
using namespace std;
class A{
public:
	int ax;
	A(int x):ax(x){};
	int getX() const {
		return ax;
	}
	void showX(){
		cout<<ax<<endl;
	}
};

int operator++(A& a,int ){
	a.ax+=2;
	return a.ax;
}
int main(){
	A a(2);
	//cout<<a.getX()<<endl;
	cout<<a++<<endl;
//	a.showX();
}
