#include <stdio.h>

//2-6
int mainun() {
	int arr[500] = { 0 };
	int num;
	int count = 0;

	printf("���� �Է��ϼ���: ");
	scanf("%d", &num);
	
	
	for (int j = 1; j <= num; j++) {
		if (num%j == 0) {
			arr[count] = j;
			count++;
		}
	}
	printf("%d�� ����� ����: \n", num);
	for (int i = 0; i < count; i++)
		printf("%d ", arr[i]);
	printf("\n�� %d���� ����� �ֽ��ϴ�.\n", count);
}