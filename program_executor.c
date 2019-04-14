#include "program_executor.h"

void execute(int argc, char *argv[])
{
    pid_t pid;

    switch (pid = vfork())
    {
    case -1:
        printf("Forking failed\n");
    case 0:
        execvp(argv[0], argv);
        printf("Command not found\n");
    default:
        waitpid(pid, NULL, 0);
    }
}

void execute2(int argc, char *argv[])
{
    pid_t pid;
    int status;

    switch (pid = fork())
    {
    case -1:
        printf("Forking failed\n");
    case 0:
        execvp(argv[0], argv);
        printf("Command not found\n");
    default:
        waitpid(pid, &status, 0);
    }
}