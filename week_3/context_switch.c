#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    const unsigned long MICROSECONDS_IN_SECONDS = 1000000;
    const unsigned long iterations = 10000000;
    struct timeval st;
    struct timeval et;

    pipe(fd);

    int rc = fork();
    if (rc < 0) {
        perror("pipe");
	exit(1);
    } else if (rc == 0) {
        /* should I close here? */
	for (int i = 0; i < iterations; i++) {
            read(fd[0], NULL, 0);
            write(fd[1], NULL, 0);
	}
    } else {
        gettimeofday(&st, NULL);
	for (int i = 0; i < iterations; i++) {
	    write(fd[1], NULL, 0);
	    read(fd[0], NULL, 0);
	}
	gettimeofday(&et, NULL);
	unsigned long st_in_micros = st.tv_sec * MICROSECONDS_IN_SECONDS + st.tv_usec;
        unsigned long et_in_micros = et.tv_sec * MICROSECONDS_IN_SECONDS + et.tv_usec;
        float total_time_in_micros = et_in_micros - st_in_micros;
	float avg_time_in_micros = total_time_in_micros / iterations;
	printf("total time in microseconds: %f\n", total_time_in_micros);
	printf("avg time in microseconds: %.5f\n", avg_time_in_micros);
    }
    /* output:
     * total time in microseconds: 16364236.000000
     * avg time in microseconds: 1.63642 */

    return 0;
}
