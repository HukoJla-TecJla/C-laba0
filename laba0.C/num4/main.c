#include <stdio.h>
#include <string.h>
int main()
{
	char* line_1 = "rrrrr hhhh www\n";
	char* line_2 = "rrrrr hhhh www\n";
	char* line_3 = "rrrrr hhhh www\n";
	char arr[500], arr2[500], arr3[500];
	FILE* f = fopen("xrp", "w");
	FILE* f_2 = fopen("lite", "w");
	if (f)
	{
		fputs(line_1, f);
		fputs(line_2, f);
		fputs(line_3, f);
	}
	fclose(f);
	f = fopen("xrp", "r");
	for (int i = 0; i < 3; ++i)
	{
		fscanf(f, "%s %s %s", arr, arr2, arr3);
		fprintf(f_2, "%s %s %s\n", arr, arr2, arr3);
	}
	fclose(f);
	fclose(f_2);
	f = fopen("xrp", "w");
	f_2 = fopen("lite", "r");
	for (int i = 0; i < 3; ++i)
	{
		fscanf(f_2, "%s %s %s", arr, arr2, arr3);
		fprintf(f, "%s %s %s\n", arr3, arr, arr2);
	}
	fclose(f);
	fclose(f_2);
}