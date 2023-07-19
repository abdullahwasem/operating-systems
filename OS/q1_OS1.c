#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_ARG_COUNT];
    int should_run = 1;
    
    while (should_run) {
        printf("osh> ");
        fflush(stdout);

        fgets(input, MAX_INPUT_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            should_run = 0;
            continue;
        }

        // Tokenize the command into arguments
        char* token;
        int arg_count = 0;
        token = strtok(input, " \n");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " \n");
        }
        args[arg_count] = NULL;

        int background = 0;
        if (arg_count > 0 && strcmp(args[arg_count - 1], "&") == 0) {
            background = 1;
            args[arg_count - 1] = NULL;
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp failed");
            exit(1);
        } else if (pid > 0) {
            // Parent process
            if (!background) {
                waitpid(pid, NULL, 0);
            }
        } else {
            // Fork error
            perror("fork failed");
            exit(1);
        }
    }
    return 0;
}