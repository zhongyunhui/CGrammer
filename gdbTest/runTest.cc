#include <iostream>
#include<unistd.h>
#include <thread>
#include<atomic>
using namespace std;
int main(){
	atomic_int i(300);
	thread * t1=new thread([&](){
		while(i>0){
			i--;
			sleep(1);
			cout<<"threadID:"<<this_thread::get_id()<<" i:"<<i<<endl;
			}
		});
	thread * t2=new thread([&](){
		while(i>0){
			i--;
			sleep(1);
			cout<<"threadID:"<<this_thread::get_id()<<" i:"<<i<<endl;
			}
		});
	while(i>0){
		i--;
		sleep(1);
		cout<<"threadID:"<<this_thread::get_id()<<" i "<<i<<endl;
	}
	return 0;
}

