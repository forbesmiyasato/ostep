#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int memory; // in megabytes
	int runTime = -1; // in seconds
	int bytes = 1024 * 1024;

	if (argc > 3) {
		printf("Too many arguments!\n");
	} else if (argc == 3) {
		runTime = atoi(argv[2]);
		printf("Run for %d seconds\n", runTime);
	}
	
	memory = atoi(argv[1]) * bytes;
	printf("Allocate %d MB of memory\n", memory / bytes);
	
	int *arr;
	arr = (int*) malloc (memory);
	int len = memory / sizeof(int);

 	clock_t start = clock();
	
	while (1) {
		clock_t curTime = clock() - start;
                double timeTaken = ((double)curTime)/CLOCKS_PER_SEC;
                if (timeTaken > runTime) {
                	break;
                }

		for (int i = 0; i < len; i++) {
			arr[i]++;
		}
	}

	free(arr);

	return 0;
}
