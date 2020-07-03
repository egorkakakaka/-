// Лабораторная работа по теме Массивы 
// Выполнил Параонов Егор Сергеевич ИВТ13-БО
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* num, int left, int right)
{
	int p; // первый элемент
	int l = left; // левая граница
	int r = right; // правая граница
	p = num[left]; // присваиваем первый элемент
	while (left < right)
	{
		while (num[right] >= p && left < right)
			right--; // сдвигаем пока r больше p
		if (left != right) // если границы не равны
		{
			num[left] = num[right]; // r ставим вместо 
			left++; // сдвигаем l вправо
		}
		while (num[left] <= p && left < right)
			left++; // сдвигаем l
		if (left != right) // если границы не равны
		{
			num[right] = num[left]; // снова меняем местами
			right--; // сдвигаем r
		}
	}
	num[left] = p; // возвращаем l 
	p = left;
	left = l;
	right = r;
	if (left < p) // рекурсия для левой части
		QuickSort(num, left, p - 1);
	if (right > p) // рекурсия для правой части
		QuickSort(num, p + 1, right);
}
int main()
{
	int i, arr_size;
	int* arr = NULL;
	printf("How many numbers you wont?");
	printf("\n");
	// количество символов в массиве
	if (scanf_s("%d", &arr_size) != 1)
	{
		printf("Error symbol");
		return 0;
	}
	arr = malloc(sizeof(int) * arr_size); // выделяем память
	if (arr == NULL)
	{
		printf("Error memmory");
		return 0;
	}
	printf("Enter %d numbers", arr_size);
	printf("\n");
	for (i = 0; i < arr_size; i++)
		if(scanf_s("%d", &arr[i])!=1)
		{
			printf("Error symbol");
			return 0;
		}
	// сортировка
	QuickSort(arr, 0, arr_size - 1);
	for (i = 0; i < arr_size; i++) 
		printf("%4d ", arr[i]);
	free(arr);
	return 0;
}
