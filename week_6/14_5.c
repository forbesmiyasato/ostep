#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *data = malloc(100 * sizeof(int));
	data[0] = 1;
	data[100] = 0;

	printf("%d %d", data[0], data[100]);

	free(data);
	return 0;
}

/*
The program runs normally, but valgrind finds an invalid write. However, it does print data[0] to be 0, output is: 0 1

==2223== Invalid write of size 4
==2223==    at 0x10919E: main (in /home/forbes/ostep/week_6/a.out)
==2223==  Address 0x4a501d0 is 0 bytes after a block of size 400 alloc'd
==2223==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2223==    by 0x109185: main (in /home/forbes/ostep/week_6/a.out)
==2223==
==2223==
==2223== HEAP SUMMARY:
==2223==     in use at exit: 0 bytes in 0 blocks
==2223==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
==2223==
==2223== All heap blocks were freed -- no leaks are possible
==2223==
==2223== For lists of detected and suppressed errors, rerun with: -s
==2223== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
