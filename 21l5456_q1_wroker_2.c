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

    
  char arr[BUFSIZ];
int fd=open("fifo_pipe" , O_RDWR);// using pipe , the same as before 
int siz=read(fd[0],arr,BUFSIZ);
int count=01;//always 1 word
int words=0;
int i=0;
 for(i=0;i<siz;i++)
 {
 if(arr[i]==' ' )
 count++;
 else
 words++;

 }
  words=words/count; //counting the avg length 
  
 
    dup2(fd, 1); //redirecting the file descriptor   
    write(1,&count,sizeof(int));//writing to fifo
    write(1,&words,sizeof(int));
    
    
return 0;
}
