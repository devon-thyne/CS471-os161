#ifndef _PID_H_
#define _PID_H_

int
proc_table_create(int *proc_table);

int
assign_pid();

int
get_thread(pid_t pid);

void
remove_pid(pid_t pid);

#endif /* _PID_H_ */
