#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

double doForks();
double doVForks();

int main(int argc, char *argv[])
{
    long mallocSize = 100 * 1024 * 1024;

    void *ptr = malloc(mallocSize);
    memset(ptr, 0, mallocSize);
    printf("Time taken per fork  (100MB):\t%f\n", doForks());
    printf("Time taken per vfork (100MB):\t%f\n", doVForks());
    free(ptr);

    ptr = malloc(mallocSize * 5);
    memset(ptr, 0, mallocSize * 5);
    printf("Time taken per fork  (500MB):\t%f\n", doForks());
    printf("Time taken per vfork (500MB):\t%f\n", doVForks());
    free(ptr);

    ptr = malloc(mallocSize * 10);
    memset(ptr, 0, mallocSize * 10);
    printf("Time taken per fork  (1000MB):\t%f\n", doForks());
    printf("Time taken per vfork (1000MB):\t%f\n", doVForks());
    free(ptr);

    return 0;
}

double doForks()
{
    clock_t start = clock();

    pid_t child = fork();
    if (child)
    {
        waitpid(child, NULL, 0);
    }
    else
    {
        exit(0);
    }

    return (((double)(clock() - start)) / CLOCKS_PER_SEC);
}

double doVForks()
{
    clock_t start = clock();

    pid_t child = vfork();
    if (child)
    {
        waitpid(child, NULL, 0);
    }
    else
    {
        _exit(0);
    }

    return (((double)(clock() - start)) / CLOCKS_PER_SEC);
}