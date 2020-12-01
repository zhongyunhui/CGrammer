#include<iostream>
#include<memory>
using namespace std;

class Investment{
	private:
		int x,y;
	public:
		Investment(int a):x(a){};
};

template<typename... Ts>
unique_ptr<Investment>
makeInvestment(Ts&&... params);
