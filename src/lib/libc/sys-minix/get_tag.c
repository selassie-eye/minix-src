#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"
#include <unistd.h>

/**
 * Get the tag value of a process
 */
int get_tag(pid_t pid)
{
  message m;      // Message variable used to pass data to system call
  m.m1_i1 = pid;  // Specified PID is passed to the system call

  // User/parent permissions enforced
  if (pid == getpid() || geteuid() == 0){
    int tag = _syscall(PM_PROC_NR, GETTAG, &m); // System call GETTAG invoked
    if (tag == -1) return tag;                  // Call fails, return -1
    else return m.m1_i1;                        // Call successful, return tag
  }
  return -1;  // Return -1 if user/parent requirements not met.
}
