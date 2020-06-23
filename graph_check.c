#include "graph_check.h"
int graph_check(int* arr, int graph_size)
{
	int i, j, sum, idx;
	for (i = 0; i < graph_size; i++)
		for (j = 0; j < graph_size; j++)
		{
			idx = (i * graph_size + j);
			if (i == j && arr[idx] != 0)
			{
				printf("Error table, try again\n");
				input_graph(graph_size, arr);
				return graph_check(arr, graph_size);
			}	
			if(arr[idx] != arr[idx])
			{
				printf("Error table, try again\n");
				input_graph(graph_size, arr);
				return graph_check(arr, graph_size);
			}
		} 
	
}
