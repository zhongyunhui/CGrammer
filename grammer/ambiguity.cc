#include <iostream>
using namespace std;
/* 多基派生导致普通的成员函数和虚函数的二义性问题*/

class A		//公共虚基类A
{
protected:		//protected成员列表
	int x;

public:
	A(int xp = 0)	//构造函数，带缺省构造参数
	{
		x=xp;
	}

	void SetX(int xp)        //SetX函数用以设置protected成员x
	{
		x = xp;
	}

	void print()	//print函数输出信息
	{
		cout << "this is x in A: " << x << endl;
	}
	virtual void a(){
		cout<<"a() in A"<<endl;
	}
	virtual void b(){
		cout<<"b() in A"<<endl;
	}
	virtual void c(){
		cout<<"c() in A"<<endl;
	}
};

class B:virtual  public A	//B由A虚基派生而来
{
};

class C:virtual  public A	//C由A虚基派生而来
{
};

class D:public B,public C	//D由B和C共同派生
{
};

class E{
public:
	virtual void a(){
		cout<<"a() in E"<<endl;
	}
	virtual void b(){
		cout<<"b() in E"<<endl;
	}
	void c(){
		cout<<"c() in E"<<endl;
	}
};

class F:public A, public E{
public:
	void a(){
		cout<<"a() in F"<<endl;
	}
	/*void b(){    //不实现b，则会默认调用基类的虚函数，导致二义性问题
		cout<<"b() in F"<<endl;
	}*/
	void c(){
		cout<<"c() in F"<<endl;
	}
};


int main()
{
	/*
	D d;		//声明一个D类对象exD

	d.SetX(5);		//SetX函数，因为virtual派生，在D中只有一个版本，不会二义
	d.print();		//print函数，因为virtual派生，在D中只有一个版本，不会二义

	d.A::print();	//还可用类名显式说明调用函数的版本
	d.B::print();
	d.C::print();   */
	F f;
	//f.b();
	cout<<" 二义性问题"<<endl;
	A* a=new F();
	a->b();//由于F未实现b，则使用静态联编，调用指针类型对应的方法 b() in A
	a->c();//c在A中是虚函数，在E中是普通函数，在F中重定义，输出取决于指针类型,则A中虚函数在F中重写了，则输入c() in F
	E* e=new F();
	e->c();//输出c() in E


	return 0;
}

