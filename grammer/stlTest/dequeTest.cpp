#include <iostream>
#include <deque>

#include "../people.h"
using namespace std;

void showDeque(deque<int> &t){
	for(auto pa=t.begin();pa!=t.end();pa++){
		cout<<" "<<*pa;
	}
	cout<<endl;
}

int main(){
	char * test=(new char[5]()+4);
	*reinterpret_cast<int*>(test-4)=5;
	test="hello \0";
	//printf("%d %s",*reinterpret_cast<int*>(test-4),test);
	deque<int>back{1,2,3,4};
	deque<int> dtest;
	dtest.push_back(9);
	dtest.assign(back.begin(),back.end());
	//cout<<"assign test: "<<endl;
	//showDeque(dtest);
	cout<<"push test: "<<endl;
	dtest.push_back(5);
	dtest.push_front(0);
	showDeque(dtest);
	//cout<<"pop test: "<<endl;
	dtest.pop_front();
	dtest.pop_back();
	//showDeque(dtest);
	dtest.insert(dtest.cbegin()+3,32);
	dtest.erase(dtest.begin()+3);
	showDeque(dtest);
	dtest.emplace_front(7);
	dtest.emplace_back(8);
	cout<<"emplace test: "<<endl;
	showDeque(dtest);
	allocator<People> allocTest;
	People * pte=allocTest.allocate(10);//分配未构造内存保存T类型的n个对象
	
}		


