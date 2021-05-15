#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__

#include "Thread.h"
namespace wd{
class Threadpool;
class WorkerThread:public Thread
{
public:
	WorkerThread(Threadpool &tp);
	~WorkerThread();
private:
	void run()override;
	Threadpool & _threadpool;
};
}
#endif
