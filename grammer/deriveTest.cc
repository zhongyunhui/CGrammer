#include "point.h"
using namespace std;

class line{
private:
	point *_p1, *_p2;
	const int cx;
public:
	line(point *p1,point *p2,int x):cx(x){
		_p1=p1;
		_p2=p2;
	}
	double kvalue(){
		if(_p1->GetX()==_p2->GetX())return 0;
		else return (_p1->GetY()-_p2->GetY())/(_p1->GetX()-_p2->GetX());
	}
	int getCx(){
		return cx;
	}
};

int main(){
	point * p1=new point(1,2);
	point3D * p2=new point3D(1,2,3);
	//line mline=line(p1,p2,3);
	//cout<<"k=: "<<mline.kvalue()<<endl;
	//cout<<"const test:"<<mline.getCx()<<endl;

//	point3D *p1=new point3D(1,2,3);
	p1=p2;
	p1->disp();
	point p3(*p2);
	p3.disp();
}


