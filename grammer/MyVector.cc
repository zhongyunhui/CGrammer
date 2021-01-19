#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

template <typename T>
class Vector{
public:
	using iterator=T*;
	Vector():_start(0),_finish(0),_endOfStorage(0){}
	T* begin(){
		return _start;
	}
	T* end(){
		return _finish;
	}
	void push_back(const T &value);
	void pop_back();
	size_t size()const{
		return _finish-_start;
	}
	size_t capacity()const{
		return _endOfStorage-_start;
	}


private:
	void reallocate();//扩容
	
	static allocator<T> _alloc;
	T* _start;
	T* _finish;
	T* _endOfStorage;
};

//定义了内部_alloc 变量
template<typename T>
allocator<T> Vector<T>::_alloc;

template<typename T>
void Vector<T>::push_back(const T& value){
	if(size()==capacity())reallocate();
	_alloc.construct(_finish++,value);
}

template<typename T>
void Vector<T>::pop_back(){
	if(size()>0){
		_alloc.destroy(--_finish);
	}
}

template<typename T>
void Vector<T> ::reallocate(){
	size_t oldCapacity=capacity();
	size_t newCapacity=oldCapacity>0? oldCapacity*2:1;
	T* ptemp=_alloc.allocate(newCapacity);//分配新的内存空间
	if(size()>0){
		//保存到新的空间;
		uninitialized_copy(_start, _finish, ptemp);
		while(_start!=_finish)_alloc.destroy(--_finish);
		_alloc.deallocate(_start,oldCapacity);//释放内存
	}
	_start=ptemp;
	_finish=_start+oldCapacity;
	_endOfStorage=_start+newCapacity;
}

int main(){
	Vector<int>myvec;
	myvec.push_back(1);
	cout<<"begin:"<<*myvec.begin()<<endl;
}








