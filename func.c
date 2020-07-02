#include <stdio.h>
#include <stdlib.h>
#include "stk.h"
#include "utl.h"
#include "func.h"

// если попалось число
int number_func(char* arr, char* answer, int* i, int* j)
{
	//добавляем число к ответу
	answer[*j] = arr[*i];
	//сдвигаем указатели на 1
	(*j)++;
	(*i)++;
	return 1;
}

// если попался умножить или делить
int mult_div_func(Stk* stack, char* arr, int arr_size, char* answer, int* i, int* j, int b)
{
	// если в вершине стэка лежит умножить или делить 
	if (top(stack) == '*' || top(stack) == '/' || top(stack) == '^')
	{
		// если до этого в стэке есть скобка
		if (b == 1)
		{
			while (top(stack) != '(')
			{
				answer[*j] = top(stack);
				pop(stack);
				(*j)++;
			}
		}
		// если в стэке нет скобок
		else
		{
			answer[*j] = pop(stack);
			(*j)++;
		}
		// закидываем символ в стэк
		push(stack, arr[*i], arr_size);
	}
	// если в вершине стэка нет умножения или деления кидаем символ в стэк
	else
		push(stack, arr[*i], arr_size);
	return (*i)++;
}

// если попался плюс или делить
int plus_minus_func(Stk* stack, char* arr, int arr_size, char* answer, int* i, int* j, int b)
{
	// если в вершине стэка умножение или деление или плюс или минус
	if (top(stack) == '*' || top(stack) == '/' || top(stack) == '+'|| top(stack) == '-'|| top(stack) == '^')
	{
		// если до этого в стэке есть скобка
		if (b == 1)
		{
			while (top(stack) != '(')
			{
				answer[*j] = top(stack);
				pop(stack);
				(*j)++;
			}
		}
		// если в стэке нет скобок
		else
		{
			while (stack->curr != 0)
			{
				answer[*j] = pop(stack);
				(*j)++;
			}
		}
		push(stack, arr[*i], arr_size);
	}
	else
		push(stack, arr[*i], arr_size);
	return (*i)++;
}

// если встретилось возведение
int exponent_func(Stk* stack, char* arr, int arr_size, char* answer, int* i, int* j, int b)
{
	if (top(stack) == '^' )
	{
		// если до этого в стэке есть скобка
		if (b == 1)
		{
			while (top(stack) != '(')
			{
				answer[*j] = top(stack);
				pop(stack);
				(*j)++;
			}
		}
		// если в стэке нет скобок
		else
		{
			while (stack->curr != 0)
			{
				answer[*j] = pop(stack);
				(*j)++;
			}
		}
		push(stack, arr[*i], arr_size);
	}
	else
		push(stack, arr[*i], arr_size);
	return (*i)++;
} 

// если попалась скобка
int bracket_func(Stk* stack, char* arr, int arr_size, char* answer, int* i, int* j)
{
	// ложим скобку в стэк
	push(stack, arr[*i], arr_size);
	// меняем указатель на следующий знак
	(*i)++;
	// пока не встретиться закрывающая скобка делаем следующее
	while (arr[*i] != ')')
	{
		// если встретилось число запускаем функцию
		if ((arr[*i] >= '0' && arr[*i] <= '9') || (arr[*i] >= 'a' && arr[*i] <= 'z'))
			number_func(arr, answer, i, j);
		// если встретился плюс или минус
		else if (arr[*i] == '+' || arr[*i] == '-')
			plus_minus_func(stack, arr, arr_size, answer, i, j, 1);
		// если встретилось умножить или делить
		else if (arr[*i] == '*' || arr[*i] == '/')
			mult_div_func(stack, arr, arr_size, answer, i, j, 1);
		// если встретилось возвести
		else if (arr[*i] == '^')
			exponent_func(stack, arr, arr_size, answer, i, j, 1);
		// если встретилась снова открывающая скобка
		else if (arr[*i] == '(')
			bracket_func(stack, arr, arr_size, answer, i, j);
	}
	// когда нам встретилась закрывающая скобка, вынемаем все из стэка до открывающей
	while (top(stack) != '(')
	{
		answer[*j] = pop(stack);
		(*j)++;
	}
	if (top(stack) == '(')
		if (stack->curr != 0)
			pop(stack);
	return (*i)++;
}

// вынемаем все из стэка кроме скобок
int end_func(Stk* stack, char* answer, int* j)
{
	while (stack->curr != 0)
	{
		if (top(stack) == '(')
			pop(stack);
		else
		{
			answer[*j] = pop(stack);
			(*j)++;
		}
	}
}

// главная функция
int func(Stk* stack, char* arr, int arr_size, char* answer)
{
	int* i, *j;
	i = malloc(sizeof(int));
	j = malloc(sizeof(int));
	*i = 0;
	*j = 0;
	while (*i < arr_size)
	{
		// если встретилось число запускаем функцию
		if ((arr[*i] >= '0' && arr[*i] <= '9') || (arr[*i] >= 'a' && arr[*i] <= 'z'))
			number_func(arr, answer, i, j);
		// если встретилась снова открывающая скобка
		else if (arr[*i] == '(')
			bracket_func(stack, arr, arr_size, answer, i, j);
		// если встретилось умножить или делить
		else if (arr[*i] == '*' || arr[*i] == '/')
			mult_div_func(stack, arr, arr_size, answer, i, j, 0);
		// если встретился плюс или минус
		else if (arr[*i] == '+' || arr[*i] == '-')
			plus_minus_func(stack, arr, arr_size, answer, i, j, 0);
		else if (arr[*i] == '^')
			exponent_func(stack, arr, arr_size, answer, i, j, 0);
	}
	end_func(stack, answer, j);
	free(i);
	free(j);
	return *j;
}
