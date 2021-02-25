#include <iostream>
using namespace std;

class point		//point类定义
{
private:		//private成员列表，表示点的坐标信息
	int xPos;
	int yPos;
protected:
	int sPos;
public:
	point(int x = 0, int y = 0)	//构造函数，带缺省参数
	{
		xPos = x;
		yPos = y;
		cout<<"point constructor"<<endl;
	}
	point(const point &tmp){
		xPos=tmp.xPos;
		yPos=tmp.yPos;
		cout<<"point constructor by copy"<<endl;
	}
	
	void virtual disp()		//成员disp函数，用来输出点的信息
	{
		cout<<"point " << "( " << xPos << " , " << yPos << " )" << endl;
	}
	
	int GetX()		//读取private成员xPos
	{
		return xPos;
	}
	
	int GetY()		//读取private成员yPos
	{
		return yPos;
	}
};

class point3D : public point	//3维点类point3D，从point类继承而来，注意格式
{
private:
	int zPos;				//在point类基础上增加了zPos坐标信息

public:
	point3D(int x, int y, int z):point(x, y)//派生类构造函数， 初始化表中调用基类构造函数
	{
		zPos = z;
	}
	
	void disp()				//隐藏了基类的中的同名disp函数
	{
		cout<<"Point3D " << "( " << GetX() << " , " << GetY() << " , " << zPos << " )" << endl;
	}
	
	int calcSum()	//增添了计算3个数据成员和的函数
	{
		return GetX() + GetY() + zPos;
	}
	void display(){
		//私有成员只能被本类的成员函数访问，子类中自定义的函数无法访问。
		//protected成员则可以在子类中访问到。
		//cout<<"x= "<<xPos;
		cout<<"s= "<<sPos;
	}
};
/*
class privatePoint3D : private point    //3维点类point3D，从point类继承而来，注意格式
{
private:
    int zPos;    //在point类基础上增加了zPos坐标信息

protected:
	int spos;
public:
    point3D(int x, int y, int z):point(x, y)//派生类构造函数，                       初始化表中调用基类构造函数
    {
        zPos = z;
    }

    void disp()             //隐藏了基类的中的同名disp函数
    {
        cout << "( " << GetX() << " , " << GetY() << " , " << zPos << " )" << endl;      }

    int calcSum()   //增添了计算3个数据成员和的函数
    {
        return GetX() + GetY() + zPos;
    }
    void display(){
        //私有成员只能被本类的成员函数访问，子类中自定义的函数无法访问。
        //cout<<"x= "<<x<<"y= "<<y;
    }
};

class protectedPoint3D : protected point    //3维点类point3D，从point类继承而来，注意格式
{
private:
    int zPos;               //在point类基础上增加了zPos坐标信息

public:
    point3D(int x, int y, int z):point(x, y)//派生类构造函数，                       初始化表中调用基类构造函数
    {
        zPos = z;
    }

    void disp()             //隐藏了基类的中的同名disp函数
    {
        cout << "( " << GetX() << " , " << GetY() << " , " << zPos << " )" << endl;      }

    int calcSum()   //增添了计算3个数据成员和的函数
    {
        return GetX() + GetY() + zPos;
    }
    void display(){
        //私有成员只能被本类的成员函数访问，子类中自定义的函数无法访问。
        cout<<"x= "<<xPos;
		cout<<"s= "<<spos;
    }
};*/

