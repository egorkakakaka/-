#include "answer_check.h"
#include <stdio.h>
int answer_check(int* arr, int* arr_2, int current, int graph_size, int last, int start, int* result)
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
			*result += 1;
			return 1;
		}
		// если в матрице единиться а столбец не равен исходному, меняем строку и вызываем на проверку данную вершину
		if (arr[idx] && i != last)
		{
			// присваеваем прошлую вершину и вызываем функцию с новой вершиной
			last = current; 
			if (answer_check(arr, arr_2, i, graph_size, last, start, result))
				return 0;
		}
	}

	return 0;
}
