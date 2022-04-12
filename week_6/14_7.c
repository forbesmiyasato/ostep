#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *data = malloc(100 * sizeof(int));
  
  data[50] = 10;

	printf("%d", data[50]);
  
	free(&data[50]);

  printf("%d", data[50]);

  return 0;
}

/*
forbes@forbes-VirtualBox:~/ostep/week_6$ ./a.out
free(): invalid pointer
Aborted (core dumped)

forbes@forbes-VirtualBox:~/ostep/week_6$ valgrind --leak-check=yes ./a.out
==2479== Command: ./a.out
==2479==
==2479== Invalid free() / delete / delete[] / realloc()
==2479==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2479==    by 0x1091EA: main (in /home/forbes/ostep/week_6/a.out)
==2479==  Address 0x4a50108 is 200 bytes inside a block of size 400 alloc'd
==2479==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2479==    by 0x1091A5: main (in /home/forbes/ostep/week_6/a.out)
==2479==
1010==2479==
==2479== HEAP SUMMARY:
==2479==     in use at exit: 400 bytes in 1 blocks
==2479==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==2479==
==2479== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2479==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2479==    by 0x1091A5: main (in /home/forbes/ostep/week_6/a.out)
==2479==
==2479== LEAK SUMMARY:
==2479==    definitely lost: 400 bytes in 1 blocks
==2479==    indirectly lost: 0 bytes in 0 blocks
==2479==      possibly lost: 0 bytes in 0 blocks
==2479==    still reachable: 0 bytes in 0 blocks
==2479==         suppressed: 0 bytes in 0 blocks
==2479==
==2479== For lists of detected and suppressed errors, rerun with: -s
==2479== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
*/
