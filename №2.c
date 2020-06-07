// ������������ ������ �� ������
// ������ �������� ��������� ���� ��������� ���13-��
// �� ���� ��������� ������� �������
#include <stdio.h>
#include <stdlib.h>
int put = 0; // ��������� �������
int start = 0; // ���������� �������


int proverka(int *a, int str, int S)
{

	for (int i = 0; i < S; i++) // �������� � ����� ������ � ����������, � ������ ������ �� ���� ��������
	{
		if (str != start && put != start && (i == start && (a + str * S + i)))
			return 1;
		if (*(a + str * S + i) && i != put)
		{
			put = str;
			if (proverka(a, i, S))
				return 1;
		}
	}

	return 0;
}
int main()
{
	int i, j, S;
	int* a;
	printf("How many vertices you have in your graph?");
	printf("\n");
	scanf_s("%d", &S); // ���������� ������ �����
	a = malloc(sizeof(int) * S * S); // �������� ������
	printf("Enter the adjacency table.");
	printf("\n");
	for (i = 0; i < S; i++) // ���� ������� �������
		for (j = 0; j < S; j++)
			scanf_s("%d", (a + i * S + j));
	proverka(a, 0, S); // ��������� ����������� �������
	int result = 0; // ���� �������� 1 �� ������ ����� ���� ���� 0 �� ����� ���
	i = 0;
	while (!result && i < S) // ������ ������
	{
		result = proverka(a, i, S);
		i++;
	}
	if (result)
		printf("Yes");
	else
		printf("No");

	free(a);
	return 0;
}