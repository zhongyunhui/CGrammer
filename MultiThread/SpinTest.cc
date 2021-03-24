#include "SpinLock.h"
#include <thread>
#include <iostream>
int cnt=0;

void func(spinLock *l){
	for(int i=0;i<100000;i++){
		l->lock();
		cnt++;
		l->unlock();
	}
}

int main(){
	spinLock *l=new spinLock();
	thread task1(func,l);
	thread task2(func,l);
	task1.join();
	task2.join();
	cout<<"result"<<cnt<<endl;
	return 0;
}
