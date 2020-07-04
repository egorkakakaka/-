#include "utl.h"
#include "stk.h"
#include <stdio.h>
#include <stdlib.h>

// ввод размера строки
int input_size()
{
	int arr_size = 0;
	printf("How many symbols you want?\n");
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
	printf("Enter %d symbols\n", arr_size);
	while (i < arr_size)
	{
		arr[i] = getchar();
		if (arr[i] != ' ' && arr[i] != '\n')
			i++;
	}
	return arr_check_1(arr, arr_size);
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
int arr_check_1(char* arr, int arr_size)
{
	int i=0;
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == '(' || arr[i] == ')' || arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-' || (arr[i] >= '0' && arr[i] <= '9')|| arr[i] == '^' || (arr[i] >= 'a' && arr[i] <= 'z'));
		else
		{
			printf("Error symbol, try again");
			return input_str(arr_size, arr);
		}
	}
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == 's')
		{
			if (((i + 2) < arr_size) && arr[i + 1] == 'i' && arr[i + 2] == 'n')
			{
				i += 2;
			}
			else
			{
				printf("Error symbol, try again\n");
				return input_str(arr_size, arr);
			}
			
		}
		if (arr[i] == 'c')
		{
			if (((i + 2) < arr_size) && arr[i + 1] == 'o' && arr[i + 2] == 's')
			{
				i += 2;
			}
			else
			{
				printf("Error symbol, try again\n");
				return input_str(arr_size, arr);
			}
		}
			
	}
	printf("All is ok\n");
	return arr_check_2(arr, arr_size);
}

int arr_check_2(char* arr, int arr_size)
{
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == 's')
		{
			if (((i + 2) < arr_size) && arr[i + 1] == 'i' && arr[i + 2] == 'n')
			{
				i += 2;
			}
			else
			{
				printf("Error symbol, try again\n");
				return input_str(arr_size, arr);
			}

		}
		if (arr[i] == 'c')
		{
			if (((i + 2) < arr_size) && arr[i + 1] == 'o' && arr[i + 2] == 's')
			{
				i += 2;
			}
			else
			{
				printf("Error symbol, try again\n");
				return input_str(arr_size, arr);
			}
		}

	}
	printf("I think so\n");
	return arr_check_3(arr, arr_size);
}

int arr_check_3(char* arr, int arr_size)
{
	int i = 0,j = 0, a=0;
	int* arr_help;
	arr_help = malloc(sizeof(int) * arr_size);
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == '('|| arr[i] == ')')
		{
			arr_help[j] = arr[i];
			j++;
		}
	}
	if (j == 0)
	{
		return printf("Yes, all is ok\n");
	}
	for (i = 0; i < arr_size; i++)
	{
		if (a >= 0)
		{
			if (arr_help[i] == '(')
				a++;
			if (arr_help[i] == ')')
				a--;
		}
		else 
		{
			printf("Error brackets count, try again\n");
			return input_str(arr_size, arr);
		}
	}
	if(a!=0)
	{
		printf("Error brackets count, try again\n");
		return input_str(arr_size, arr);
	}
	printf("1 more check\n");
	arr_check_4(arr, arr_size);
}

int arr_check_4(char* arr, int arr_size)
{
	int i = 0, j = 0, a = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (( arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-' || arr[i] == '^') && (arr[i-1] == '*' || arr[i-1] == '/' || arr[i-1] == '+' || arr[i-1] == '-' || arr[i-1] == '^'))
		{
			printf("Oh sentence error, try again\n");
			return input_str(arr_size, arr);
		}
	}
	printf("Yes all is good ;)\n");
}

// вывод строки в обратной польской записи
int output(char* answer, int arr_size)
{
	printf("Your answer - ");
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (answer[i] == '*' || answer[i] == '/' || answer[i] == '+' || answer[i] == '-' || (answer[i] >= '0' && answer[i] <= '9') || answer[i] == '^'|| (answer[i] >= 'a' && answer[i] <= 'z'))
		{
			printf("%c", answer[i]);
		}
	}
}
