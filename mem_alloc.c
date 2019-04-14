#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    long mallocSize = 500 * 1024 * 1024 * 2;
    void *ptr = malloc(mallocSize);
    free(ptr);

    _exit(EXIT_SUCCESS);
}