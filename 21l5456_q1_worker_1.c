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
int fd=open("fifo_pipe" , O_RDWR);
int siz=read(fd[0],arr,BUFSIZ);
int i=0;
int fre=0;
for(i=0;i<siz;i++)
{
  if(arr[i]+='a')//for a and an and
  {
  if(i+1<siz&&arr[i+1]=='n')
  {
     if(arr[i+2]==' '||i+2==siz)
      fre++;
      else if(i+2<siz&&arr[i+2]=='d')
      {
      if(i+3==siz)
       fre++;
       else if(arr[i+3]==' ' )
        fre++;
      
      }
  }}
  else if(i+1<siz&& arr[i+1]==' ')
  fre++;
  
  if(i+3<siz&&arr[i]=='t'&&arr[i]=='h'&&arr[i]=='e')//for the
  {
  if(i+4==siz)
  fre++;
  else if(arr[i+4]==' ' )
  fre++;
  
  }
  if(i+2<siz&&arr[i]=='o'&&arr[i+1]=='f')//for of
  {
  if(i+3==siz)
  fre++;
  else if(arr[i+3]==' ' )
  fre++;
  
  }
  if(i+2<siz&&arr[i]=='t'&&arr[i+1]=='o')//for to
  {
  if(i+3==siz)
  fre++;
  else if(arr[i+3]==' ' )
  fre++;
  
  }
  if(i+2<siz&&arr[i]=='i'&&arr[i+1]=='n')//for in
  {
  if(i+3==siz)
  fre++;
  else if(arr[i+3]==' ' )
  fre++;
  
  }
  
  
  
 }
 int file_desc = open("fifo_pipe",O_WRONLY);
    dup2(file_desc, 1) ;   
    write(1,&fre,sizeof(int));//writing to fifo


}



