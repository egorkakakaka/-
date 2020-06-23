#include "memmory_check.h"
#include <stdio.h>
#include <stdlib.h>
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
