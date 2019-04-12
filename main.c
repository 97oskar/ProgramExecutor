
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <time.h>

#define MAXARG 20
#define MAXLINE 200

#define NRM "\x1B[0m"
#define CYN "\x1B[36m"

#include "argument_parser.c"

static void execute(int argc, char *argv[]);
static void execute2(int argc, char *argv[]);

static void benchamark(int argc, char *argv[]);

int main(void)
{
    char *argv[MAXARG];
    int argc;
    bool eof;

    while (true)
    {
        printf("%s#: ", CYN);
        printf("%s", NRM);
        if (getargs(&argc, argv, MAXARG, &eof) && argc > 0)
            execute(argc, argv);
        // benchamark(argc, argv);

        if (eof)
            exit(EXIT_SUCCESS);
    }

    return 0;
}

static void execute(int argc, char *argv[])
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

static void execute2(int argc, char *argv[])
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

static void benchamark(int argc, char *argv[])
{
    clock_t start;
    char *envs[3];
    double results[3];

    envs[0] = "vfork + execvp";
    start = clock();
    for (int i = 0; i < 10000; i++)
        execute(argc, argv);
    results[0] = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    envs[1] = "fork + execvp";
    start = clock();
    for (int i = 0; i < 10000; i++)
        execute2(argc, argv);
    results[1] = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    envs[2] = "system + execvp";
    start = clock();
    for (int i = 0; i < 10000; i++)
        system("./hello");
    results[2] = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < 3; i++)
        printf("time: %f [%s]\n", results[i], envs[i]);
}