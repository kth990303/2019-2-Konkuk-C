#include <stdio.h>

//2-6
int mainun() {
	int arr[500] = { 0 };
	int num;
	int count = 0;

	printf("수를 입력하세요: ");
	scanf("%d", &num);
	
	
	for (int j = 1; j <= num; j++) {
		if (num%j == 0) {
			arr[count] = j;
			count++;
		}
	}
	printf("%d의 약수의 갯수: \n", num);
	for (int i = 0; i < count; i++)
		printf("%d ", arr[i]);
	printf("\n총 %d개의 약수가 있습니다.\n", count);
}