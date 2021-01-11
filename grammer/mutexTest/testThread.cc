#include "MutexLock.h"
#include "Condition.h"
#include "iostream"
#include <pthread.h>

using namespace wd;

int gNumber=0;
MutexLock mutex;
Condition cond(mutex);
bool flag=true;

void *func1(void *args){
	int cnt=10;
	while(cnt--){
		//MutexGuard autolock(mutex);
		mutex.lock();
		if(flag==false){
			cond.wait();
		}
		++gNumber;
		std::cout<<"thread1:"<<pthread_self()<<" gNumber:"<<gNumber<<std::endl;
		flag=false;
		cond.notify();
		mutex.unlock();
	}
	return NULL;
}
void *func2(void *args){
	int cnt=10;
	while(cnt--){
		//MutexGuard autolock(mutex);
		mutex.lock();
		if(flag==true){
			cond.wait();
		}
		++gNumber;
		std::cout<<"thread2:"<<pthread_self()<<" gNumber:"<<gNumber<<std::endl;
		flag=true;
		cond.notify();
		mutex.unlock();
	}
	return NULL;
}
int main(){
	pthread_t p1,p2;
	pthread_create(&p1,NULL,func1,NULL);
	pthread_create(&p2,NULL,func2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	return 0;
}

