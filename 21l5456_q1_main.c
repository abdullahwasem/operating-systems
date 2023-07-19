#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>
#include<fcntl.h>
#include<wait.h>
int main()
{

     int file_desc = open("inp.c",O_RDONLY);
    char buffer[BUFSIZ];  
    dup2(file_desc, 0) ;  
      
    int siz=read(0,buffer,500);
    int fd=open("fifo_pipe" , O_RDWR);
    write(fd[1],buffer,siz*sizeof(buffer[0]));//for worker1 sending through fifo
    pid_t pid=fork();
    if(pid==0)
    {
    execlp("./worker1","./worker1",NULL);
    exit(1);
    }
    else if(pid>0)
    {
    
    wait(NULL);
    int fd=open("fifo_pipe" , O_RDWR);
    int fre;
    read(fd[0],fre,BUFSIZ);//reading , not sure if & is to be used
    printf("Frequency:%d" , fre);
    
    write(fd[1],buffer,siz*sizeof(buffer[0]));//for worker2 sending through fifo
    pid=fork();
    if(pid==0)
    {
    execlp("./worker2","./worker2",NULL);
    
    
    }
    else if(pid>0)
    {
    wait(NULL);
    int fd=open("fifo_pipe", O_RDWR);
    int output;
    read(fd[0],output,sizeof(int));
    printf("\nCount:%d" , output);
    read(fd[0],&output,sizeof(int));
    printf("\nAverage Word Count:%d",output);
    
    }
    
    }
 
return 0;
}
