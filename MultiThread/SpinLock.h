#include <atomic>
using namespace std;
class spinLock{
private:
	atomic_bool flag=ATOMIC_VAR_INIT(false);
public:
	spinLock()=default;
	spinLock(const spinLock& )=delete;
	spinLock & operator=(const spinLock& )=delete;
	void lock(){
		bool expected=false;
		while(!flag.compare_exchange_strong(expected, true)){
			expected=false;
		}
	}
	void unlock(){
		flag.store(false);
	}
};

