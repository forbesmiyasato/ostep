#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct timeval st;
    struct timeval et;
    const unsigned long MICROSECONDS_IN_SECONDS = 1000000;
    const unsigned long iterations = 10000000;
    gettimeofday(&st, NULL);
    for (int i = 0; i < iterations; i++) {
        read(0, NULL, 0);
    }
    gettimeofday(&et,NULL);
    unsigned long st_in_micros = st.tv_sec * MICROSECONDS_IN_SECONDS + st.tv_usec;
    unsigned long et_in_micros = et.tv_sec * MICROSECONDS_IN_SECONDS + et.tv_usec;
    float total_time_in_micros = et_in_micros - st_in_micros;
    float total_time_in_seconds = total_time_in_micros / (float)MICROSECONDS_IN_SECONDS;
    float avg_time_in_micros = total_time_in_micros / iterations;
    float avg_time_in_seconds = avg_time_in_micros / MICROSECONDS_IN_SECONDS;
    printf("total time in microseconds: %f\n", total_time_in_micros);
    printf("total time in seconds: %f\n", total_time_in_seconds);
    printf("avg time in microseconds: %.5f\n", avg_time_in_micros);
    printf("avg time in seconds: %.10f\n", avg_time_in_seconds);
    /* Average time in microseconds is 3 if iteration is 1
     * output when iteration is 10000000:
     * total time in microseconds: 5319517.000000
     * total time in seconds: 5.319517
     * avg time in microseconds: 0.53195
     * avg time in seconds: 0.0000005320 */

    return 0;
}
