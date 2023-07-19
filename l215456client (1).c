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
char*lmao;
char buffer[100];
int id;

//int fd=open(argv[1],O_RDONLY);
int n=read(fd,buffer,100);
printf("%d\n",n);
//buffer[n]='\0';
printf("%s\n",buffer);
//id=shmget(99999,1024,0666|IPC_CREAT);
if(id<0)
{
printf("SHM FAILED\n");
}
else
{
printf("SHM SUCCESSFUL");
}
//lmao=shmat(id,NULL,0);
if(lmao==NULL)
{
printf("SHMAT FAILED");
}
//strncpy(lmao,buffer,n);
//shmdt(lmao);
return 0;

}
