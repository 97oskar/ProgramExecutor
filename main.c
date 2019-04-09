
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#define MAXARG 20
#define MAXLINE 200

#include "argument_parser.c"

static void execute(int argc, char *argv[]);

int main(void)
{
    char *argv[MAXARG];
    int argc;
    bool eof;

    while (true)
    {
        printf("#: ");
        if (getargs(&argc, argv, MAXARG, &eof) && argc > 0)
            execute(argc, argv);

        if (eof)
            exit(EXIT_SUCCESS);
    }

    return 0;
}

static void execute(int argc, char *argv[])
{
    pid_t pid;
    int status;

    switch (pid = vfork())
    {
    case -1:
        printf("Forking failed");
    case 0:
        execvp(argv[0], argv);
    default:
        waitpid(pid, &status, 0);
    }
}