#include <c++/7/bits/c++config.h>
#include <iostream>
#include <functional>
using namespace std;
template<typename T, typename D=std::function<void(T*)>>
class UniquePointer{
public:
	UniquePointer(const UniquePointer &)=delete;
	UniquePointer &operator=(const UniquePointer &)=delete;
	UniquePointer(T *raw_p=nullptr,const std::function<void(T*)>&del=Deleter()):p(raw_p), deleter(del){}
	UniquePointer& operator=(UniquePointer &&)noexcept;//保留右值等于初始化
	T* get()const{return p;}
	T* release()noexcept{deleter(p);}
	~UniquePointer(){deleter(p);}
	void reset(T* ptr=nullptr)noexcept;
	void swap(UniquePointer<T>&);



private:
	T*p;
	std::function<void(T*)>deleter=D();
};
template<typename T, typename D=std::function<void(T*)>>//参数为T*
class SharedPointer{
private:
	size_t *use_c;
	T* p;
	std::function<void(T*)>deleter;
	void release();

public: 
	SharedPointer(T *ptr=nullptr,const std::function<void(T*)>&del=Deleter()):
		p(ptr),use_c(new size_t(ptr!=nullptr),deleter(del){}
	~SharedPointer(){release();}
	void reset(T* ptr=nullptr,const function<void(T*)>&del=Deleter());
	T *get()const {return *p;}
	T &operator *()const{return *p;}
	T *operator->()const{return p;}



