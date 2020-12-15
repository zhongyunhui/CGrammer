#include<iostream>
#include<memory>
using namespace std;
class Task{
public:
	int mId;
	Task(int id){
		this->mId=id;
		cout<<"Constructor process: "<<mId<<endl;
	}
	~Task(){
		cout<<"Destructor process: "<<mId<<endl;
	}
};
std::unique_ptr<Task> RTesk(){
	std::unique_ptr<Task>transTest(new Task(32));
	transTest.get();
	return transTest;
}

void ParameterTest(Task *mTask){
	cout<<"parameterTest"<<mTask->mId<<std::endl;
	mTask->mId=33;
}

void uniqueptrTest(){
	std::unique_ptr<Task>receiver(RTesk());
	std::cout<<"method Trans  "<<receiver->mId<<std::endl;
	ParameterTest(receiver.get());
	cout<<"after Trans"<<receiver->mId<<std::endl;
	unique_ptr<Task> taskptr(new Task(23));
	unique_ptr<Task> staskptr;//=new Task(32)不可以
	staskptr=make_unique<Task>(32);//使用make_unique创建unique_ptr对象
	Task *mTask=staskptr.get();//可通过.get()获得管理对象的指针。
	cout<<mTask->mId<<endl;
	staskptr.reset(mTask);
	staskptr.reset(new Task(11));//释放关联的原始指针，将unique_ptr置为空
	cout<<mTask->mId<<endl;//打印0值，该块内存区域已经备置为空。
	cout<<"reset test:"<<staskptr->mId<<endl;
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

void sharedptrTest(){
	//构造：
	shared_ptr<Task>p1(new Task(24));
	cout<<"构造："<<p1->mId<<endl;
	auto q=p1;//q(p1);
	auto r=new Task(26);
	q.reset(r);//可以将Task *强转为shared_ptr<Task>
	//r=make_shared<Task>(27);不可以将shared_ptr<Task>强转为Task*
	cout<<"countnum:"<<p1.use_count()<<endl;
	shared_ptr<Task>p2(new Task(34));
	//p2.reset(q.get());该行会导致重复释放内存报错
	p2.swap(p1);
	cout<<"p2 is"<<p2->mId<<"p1 is"<<p1->mId<<endl;
	cout<<"析构test:"<<"  "<<q.use_count()<<endl;
	auto p3=p2;
	cout<<p2.use_count()<<endl;
	p2.unique();
	shared_ptr<Task> sizeShare;
	cout<<p2.use_count()<<endl;
	cout<<"size of shared_ptr:"<<sizeof(p2)<<"   "<<sizeof(sizeShare)<<endl;
	unique_ptr<Task> sizeUnique;
	cout<<"size of unique_ptr"<<sizeof(sizeUnique)<<endl;
}

void make_pointer(){
	shared_ptr<Task> sp,tp;
	tp=make_shared<Task>(3);	
	sp.reset(new Task(2));
	unique_ptr<Task> up,qp;
	qp=make_unique<Task>(4);
	//up.reset(qp);
}
//https://blog.csdn.net/hp_cpp/article/details/103452196 指定删除器
template<typename T>
shared_ptr<T> make_shared_array(size_t size)
{
	return shared_ptr<T>( new T[size],default_delete <T[]>());	
}

void deleter(Task *x){
	cout<<"delete from deleter function"<<endl;
	delete x;
}

class Deleter{
	public:
	void operator()(Task *x){
		cout<<"delete from delete class"<<endl;
		delete x;
	}
};


void specifiedDeleter(){
	//shared_ptr<Task>p1(new Task(34),deleter);//使用普通函数
	//shared_ptr<Task>p2(new Task(35),Deleter());//使用仿函数
	shared_ptr<Task>p3(new Task(36),[](Task *x){
				cout<<"delete from lambda "<<endl;
				delete x;
				});

}

int main(){
	uniqueptrTest();
	//sharedptrTest();
	//make_pointer();
	//specifiedDeleter();
	return 0;
}
