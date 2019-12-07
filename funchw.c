#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastruct.h"

void makeROW(Person2 ***p_addr, int size1) {
	int i;
	Person2 *p = *p_addr;
	*p_addr = (Person2 **)malloc(sizeof(Person2*)*size1);
	if (p_addr == NULL) {
		printf("�ǹ��� �� ����(���� �Ҵ�)�� �����߾��\n");
		exit(1);
	}
	else
		printf("�� �ǹ��� %d��: (%d bytes) \n",size1, _msize(*p_addr));
}

void makeCOL(Person2 ***p_addr, int size1) {
	int i,j=0;
	int *q = (int *)malloc(sizeof(int)*size1);
	Person2 *p = *p_addr;

	for (i = 0; i < size1; i++) {
		printf("%d���� �� ȣ���� �����Ͻðڽ��ϱ�? ", i + 1); scanf("%d", q + i);
		*(*(p_addr)+i) = (Person2 **)malloc(sizeof(Person2)*(*(q + i)));

		if (p_addr + i == NULL) {
			printf("�ǹ��� ȣ�� ����(���� �Ҵ�)�� �����߾��\n");
			exit(1);
		}
		else
			printf("%d���� �Ҵ�� ĭ: %d bytes \n", i + 1, _msize(*(*(p_addr)+i)));
			//printf("%d\n", _msize(*(*(p_addr)+i))/sizeof(Person2));
	}
	free(q);
	q = NULL;
}

//Person2 **makeRow2(int size1) {
//	Person2 **p = (Person2 **)malloc(sizeof(Person2*)*size1);
//	return p;
//} 
// ���� �������� �ּҸ� �Ѱܹ��� ������ �Լ� �������� ����� ���� ��ȭ�� �Ͼ�� ���� ���� ������ ����.
// Call-by-value
// ���� ���� �������� �ּ�(Call-by-reference)�� �Ѱܹ޾ƾ� �ż� ***p�� ���� (p_address: p_addr)

void ShowRoom(Person2 ***p_addr, int size1) {
	printf("==========================================\n");
	int i, j;
	
	for (i = 0; i < size1; i++) {
		printf("%d��: ", i + 1);
		for (j = 0; j < _msize(*(*(p_addr)+i)) / sizeof(Person2); j++) {
			printf("��");
		}
		printf("\n");
	}
}

//void inputinfo(Person2 **p, Person2 ***p_addr, int size1) {
//	int i, j, len1, len2 = 0;
//	char *name = (char *)calloc("", sizeof(char)*50);
//	char *phone = (char *)calloc("", sizeof(char)*50);
//
//	printf("==========================================\n");
//	printf("�� ���� �����Ͻðڽ��ϱ�? "); scanf("%d", &i);
//	printf("�� ȣ�� �����Ͻðڽ��ϱ�? "); scanf("%d", &j);
//	if (i > size1 || j>_msize(*(*(p_addr)+(i-1))) / sizeof(Person2) || i <= 0 || j <= 0) {
//		printf("�ùٸ� ������ �Է��ؾ� ���� �����մϴ�.\n");
//		exit(1);
//	}
//
//	printf("���� �Է��� �����մϴ�.\n");
//	printf("�̸�: "); scanf("%s", name);
//	if (strlen(name) > 50) {
//		realloc(name, strlen(name)-50+1);
//	}
//	p[i-1][j-1].name = name;
//	printf("����: "); scanf("%d", &(p[i-1][j-1].age));
//	printf("��ȭ��ȣ: "); scanf("%s", phone);
//	if (strlen(phone) > 50) {
//		realloc(phone, strlen(phone) - 50 + 1); 
//	}
//	p[i-1][j-1].phone = phone;
//
//	if (name == NULL || phone == NULL) {
//		printf("���� ����! (�Ҵ� ����)\n");
//		exit(1);
//	}
//	else printf("���� �Ϸ�!\n");
//	printf("==========================================\n");
//	printf("%d0%dȣ ����: \n", i, j);
//	printf("�̸� : %s\n����: %d��\n��ȭ��ȣ: %s \n ", p[i-1][j-1].name, p[i-1][j-1].age, p[i-1][j-1].phone);
//
//	free(name);
//	free(phone);
//}

int main() {
	int size1 = 0, size2 = 0, i;
	int row, col;
	int k = 0;
	//Person2 *p = NULL;; // 1�� n�� => n��.
	
	Person2 **p = NULL; // n�� n�� => n���� n�� ���´�. �ּҸ� �� �� �����ؾ� Person2.
	printf("==========================================\n");
	printf("������    �ּ�  \t��     Ÿ��\n");
	printf("  p    %p    %p   Person2 **\n", &p, p);
	printf("==========================================\n");

	printf("�� ���Դϱ�? "); scanf("%d", &size1);

	
	printf("\n");
	makeROW(&p, size1);
	printf("==========================================\n");
	printf("������    �ּ�  \t��     Ÿ��\n");
	printf("  p    %p    %p   Person2 **\n", &p, p);
	printf("==========================================\n");
	makeCOL(&p, size1);
	ShowRoom(&p, size1);
	/*inputinfo(p, &p, size1);*/
	free(p);
	p = NULL;
}