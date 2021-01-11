#ifndef _Mutex_h_
#define _Mutex_h_
#include <pthread.h>
namespace wd{
	class MutexLock{
	public:
		MutexLock();
		~MutexLock();
		MutexLock(const MutexLock&)=delete;
		MutexLock& operator=(const MutexLock &)=delete;
		void lock();
		void unlock();
		pthread_mutex_t *getMutexLock(){
			return &_mutex;
		}
	private:
		pthread_mutex_t _mutex;
	};
	class MutexGuard{
	public:
		MutexGuard(MutexLock &mutex):_mutex(mutex){
			_mutex.lock();
		}
		~MutexGuard(){
			_mutex.unlock();
		}
	private:
		MutexLock& _mutex;
	};	
}

#endif
