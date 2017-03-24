#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"
#include <unistd.h>

/**
 * Set the tag value of a process
 */
int set_tag(pid_t pid, int tag)
{
  message m;        // Message variable used to pass data to system call
  m.m1_i1 = pid;    // PID passed to system call
  m.m1_i2 = tag;    // Future process tag passed to system call

  if (tag < 0) return -1;   // Tag value cannot be negative

  else{
    if (geteuid() == 0){   // user/parent permissions enforced
      int r = _syscall(PM_PROC_NR, SETTAG, &m);   // System call SETTAG invoked
      if (r == -1) return r;                      // Call fails, return -1
      else return tag;                            // Call successful, return tag
    }
  }
  return -1;  // Return -1 if user/parent requirements not met
}
