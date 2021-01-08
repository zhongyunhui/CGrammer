#include "widget.h"
#include "gadget.h"
#include "people.h"
struct Widget::Impl{
	std::string name;
	std::vector<double> data;
	Gadget g1, g2, g3;
};
//实现构造函数
Widget::Widget():pImpl(std::make_unique<Impl>()){}
//实现析构函数
Widget::~Widget(){
}
Widget::Widget(Widget &rhs):pImpl(std::make_unique<Impl>(*rhs.getImpl())){}

Widget& Widget::operator=(const Widget &rhs){
	//修改pImpl的指向的值
	*pImpl=(*(const_cast<Widget&>(rhs).getImpl()));
	return *this;
}


int main(){
	Widget widget;
	Widget widget2=widget;
	std::cout<<"pos1:"<<widget.getImpl()<<std::endl;
	Widget widget3(std::move(widget));
	std::cout<<" age is: "<<widget2.getImpl()->g1.age<<std::endl; 
	std::cout<<" pos2: "<<widget2.getImpl()<<" pos3 "<<widget3.getImpl()<<std::endl;
		
	People *people=new People(3);
	std::unique_ptr<People> mp=std::make_unique<People>(*people);
}
		

