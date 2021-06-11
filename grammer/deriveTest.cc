#include "point.h"
#include <memory>
#include <thread>

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

class Fruit{
public:
	virtual void show(){
		cout<<"this is Fruit"<<endl;
	}
};

class Apple:public Fruit{
public:
	void show(){
		cout<<"this is Apple"<<endl;
	}
};

void showTest(Fruit &f){
	f.show();
}
#include <unistd.h>
int main(){
	Fruit *f=new Apple();
	//showTest(*f);
	auto lamb=[&](Fruit * f){
		cout<<"delete fruit"<<endl;
		cout<<this_thread::get_id()<<endl;
		delete f;
	};
	shared_ptr<Fruit> sp(new Apple,lamb);
	sp->show();
	thread * t1=new thread(
		[=](){
		cout<<"this is subThread id"<<this_thread::get_id()<<endl;
		sp->show();
		//sp.reset(new Fruit, lamb);
		cout<<"use cont "<<sp.use_count()<<endl;
		});
	t1->detach();
	sleep(3);
	cout<<"main thread id"<<this_thread::get_id()<<endl;
	//t1->join();
	/*point * p1=new point(1,2);
	point3D * p2=new point3D(1,2,3);
	//line mline=line(p1,p2,3);
	//cout<<"k=: "<<mline.kvalue()<<endl;
	//cout<<"const test:"<<mline.getCx()<<endl;

//	point3D *p1=new point3D(1,2,3);
	p1=p2;
	p1->disp();
	point p3(*p2);
	p3.disp();*/
}


