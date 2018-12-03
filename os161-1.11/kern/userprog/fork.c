/*
 * fork.c
 *
 * Devon Thyne
 * Matthew Gayhart
 *
 * CS 471 - 001
 */

#include <types.h>
#include <kern/errno.h>
#include <thread.h>
#include <curthread.h>
#include <syscall.h>
#include <machine/trapframe.h>



/*
 * Fork System call
 * The child process returns 0, the Parent returns pid of child
 *
 * On Error, do not create child, return -1
 *
 */

pid_t
sys_fork(void)
{
	/*Create a PID for child process and add to process_table*/
	
	//child = get_new_pid()
	//if(child == NULL) /can't get a pid
	//	return -1
	//else
	//
	//Child trapframe = parent Trapframe
	//caddrspc = as_copy();
	//thread_fork();
	//
	//??
	//if child return 0
	//if parent return child
	return 0;
}

