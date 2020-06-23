#include "input_graph.h"
#include <stdlib.h>
#include <stdio.h>

int input_graph(int graph_size, int* arr)
{
	int i, j, idx=0;
	printf("Enter the adjacency table.\n");
	for (i = 0; i < graph_size; i++)
	{
		for (j = 0; j < graph_size; j++)
		{
			idx = (i * graph_size + j);
			// проверяем на правильность ввода матрицу смежности
			if ((scanf_s("%d", &arr[idx]) == 0) || (arr[idx] != 1) && (arr[idx] != 0))
			{
				printf("Error symbol");
				return 0;
			}

		}
	}
}
