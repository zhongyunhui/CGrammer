#include <iostream>
using namespace std;

 // 多参数函数可以使用结构体作为传参
 
 // 方法链的使用
class City {
	struct DayEvents {
	private:
		friend City;
		bool flood;
		bool fire;
		DayEvents() : flood(false), fire(false) {}
		
		DayEvents& SetFlood() {
			flood = true;
			return *this;
		}
		
		DayEvents& SetFire() {
			fire = true;
			return *this;
		}
	};
	
	void day(DayEvents events);
}; 




