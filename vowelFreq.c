#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void vowelFreq(char arr[])
{

    int cA , cE , cI, cO, cU , cC;

    for(int i = 0 ; arr[i] != '\0'; i++)
    {
        if(arr[i] == 'a' || arr[i] == 'A')
        {
            cA++;
        }
        else if(arr[i] == 'e' || arr[i] == 'E')
        {
            cE++;
        }
        else if(arr[i] == 'i' || arr[i] == 'I')
        {
            cI++;
        }
        else if(arr[i] == 'o' || arr[i] == 'O')
        {
            cO++;
        }
        else if(arr[i] == 'u' || arr[i] == 'U')
        {
            cU++;
        }
        else 
        { cU++ ;
        }
    }

    printf("A: %d\n", cA);
    printf("E: %d\n", cE);
    printf("I: %d\n", cI);
    printf("O: %d\n", cO);
    printf("U: %d\n", cU);
    printf("consonents: %d\n", cC);

    printf("ID: %d", getpid());
    printf("\n");

   
}


int main(int argc, char* argv[])
{
    int MyPipe[2];
    int p = pipe(MyPipe);

    int pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid > 0) // parents code
    {
        close(MyPipe[0]);

        char* str = argv[1];
        int l = strlen(str);

        write(MyPipe[1], str, l);

        close(MyPipe[1]);
    }
    else
    {
        close(MyPipe[1]);

        char buff[200];

        int r = read(MyPipe[0], buff, 200);

        close(MyPipe[0]);

        vowelFreq(buff);

        exit(0);
    }
}
 
