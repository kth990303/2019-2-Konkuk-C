#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
	int grade[] = { 1,2,3,4,5,6 };
	int i = 9;
	char c = 'a';

	int size1 = sizeof(grade) / sizeof(grade[0]);
	
	printf("�ּ�\t  ��\t������\n");
	for (int i = 0; i < size1; i++)
		printf("%p: grade[%d] : %d\n", &grade[i], i, grade[i]); //%p: 16���� (�ּҰ�: 16����)

	printf("%p: %8d %3d\n ", &i, i, sizeof(i));
	printf("%p: grade: %4d\n", &grade, sizeof(grade));
}