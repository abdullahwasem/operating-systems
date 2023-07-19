#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc,char*argv[])
{
//char*lmao;
char buffer[1024];
int id;

printf("%s\n",buffer);
//id=shmget(99999,1024,0);
if(id<0)
{
printf("SHM FAILED\n");
}
else
{
printf("SHM failsus");
}
//lmao=shmat(id,NULL,0);
if(lmao=NULL)
{
printf("SHMAT FAILED");
}
//strncpy(buffer,lmao,1024);
printf("data:%s\n",buffer);
int i=0;
int sum=0;
int val;
int count=0.00;
while(buffer[i]!='\0')
{
if(buffer[i]>='0' && buffer[i]<='9')
{
//val=(buffer[i])-48;
//sum=sum+val;
count++;
}
i++;
}
printf("sum=%d\n",sum);
//float av=sum;
av=av/count;
//printf("average=%f\n",av);
shmdt(lmao);
return 0;

}
