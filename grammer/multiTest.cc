#include <iostream>
#include <set>
using namespace std;

int main(){
	multiset<int>mset;
	mset.insert(1);
	mset.insert(2);
	mset.insert(1);
	auto head=mset.begin();
	for(int i=0;i<mset.size();i++,head++){
		auto it=head+i;
		cout<<*head<<" ";
	}
}

