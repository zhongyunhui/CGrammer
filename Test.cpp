#include<iostream>
#include<vector>

using namespace std;

class TestA{
	public:
		int a,b;
		TestA(int x,int y):a(x),b(y){}
};
template <typename ArtType> std::vector<ArtType*>& TestMap();
template < >
vector<TestA*>& TestMap<TestA>(){
	cout<<"hello哇"<<endl;
}

int main(){
	TestMap<TestA>().size();
}


