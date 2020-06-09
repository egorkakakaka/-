// ������������ ������ �� ������
// ������ �������� ��������� ���� ��������� ���13-��
// �� ���� ��������� ������� ��������, ��������� ��������� ���� �� � ������ ����� ����� ��� �� ���
#include <stdio.h>
#include <stdlib.h>
#include "proverka.h"

int main()
{
	int i, j, s;
	int* a;
	printf("How many vertices you have in your graph?");
	printf("\n");
	scanf_s("%d", &s); // ���������� ������ �����
	a = malloc(sizeof(int) * s * s); // �������� ������
	printf("Enter the adjacency table.");
	printf("\n");
	int start = 0;
	for (i = 0; i < s; i++) // ���� ������� �������
		for (j = 0; j < s; j++)
			scanf_s("%d", (a + i * s + j));
	int result = proverka(a, 0, s, 0, 0); // ���� �������� 1 �� ������ ����� ���� ���� 0 �� ����� ���
	if (result)
		printf("Yes");
	else
		printf("No");

	free(a);
	return 0;
}