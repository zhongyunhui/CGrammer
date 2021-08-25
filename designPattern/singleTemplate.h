//作为单例模板时，子类需要将自己作为传递给Singleton<T>模板，同时需要将基类声明为友元类
#include <iostream>
using namespace std;

template<typename T>
class Singleton{
protected:
	Singleton()=default;
public:
	Singleton &operator=(const Singleton &)=delete;
	Singleton(const Singleton &)=delete;
	static T& getInstance(){
		static T instance;
		return instance;
	}
};
class DerivedSingle:public Singleton<DerivedSingle>{
	//定义父类为友元
	friend class Singleton<DerivedSingle>;
public:
	//不能继承的三大成员函数：
	//构造函数，析构函数，赋值运算符重载函
	DerivedSingle(const DerivedSingle &)=delete;
	DerivedSingle &operator=(DerivedSingle &)=delete;
private:
	DerivedSingle()=default;
};


