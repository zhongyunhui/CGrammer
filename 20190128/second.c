#include<func.h>

void *thfunc(void *p){
	printf("it's child thread ");
	printf("%ld\n",(long)p);
	pthread_exit((void*)3);
}
int main(){
	pthread_t pthid;
	int ret=pthread_create(&pthid,NULL,thfunc,(void*)1);
	if(ret!=0){
		printf("pthread_creat fails");
		return -1;
	}
	long  lret;
	pthread_join(pthid,(void**)&lret);
	printf("it's main thread %ld\n",lret);
	return 0;
}	
