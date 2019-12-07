#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
	int grade[] = { 1,2,3,4,5,6 };
	int i = 9;
	char c = 'a';

	int size1 = sizeof(grade) / sizeof(grade[0]);
	
	printf("주소\t  값\t사이즈\n");
	for (int i = 0; i < size1; i++)
		printf("%p: grade[%d] : %d\n", &grade[i], i, grade[i]); //%p: 16진수 (주소값: 16진수)

	printf("%p: %8d %3d\n ", &i, i, sizeof(i));
	printf("%p: grade: %4d\n", &grade, sizeof(grade));
}