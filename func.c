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
int input_str(Stk* stack, int arr_size, char* arr)
{
	int i = 0;
	printf("Enter %d symbols\n", arr_size);
	while (i < arr_size)
	{
		arr[i] = getchar();
		if (arr[i] != ' ' && arr[i] != '\n')
			i++;
	}
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
		if (arr[i] == '(' || arr[i] == ')' || arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-' || (arr[i] >= '0' && arr[i] <= '9')|| arr[i] == '^');
		else
		{
			printf("Error symbol, try again");
			return input_str(stack, arr_size, arr);
		}
	}
	printf("All is ok\n");
}

// вывод строки в обратной польской записи
int output(char* answer, int arr_size)
{
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (answer[i] == '*' || answer[i] == '/' || answer[i] == '+' || answer[i] == '-' || (answer[i] >= '0' && answer[i] <= '9') || answer[i] == '^')
		{
			printf("%c", answer[i]);
		}
	}
}
