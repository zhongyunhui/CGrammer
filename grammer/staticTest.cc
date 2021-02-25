//使用static成员函数为包含private构造函数的类创建对象
#include <iostream>
using namespace std;

class Example	//类定义
{ 
private:
	int x;
	Example(int xp)	//类的构造函数定义为private型
	{
		x = xp;
	}

public:
	static Example* CreateObject(int xp)//static函数，不用创建对象便可调用
	{
		return new Example(xp);	//申请动态内存
	} 

	static void DeleteObject(Example* pE)//static函数，不用创建对象便可调用
	{
		delete pE;	//释放申请到的内存资源
	}

	void disp()	//成员函数
	{
		cout << "x is " << x << endl;
	}
};

int main()
{
//	Example e;	//错误, Example的构造函数是private类型, 不能访问
//	Example *pe = new Example();
//错误, Example的构造函数是private类型, 不能new
	Example *ppe = NULL;	//正确

	//使用类名访问static函数创建对象，返回指向动态内存的指针
	Example * pE = Example::CreateObject(5);

	//功能访问
	pE->disp();
	
	//释放资源
	Example::DeleteObject(pE);
	
	return 0;
}

