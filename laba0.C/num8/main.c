#include <stdio.h>
#include <locale.h>
#include <string.h>
int main()
{
	setlocale(LC_ALL, "rus");
	FILE* f = fopen("inter.txt", "r");
	int arr_i[128];
	int arr_i2[128];
	int ch = 0;
	int d = 0;
	int index = 0;
	int max_number = 0;
	int max_diff = 0;
	int flag2 = 0;
	int i_2 = 0;
	int sum_number = 0;
	char flag[100] = { "" };
	printf("inter a or b or c or d or e:");
	scanf("%s", &flag);

	if (f == 0)
	{
		printf("invalid file\n");
		return 1;
	}
	for (int i = 0; i < 128; ++i)
	{
		if ((fscanf(f, "%d", &arr_i[i])) == EOF)
		{
			break;
		}
		++ch;
	}
	fclose(f);

	for (int i = 0; i < ch; ++i)
	{
		printf("%d\n", arr_i[i]);
	}
	printf("\n");

	if (strcmp(flag, "a") == 0)
	{
		for (int r = 0; r < ch; r += 2)
		{
			arr_i2[d] = arr_i[r];
			++d;
		}
		for (int d = 0; d <= (ch / 2); ++d)
		{
			printf("%d\n", arr_i2[d]);
		}
	}

	else if (strcmp(flag, "b") == 0)
	{
		for (int i = 0; i < ch; ++i)
		{
			if (arr_i[i] % 2 == 0)
			{
				printf("%d\n", arr_i[i]);
			}
		}
	}

	else if (strcmp(flag, "c") == 0)
	{
		printf("inter index: ");
		scanf("%d", &index);
		max_number = arr_i[0];
		max_diff = max_number - arr_i[index];
		for (int i = 1; i < ch; ++i)
		{
			if ((arr_i[i] - arr_i[index]) > max_diff)
			{
				max_diff = arr_i[i] - arr_i[index];
				max_number = arr_i[i];
				flag2 = 1;
			}
		}
		if (flag2 == 1)
		{
			printf("%d", max_number);
		}
		else
		{
			printf("number error");
		}
	}

	else if (strcmp(flag, "d") == 0)
	{
		printf("enter index: ");
		scanf("%d", &index);
		while (arr_i[i_2] != arr_i[index])
		{
			sum_number += arr_i[i_2];
			++i_2;
		}
		printf("%d", sum_number);
	}

	else if (strcmp(flag, "e") == 0)
	{
		printf("enter index: ");
		scanf("%d", &index);
		for (int i = 0; i < ch; ++i)
		{
			if (arr_i[i] < arr_i[index])
			{
				sum_number += arr_i[i];
			}
		}
		printf("%d", sum_number);
	}
}