#include "Threadpool.h"
#include "WorkerThread.h"
#include <unistd.h>
#include <iostream>
using namespace wd;

Threadpool::Threadpool(size_t threadNum, size_t queSize):
	_threadNum(threadNum), _queSize(queSize), _que(queSize), _isExit(false)
{
	_threads.reserve(threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit){
		stop();
	}
}

void Threadpool::addTask(Task *pTask)
{
	_que.push(pTask);
}

void Threadpool::start()
{
	for(size_t idx=0;idx!=_threadNum;idx++){//初始化_threads,讲WorkerThread作为工作线程
		unique_ptr<Thread>up(new WorkerThread(*this));
		_threads.push_back(std::move(up));
	}
	for(auto &thread:_threads){ //将每个线程启动
		thread->start();
	}
}

void Threadpool::stop()
{
	if(!_isExit){
		//任务没执行完不退出
		while(!_que.empty()){sleep(1);}
		_isExit=true;
		for(auto &thread:_threads){
			thread->join();
		}
	}
}

Task* Threadpool::getTask(){
	return _que.pop();
}

void Threadpool::threadFunc() //WorkderThread::run运行的函数,主线程，判断是否有任务
{
	while(!_isExit){
		Task* ptask=getTask();
		if(ptask){
			ptask->process();
		}
	}
}
	
	
