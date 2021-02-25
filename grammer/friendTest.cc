#include "people.h"
#include <iostream>

int askAge(People person){
	return person.age;
}
class friendTool{
public:
	static int getPeopleage(People person){
		return person.age;
	}
	static int getpage(){
		return 0;
	}
};


int main(){
	People person(3);
	std::cout<<"askAge: "<<askAge(person)<<std::endl;
	std::cout<<"friend class test: "<<friendTool::getPeopleage(person)<<std::endl;
	People nperson(5);//构造函数隐式转换,加上explicit可以关闭隐式转换
	int ageTran=nperson;
	//std::cout<<"nperson askAge: "<<ageTran<<std::endl;
	std::cout<<nperson;
}
