#pragma once
typedef struct Stack
{
	char data[40];
	int curr;
} Stk;
void start(Stk* stack);
void push(Stk* stack, char symbol, int arr_size);
int pop(Stk* stack);
int top(Stk* stack);
