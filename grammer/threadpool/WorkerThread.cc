#include "WorkerThread.h"
#include "Threadpool.h"

using namespace wd;
WorkerThread::WorkerThread(Threadpool &tp):_threadpool(tp){}
WorkerThread::~WorkerThread(){cout<<"~WorkerThread"<<endl;}
void WorkerThread::run(){_threadpool.threadFunc();}

