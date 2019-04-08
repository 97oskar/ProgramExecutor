
void set(int argc, char *argv[])
{
    int i;

    if (argc != 1)
        printf("Extra args\n");
    else
        for (i = 0; environ[i] != NULL; i++)
            printf("%s\n", environ[i]);
}

void asg(int argc, char *argv[])
{
    char *name, *val;

    if (argc != 1)
        printf("Extra args\n");
    else
    {
        name = strtok(argv[0], "=");
        val = strtok(NULL, "");
        if (name == NULL || val == NULL)
            printf("Invalid commnad\n");
        else
            setenv(name, val, true);
    }
}
