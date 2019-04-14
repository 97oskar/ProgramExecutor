#include "benchmark.h"

void benchmark(int argc, char *argv[], int num_of_calls, char *system_call_command)
{
    clock_t start;
    char *envs[3];
    double results[3];

    envs[0] = "vfork + execvp";
    start = clock();
    for (int i = 0; i < num_of_calls; i++)
        execute(argc, argv);
    results[0] = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    envs[1] = "fork + execvp";
    start = clock();
    for (int i = 0; i < num_of_calls; i++)
        execute2(argc, argv);
    results[1] = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    envs[2] = "system call";
    start = clock();
    for (int i = 0; i < num_of_calls; i++)
        system(system_call_command);
    results[2] = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < 3; i++)
        printf("time: %f [%s]\n", results[i], envs[i]);
}
