/*
 * exit.c
 *
 * Devon Thyne
 * Matthew Gayhart
 *
 * CS 471 - 001
 */

nclude <types.h>
#include <kern/errno.h>
#include <thread.h>
#include <curthread.h>
#include <syscall.h>
#include <machine/trapframe.h>
#include <pid.h>

/*
 * Exit System call
 * Causes the current process to terminate
 */

void
sys__exit(int code)
{
	lock *lock_save = curthread->exit_lock;
	pid_t pid_save = curthread->pid;

	thread_exit(curthread);
	
	//check mechanism in scheduler to see if other processes are interested and/or waiting on the PID
	//if so, do not remove entry in the PID table, else, remove entry in the PID table
	remove_pid(pid_save);	

	lock_release(lock_save);
}
