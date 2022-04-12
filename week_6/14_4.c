#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *ptr = malloc(10 * 1024 * 1024);

	return 0;
}

/*
The process ran normally and there was also no problems when using gdb. However, we were able to find a memory leak with valgrind:
==2137== HEAP SUMMARY:
==2137==     in use at exit: 10,485,760 bytes in 1 blocks
==2137==   total heap usage: 1 allocs, 0 frees, 10,485,760 bytes allocated
==2137==
==2137== 10,485,760 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2137==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2137==    by 0x109165: main (in /home/forbes/ostep/week_6/a.out)
==2137==
==2137== LEAK SUMMARY:
==2137==    definitely lost: 10,485,760 bytes in 1 blocks
==2137==    indirectly lost: 0 bytes in 0 blocks
==2137==      possibly lost: 0 bytes in 0 blocks
==2137==    still reachable: 0 bytes in 0 blocks
==2137==         suppressed: 0 bytes in 0 blocks
==2137==
==2137== For lists of detected and suppressed errors, rerun with: -s
==2137== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
