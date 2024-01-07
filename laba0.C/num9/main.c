#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int covert_10(char* number, int base)
{
	int ch = 0;
	int base10 = 0;
	int len = strlen(number);
	for (int i = len - 1; i >= 0; i--)
	{
		int number_int = 0;
		if (number[i] >= '0' && number[i] <= '9')
		{
			number_int = number[i] - '0';
		}
		else
		{
			number_int = number[i] - 'A' + 10;
		}
		base10 += number_int * pow(base, ch);
		ch++;
	}
	return base10;
}

char* convert_to_base(int number, int base)
{
	char* array_convert_base = malloc(sizeof(char) * 100);
	int value = number;
	int ch = 0;
	while (value > 0)
	{
		if (value % base < 10)
		{
			array_convert_base[ch] = (value % base) + '0';
		}
		else
		{
			array_convert_base[ch] = (value % base) - 10 + 'A';
		}
		value /= base;
		ch++;
	}
	array_convert_base[ch] = '\0';

	int len_array = strlen(array_convert_base);
	for (int i = 0; i < strlen(array_convert_base) / 2; i++)
	{
		char number_swap = array_convert_base[i];
		array_convert_base[i] = array_convert_base[len_array - i - 1];
		array_convert_base[len_array - i - 1] = number_swap;
	}
	return array_convert_base;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char numbers[37];
	char input_base[2];
	printf("Введите систему исчисления в диапазоне [2...36]: ");
	scanf("%s", input_base);
	int base = atoi(input_base);
	int max_number = 0;
	while (1)
	{
		printf("Введите числа в этой СС. Для окончания ввода введите: Stop: ");
		scanf("%s", numbers);
		if (strcmp(numbers, "Stop") == 0)
		{
			break;
		}
		int number = abs(covert_10(numbers, base));
		if (number > max_number)
		{
			max_number = number;
		}


	}
	printf("Максимальное число по модулю с основанием 9: %s\n", convert_to_base(max_number, 9));
	printf("Максимальное число по модулю с основанием 18: %s\n", convert_to_base(max_number, 18));
	printf("Максимальное число по модулю с основанием 27: %s\n", convert_to_base(max_number, 27));
	printf("Максимальное число по модулю с основанием 36: %s\n", convert_to_base(max_number, 36));
}
