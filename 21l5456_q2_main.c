#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc,char *argv[])
{

 int pipefd[2] 
 int p = pipe(pipefd);
 int pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid > 0) 
    {
        printf("\nParent ID: %d" , getpid());
        
        
        close(pipefd[0]);  // read end of 1st pipe
       // close(pipefd2[1]);  // write end of 2nd pipe

        write(pipefd[1], argv[1], sizeof(argv[1]) + 1);
        close(pipefd[1]);

        wait(NULL);

        int sum = 0;

        printf("\nParent ID: %d" , getpid());

       // read (pipefd2[0], &sum, 4);

       // close(pipefd2[0]);

        printf("\nSum is: %d ", sum);

       

    }
    
    
    else
    {
         printf("\nChild ID: %d" , getpid());
        //int arr[5] = {0};
        close(pipefd[1]);
        //close(pipefd2[0]);

        read(pipefd[0], argv[1] , sizeof(argv[1]) + 1);
        close(pipefd[0]);

        int sum = 0;

        for(int i = 0; i < 5; i++)
        {
            sum += arr[i];
        }

        //write(pipefd2[1], &sum, 4);
        close(pipefd[1]);

    }
