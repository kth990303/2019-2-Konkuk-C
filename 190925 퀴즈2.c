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

	printf("���� �ϳ��� �Է��ϼ���: ");
	scanf("%d", &num1);

	printf("�ٸ� ������ �Է��ϼ���: ");
	scanf("%d", &num2);

	printf("#######################################\n");
	printf("ù ��° �Է��� ������ �� ��° �Է��� ������ �����ڽ��ϴ�.\n\n");

	printf("%d�� %d�� ���� ��: %d\n", num1, num2, ddive(num1, num2));
	printf("%d�� %d�� ���� ������: %d\n", num1, num2, mmod(num1, num2));
}