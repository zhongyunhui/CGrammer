#include "Threadpool.h"
#include <cstdlib>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
using namespace std;
using namespace wd;
class MyTask:public Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		int number=::rand()%100;
		cout<<"subThread: "<<pthread_self()<<" randam number: "<<number<<endl;
	}
};

int main(){
	Threadpool threadpool(4,10);//threadnum:4 queSize:10;
	threadpool.start();
	int cnt=20;
	unique_ptr<Task> task(new MyTask());
	while(cnt--){
		threadpool.addTask(task.get());
		::sleep(1);
	}
	threadpool.stop();
	return 0;
}

