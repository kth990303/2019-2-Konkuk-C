#include <stdio.h>

int ddive(int num1, int num2)
{
	int result;
	
	if (num2 == 0) return 0;
	result= num1 / num2;
	return result;
}

int mmod(int num1, int num2)
{
	if (num2 == 0) return 0;
	int resultmmod = num1 % num2;
		return resultmmod;
}

int main_qz2() {
	int num1, num2;

	printf("정수 하나를 입력하세요: ");
	scanf("%d", &num1);

	printf("다른 정수를 입력하세요: ");
	scanf("%d", &num2);

	printf("#######################################\n");
	printf("첫 번째 입력한 정수를 두 번째 입력한 정수로 나누겠습니다.\n\n");

	printf("%d를 %d로 나눈 몫: %d\n", num1, num2, ddive(num1, num2));
	printf("%d를 %d로 나눈 나머지: %d\n", num1, num2, mmod(num1, num2));
}