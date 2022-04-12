#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *data = malloc(100 * sizeof(int));
  data[0] = 10;

  free(data);

  printf("%d", data[0]);

  return 0;
}

/*
Runs without exceptions, but prints the wrong value (0 instead of 10). Valgrind returns error:
==2385== Invalid read of size 4
==2385==    at 0x1091C4: main (in /home/forbes/ostep/week_6/a.out)
==2385==  Address 0x4a50040 is 0 bytes inside a block of size 400 free'd
==2385==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2385==    by 0x1091BF: main (in /home/forbes/ostep/week_6/a.out)
==2385==  Block was alloc'd at
==2385==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2385==    by 0x1091A5: main (in /home/forbes/ostep/week_6/a.out)
==2385==
10==2385==
==2385== HEAP SUMMARY:
==2385==     in use at exit: 0 bytes in 0 blocks
==2385==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==2385==
==2385== All heap blocks were freed -- no leaks are possible
==2385==
==2385== For lists of detected and suppressed errors, rerun with: -s
==2385== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
