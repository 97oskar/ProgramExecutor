
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define MAXARG 20

#define NRM "\x1B[0m"
#define CYN "\x1B[36m"

#include "argument_parser.h"
#include "program_executor.h"

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

        if (eof)
            exit(EXIT_SUCCESS);
    }

    return 0;
}
