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
	p = (Person2 **)malloc(sizeof(Person2*)*size1); //층

	printf("이 건물은 %d층입니다. \n", size1);
	for (j = 0; j < size1; j++) {
		printf("%d층은 몇 호실까지 배정하시겠습니까?\n", j + 1); scanf("%d", r + j);

		**p_addr = (Person2*)malloc(sizeof(Person2)*(*(r+j))); //호실
	}

}



int main123() {
	int size1 = 0, size2 = 0, i;

	Person2 **p = NULL; // n행 n열 => n명이 n줄 들어온다. 주소를 두 번 참조해야 Person2.

	printf("몇 층입니까? "); scanf("%d", &size1);
	make(&p, size1);
}