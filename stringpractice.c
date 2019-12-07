#include <stdio.h>
#define N 100

int mainst() {
	char str[N], str1[N], str2[N], str3[N], str4[N];
	int i = 0;
	int j = 0;
	int ogn = 0;

	printf("문자열을 입력하세요: ");
	scanf("%s", str);

	printf("target 문자열: "); scanf("%s", str1);
	printf("대체할 문자열: "); scanf("%s", str2);

	while (str[ogn]) ogn++;
	while (str1[i]) i++;
	while (str2[j]) j++;

	for (int k = 0; k < ogn - i - j; k++)printf("%c", str[k]);
	printf("%s", str2);
	
}