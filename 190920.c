#include <stdio.h>
#include <Windows.h>
#include <math.h>

#define SIZE 1000

int Get_string(char str[], int size)
{
	int i, j = 0;
	char c;

	for (int i = 0; i < size; i++)
	{
		scanf("%c", &c);
		if (c == '\n') break;
		else {
			str[i] = c;
			j++;
		}
	}

	return j;
}
int Get_number(char str[], int size)
{
	int j = 0;
	char c;

	for (int i = 0; i < size; i++)
	{
		scanf("%c", &c);
		if (c == '\n') break;
		if (c >= '0'&&c <= '9') {
			str[i] = c;
			j++;
		}
	}
	
	return j;
}
int strint(char str[], int size)
{
	int n, result=0;

	for (int i = 0; i < size; i++)
	{
		n = str[i] - '0';
		for (int k = 0; k<size-1-i; k++)
			n *= 10;
		printf("str[%d]= %c => %d\n", i, str[i], n);
		result += n;
	}

	return result;
}


int main_input() {
	char str[SIZE] = "";
	int size, num;

	printf("입력: ");
	size = Get_string(str, SIZE);
	printf("입력된 문자열: %s (%d글자)\n", str, size);

	num = strint(str, size);
	printf("숫자 : %d\n", num);

	return 0;
}



