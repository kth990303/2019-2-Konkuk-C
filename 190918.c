#include <stdio.h>
#include <Windows.h>
#include <math.h>

int add(int i, int j)
{
	int result = i+j;
	return result;
}

int minus(int i, int j)
{
	int Result = i - j;
	return Result;
}

void Mult(int i, int j)
{
	printf("%d x %d = %d\n", i, j, i*j);
}

void Nanu(int i, int j)
{
	printf("%d / %d = %lf\n", i, j, (double) i/j);

	if (i == 0)
		printf("0은 어떤 값으로 나눌 수 없습니다.\n");
}

void 메뉴보이기()
{
	printf("####################################\n");
	printf("1. 더하기 \n");
	printf("2. 빼기 \n");
	printf("3. 곱하기 \n");
	printf("4. 나누기 \n");
	printf("0. 그만하기 \n");
	printf("####################################\n\n");
}

int main_계산()
{
	int i, j, menu;
	char c;

	메뉴보이기();

	while (1) {
		printf("메뉴를 입력하세요: ");
		scanf("%d", &menu);

		if (menu == 0)
			break;

		printf("두 개의 정수를 입력하세요: ");
		scanf("%d %d", &i, &j);

		//printf("연산자 +, -, *, / 중 하나를 입력하세요: ");
		//scanf(" %c", &c);

		switch (menu)
		{
		case 1:
			printf("%d + %d = %d\n", i, j, add(i, j));
			break;
		case 2:
			printf("%d - %d = %d\n", i, j, minus(i, j));
			break;
		case 3:
			Mult(i, j);
			break;
		case 4:
			Nanu(i, j);
			break;
		case 0:
			return -1;
			break;
		default:
			printf("올바르지 않은 연산자를 입력하셨습니다.\n");
			break;
		}
		printf("\n####################################\n\n");
	}
}


/*
int main() {
	int i = 0;
	int 일의자리, 십의자리 = 0;

	while (1) {
		printf("%d: ", i);

		일의자리 = i % 10;
		십의자리 = i / 10;

		if (일의자리 != 0 && 일의자리 % 3 == 0) {
			if (십의자리 != 0 && 십의자리 % 3 == 0)
				printf("짝");
			printf("짝!\n");
		}

		if (십의자리 != 0 && 십의자리 % 3 == 0 && 일의자리 % 3 != 0)
			printf("짝! ");
			
		i++;

		Sleep(200);
	}
}
*/

/*
int main()
{
	char c;
	int j;

	printf("문자열을 입력하세요: ");
	scanf(" %c", &c);

	if (c == 'a')
		j = 1;
	else
		j = 0;

	printf("c: %c, a= %d", c, j);
}
*/