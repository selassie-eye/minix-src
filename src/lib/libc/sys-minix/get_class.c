#include <sys/cdefs.h>
#include <lib.h>
#include <stdio.h>
#include <errno.h>
int get_class(FILE* fd){
	if(fd == NULL || fileno(fd)==-1){
		errno=1;
		return -1;
		printf("GET_CLASS ERROR\n");
	}

	message m;
	m.m1_i1=fileno(fd);
	m.m1_i2=0;
	m.m1_i3=0;
	printf("GET_CLASS NO ERROR\n");

	return _syscall(VFS_PROC_NR, CLASS, &m);
}
