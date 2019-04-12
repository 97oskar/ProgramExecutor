#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));

	for (int i = 0; i < atoi(argv[1]); i++)
		pow(10, sin(log10(rand())));

	_exit(EXIT_SUCCESS);
}