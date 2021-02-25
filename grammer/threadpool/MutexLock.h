#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>
namespace wd
{
class MutexLock:Noncopyable
{
private:
	pthread_mutex_t _mutex;
	bool  isLocking;
public:
	MutexLock():isLocking(false)
	{	pthread_mutex_init(&_mutex,NULL); }
	~MutexLock()
	{   pthread_mutex_destroy(&_mutex);   }
	void lock()
	{
		pthread_mutex_lock(&_mutex);
		isLocking=true;
	}
	void unlock()
	{
		pthread_mutex_unlock(&_mutex);
		isLocking=false;
	}
	pthread_mutex_t *getMutexLock(){return &_mutex;}
};
class MutexLockGuard
{
private:
	MutexLock & _mutex;
public:
	MutexLockGuard(MutexLock& mutex):_mutex(mutex)
	{_mutex.lock();}
	~MutexLockGuard(){_mutex.unlock();}
};
}	
#endif
