// Лабораторная работа по теме Стэк и Очередь
// Выполнил Парамонов Егор Сергеевич ИВТ13-БО
// Программа переводит выражение в обратную польскую запись
#include <stdio.h>
#include <stdlib.h>
#include "stk.h"
#include "utl.h"
#include "func.h"

int main()
{
	int i = 0, arr_size=0, j = 0;
	char arr[40];
	char answer[40];
	Stk* stack = NULL;
	// количество символов в массиве
	arr_size = input_size();
	stack = malloc(sizeof(Stk));
	memmory_check(stack);
	input_str(arr_size, arr);
	start(stack);
	func(stack, arr, arr_size, answer);
	output(answer, arr_size);
	free(stack);
	return 0;
}
