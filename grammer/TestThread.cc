#include <thread>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <mutex>
using namespace std;

int b;
mutex Mutex;
void PrintTest(int x){
	Mutex.lock();
	b++;
	Mutex.unlock();
//	cout<<x<<endl;//<<" pid: "<<pthread_self()<<endl;
}

#define max_num 20000
int main(){
	thread arr[max_num];
	static int x;
	for(int i=0;i<max_num;i++){
		arr[i]=thread(PrintTest,x);
	}
	for(int i=0;i<max_num;i++){
		arr[i].join();
	}
	cout<<b<<endl;
	return 0;
}
	
