#include <stdio.h>
#include <string.h>
#include <math.h>
int main(int argc, char* argv[])
{
	int arg_1, arg_2, arg_3;
	double disc;
	double x1;
	double x2;

	if (argc < 4 || argc > 5)
	{
		printf("invalid arguments count!");
		return 1;
	}

	else if (argc == 4)
	{
		sscanf(argv[2], "%i", &arg_1);
		sscanf(argv[3], "%i", &arg_2);

		if (arg_1 == 0 || arg_2 == 0)
		{
			printf("invalid arguments count!");
			return 2;
		}

		else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0)
		{
			if (arg_1 % arg_2 == 0)
			{
				printf("multiple");
			}
			else
			{
				printf("not multiple");
			}
		}
	}
	else if (argc == 5)
	{
		sscanf(argv[2], "%i", &arg_1);
		sscanf(argv[3], "%i", &arg_2);
		sscanf(argv[4], "%i", &arg_3);

		if (strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0)
		{

			disc = pow(arg_2, 2) - (4 * arg_1 * arg_3);
			if (disc < 0)
			{
				printf("no solution");
			}
			else if (disc == 0)
			{
				x1 = (-1 * arg_2) / (2 * arg_1);
				printf("x1 = %f", x1);
			}
			else
			{
				x1 = ((-1 * arg_2) - sqrt(disc)) / (2 * arg_1);
				x2 = ((-1 * arg_2) + sqrt(disc)) / (2 * arg_1);
				printf("x1 = %f and x2 = %f", x1, x2);
			}
		}
		else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0)
		{
			if (arg_1 == 0 || arg_2 == 0 || arg_3 == 0)
			{
				printf("invalid arguments count!");
				return 3;
			}
			else if (arg_1 + arg_2 > arg_3 && arg_1 + arg_3 > arg_2 && arg_2 + arg_3 > arg_1)
			{
				printf("the triangle exists");
			}
			else
			{
				printf("the triangle does not exist");
			}
		}
	}
}