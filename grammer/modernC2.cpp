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

int main(){
	auto color1=Color::white;
	int int1=static_cast<int>(color1);
	std::cout<<int1;
	UserInfo uInfo=std::make_tuple("wang","123",12);
	printf("zyh:test1");
	auto val=std::get<toUType(UserInfoFields::uiname)>(uInfo);
	std::cout<<val<<std::endl;
}

