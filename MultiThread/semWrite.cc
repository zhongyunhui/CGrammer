#include <iostream>
#include <semaphore.h>
#include <thread>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
using namespace std;
#define BUF_SIZE 100

void readfile(sem_t *psem1,sem_t *psem2){
	FILE *fp;
	char buf[BUF_SIZE];
	int str_len, str_seek=0;
	while(1){
		sem_wait(psem1);
		fp=fopen("data.txt","r+");
		if(fp==NULL)return ;
		memset(buf, 0, 100);
		fseek(fp,str_seek,SEEK_SET);
		str_len=fread(buf, sizeof(char),BUF_SIZE-1,fp);
		buf[str_len]=0;
		str_seek+=str_len;
		fputs("output:",stdout);
		fputs(buf,stdout);
		fclose(fp);
		sem_post(psem2);
	}
}
void writefile(sem_t *psem1, sem_t *psem2){
	FILE *fp;
	char buf[BUF_SIZE];
	while(1){
		cout<<"before wait"<<endl;
		sem_wait(psem2);
		cout<<"after "<<endl;
		fp=fopen("data.txt","a");
		if(fp==NULL)return ;
		memset(buf,0,BUF_SIZE);
		fputs("Input:",stdout);
		fgets(buf,BUF_SIZE,stdin);
		fwrite(buf,sizeof(char),strlen(buf),fp);
		fclose(fp);
		sem_post(psem1);
	}
}
			
int main(){
	int pid;
	int fd1,fd2;
	sem_t *psem1, *psem2;
	/*
	fd1=open("data1",O_CREAT|O_RDWR|O_TRUNC, 0666);
	fd2=open("data2",O_CREAT|O_RDWR|O_TRUNC, 0666);
	ftruncate(fd1, 8192);
	ftruncate(fd2,8196);
	*/
	//mmap参数 void* start(通常为NULL),size_t length, 
	//int prot: PROT_EXEC|PROT_READ|PROT_WRITE|PROT_NONE(不能存取)
	//int flags:MAP_SHARED写入数据复制到文件中 | MAP_PRIVATE修改不会写回原来的文件 | MAP_DENYWRITE只允许对映射区间写入，对文件写入被拒绝 |MAP_LOCKED 不会被置换
	//int fd,文件描述符，如果使用匿名映射（MAP_ANONYMOUS)，fd设为-1
	//offset,文件映射偏移量，通常为1，必须是分页大小的整数倍

	//psem1=(sem_t*)mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
	//psem2=(sem_t*)mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
	psem1=sem_open("data1",O_CREAT|O_RDWR,0666,0);
	psem2=sem_open("data2",O_CREAT|O_RDWR,0666,1);
	if(psem2==SEM_FAILED || psem1==SEM_FAILED){
		cout<<"sem2 error"<<endl;
		return -1;
	}
	//sem_init(psem1,1,0);
	//sem_init(psem2,1,1);
	writefile(psem1,psem2);	
	//sem_destroy(psem1);
	//sem_destroy(psem2);
	//munmap(psem1,sizeof(sem_t));
	//munmap(psem2,sizeof(sem_t));
	close(fd1);
	close(fd2);
	sem_close(psem1);
	sem_close(psem2);
	sem_unlink("data1");
	sem_unlink("data2");
	return 0;
}

