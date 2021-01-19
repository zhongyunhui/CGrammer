#include <stddef.h>
#include <malloc.h>
#include <iostream>
class friendTool;

class People{
	private:
		friend class friendTool;
		int age{0};
		friend int askAge(People person);
		friend std::ostream & operator <<(std::ostream &os, const People &rhs);
		friend bool operator >(const People &lhs,const People &rhs);
		friend bool operator <(const People &lhs,const People &rhs);
	public:
		int getage(){
			return age;
		}
		void setAge(int aa){
			age=aa;
		}
		People()=default;
		explicit People(int a):age(a){}
		operator int(){
			return age;
		}
};
std::ostream &operator <<(std::ostream &os, const People &rhs){
	os<<"this person age is"<<rhs.age<<std::endl;
	return os;
}
bool operator>(const People &lhs,const People &rhs){
	return lhs.age> rhs.age;
}
bool operator<(const People &lhs,const People &rhs){
	return lhs.age<rhs.age;
}


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

