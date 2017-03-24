#include "pm.h"
#include <minix/callnr.h>
#include <minix/endpoint.h>
#include <limits.h>
#include <minix/com.h>
#include <signal.h>
#include "mproc.h"
#include "param.h"


/*===========================================================================*
 *				do_gettag		       	     *
 *===========================================================================*/
int do_gettag()
{
  struct mproc *rmp = find_proc(m_in.m1_i1); // Find process with matching PID
  if(!rmp) return -1;                        // If no process found, return -1
  mp->mp_reply.m1_i1 = rmp->tag;             // Process's tag is passed back to caller
  return 0;                                  // No error, return 0
}

/*===========================================================================*
 *				do_settag			       	   *
 *===========================================================================*/
int do_settag()
{
  struct mproc *rmp = find_proc(m_in.m1_i1);  // Find process with matching PID
  if(!rmp) return -1;                         // If no process found, return -1
  rmp->tag = m_in.m1_i2;                      // Set process's tag to desired value
  return 0;                                   // No error, return 0
}
