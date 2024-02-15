#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

#include "parallel.h"

int status;
int system(const char *command);

void parallel(char *cmd) {
    pid_t forking = fork();
    if (forking == 0) {
        system(cmd);
    }
}
