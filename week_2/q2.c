#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int fd = open("./q2.output", O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
		// child: redirect standard output to a file
		close(STDOUT_FILENO); 
		char text[] = "This is from the child\n";
		write(fd, text, sizeof(text));
    } else {
        // parent goes down this path (original process)
        close(STDOUT_FILENO); 
		char text[] = "This is from the parent\n";
		write(fd, text, sizeof(text));
    }
    return 0;
}

/*
This is from the parent
This is from the child
*/
