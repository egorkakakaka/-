// Лабараторная работа по графам
// Работу выполнил Парамонов Егор Сергеевич ИВТ13-БО
// На вход поступает матрица смежности, программа проверяет есть ли в данном графе циклы или их нет
#include <stdio.h>
#include <stdlib.h>
#include "input_size.h"
#include "memmory_check.h"
#include "input_graph.h"
#include "graph_check.h"
#include "answer_check.h"

int main()
{
	int i, graph_size = 0, result = 0, start = 0;
	int* arr;
	int* arr_2;
	// количество вершин графа
	graph_size = input_size();
	// выделяем память под массив
	arr = (int*) malloc(sizeof(int) * graph_size * graph_size); 
	arr_2 = (int*) malloc(graph_size * sizeof(int));
	memmory_check(arr, graph_size);
	memmory_check(arr_2, graph_size);
	// ввод графа через таблицу смежности
	input_graph(graph_size, arr);
	// проверка на правильность ввода графа
	graph_check(arr, graph_size);
	// заполняем массив нулями, в котором будем помечать вершины, в которых мы уже были
	for (i = 0; i < graph_size; i++)
		arr_2[i] = 0;
	//запускаем проверку на циклы
	answer_check(arr, arr_2, 0, graph_size, 0, 0, &result);
	// если граф не связный то проверяем те вершины в которых мы еще не были
	for (i = 0; i < graph_size; i++)
		if (arr_2[i] == 0)
			answer_check(arr, arr_2, i, graph_size, 0, i, &result);
	if (result!=0)
		printf("Yes");
	else
		printf("No");
	free(arr);
	return 0;
}
