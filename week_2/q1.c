#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    int x = 100;
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        printf("variable x in child: %d\n", x);
        x = 200;
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        printf("variable x in parent: %d\n", x);
        x = 300;
    }
    printf("variable x back in main after being modified: %d\n", x);
    return 0;
}

/* 
hello world (pid:3694)
hello, I am parent of 3695 (pid:3694)
variable x in parent: 100
variable x back in main after being modified: 300
hello, I am child (pid:3695)
variable x in child: 100
variable x back in main after being modified: 200
*/
