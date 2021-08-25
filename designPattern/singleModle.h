#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
/*
 * 全局只有一个实例，static特性，将构造函数设为private;
 * 线程安全
 * 禁止复制和拷贝
 * 通过static类成员函数获取
 */
using namespace std;
class Singleton{
private:
	static shared_ptr<Singleton> ptr;
	static mutex mut;
	Singleton()=default;
public:
	Singleton(Singleton &)=delete;
	Singleton& operator=(const Singleton &)=delete;
	static shared_ptr<Singleton> getSingle(){
		if(ptr==nullptr){
			lock_guard<mutex> lk(mut);
			//双检锁，只有判断指针为空时才加锁
			if(ptr==nullptr)ptr=shared_ptr<Singleton>(new Singleton());
		}
		return ptr;
	}
	/*最佳的方式
	 * 变量在初始化时，并发进入声明语句，并发线程会阻塞等待初始化完成
	static Singleton & getSingle(){
		static Singleton instance;
		return instance;
	}
	*/
};
//static变量需要在类外初始化
shared_ptr<Singleton> Singleton::ptr=nullptr;
mutex Singleton::mut;
