#include <stdio.h>
#define SIZE 16

int main3() {
	int input=0;
	int i = 1;
	int arr[SIZE] = { 0 };
	int num[SIZE] = { 0 };


		printf("수를 입력하세요: ");
		scanf("%d", &input);

		printf("16진수: %p\n", input);

		num[0] = input / 2; //printf("num[0]=%d ", num[0]);
		arr[0] = input % 2; //printf("arr[0]=%d \n", arr[0]);

		while (1) {
			num[i] = num[i - 1] / 2; //printf("num[%d]=%d ", i, num[i]);
			arr[i] = num[i - 1] % 2; //printf("arr[%d]=%d \n", i, arr[i]);
			if (num[i] == 1) {
				arr[i + 1] = num[i];
				//printf("\tarr[%d]=%d \n", i + 1, arr[i + 1]);
				i++;
				break;
			}
			i++;
		}
		//printf("자릿수: %d\n", i+1);
		for (int j = i + 1; j < SIZE; j++) // 자릿수 이상의 숫자는 0
			arr[j] = 0;

		printf("2진수:  ");
		for (int k = SIZE - 1; k >= 0; k--)
		{
			printf("%d ", arr[k]);
		}
		printf("\n");
}