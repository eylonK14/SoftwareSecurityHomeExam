#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>

#define OBJ_PATH "/lib/x86_64-linux-gnu/libc.so.6"
#define FIXED_NUMBER 666

typedef int (*sym)(const char *, ...);
void* handle;
static void myinit() __attribute__((constructor));
static void mydest() __attribute__((destructor));

void myinit() 
{
	handle = dlopen(OBJ_PATH, RTLD_LAZY);
}

void mydest() 
{
	dlclose(handle);
}

int rand(void)
{
	return FIXED_NUMBER;
}

