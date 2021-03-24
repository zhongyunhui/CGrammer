#include <iostream>
using namespace std;

class BaseClass
{
public:
BaseClass()
{
cout<<"BaseClass"<<endl;
}
virtual ~BaseClass()
{
cout<<"~BaseClass"<<endl;
}
virtual void test() const
{
cout<<"BaseClass test"<<endl;
}
int x;
};
class DerivedClass :public BaseClass
{
public:
DerivedClass()
{
cout<<"DerivedClass"<<endl;
}
~DerivedClass()
{
cout<<"~DerivedClass"<<endl;
}
void test()const override
{
cout<<"DerivedClass test"<<endl;
}
int y;
int z;
};
void show(const DerivedClass bcArray[],int len)
{
for(int i = 0 ; i < len ; i++)
{
bcArray[i].test();
}
}
int main()
{
DerivedClass data[10];
show(data,10);
return 0;
}
