/*
 * execv.c
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
 * Execv System call
 * Replaces the currently executing program image with a new process image
 */
int
sys_execv(char *program, char **args)
{
	if(program == NULL){
		return ENOENT;
	}
}
