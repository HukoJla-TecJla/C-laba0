#include <stdio.h>
#include <string.h>
#include <math.h>
int main(int argc, char* argv[])
{
	int i = 0, arg_ch = 0, ch, flag = 0, ch2;
	int sum = 0;
	int fact = 1;
	char str[10000];
	if (argc != 3)
	{
		printf("invalid arguments count");
		return 0;
	}
	if ((sscanf(argv[2], "%u", &arg_ch) != 1) || (arg_ch == 0))
	{
		printf("invalid");
		return 1;
	}
	if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "/h") == 0))
	{
		ch = arg_ch;
		while (ch <= 100)
		{
			printf("%d\n", ch);
			ch += arg_ch;
		}
	}
	else if (strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "/p") == 0)
	{
		if (arg_ch == 1)
		{
			printf("Not prime and not composite\n");
		}
		else if (arg_ch == 2)
		{
			printf("Composite1\n");
		}
		else if ((arg_ch & 1) == 0)
		{
			printf("Composite2\n");
		}
		else
		{
			for (int i = 3; i <= (int)sqrt(arg_ch); i += 2)
			{
				if (arg_ch % i == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				printf("Composite3\n");
			}
			else
			{
				printf("Prime4\n");
			}

		}
	}
	else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "/s") == 0)
	{
		snprintf(str, sizeof str, "%d", arg_ch);
		while (i <= strlen(str))
		{
			printf("%c\t", str[i]);
			++i;
		}
	}
	else if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "/e") == 0)
	{
		if (arg_ch <= 10)
		{
			for (i = 1; i <= 10; ++i)
			{
				for (ch2 = 1; ch2 <= arg_ch; ++ch2)
				{
					printf("%.f\t", pow(i, ch2));

				}
				printf("\n");
			}
		}
	}
	else if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "/a") == 0)
	{
		for (i = 1; i <= arg_ch; ++i)
		{
			sum += i;
		}
		printf("%d", sum);
	}
	else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "/f") == 0)
	{
		for (i = 2; i <= arg_ch; ++i)
		{
			fact *= i;
		}
		printf("%d", fact);
	}
}