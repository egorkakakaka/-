#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

// ввод количества вершин графа и проверка
int input_size()
{
	int i = 0;
	int graph_size = 0;
	printf("How many vertices you have in your graph?\n");
	graph_size = getch();
	if (graph_size <= '0' || graph_size >= '9')
	{
		printf("%c\n", graph_size);
		printf("Error symbol\nTry again\n");
		return input_size();
	}
	printf("%c\n", graph_size);
	graph_size = graph_size - '0';
	return graph_size;
}

// проверка памяти
int memmory_check(int* arr, int graph_size)
{
	if (arr == NULL)
	{
		printf("Error memmory");
		printf("Try again\n");
		arr = (int*)malloc(sizeof(int) * graph_size * graph_size);
		return 0;
	}
}
