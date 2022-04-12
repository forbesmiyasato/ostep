#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *data = malloc(100 * sizeof(int));
  
  data[50] = 10;

  printf("%d", data[50]);
  
  free(&data[50]);

  printf("%d", data[50]);

  free(data);

  return 0;
}

/*
forbes@forbes-VirtualBox:~/ostep/week_6$ ./a.out
free(): invalid pointer
Aborted (core dumped)

forbes@forbes-VirtualBox:~/ostep/week_6$ valgrind --leak-check=yes ./a.out
==2558== Invalid free() / delete / delete[] / realloc()
==2558==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2558==    by 0x1091EA: main (in /home/forbes/ostep/week_6/a.out)
==2558==  Address 0x4a50108 is 200 bytes inside a block of size 400 alloc'd
==2558==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==2558==    by 0x1091A5: main (in /home/forbes/ostep/week_6/a.out)
==2558== 
1010==2558== 
==2558== HEAP SUMMARY:
==2558==     in use at exit: 0 bytes in 0 blocks
==2558==   total heap usage: 2 allocs, 3 frees, 1,424 bytes allocated
==2558== 
==2558== All heap blocks were freed -- no leaks are possible
==2558== 
==2558== For lists of detected and suppressed errors, rerun with: -s
==2558== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
