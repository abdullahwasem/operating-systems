#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    
    while (n != 1) {
        printf("%d ", n);
        pid = fork();
        
        if (pid < 0) {
            fprintf(stderr, "Fork failed");
            return 1;
        }
        else if (pid == 0) { // child process
            close(fd[0]); // close read end of the pipe
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            write(fd[1], &n, sizeof(n)); // write the result to the parent
            exit(0);
        }
        else { // parent process
            close(fd[1]); // close write end of the pipe
            wait(NULL); // wait for child to finish
            
            int result;
            read(fd[0], &result, sizeof(result)); // read the result from the child
            n = result;
        }
    }
    
    printf("1\n");
    
    return 0;
}












//gcc -o collatz collatz.c
//./collatz 35