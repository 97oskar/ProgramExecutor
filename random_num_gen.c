#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	double result;
	srand(time(NULL));

	for (int i = 0; i < atoi(argv[1]); i++)
		result = pow(120, sin(log10(rand())));

	_exit(EXIT_SUCCESS);
}