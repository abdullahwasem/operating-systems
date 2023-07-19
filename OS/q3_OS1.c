#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            gettimeofday(&end, NULL);
            double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
            printf("Elapsed time: %.5f seconds\n", elapsed);
            return 0;
        } else {
            fprintf(stderr, "Command exited abnormally\n");
            return 1;
        }
    }
}
