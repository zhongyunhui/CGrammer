#include "Thread.h"
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <memory>
using namespace std;
using namespace wd;
class Foo{
public:
	void threadFunc()
	{
		::srand(::clock());
		int cnt=10;
		while(cnt--){
			int num=::rand()%10;
			cout<<"subThread "<<pthread_self()<<" number:" <<num<<endl;
			::sleep(1);
		}
	}
	~Foo(){
		cout<<"~Foo()"<<endl;
	}
};
void Execute(){
	srand(::clock());
	int cnt = 10;
	while(cnt--) {
		int number = ::rand() % 100;
		cout << ">>> subThread " << pthread_self()
			 << ":  number = " << number << endl;
		::sleep(1);
	}
}

int main(){
	cout<<"mainThread: "<<pthread_self()<<endl;
	unique_ptr<Thread> pthread(new Thread(
					bind(&Foo::threadFunc,Foo())
					//Execute
					)
				);
	pthread->start();
	pthread->join();
	return 0;
}
