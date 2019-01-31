#include <func.h>

void* pthreadfunc(void *p)
{
    sleep(5);
    printf("It's child thread\n");
    pthread_exit((void*)3);
}

int main()
{
    pthread_t threadid;
    int ret;
    ret=pthread_create(&threadid,NULL,pthreadfunc,NULL);
    if(ret!=0)
    {
        printf("pthread_create failed err code=%d\n",ret);
        return -1;
    }
    printf("It's main thread\n");
    long lret;
    pthread_cancel(threadid);
    pthread_join(threadid,(void**)&lret);
    printf("thread ret=%ld\n",lret);
    return 0;
}
