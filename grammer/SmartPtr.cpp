#include<iostream>
#include<memory>
using namespace std;
class Task{
public:
	int mId;
	Task(int id){
		this->mId=id;
		cout<<"Constructor process"<<endl;
	}
	~Task(){
		cout<<"Destructor process"<<endl;
	}
};
void uniqueptrTest(){
	unique_ptr<Task> taskptr(new Task(23));
	unique_ptr<Task> staskptr;//=new Task(32)不可以
	staskptr=make_unique<Task>(32);//使用make_unique创建unique_ptr对象
	Task *mTask=staskptr.get();//可通过.get()获得管理对象的指针。
	cout<<mTask->mId<<endl;
	staskptr.reset();//释放关联的原始指针，将unique_ptr置为空
	cout<<mTask->mId<<endl;//打印0值，该块内存区域已经备置为空。
	mTask->mId=1;//依然可以访问
	cout<<mTask->mId<<endl;
	if(staskptr==nullptr){
		cout<<"get a nullptr"<<endl;
	}
	staskptr=move(taskptr);
	cout<<staskptr->mId<<endl;
	if(taskptr==nullptr){
		cout<<"move successful"<<endl;
	}
	mTask=staskptr.get();
	staskptr.release();//release只会释放所有权，不会delete原始指针,
	//reset会打印destroy,release不会调用析构函数。
	if(staskptr==nullptr){
		cout<<"release successful"<<endl;
		cout<<mTask->mId<<endl;
	}
}
int main(){
	uniqueptrTest();

	return 0;
}
