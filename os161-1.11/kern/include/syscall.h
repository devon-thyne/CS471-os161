#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/*
 * Prototypes for IN-KERNEL entry points for system call implementations.
 */

int sys_reboot(int code);
int sys_getpid(pid_t *retval);
int sys_fork(struct trapframe *parent_tf, pid_t *child_pid);
int sys_execv(char *program, char **args);
pid_t sys_waitpid(pid_t pid, int *status, int options);
void sys__exit(int code);

#endif /* _SYSCALL_H_ */
