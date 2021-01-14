#include <array>
#include <cstdio>
#include <iostream>
using Myarray= std::array<int,4>;
void ArrayTest(){
	Myarray c0={0,1,2,3};
	for(auto p=c0.begin();p!=c0.end();p++){
		std::cout<<*p<<" ";
	}
	Myarray c1;
	c1.fill(5);
	auto addr=c1.data();//int *
	auto size=c1.size();
	std::printf("addr: %zu %zu\n",addr,size);
	for(int i=0;i<size;i++){
		std::cout<<*(addr+i)<<" ";
	}
}

int main(){
	ArrayTest();
	return 0;
}

