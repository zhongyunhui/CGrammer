#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pred{
private:
	int _val;
public:
	Pred(int val):_val(val){}
	bool operator ()(int val){
		return val>_val;
	}
};

int main(){
	vector<int>arr{1,2,3,4,5,6,7};
	cout<<count_if(arr.begin(),arr.end(),Pred(3))<<endl;
	return 0;
}
