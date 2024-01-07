#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int str_number_base(char* str_number, int base)
{
	char* str_end;
	strtol(str_number, &str_end, base);
	return *str_end == '\0';
}



int min_number_base(char* str_number)
{
	int min_base = 2;
	while (min_base <= 16)
	{
		if (str_number_base(str_number, min_base))
		{
			return min_base;
		}
		++min_base;
	}
	return 1;
}



int main()
{
	setlocale(LC_ALL, "RUS");

	FILE* f = fopen("file_new.txt", "r");
	FILE* f_out = fopen("Out_f.txt", "w");

	char str_f[500];

	if (f == NULL || f_out == NULL)
	{
		printf("Файл некорректный\n");
		return -1;
	}

	while (fgets(str_f, sizeof(str_f), f))
	{
		char* str_number = strtok(str_f, "\t", "\n", "\0");

		while (str_number != NULL)
		{
			int min_base = min_number_base(str_f);
			if (min_base == 1)
			{
				printf("Число %s некорректное\n", str_number);
			}
			else
			{
				fprintf(f_out, "%s - число; %d - мин.сс; %d - число в 10 сс", str_number, min_base, strtol(str_number, NULL, 10));
			}
			str_number = strtok(NULL, " \t\n");
		}
	}

	fclose(f);
	fclose(f_out);
	return 0;
}