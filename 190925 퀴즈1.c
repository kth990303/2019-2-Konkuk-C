#include <stdio.h>

int main_qz1() {
	int num1, num2 = 0;

	printf("���� �ϳ��� �Է��ϼ���: ");
	scanf("%d", &num1);

	printf("�ٸ� ������ �Է��ϼ���: ");
	scanf("%d", &num2);

	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("############################\n\n");
	printf("%d %d \n", num1, num2);
}