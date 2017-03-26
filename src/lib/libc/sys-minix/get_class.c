#include <sys/cdefs.h>
#include <lib.h>
#include <stdio.h>
#include <errno.h>
int get_class(FILE* fd){
	if(fd == NULL){
		errno=1;
		return -1;
	}

	message m;
	m.m1_i1=fileno(fd);
	m.m1_i2=0;
	m.m1_i3=0;

	return _syscall(VFS_PROC_NR, CLASS, &m);
}
