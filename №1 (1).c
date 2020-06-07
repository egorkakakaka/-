// ������������ ������ �� ���� ������� 
// �������� �������� ���� ��������� ���13-��
#include <stdio.h>
#include <stdlib.h>
void QuickSort(int* num, int lef, int rig)
{
	int p; // ������ �������
	int l = lef; // ����� �������
	int r = rig; // ������ �������
	p = num[lef]; // ����������� ������ �������
	while (lef < rig)
	{
		while ((num[rig] >= p) && (lef < rig))
		{
			rig--; // �������� ���� r ������ p
		}
		if (lef != rig) // ���� ������� �� �����
		{
			num[lef] = num[rig]; // r ������ ������ 
			lef++; // �������� l ������
		}
		while ((num[lef] <= p) && (lef < rig))
		{
			lef++; // �������� l
		}
		if (lef != rig) // ���� ������� �� �����
		{
			num[rig] = num[lef]; // ����� ������ �������
			rig--; // �������� r
		}
	}
	num[lef] = p; // ���������� l 
	p = lef;
	lef = l;
	rig = r;
	if (lef < p) // �������� ��� ����� �����
		QuickSort(num, lef, p - 1);
	if (rig > p) // �������� ��� ������ �����
		QuickSort(num, p + 1, rig);
}
int main()
{
	int i, S;
	int *a;
	printf("How many numbers you wont?");
	printf("\n");
	scanf_s("%d", &S); // ���������� �������� � �������
	a = malloc(sizeof(int)*S); // �������� ������
	printf("Enter %d numbers", S);
	printf("\n");
	for (i = 0; i < S; i++)
		scanf_s("%d", &a[i]); // ����
	QuickSort(a, 0, S - 1); // ����������
	for ( i = 0; i < S; i++) // �����
		printf("%4d ", a[i]);
	free(a);
	return 0;
}