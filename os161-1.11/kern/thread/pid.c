/*
 * pid.c
 *
 * Devon Thyne
 * Matthew Gayhart
 */

#include <types.h>
#include <pid.h>
#include <lib.h>
#include <thread.h>
#include <scheduler.h>
#include <kern/limits.h>

/*
 * Initialize Process Table with -1's
 * Return 0 for success
 * Return -1 for failure
 */
int
proc_table_create(int *proc_table)
{
	*proc_table = kmalloc(sizeof(int) * PROC_MAX);
	if(proc_table == NULL) {
		return -1;
	}
	int i;
	for(i = 0; i < PROC_MAX; i++){
		proc_table[i] = -1;
	}
	return 0;
}

/*
 * Add Process to lowest available entry in the Process Table
 * Starts by reserving pid index by setting to 0, child thread has to go back later and set pointer
 * Return i = pid on success
 * Return -1 for failure
 */
int
assign_pid()
{
	int i;
	int *process_table = get_process_table();

	for(i = 0; i < PROC_MAX; i++){
		if(process_table[i] == -1){
			process_table[i] = 0;
			return i;
		}
	}
	return -1;
}

/*
 * Returns the pointer to the thread with passed PID
 */
int
get_thread(pid_t pid)
{
	int *process_table = get_process_table();

	return process_table[pid - 1];
}

/*
 * Removes entry in the Process Table
 * Does so by setting index at that PID back to -1
 */
void
remove_pid(pid_t pid)
{
	int *process_table = get_process_table();
	
	process_table[pid - 1] = -1;
}
