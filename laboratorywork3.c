// Лабораторная работа по теме Стэк и Очередь
// Выполнил Параонов Егор Сергеевич ИВТ13-БО
#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 40

typedef struct Stack
{
	char data[STACK_MAX_SIZE];
	int curr;
} Stk;

void start(Stk* stack)
{
	stack->curr = 0;
}

void push(Stk* stack, char symbol, int arr_size)
{
	if (stack->curr >= arr_size)
	{
		printf("Error of nomber counts");
		exit(0);
	}
	stack->data[stack->curr] = symbol;
	stack->curr++;
}

int pop(Stk* stack)
{
	if (stack->curr == 0)
	{
		printf("Error of nomber counts");
		exit(0);
	}
	stack->curr--;
	return stack->data[stack->curr];
}

int top(Stk* stack)
{
	if (stack->curr == 0)
		return stack->data[stack->curr];
	else
		return stack->data[stack->curr-1];
}

int main()
{
	int i = 0, arr_size, j = 0;
	char arr[40];
	char answer[40];
	int check=0;
	Stk* stack = NULL;
	printf("How many symbols you wont?");
	printf("\n");
	// количество символов в массиве
	scanf_s("%d", &arr_size);
	/*arr = malloc(sizeof(char) * 100);*/
	stack = malloc(sizeof(Stk));
	if (stack == NULL)
	{
		printf("Error memmory");
		return 0;
	}
	/*if (arr == NULL)
	{
		printf("Error memmory");
		return 0;
	}*/
	printf("Enter %d symbols", arr_size);
	printf("\n");
	while (i < arr_size)
	{
		arr[i] = getchar();
		if (arr[i] != ' ' && arr[i] != '\n')
			i++;
	}
	start(stack);
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == '(' || arr[i] == ')' || arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-' || (arr[i] >= '0' && arr[i] <= '9'))
			check = 1;
		else
		{
			printf("Error symbol");
			return 1;
		}
	}
	if (check == 1)
		printf("All is ok\n");
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			answer[j] = arr[i];
			j++;
		}
		else if (arr[i] == '(')
		{
			push(stack, arr[i], arr_size);
			while (arr[i] != ')')
			{
				if (arr[i] >= '0' && arr[i] <= '9')
				{
					answer[j] = arr[i];
					j++;
					i++;
				}
				else if ((arr[i] == '+' || arr[i] == '-') && (top(stack) == '*' || top(stack) == '/'))
				{
					while (top(stack) != '(')
					{
						answer[j] = top(stack);
						stack->curr--;
						j++;
					}
					push(stack, arr[i], arr_size);
					i++;
				}
				else if ((arr[i] == '+' || arr[i] == '-') && (top(stack) != '*' || top(stack) != '/'))
				{
					push(stack, arr[i], arr_size);
					i++;
				}
				else if ((arr[i] == '*' || arr[i] == '/') && (top(stack) == '*' || top(stack) == '/'))
				{
					answer[j] = pop(stack);
					j++;
				}
				else if ((arr[i] == '*' || arr[i] == '/') && (top(stack) != '*' && top(stack) != '/'))
				{
					push(stack, arr[i], arr_size);
					i++;
				}
				else if (arr[i] == '(')
					i++;
			}
			while (top(stack) != '(')
			{
				answer[j] = top(stack);
				stack->curr--;
				j++;
			}
			if (top(stack) == '(')
					if (stack->curr != 0)
						stack->curr--;
		}
		else if ((arr[i] == '*' || arr[i] == '/') && (top(stack) == '*' || top(stack) == '/'))
		{
			answer[j] = pop(stack);
			j++;
			push(stack, arr[i], arr_size);
		}
		else if ((arr[i] == '*' || arr[i] == '/') && (top(stack) != '*' && top(stack) != '/'))
		{
			push(stack, arr[i], arr_size);
		}
		else if (arr[i] == '+' || arr[i] == '-')
		{
			push(stack, arr[i], arr_size);
		}
	}
	while (stack->curr != 0)
	{
		if (top(stack) == '(')
			pop(stack);
		else
		{
			answer[j] = pop(stack);
			j++;
		}
	}
	for (i = 0; i < arr_size; i++)
	{
		if ( answer[i] == '*' || answer[i] == '/' || answer[i] == '+' || answer[i] == '-' || (answer[i] >= '0' && answer[i] <= '9'))
		{
			printf("%c", answer[i]);
		}
	}
	/*free(arr);*/
	free(stack);
	return 0;
}
