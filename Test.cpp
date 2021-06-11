#include<iostream>
#include<vector>

using namespace std;

class TestA{
	public:
		int a,b;
		TestA(int x,int y):a(x),b(y){}
	private:
		int c;
};
class TestB:public TestA{
public:
	int getC(){
		//return c;//private区域无法访问
	}
};
template <typename ArtType> std::vector<ArtType*>& TestMap();
template < >
vector<TestA*>& TestMap<TestA>(){
	cout<<"hello哇"<<endl;
}
#include <queue>
#include <algorithm>
#include <malloc.h>
void getPos(int ** p){
	*p=(int*)malloc(sizeof(int));
	**p=22;
}

int main(){
	int *p1=nullptr;
	getPos(&p1);
	cout<<*p1<<endl;
	int a=0x1234;
	char *p=(char*)&a;
	cout<<(int)*p<<endl;
	cout<<(int)*(++p)<<endl;


	return 0;
	vector<string> arr={"1","22","333","444","21","5"};
	auto cmp=[](string s1, string s2){
		return s1.size()>s2.size();//优先队列按照升序；
	};
	sort(arr.begin(),arr.end(),cmp);

	priority_queue<string, vector<string>, decltype(cmp)>que{cmp};
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
		que.push(arr[i]);
	}
	cout<<endl;
	while(!que.empty()){
		cout<<que.top()<<" ";
		que.pop();
	}


	//TestMap<TestA>().size();
}


