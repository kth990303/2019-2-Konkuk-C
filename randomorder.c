#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//2-4
//��������
void choice(int arr[20]) {
	int temp;
	int n;
	for (int k = 0; k < 20; k++) {
		n = k;
		for (int i = k+1; i < 20; i++)
		{
			if (arr[n] > arr[i]) {
				n = i;
			}
		}
		printf("arr[%d] <=> arr[%d]   ", k, n);
		if (k % 2 == 1) printf("\n");
		temp = arr[k];
		arr[k] = arr[n];
		arr[n] = temp;
	}
}
//��������
void bubble(int arr[20]) {
	for (int i = 0; i < 19; i++) {
		int count = 0;
		for (int j = 0; j < 19; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count++;
			}
		}
		printf("arr[%d]: %d�� �۾� ", i, count);
		if (i % 2 == 1) printf("\n");
	}
}
//����Ž��
int check1(int arr[20], int number) {
	//������ ��
	for (int i = 0; i < 20; i++) {
		if (arr[i] == number) {
			printf("%d��°���� ������ ���� ã�ҽ��ϴ�.\n", i + 1);
			return i + 1;
			break;
		}
		//�ٸ� ��
		if (i == 19) {
			for (int j = 0; j < 100; j++) {
				for (int k = 0; k < 20; k++) {
					if ((unsigned)(number - arr[k]) <= j||(unsigned)(arr[k]-number)<=j) {
						printf("���� ������ ���� %d�Դϴ�.\n", arr[k]);
						printf("������ %d�Դϴ�.\n", j);
						return k+1;
					}
				}
			}
		}
	}
}
//����Ž��
int check2(int arr[20], int number) {
	int max = 20;
	int min = 0;
	int mid;
	int count = 0;
	//������ ��
	while (1) {
		mid = (max + min) / 2;
		if (arr[mid] == number) {
			printf("%d��°���� ������ ���� ã�ҽ��ϴ�.\n", mid + 1);
			count++; return count;
		}
		else if (arr[mid] > number) { 
			max = (int)mid;
			count++;
			if (count == 4) {
				for (int j = 0; j < 100; j++) {
					for (int k = 0; k < 20; k++) {
						if ((unsigned)(number - arr[k]) <= j || (unsigned)(arr[k] - number) <= j) {
							printf("���� ������ ���� %d�Դϴ�.\n", arr[k]);
							printf("������ %d�Դϴ�.\n", j);
							return count + 1;
						}
					}
				}
			}
		}
		else if(arr[mid]<number) {
			min = (int)mid; 
			count++;
			if (count == 4) {
				for (int j = 0; j < 100; j++) {
					for (int k = 0; k < 20; k++) {
						if ((unsigned)(number - arr[k]) <= j || (unsigned)(arr[k] - number) <= j) {
							printf("���� ������ ���� %d�Դϴ�.\n", arr[k]);
							printf("������ %d�Դϴ�.\n", j);
							return count + 1;
						}
					}
				}
			}
		}
	}	
}
int mainra() {
	int arr[20];
	int n = 0;
	int k;
	
	
	while (1) {
		srand((unsigned)time(NULL));
		//srand �ߺ��Ǵ� �� ����
		for (int i = 0; i < 20; i++) {
			int k = rand() % 99 + 1;
			int check = 0;
			for (int j = 0; j <= i; j++) {
				if (i == 0) break;
				if (arr[j] == k) {
					check = 1;
					break;
				}
			}
			if (check) i--;
			else arr[i] = k;
		}
		printf("##########################################################################\n");
		printf("���� �迭�� �Ʒ��� �����ϴ�.\n");
		for (int i = 0; i < 20; i++)
			printf("%d ", arr[i]);
		printf("\n� �۾��� ���Ͻʴϱ�?\n1. �������� 2. ��������: 3. ����Ž�� 4. ����Ž�� 0: �׸�: ");
		scanf("%d", &n);
		printf("\n");
		if (n == 0) return -1;

		if (n == 1) {
			choice(arr);
			for (int i = 0; i < 20; i++)
				printf("%d ", arr[i]);
			printf("\n");
		}
		if (n == 2) {
			bubble(arr);
			printf("\n");
			for (int i = 0; i < 20; i++)
				printf("%d ", arr[i]);
			printf("\n");
		}
		if (n == 3) {
			printf("Ž���� ���� �Է��ϼ���: "); scanf("%d", &k);

			printf("Ž�� Ƚ��: %d\n", check1(arr, k));
		}
		if (n == 4) {
			bubble(arr);
			printf("\n\n");
			for (int i = 0; i < 20; i++)
				printf("%d ", arr[i]);
			printf("\n");
			printf("���ĵ� �Լ����� ����Ž���� �����մϴ�.\n");
			printf("Ž���� ���� �Է��ϼ���: "); scanf("%d", &k);
			printf("Ž�� Ƚ��: %d\n", check2(arr, k));
		}
	}
}