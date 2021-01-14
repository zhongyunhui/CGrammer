#include <stddef.h>
#include <malloc.h>

class friendTool;

class People{
	private:
		friend class friendTool;
		int age{0};
		friend int askAge(People person);
	public:
		int getage(){
			return age;
		}
		People()=default;
		explicit People(int a):age(a){}
		operator int(){
			return age;
		}
};
//只能生成堆对象 在private中重载new运算符
class PeopleNo{
private:
	int age;
	static PeopleNo* Peonew;
	void* operator new(size_t size){
		Peonew=(PeopleNo*)malloc(size);
		Peonew->age=4;
		return Peonew;
	}
public:
	PeopleNo(int a):age(a){}
	int getAge(){
		return age;
	}
};
//只能生成栈对象 将析构函数定义到private区域 在public区域定义destroy()
class PeopleYes{
private:
	int age;
	~PeopleYes()=default;
public:
	PeopleYes(int a):age(a){}
};

