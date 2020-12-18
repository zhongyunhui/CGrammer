#include <iostream>
#include <memory>
int main(int argc, char *argv[])
{
	std::unique_ptr<int>tptr(new int(3));
	std::cout<<"int:"<<*tptr<<std::endl;
    auto message = "Hello C++11";
    std::cout << message << std::endl;
    return 0;
}
