/*
 * forktest - test fork().
 *
 * This should work correctly when fork is implemented.
 *
 * It should also continue to work after subsequent assignments, most
 * notably after implementing the virtual memory system.
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>

int
main(int argc, char *argv[])
{
	int pid;

	printf("getpidtest.c pre-getpid() func.\n");	

	pid = getpid();

	printf("user-side getpid() = %d\n", pid);

	reboot(RB_REBOOT);
	return 0;
}
