#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int parentpid = getpid();
    int rc = fork();
	kill(parentpid, SIGTSTP);
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello from child\n");
        kill(parentpid, SIGCONT);
    } else {
        // parent goes down this path (original process)
        printf("goodbye from parent\n");
    }
    return 0;
}

