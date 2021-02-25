#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

using std::queue;
namespace wd
{
class Task;
using ElementType=Task *;
class TaskQueue
{
private:
	size_t _size;
	queue<ElementType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
public:
	TaskQueue(size_t);
	bool full()const;
	bool empty()const;
	void push(ElementType value);
	ElementType pop();
};
}
#endif
