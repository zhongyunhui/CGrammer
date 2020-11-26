#include<iostream>

void Initializer_list_test(){
	std::initializer_list<int> iniList={0,1,2,3};
	for(auto i=iniList.begin();i!=iniList.end();i++){
		std::printf("%d ",*i);
	}
	std::cout<<std::endl;
}

int main(){
	Initializer_list_test();
	return 0;
}
