#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T, int ksize=10>
class stacktemp
{
private:
	int _top;
	T *_array;
public:
	stacktemp():_top(-1),_array(new T[ksize]){}//默认容量开为ksize
	~stacktemp(){ 
		delete []_array;
	}
	bool empty()const;
	bool full()const;
	void push(const T &t);
	void pop();
	T top();
};
template<typename T, int ksize>
bool stacktemp<T,ksize>::empty()const{
	return _top==-1;
}

template<typename T, int ksize>
bool stacktemp<T,ksize>::full()const{
	if(_top==ksize-1){
		return true;
	}
	return false;
}
template<typename T, int ksize>
void stacktemp<T,ksize>::push(const T &t){
	if(!full()){
		_array[++_top]=t;
	}
	else cout<<"stack is full"<<endl;
}
template<typename T, int ksize>
void stacktemp<T,ksize>::pop(){
	if(!empty()){
		 --_top;
	}
	else cout<<"stack is empty"<<endl;
}
template<typename T, int ksize>
T stacktemp<T,ksize>::top(){
	if(empty())return NULL;
	return _array[_top];
}

