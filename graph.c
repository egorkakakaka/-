#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

// проверка грфа на правильность структуры(на главной диагонали нет единиц, таблица симметричная)
int graph_check(int* arr, int graph_size)
{
	int i, j, sum, idx;
	for (i = 0; i < graph_size; i++)
		for (j = 0; j < graph_size; j++)
		{
			idx = (i * graph_size + j);
			// если на главной диагонали единица
			if (i == j && arr[idx] != 0)
			{
				printf("Error table, try again\n");
				input_graph(graph_size, arr);
				return graph_check(arr, graph_size);
			}
			// если таблица не симметричная
			if (arr[idx] != arr[j * graph_size + i])
			{
				printf("Error table, try again\n");
				input_graph(graph_size, arr);
				return graph_check(arr, graph_size);
			}
		}

}

//ввод графа и проверка символов в матрице смежности
int input_graph(int graph_size, int* arr)
{
	int i, j, idx = 0;
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

int answer_check(int* arr, int* arr_2, int current, int graph_size, int last, int start)
{
	int idx;
	// меняем столбцы
	for (int i = start; i < graph_size; i++)
	{
		arr_2[current] += 1;
		idx = (i * graph_size + current);
		// если текущая вершина не начальная, предыдущая першина не равна стартовой, текущий столбец равен начальному и стоит единица
		if (current != start && last != start && (i == start && arr[idx]))
		{
			return 1;
		}
		// если в матрице единиться а столбец не равен предыдущму, то меняем строку и вызываем на проверку данную вершину
		if (arr[idx] && i != last)
		{
			// присваеваем прошлую вершину и вызываем функцию с новой вершиной
			last = current;
			return answer_check(arr, arr_2, i, graph_size, last, start);
		}
	}

	return 0;
}
