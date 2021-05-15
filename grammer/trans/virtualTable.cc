 ///
 /// @file    virtualTable.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-17 10:30:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double dbase)
	: _dbase(dbase)
	{}

	virtual void func1() {	cout << "Base::func1()" << endl;	}
	virtual void func2() {	cout << "Base::func2()" << endl;	}
	virtual void func3() {	cout << "Base::func3()" << endl;	}

	virtual
	~Base() {	cout << "~Base()" << endl;	}

private:
	long _dbase;
};

class Derived
: public Base
{
public:
	Derived(double dbase, double dderived)
	: Base(dbase)
	, _dderived(dderived)
	{	cout << "Derived(double,double)" << endl;}

	virtual void func2() {	cout << "Derived::func2()" << endl;	}
	virtual void func3() {	cout << "Derived::func3()" << endl;	}

	virtual 
	~Derived()
	{	cout << "~Derived()" << endl;	}
private:
	long _dderived;
};
 
int main(void)
{
	//64位系统下指针长度为8Byte
	cout << "sizeof(long) = " << sizeof(long) << endl;
	Derived d(1, 2);
	cout << endl;

	long ** pvtable = (long**)&d;

	typedef void (*Function)();

	for(int idx = 0; idx != 3; ++idx) {
		//证明虚表的存在
		Function f = (Function)pvtable[0][idx];
		f();
	}

	long d1 = (long)(pvtable[1]);
	long d2 = (long)pvtable[2];
	cout << "d1 = " << d1 << endl
		 << "d2 = " << d2 << endl;

	return 0;
}
