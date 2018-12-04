/*
 * waitpid.c
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
#include <pid.h>

/*
 * Waitpid System call
 * Waits on the process with pid to exit
 *
 * Returns its exit code with integet pointer status
 */

pid_t
sys_waitpid(pid_t pid, int *status, int options)
{
	//check if valid process
	if(get_thread(pid) == -1){
		return -1;
	}
	//attempt to asquire process' exit_lock, which they will have acquisition of
	//until they exit, thus waking you up and you can then continue
	lock_acquire(get_thread(pid)->exit_lock);
	return get_thread(pid)->exit_code;
}
