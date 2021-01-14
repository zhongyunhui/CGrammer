#include <iostream>
#include <deque>

#include "../people.h"
using namespace std;

int main(){
	char * test=(new char[5]()+4);
	*reinterpret_cast<int*>(test-4)=5;
	test="hello \0";
	printf("%d %s",*reinterpret_cast<int*>(test-4),test);
	deque<int> dtest(10,1);
	dtest.push_back(9);
	int f=dtest.front();
	int b=dtest.back();
	auto e=dtest.begin();
	dtest.insert(e,3,2);
	dtest.erase(e=dtest.begin());
	for(auto pa=dtest.begin();pa!=dtest.end();pa++){
		cout<<" "<<*pa;
	}
	cout<<"f:"<<f<<" b:"<<b<<endl;
	allocator<People> allocTest;
	People * pte=allocTest.allocate(10);//分配未构造内存保存T类型的n个对象

}		


