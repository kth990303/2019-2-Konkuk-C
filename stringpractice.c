#include <stdio.h>
#define N 100

int mainst() {
	char str[N], str1[N], str2[N], str3[N], str4[N];
	int i = 0;
	int j = 0;
	int ogn = 0;

	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%s", str);

	printf("target ���ڿ�: "); scanf("%s", str1);
	printf("��ü�� ���ڿ�: "); scanf("%s", str2);

	while (str[ogn]) ogn++;
	while (str1[i]) i++;
	while (str2[j]) j++;

	for (int k = 0; k < ogn - i - j; k++)printf("%c", str[k]);
	printf("%s", str2);
	
}