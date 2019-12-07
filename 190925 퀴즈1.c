#include <stdio.h>

int main_qz1() {
	int num1, num2 = 0;

	printf("정수 하나를 입력하세요: ");
	scanf("%d", &num1);

	printf("다른 정수를 입력하세요: ");
	scanf("%d", &num2);

	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("############################\n\n");
	printf("%d %d \n", num1, num2);
}