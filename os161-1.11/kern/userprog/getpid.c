/*
 * getpid.c
 *
 * Devon Thyne
 * Matthew Gayhart
 *
 * CS 471 - 001
 */

#include <kern/types.h>
#include <syscall.h>
#include <thread.h>
#include <curthread.h>

/*
 * Get the pid of the current process, value stored in the thread Struct
 * returns 0 as get_pid does not fail
 */

int
sys_getpid(pid_t *return_pid)
{
	*return_pid = curthread->pid;
	return 0;
}

