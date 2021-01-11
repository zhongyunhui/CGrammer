/*  g++ conCurrent.cpp -lpthread   */
#include <vector>
#include <iostream>
#include <future>
#include <thread>
#include <type_traits>

template<typename F,typename ... Ts>
inline
auto //std::future<typename std::result_of<F(Ts...)>::type>
reallyAsync(F&& f, Ts&&... params)
{
	return std::async(std::launch::async,std::forward<F>(f),std::forward<Ts>(params)...);
}

int func(int num){
	std::cout<<"this is func: "<<num<<std::endl;
	return 0;
}

constexpr auto tenMillion=10000000;
bool dowork(std::function<bool(int)>filter,int maxval=tenMillion){
	std::vector<int> goodvals;
	std::thread t([&filter,maxval,&goodvals]{
				for(auto i=0;i<=maxval;i++){
					if(filter(i)){
					goodvals.push_back(i);
					}
				}
				});
	auto nh=t.native_handle();//使用t的低值句柄设定t的优先级
	if(true){
		t.join();

		return true;
	}
	return false;
}

int main(){
	auto fut=reallyAsync(func,1);
	
	return 0;
}
