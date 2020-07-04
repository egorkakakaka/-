#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	char* data;
	int curr;
} Stk;

void start(Stk* stack, int arr_size);
void push(Stk* stack, char symbol, int arr_size);
int pop(Stk* stack);
int top(Stk* stack);
