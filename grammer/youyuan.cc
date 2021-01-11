#include "people.h"
#include <iostream>

int askAge(People person){
	return person.age;
}

int main(){
	People person(3);
	std::cout<<"askAge: "<<askAge(person)<<std::endl;
	People nperson;
	std::cout<<"askAge: "<<askAge(nperson)<<std::endl;
}
