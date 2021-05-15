#ifndef __WD_CONDTION_H__
#define __WD_CONDTION_H__
#include "Noncopyable.h"
#include "MutexLock.h"
#include <pthread.h>

namespace wd
{
class Condition:Noncopyable
{
private:
	pthread_cond_t _cond;
	MutexLock &_mutex;
public:
	Condition(MutexLock &mutex):_mutex(mutex)
	{pthread_cond_init(&_cond,NULL);}
	void wait(){pthread_cond_wait(&_cond,_mutex.getMutexLock());}

	void notify(){pthread_cond_signal(&_cond);}
	void notifyall(){pthread_cond_broadcast(&_cond);}
	~Condition(){pthread_cond_destroy(&_cond);}
};
}
#endif
