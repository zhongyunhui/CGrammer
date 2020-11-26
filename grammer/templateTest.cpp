#include<cstdio>
#include<type_traits>
#include<iostream>
#include<functional>
#include<memory>
#include <type_traits>
#include<vector>

template <typename T,typename R>
R TSwap(T &a,T &b){
	T t=a;
	a=b;
	b=t;
	return a+b;
}

template<class T>
class TD{
	public:
		T key;
		TD(T x){
			key=x;
		};
};
class Widge{
	public:
		Widge(int key,int key2){
			this->key=key;
		}
		Widge(int key){
			this->key=key;
		}
		Widge(std::initializer_list<std::string>il){//参数为long bool string，构造传输参数为大括号时，
			//分别会对应三种情况，long则调用此构造方法，bool则报错，string则调用第一个方法。
			auto it=il.begin();
			//flag=*it;
		}
		int getKey(){
			return key;
		}
	private:
		int key{0};
		bool flag;
};
template<typename T>
void f(const T& param){
	using namespace std;
	cout<<"T=    "<<typeid(T).name()<<endl;
	cout<<"Param="<<typeid(T).name()<<endl;
}

std::function<void(int)>funTest;


void tuidaoTest(int a){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	for(auto i:arr){
		printf("%d ",arr[i]);
	}
	printf("zyh: %d",a);
	int x;
	double y;
	TD<decltype(x) >xType(1);
	TD<decltype(y) >yType(1);
	printf("xType =%d\n yType",xType.key);
}

void dakuohaoTest(){
	Widge w{1,2};
	printf("{}%d \n",w.getKey());
	Widge w2(1,2);
	printf("()%d \n",w2.getKey());
}


using uptrVector =std::unique_ptr<std::vector<int> >;

//std::remove_const<const int>::type Tint

void remove_add_test(){
	const int x=0;
	using Tint=std::remove_const<const int>::type;
	//Tint tempi=0;
	Tint tempi=0;
	printf("remove_const %d\n",tempi);
}


int main(){
	int a=2;
	int b=3;
	int x=a&b;
	int *Pa=nullptr;
	remove_add_test();
	uptrVector newVector;
	newVector->push_back(1);
	//printf("vector %d \n",(*newVector)[0]);
	dakuohaoTest();
	auto Test=tuidaoTest;
	Test(3);
	Widge tempWidge(1);
	f(tempWidge);
	//tuidaoTest();
	printf("x=%d\n address=%zu",x,reinterpret_cast<size_t>(&x));
	//int c=TSwap<int,int>(a,b);
	//printf("a=%d  add=%d\n",a,c);
	//TSwap(a,b);
	//printf("a=%d\n",a);
	return 0;
}
