
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

extern char **environ;

#include "argument_parser.c"
#include "handle_functions.c"

#define MAXARG 20

static void execute(int argc, char *argv[])
{
    execvp(argv[0], argv);
    printf("Can't execute\n");
}

static void execute2(int argc, char *argv[])
{
    pid_t pid;

    switch (pid = vfork())
    {
    case -1:
        printf("Fork failed");
    case 0:
        execvp(argv[0], argv);
    default:
        wait(NULL);
    }
}

int main(void)
{
    char *argv[MAXARG];
    int argc;
    bool eof;

    while (true)
    {
        printf("#: ");
        if (getargs(&argc, argv, MAXARG, &eof) && argc > 0)
        {
            if (strchr(argv[0], '=') != NULL)
                asg(argc, argv);
            else if (strcmp(argv[0], "set") == 0)
                set(argc, argv);
            else
                execute2(argc, argv);
        }
        if (eof)
            exit(EXIT_SUCCESS);
    }

    return 0;
}
