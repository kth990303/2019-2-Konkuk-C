#include <stdio.h>
#include <stdlib.h>

typedef struct person2 {
	char *name;
	int age;
	char *phone;
} Person2;

void make(Person2 ***p_addr, int size1) {
	int i, j;
	int *r = (int *)malloc(sizeof(int)*size1);
	Person2 *p = *p_addr;
	p = (Person2 **)malloc(sizeof(Person2*)*size1); //��

	printf("�� �ǹ��� %d���Դϴ�. \n", size1);
	for (j = 0; j < size1; j++) {
		printf("%d���� �� ȣ�Ǳ��� �����Ͻðڽ��ϱ�?\n", j + 1); scanf("%d", r + j);

		**p_addr = (Person2*)malloc(sizeof(Person2)*(*(r+j))); //ȣ��
	}

}



int main123() {
	int size1 = 0, size2 = 0, i;

	Person2 **p = NULL; // n�� n�� => n���� n�� ���´�. �ּҸ� �� �� �����ؾ� Person2.

	printf("�� ���Դϱ�? "); scanf("%d", &size1);
	make(&p, size1);
}