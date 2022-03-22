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

    switch(fork()) {
    case -1:
        perror("pipe");
	exit(1);
    case 0:
        /* child */
        /* should I close here? */
	for (int i = 0; i < iterations; i++) {
            read(fd[0], NULL, 0);
            write(fd[1], NULL, 0);
	}
    default:
	/* parent */
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
        break;
    }
    /* output (all from same run):
     * total time in microseconds: 16627874.000000
     * avg time in microseconds: 1.66279
     * total time in microseconds: 8195315.000000
     * avg time in microseconds: 0.81953 */

    return 0;
}
