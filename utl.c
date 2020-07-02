#include "utl.h"
#include "stk.h"
#include <stdio.h>
#include <stdlib.h>

// ввод размера строки
int input_size()
{
	int arr_size = 0;
	printf("How many symbols you wont?\n");
	if (scanf_s("%d", &arr_size))
		return arr_size;
	else
	{
		printf("Error symbol, try again\n");
		return input_size();
	}
}

// ввод строки
int input_str(int arr_size, char* arr)
{
	int i = 0, j = 0, k=0, num;
	/*char* help_arr;
	help_arr = malloc(sizeof(int) * arr_size);*/
	printf("Enter %d symbols\n", arr_size);
	while (i < arr_size)
	{
		arr[i] = getchar();
		if (arr[i] != ' ' && arr[i] != '\n')
			i++;
	}
	/*for (i = 0; i < arr_size; i++)
	{
		while (arr[i]>='0' && arr[i] <= '9')
		{
			help_arr[j] = arr[i];
			j++;
			i++;
		}
		if ((arr[i] <= '0' || arr[i] >= '9')&& atoi(help_arr)!=0)
		{
			if (arr[k] >= '0' && arr[k] <= '9' && (arr[k + 1] >= '0' && arr[k + 1] <= '9'))
			{
				num = atoi(help_arr);
				arr[k] = num+'0';
				k++;
			}
			while (arr[k] >= '0' && arr[k] <= '9')
				k++;
			k++;
		}
		help_arr[0] = "g";
	}*/
	/*free(help_arr);*/
}

// проверка выделенной памяти
int memmory_check(Stk* stack)
{
	if (stack == NULL)
	{
		printf("Error memmory");
		return 0;
	}
}

// проверка введенной строки
int arr_check(char* arr, int arr_size, Stk* stack)
{
	int i=0;
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == '(' || arr[i] == ')' || arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-' || (arr[i] >= '0' && arr[i] <= '9')|| arr[i] == '^' || (arr[i] >= 'a' && arr[i] <= 'z'));
		else
		{
			printf("Error symbol, try again");
			return input_str(stack, arr_size, arr);
		}
	}
	/*for (i = 0; i < arr_size; i++)
	{
		if(arr[i]=='s')
		if (((i + 2) < arr_size) && arr[i] == 's' && arr[i + 1] == 'i' && arr[i + 2] == 'n');
		else
		{
			printf("Error symbol, try again");
			return input_str(stack, arr_size, arr);
		}
		if (((i + 2) < arr_size) && arr[i] == 'c' && arr[i + 1] == 'o' && arr[i + 2] == 's');
	}*/
	printf("All is ok\n");
}

// вывод строки в обратной польской записи
int output(char* answer, int arr_size)
{
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (answer[i] == '*' || answer[i] == '/' || answer[i] == '+' || answer[i] == '-' || (answer[i] >= '0' && answer[i] <= '9') || answer[i] == '^'|| (answer[i] >= 'a' && answer[i] <= 'z'))
		{
			printf("%c", answer[i]);
		}
	}
}
