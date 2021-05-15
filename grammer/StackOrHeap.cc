#include <iostream>
using namespace std;
//只生成栈对象，不能使用new运算符
//1.将new函数放入private区域

class C{
private:
	void *operator new(size_t t){}
	void operator delete(void * ptr){}
public:
	C(){}
	~C(){}
};

//只能生成堆对象，
//1.将析构函数放入private区域：在public区域定义destroy()函数用来调用delete函数

class A{
public:
	A(){}
	void destroy(){
		delete this;
	}
private:
	~A(){}
};
//2.将构造函数声明为protected,提供public的静态函数完成构造；析构函数声明为protected;
//属于单利模式
class B{
protected:
	B(){}
	~B(){}
public:
	static B *create(){
		return new B();
	}
	void destroy(){
		delete this;
	}
};


