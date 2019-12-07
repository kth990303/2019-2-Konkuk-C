#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//2-4
//선택정렬
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
//버블정렬
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
		printf("arr[%d]: %d번 작업 ", i, count);
		if (i % 2 == 1) printf("\n");
	}
}
//순차탐색
int check1(int arr[20], int number) {
	//동일할 때
	for (int i = 0; i < 20; i++) {
		if (arr[i] == number) {
			printf("%d번째에서 동일한 값을 찾았습니다.\n", i + 1);
			return i + 1;
			break;
		}
		//다를 때
		if (i == 19) {
			for (int j = 0; j < 100; j++) {
				for (int k = 0; k < 20; k++) {
					if ((unsigned)(number - arr[k]) <= j||(unsigned)(arr[k]-number)<=j) {
						printf("가장 근접한 수는 %d입니다.\n", arr[k]);
						printf("오차는 %d입니다.\n", j);
						return k+1;
					}
				}
			}
		}
	}
}
//이진탐색
int check2(int arr[20], int number) {
	int max = 20;
	int min = 0;
	int mid;
	int count = 0;
	//동일할 때
	while (1) {
		mid = (max + min) / 2;
		if (arr[mid] == number) {
			printf("%d번째에서 동일한 값을 찾았습니다.\n", mid + 1);
			count++; return count;
		}
		else if (arr[mid] > number) { 
			max = (int)mid;
			count++;
			if (count == 4) {
				for (int j = 0; j < 100; j++) {
					for (int k = 0; k < 20; k++) {
						if ((unsigned)(number - arr[k]) <= j || (unsigned)(arr[k] - number) <= j) {
							printf("가장 근접한 수는 %d입니다.\n", arr[k]);
							printf("오차는 %d입니다.\n", j);
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
							printf("가장 근접한 수는 %d입니다.\n", arr[k]);
							printf("오차는 %d입니다.\n", j);
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
		//srand 중복되는 것 없이
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
		printf("현재 배열은 아래와 같습니다.\n");
		for (int i = 0; i < 20; i++)
			printf("%d ", arr[i]);
		printf("\n어떤 작업을 원하십니까?\n1. 선택정렬 2. 버블정렬: 3. 순차탐색 4. 이진탐색 0: 그만: ");
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
			printf("탐색할 수를 입력하세요: "); scanf("%d", &k);

			printf("탐색 횟수: %d\n", check1(arr, k));
		}
		if (n == 4) {
			bubble(arr);
			printf("\n\n");
			for (int i = 0; i < 20; i++)
				printf("%d ", arr[i]);
			printf("\n");
			printf("정렬된 함수에서 이진탐색을 시작합니다.\n");
			printf("탐색할 수를 입력하세요: "); scanf("%d", &k);
			printf("탐색 횟수: %d\n", check2(arr, k));
		}
	}
}