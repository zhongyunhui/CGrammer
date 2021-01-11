#ifndef _CONDITION_H_
#define _CONDITION_H_

#include <pthread.h>
namespace wd{
	class MutexLock;//类的前向声明
	class Condition{
		public:
			Condition(MutexLock &mutex);
			~Condition();
			Condition(const Condition &)=delete;//复制构造函数删除
			Condition & operator=(const Condition &)=delete;//复制赋值运算符删除
			void wait();
			void notify();
			void notifyAll();
		private:
			pthread_cond_t _cond;
			MutexLock & _mutex;
	};
}
#endif
