#include <sys/cdefs.h>
#include <lib.h>
#include <stdio.h>
#include <errno.h>
int set_class(FILE* fd, int newvalue){
	if(newvalue < 0 || fd==NULL || fileno(fd)==-1){
		errno=1;
		return -1;
	}

	message m;
	m.m1_i1=fileno(fd);
	m.m1_i2=newvalue;
	m.m1_i3=1;

	return _syscall(VFS_PROC_NR, DO_CLASS, &m);
}
