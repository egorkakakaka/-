// Лабараторная работа по графам
// Работу выполнил Парамонов Егор Сергеевич ИВТ13-БО
// На вход поступает матрица сежности, программа проверяет есть ли в данном графе циклы или их нет
#include <stdio.h>
#include <stdlib.h>
#include "proverka.h"

int main()
{
	int i, j, s;
	int* a;
	printf("How many vertices you have in your graph?");
	printf("\n");
	scanf_s("%d", &s); // количество вершин графа
	a = malloc(sizeof(int) * s * s); // выделяем память
	printf("Enter the adjacency table.");
	printf("\n");
	int start = 0;
	for (i = 0; i < s; i++) // ввод смежной матрицы
		for (j = 0; j < s; j++)
			scanf_s("%d", (a + i * s + j));
	int result = proverka(a, 0, s, 0, 0); // если вернется 1 то значит петля есть если 0 то петли нет
	if (result)
		printf("Yes");
	else
		printf("No");

	free(a);
	return 0;
}