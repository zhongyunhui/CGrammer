#include <iostream>
#include<unistd.h>
using namespace std;
int main(){
	int i=100;
	while(i>0){
		i--;
		sleep(1);
		cout<<"Hello: "<<i<<endl;
	}
	return 0;
}

