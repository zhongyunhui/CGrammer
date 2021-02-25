#ifndef Thread_H
#define Thread_H
#include <pthread.h>
#include <functional>

#include "Noncopyable.h"
namespace wd{
class Thread:Noncopyable{
private:
	pthread_t _pthid;
	bool _isRunning;
	
	static void * threadFunc(void *arg);

public:
	using ThreadCallback=std::function<void()>;
	Thread(ThreadCallback &&cb):_pthid(0), _isRunning(false), _cb(std::move(cb)){}
	~Thread();
	void start();
	void join();
	bool isRunning() const{
		return _isRunning;
	}
private:
	ThreadCallback _cb;
};

}
#endif
