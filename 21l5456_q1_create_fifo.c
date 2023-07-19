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


mkfifo ("fifo_pipe",0777);


 
return 0;
}
