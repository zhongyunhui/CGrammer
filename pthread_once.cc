#include <pthread.h>
#include <iostream>
using namespace std;

void JustOnce(){
	static int cnt=0;
	cout<<"Hello, this is"<<cnt++<<endl;
}
pthread_once_t tonce=PTHREAD_ONCE_INIT;
void *help(void *arg){
	//pthread_once_t tonce;
	pthread_once(&tonce,JustOnce);
	return nullptr;
}

int main(){
	pthread_once(&tonce,JustOnce);
	JustOnce();
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, 1);
	int err=pthread_create(&thread, NULL,help, NULL);
	pthread_join(thread,NULL);
	return 0;
}

