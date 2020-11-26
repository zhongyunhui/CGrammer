#include"symTest.h"

int nums=0;

int insidefunc(int a){
	printf("inside,%d",a);
	return a+1;
}
void func(int a){
	printf("%d",a);
	a=insidefunc(nums);
}
