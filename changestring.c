#include <stdio.h>
#define N 81
//2-5
//���� ã�� �Լ�
int search(char str[N], char str2[N], int len, int len2)
{
	int n = 0;
	int k = 0;
	int arr[N] = { 0 };
	for (int i = 0; i < len; i++) {
		if (str[i] == str2[n]) {
			n++;
		}
		if (n == len2) {
			arr[k] = i - len2 + 2;
			printf("%d��° ������ ã�ҽ��ϴ�.\n", arr[k]);
			n = n - len2;
			k++;
		}
	}
	return k;
}
//���ڹٲٱ� �Լ�
void changealphabet(char str[N], char str2[N], char str3[N], int len, int len2, int len3)
{
	int n = 0; int j = 0;
	int k = 0; int m = 0;
	int arr[N] = { 0 }; int arr2[N] = { 0 };
	char temp[N] = { "" };
	temp[N] = str[N];
	for (int i = 0; i < len; i++) {
		if (str[i] == str2[n]) {
			n++;
		}
		if (n == len2) {
			arr[k] = i - len2 + 2; //str[arr[k]-1]�������� str2 ����.
			n = n - len2; 
			k++;
		}
	}
	for (int i = 0; i < len; i++) {
		if (str[i] == str3[j]) {
			j++;
		}
		if (j == len3) {
			arr2[m] = i - len3 + 2;
			j = j - len3;
			m++;
		}
	}
	
	for (int i = 0; i < arr[0] - 1; i++) printf("%c", str[i]);
	printf("%s", str3);
	if (arr2[0] - 1 - arr[0]-len2 > 0) {
		for (int i = arr[0] - 1 + len2;; i++) {
			printf("%c", str[i]);
			if (i == arr2[0] - 2) break;
		}
	}	
	printf("%s", str2);
	if (len - arr2[0] + 1 - len3>0) {
		for (int i = arr2[0] - 1 + len3; i < len; i++) printf("%c", str[i]);
	}	
	printf("\n");
	}
int main() {
	char str1[N];
	char str2[N];
	char str3[N];
	int len = 0;
	int len2 = 0;
	int len3 = 0;
	int k;
	while (1) {
		printf("#######################################################\n");
		printf("1.���ڿ� ã�� 2.���ڿ� �ٲٱ� 0.����: ");
		scanf("%d", &k);
		if (k == 0) break;

		printf("���ڿ��� �Է��ϼ���: "); scanf("%s", str1);
		while (str1[len]) len++;
		
		if (k == 1) {
			printf("ã�� ���ڿ��� �Է��ϼ���: "); scanf("%s", str2);
			while (str2[len2]) len2++;
			printf("�� %d�� �߰�.\n", search(str1, str2, len, len2));
		}
		if (k == 2) {
			printf("���ڿ��� �����ϼ���: "); scanf("%s", str2);
			while (str2[len2]) len2++;
			printf("��ġ��ȯ�� ���ڿ��� �Է��ϼ���: "); scanf("%s", str3);
			while (str3[len3]) len3++;
			changealphabet(str1, str2, str3,len, len2, len3);
		}
	}
}