#include <stdio.h>


//�ֹε�Ϲ�ȣ �˻�

int main_ch() {
	char str[14] = { 0 };
	int sum = 0;
	int weight[12] = { 2,3,4,5,6,7,8,9,2,3,4,5 };


	printf("�ֹι�ȣ�� �Է��ϼ��� (-���� 13����): ");
	scanf("%s", str);
	
	for (int j = 0; j < 12; j++)
		sum += ((str[j] - '0') * weight[j]);

	int a = (11 - (sum % 11)) % 10;

	if (a == str[12]-'0')
		printf("Correct!");
	else
		printf("Wrong!");
}