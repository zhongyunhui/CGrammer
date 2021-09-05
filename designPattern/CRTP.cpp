#include <iostream>
using namespace std;

 // CRTP是静态多态实现，效率比虚函数更高 

template <typename Child>
class Base {
public:
	Base() : _i(0){}
	
	void f(int i) {
		//强转为子类，调用子类的函数 直接调用f函数相当于f()是纯虚函数 
		//derived()->f(i);
		// 子类实现了则调用子类f_impl,否则调用父类f_impl; 
		derived()->f_impl(i); 
	}
	void f_impl(int i) {
		_i += i;
	} 
	int get() const {return _i;}
	~Base() {
		cout << "析构Base" <<endl; 
	}
protected:
	int _i;
private:
	// 调用f(int)方法前该方法不会被编译，调用该方法后，D类已声明完成类型完整 
	Child* derived() {
		return static_cast<Child*>(this);
	}
};

class Child1 : public Base<Child1> {
public:
	void f(int i) {
		_i += i;
	}
//	void f_impl(int i) {
//		_i += i * 2;
//	}
	~Child1() {
		cout << "析构child" <<endl;
	}
};
 // 编译器未知类型的函数 
template <typename Child>
void apply(Base<Child>* b, int& i) {
	b->f(++i);
} 

 // 析构需要专门编写方法
template <typename Child>
void destroy(Base<Child>* b) {
	delete static_cast<Child*>(b);
}

template <typename D>
class registry {
public:
	static size_t count;
	static D* head; // 将泛型类型作为成员变量，所有类对象共享该类 
	D* prev;
	D* next;

protected:
	registry() {
		++count;
		prev = nullptr;
		next = head;
		head = static_cast<D*> (this);
		if (next) next->prev = head;
	}
	
	registry(const registry&) {
		++count;
		prev = nullptr;
		next = head;
		head = static_cast<D*> (this);
		if (next) next->prev = head;
	}
	
	~registry() {
		--count;
		if (prev) prev->next = next;
		if (next) next->prev = prev;
		if (head == this) head = next;
	}
};

template <typename D>
size_t registry<D>::count(0);
template <typename D>
D* registry<D>::head(nullptr);
 
class testRig : public registry<testRig> {
public:
	testRig(int i) : _i(i) {}
	friend std::ostream& operator << (std::ostream& out,
	const testRig& t) {
		out << c._i;
		return out;	
	}
private:
	int _i;
};

int main() {
	Base<Child1> * c1 = new Child1();
	c1->f(3);
	int c = 3;
	//apply(c1, c);
	cout << "_i is " << c1->get() << endl;
	//delete c1; //只能直接调用父类的析构 
	destroy(c1);
	return 0;
	
}
