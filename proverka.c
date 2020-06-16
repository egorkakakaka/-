#include "proverka.h"
int proverka(int* arr, int current, int graph_size, int last, int start)
{
    // меняем столбцы
	for (int i = 0; i < graph_size; i++) 
	{
		// если текущая вершина не начальная, предыдущая першина не равна стартовой, текущий столбец равен начальному и стоит единица
		if (current != start && last != start && (i == start && *(arr + current * graph_size + i)))
			return 1;
		// если в матрице единиться а столбец не равен исходному, меняем строку и вызываем на проверку данную вершину
		if (*(arr + current * graph_size + i) && i != last)
		{
			// присваеваем прошлую вершину и вызываем функцию с новой вершиной
			last = current; 
			if (proverka(arr, i, graph_size, last, 0))
				return 1;
		}
	}

	return 0;
}
