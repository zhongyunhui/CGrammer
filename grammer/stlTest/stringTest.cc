#include <cstdio>
#include <string>
#include <iostream>
#include <signal.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
using namespace std;

#define PAGE_SHIFT 12
#define PAGE_SIZE   (1UL << PAGE_SHIFT)
#define PAGE_MASK   (~(PAGE_SIZE-1))


int main(){
	char str1[]="hello";
	char str2[]="hello";
	char *str3="hello";
	char *str4="hello";
	if(str1!=str2){
		std::cout<<"字符串数组有各自的空间"<<std::endl;
	}
	if(str3==str4){
		printf("addr: %zu",(size_t)str3);
		std::cout<<"两个指针指向相同的字符串常量"<<std::endl;
	}
	//segment fault，常量区无法修改
	//str4[1]='f';
	struct sigaction sa;
	sa.sa_flags=SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	size_t sysMemPageSize=sysconf(_SC_PAGESIZE);
	printf("pagesize: %zu\n",sysMemPageSize);
	//size_t tempaddr=str3;//&~PAGE_MASK;
	std::string a="abcde";
	std::string b=a;
	printf("a address:%x\n",a.c_str());
	printf("b address:%x\n",b.c_str());
	b[1]='f';
	printf("a address:%x\n",a.c_str());
	printf("b address:%x\n",b.c_str());
}
