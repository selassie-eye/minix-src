#include <sys/cdefs.h>
#include <lib.h>
#include <stdio.h>
#include <errno.h>
int get_dirty(FILE* fd, int newvalue){
	if(fd == NULL)
	{
		errno = 1;
		return -1;
	}
	else if(newvalue < 0)
	{
		errno = 1;
		return -1;
	}
	else
	{
		message m;
		m.m1_i1 = fileno(fd);
		m.m1_i2 = newvalue;
		m.m1_i3=2;
		return _syscall(VFS_PROC_NR, DO_CLASS, &m);
	}
}
