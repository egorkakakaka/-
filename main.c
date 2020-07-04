// Лабораторная работа по теме Стэк и Очередь
// Выполнил Парамонов Егор Сергеевич ИВТ13-БО
// Программа переводит выражение в обратную польскую запись
#include <stdio.h>
#include <stdlib.h>
#include "stk.h"
#include "utl.h"
#include "reverse_polish_notation.h"

int main()
{
	int i = 0, j = 0;
	int arr_size=0;
	char* arr = NULL;
	char* answer = NULL;
	Stk* stack = NULL;
	// количество символов в массиве
	arr_size = input_size();
	stack = malloc(sizeof(Stk));
	arr = malloc(sizeof(char) * arr_size);
	answer = malloc(sizeof(char) * arr_size);
	memmory_check(stack);
	memmory_check(arr);
	memmory_check(answer);
	input_str(arr_size, arr);
	start(stack, arr_size);
	reverse_polish_notation(stack, arr, arr_size, answer);
	output(answer, arr_size);
	free(arr);
	free(answer);
	free(stack->data);
	free(stack);
	return 0;
}
