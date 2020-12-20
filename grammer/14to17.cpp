#include<iostream>
#include<array>
#include <windows.h> //windows下多线程 
#include<atomic>
#include<mutex>
#include<fstream>
using namespace std;


constexpr auto arraysize=10;  
array<int,arraysize>data2; 

class Point{
public:
	constexpr Point(double xval,double yval)noexcept:x(xval),y(yval){}
	constexpr double getX()const noexcept{
		
		return x;
	}
	constexpr double getY()const noexcept{
		return y;
	}
	void setX(double xval)noexcept{
		x=xval;
	}
	void setY(double yval)noexcept{
		y=yval;
	}
	
private:
	double x,y;
};
constexpr Point p1(9.4,2.3);
constexpr Point p2(1.0,2.3);//定义constexpr对象。
//使用constexpr函数初始化constexpr对象：
constexpr Point midPoint(const Point&p1,const Point&p2)noexcept{
	return{
		(p1.getX()+p2.getX())/2,(p1.getY()+p2.getY())/2
	};
} 
constexpr auto mid=midPoint(p1,p2);//设计了构造函数、访问器和非成员函数调用，依然可在只读内存中创建。 

void Throw(){ 
	throw 1;
}
void NoBlockThrow(){
	Throw();
}
void BlockThrow()noexcept{
	Throw();
}
void noexceptTest(){
	try{
		Throw();
	}catch(...){
		cout<<"Throw found"<<endl;
	}
	try{
		NoBlockThrow();
	}catch(...){
		cout<<"Throw is not blocked."<<endl;
	}
//	try{
//		BlockThrow();
//	}catch(...){
//		cout<<"Throw is not blocked."<<endl;
//	}
}
constexpr int getInt(){                                                                  
	return 10;
}
constexpr int getInt(int n){
	return n+10;
}
void constexprTest(){
	cout<<getInt()<<endl;
	cout<<getInt(2)<<endl;
} 
ofstream in;


class newPoint{
public:
	newPoint(int xv,int yv):x(xv),y(yv){
	}
	void readTest()const noexcept{
		readCount++;
		cout<<"readCount: "<<readCount<<endl;
	}
	void mutexTest()const noexcept{
		//lock_guard<mutex> guard(m);
		x++;y++;
		in<<"x= "<<x<<" y= "<<y<<endl;
	} 
private:
	mutable int x,y;
	mutable atomic<int> readCount;
	mutable mutex m;
	
}; 

newPoint mPoint(2,2);
void ConstAtomic(){
	mPoint.readTest();
} 
void ConstMutex(){
	mPoint.mutexTest();
}
#define hThread(i) hThread##i
int main(){
	in.open("com.txt",ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	for(int i=0;i<10;i++){
		//cout<<"thread NO:"<<i<<endl;
		HANDLE hThread(i) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConstMutex, NULL, 0, NULL);
		CloseHandle(hThread(i));
	}
    in.close();
	
	//constexprTest();
	return 0;
} 
