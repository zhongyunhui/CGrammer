#include <iostream>
using namespace std;

 // �������������ʹ�ýṹ����Ϊ����
 
 // ��������ʹ��
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




