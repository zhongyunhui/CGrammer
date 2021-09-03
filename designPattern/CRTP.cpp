#include <iostream>
using namespace std;

template <typename Child>
class Base {
public:
	Base() : _i(0){}
	
	void f(int i) {
		//ǿתΪ���࣬��������ĺ��� ֱ�ӵ���f�����൱��f()�Ǵ��麯�� 
		//derived()->f(i);
		// ����ʵ�������������f_impl,������ø���f_impl; 
		derived()->f_impl(i); 
	}
	void f_impl(int i) {
		_i += i;
	} 
	int get() const {return _i;}
	~Base() {
		cout << "����Base" <<endl; 
	}
protected:
	int _i;
private:
	// ����f(int)����ǰ�÷������ᱻ���룬���ø÷�����D������������������� 
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
		cout << "����child" <<endl;
	}
};
 // ������δ֪���͵ĺ��� 
template <typename Child>
void apply(Base<Child>* b, int& i) {
	b->f(++i);
} 

 // ������Ҫר�ű�д����
template <typename Child>
void destroy(Base<Child>* b) {
	delete static_cast<Child*>(b);
}

int main() {
	Base<Child1> * c1 = new Child1();
	c1->f(3);
	int c = 3;
	//apply(c1, c);
	cout << "_i is " << c1->get() << endl;
	//delete c1; //ֻ��ֱ�ӵ��ø�������� 
	destroy(c1);
	return 0;
	
}
