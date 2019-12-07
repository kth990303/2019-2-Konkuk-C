#include <stdio.h>

#define SIZE 100

int Get_String(char *str, char *str1, int size)
{
	int i,j, count = 0;
	char c;

	for (i = 0; i < size; i++)
	{
		scanf("%c", &c);
		if (c == '\n') break;
		if (c < '9') {
			continue;
		}
		else {
			str1[count] = c;
			count++;
		}
	}

	str1[count] = '\0';
	return count;
}

int main_hw1()
{
	char str[SIZE];
	char str1[SIZE];

	printf("입력: ");
	int size=Get_String(str, str1, SIZE);
	printf("입력된 문자열: %s (%d)\n", str1, size);

	for (int k = 0; k < size; k++)
	{
		printf("%c = %d\n", str1[k], str1[k] - '0');
	}
}