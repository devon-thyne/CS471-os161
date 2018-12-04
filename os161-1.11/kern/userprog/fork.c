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
#include <pid.h>


/*
 * Fork System call
 * The child process returns 0, the Parent returns pid of child
 *
 * On Error, do not create child, return -1
 *
 */

int
sys_fork(struct trapframe *parent_tf, pid_t *child_pid)
{
	/*Create a PID for child process and add to process_table*/
	int child_pid = assign_pid();
	if(child_pid == -1){
		return EAGAIN;
	}	

	struct trapframe *child_tf;
	child_tf = kmalloc(sizeof(struct trapframe));
	if(child_tf == NULL){
		return ENOMEM;
	}

	//set child trapframe to parent trapframe
	*child_tf = *parent_tf;

	//fork thread, this creating child process
	//return thread_fork(curthread->t_name,
	return -1;
}

