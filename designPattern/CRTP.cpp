#include <iostream>
using namespace std;

 // CRTP�Ǿ�̬��̬ʵ�֣�Ч�ʱ��麯������ 

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

template <typename D>
class registry {
public:
	static size_t count;
	static D* head; // ������������Ϊ��Ա�������������������� 
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
	//delete c1; //ֻ��ֱ�ӵ��ø�������� 
	destroy(c1);
	return 0;
	
}
