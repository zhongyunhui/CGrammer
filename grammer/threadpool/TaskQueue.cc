#include "TaskQueue.h"
using namespace wd;
TaskQueue::TaskQueue(size_t size):_size(size),_mutex(),_notFull(_mutex),\
									  _notEmpty(_mutex){}
bool TaskQueue::full()const{return _que.size()==_size;}
bool TaskQueue::empty()const {return _que.size()==0; }
//push方法运行在生产者线
void TaskQueue::push(ElementType value)
{
	MutexLockGuard autoLock(_mutex);
	while(full()){ _notFull.wait();}
	_que.push(value);
	_notEmpty.notify();
}
ElementType TaskQueue::pop()
{
	ElementType value;
	MutexLockGuard autoLock(_mutex);
	while(empty()){
		_notEmpty.wait();
	}
	value=_que.front();
	_que.pop();
	
	_notFull.notify();
	return value;
}
			
