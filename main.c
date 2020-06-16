// Лабараторная работа по графам
// Работу выполнил Парамонов Егор Сергеевич ИВТ13-БО
// На вход поступает матрица смежности, программа проверяет есть ли в данном графе циклы или их нет
#include <stdio.h>
#include <stdlib.h>
#include "proverka.h"

int main()
{
	int i, j, graph_size;
	int* arr;
	printf("How many vertices you have in your graph?");
	printf("\n");
	// количество вершин графа
	if(scanf_s("%d", &graph_size)!=1)
	{
		printf("Error symbol");
		return 0;
	}
	// выделяем память под массив
	arr = malloc(sizeof(int) * graph_size * graph_size); 
	if (arr == NULL)
	{
		printf("Error memmory");
		return 0;
	}
	printf("Enter the adjacency table.");
	printf("\n");
	int start = 0;
	for (i = 0; i < graph_size; i++) // ввод смежной матрицы
		for (j = 0; j < graph_size; j++)
	// проверяем на правильность ввода матрицу смежности
			if((scanf_s("%d", (arr + i * graph_size + j))!=1) || (*(arr + i * graph_size + j))!=1 || (*(arr + i * graph_size + j)) != 1)
			{
				printf("Error symbol");
				return 0;
			}
	int result = proverka(arr, 0, graph_size, 0, 0); // если вернется 1 то значит петля есть если 0 то петли нет
	if (result)
		printf("Yes");
	else
		printf("No");

	free(arr);
	return 0;
}
