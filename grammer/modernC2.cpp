#include<iostream>
#include<tuple>

enum class Color{
	black,red,white
};

using UserInfo=std::tuple<std::string,std::string,std::size_t>;

enum class UserInfoFields{uiname,niEmail,uiReputation};

template<typename E>
constexpr std::underlying_type_t<E>
toUType(E enumerator) noexcept{
	return static_cast<std::underlying_type_t<E>>(enumerator);
}

template<typename T>
void processPointer(T *ptr){
	std::cout<<"DeleteTest:"<<*ptr<<std::endl;
}
template<>
void processPointer<int>(int*)=delete;

class deleteClass{
	public:
		int x;
		deleteClass(int key){
			x=key;
		}
};

void DeleteTest(){
	double dSo=10;
	double *dtemp=&dSo;
	processPointer<double>(dtemp);
	int iSo=10;
	int *itemp=&iSo;
	//processPointer<int>(itemp);
}

int main(){
	auto color1=Color::white;
	DeleteTest();
	int int1=static_cast<int>(color1);
	std::cout<<int1;
	UserInfo uInfo=std::make_tuple("wang","123",12);
	auto val=std::get<toUType(UserInfoFields::uiname)>(uInfo);
	//std::cout<<val<<std::endl;
}

