#include<iostream>
#include<cstdarg>
#include<memory>
using namespace std;

class Investment{
	private:
		int x,y;
	public:
		Investment(int a):x(a){};
		virtual int getX(){
			return x;
		}
		virtual ~Investment(){
			cout<<"delete by Investment"<<endl;
		}
};

class Stock:public Investment{
	public:
		Stock(int a):Investment(a){
			cout<<"Construct stock"<<endl;
		}
		virtual int getX(){
			Investment::getX();
		}       
};
//lambda
auto delInvmt = [](Investment* pInvest) {
	printf("delete by delInvmt\n");
	delete pInvest;
};


template<typename Ts>
unique_ptr<Investment>
makeInvestment(Ts params) {
	return unique_ptr<Investment>(move(params));
}

template<typename Ts,typename Td>
unique_ptr<Investment,decltype(delInvmt)>
makeInvestment(Ts params,Td dele){
	return unique_ptr<Investment,decltype(delInvmt)>(params,dele);
}

void UniqueTest(){
	auto pInvestment=makeInvestment(new Stock(3),delInvmt);
	cout<<pInvestment->getX()<<endl;
}

void Consume(Investment&& invest) {
    auto my_inv = move(invest);
    cout << my_inv.getX() <<endl;
}

void moveTest() {
    Investment m1(3), m2(4);
    Consume(move(m1));
    //Consume(m2);
}

int main(){
	//UniqueTest();
	moveTest();
	
	return 0;
} 
