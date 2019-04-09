
static bool getargs(int *argcp, char *argv[], int max, bool *eopf)
{
    static char cmd[MAXLINE];
    char *cmdp;
    int i;

    *eopf = false;
    if (fgets(cmd, sizeof(cmd), stdin) == NULL)
    {
        if (ferror(stdin))
            printf("Error while reading command line");
        *eopf = true;
        return false;
    }

    if (strchr(cmd, '\n') == NULL)
    {
        while (true)
        {
            switch (getchar())
            {
            case '\n':
                break;
            case EOF:
                if (ferror(stdin))
                    printf("Incorrect commnad");
            default:
                continue;
            }
            break;
        }
        printf("Input too long - commnad ignored\n");
        return false;
    }

    cmdp = cmd;
    for (i = 0; i < max; i++)
    {
        if ((argv[i] = strtok(cmdp, " \t\n")) == NULL)
            break;
        cmdp = NULL;
    }
    if (i >= max)
    {
        printf("Input too long - commnad ignored\n");
        return false;
    }

    *argcp = i;
    return true;
}