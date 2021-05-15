#include <iostream>
using namespace std;

int main(){
	int a=1;
	auto t=[&]()->int{a=2;return a;};
	cout<<t()<<endl;
	cout<<a<<endl;
}

