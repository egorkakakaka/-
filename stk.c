#include "stk.h"
#include <stdio.h>
#include <stdlib.h>
#include "utl.h"
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
		return stack->data[stack->curr - 1];
}
