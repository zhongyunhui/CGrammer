#include <iostream>
#include <string>
#include <vector>
#include <memory>
class Widget{
	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	public:
		Widget();
		~Widget();
		const Impl* getImpl(){
			return pImpl.get();
		}
		Widget(Widget &&rhs)=default;
		Widget &operator=(Widget&& rhs)=default;

		Widget(Widget &rhs);
		Widget & operator=(const Widget& rhs);
};
