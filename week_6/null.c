#include <stdio.h>

int main(int argc, char *argv[]) {
	int *ptr = NULL;

	*ptr = 1;

	return 0;
}

/* 
1. What happens when you run this program?
Segmentation fault (core dumped)

2. What does gdb show you? 
Program received signal SIGSEGV, Segmentation fault.
0x0000555555555144 in main (argc=1, argv=0x7fffffffe0d8) at null.c:6
6		*ptr = 1;

3. What happens when you run valgrind --leak-check=yes null?
==4870== Memcheck, a memory error detector
==4870== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4870== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==4870== Command: ./null
==4870==
==4870== Invalid write of size 4
==4870==    at 0x109144: main (null.c:6)
==4870==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==4870==
==4870==
==4870== Process terminating with default action of signal 11 (SIGSEGV)
==4870==  Access not within mapped region at address 0x0
==4870==    at 0x109144: main (null.c:6)
==4870==  If you believe this happened as a result of a stack
==4870==  overflow in your program's main thread (unlikely but
==4870==  possible), you can try to increase the size of the
==4870==  main thread stack using the --main-stacksize= flag.
==4870==  The main thread stack size used in this run was 8388608.
==4870==
==4870== HEAP SUMMARY:
==4870==     in use at exit: 0 bytes in 0 blocks
==4870==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4870==
==4870== All heap blocks were freed -- no leaks are possible
==4870==
==4870== For lists of detected and suppressed errors, rerun with: -s
==4870== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)

I also got an ubuntu popup error "Sorry, the application membheck-amd64-linux has stopped unexpectedly."
