#include<func.h>

void sigfunc(){
	time_t now;
	now=time(NULL);
	printf("%s\n",ctime(&now));
}

int main(){
	signal(SIGPROF,sigfunc);
	struct itimerval st;
	memset(&st,0,sizeof(st));
	st.it_interval.tv_sec=5;
	st.it_value.tv_sec=2;
	int ret=setitimer(ITIMER_PROF,&st,NULL);
	if(-1==ret){
		perror("setitimer");
		return -1;
	}
	sleep(5);
	while(1);
}
