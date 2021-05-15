#include "people.h"
#include <iostream>
class StaticPeople{
public:
	static int getAge(){return age;}
private:

	static int age;
};
int StaticPeople::age=1;
int main(){
	PeopleNo p1(1);
	People *p3=new People(5);
	std::cout<<StaticPeople::getAge();
	//PeopleNo *p2=new PeopleNo();
	//PeopleYes p4(4);
}
