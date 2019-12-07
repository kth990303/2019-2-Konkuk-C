#include <stdio.h>
#include <stdlib.h>

#define N 6
#define RANGE 45
#define CHANCE 8
//�ζ� ���� ���ϱ�
void Lottonum(int arr1[]) {
	for (int i = 0; i < 6; i++)
		arr1[i] = 1 + (rand() % RANGE);
	for (int j = 0; j < 5; j++) {
		if (arr1[j] == arr1[j + 1])
			arr1[j + 1] += 1;
	}
}


int mainlotto() {
	int arr1[N] = { 0 };
	int arr2[N] = { 0 };
	int n = 0; int correct;

	srand((unsigned)time(NULL));
	Lottonum(arr1);

	while (1) {
		printf("%d��° �õ�\n", n+1);
		for (int i = 0; i < N; i++) {
			printf("%d��° ���� �Է����ּ���: ", i + 1);
			scanf("%d", &arr2[i]);

			if (arr2[i] > RANGE || arr2[i] < 0) {
				printf("������ �ʰ��Ͽ����ϴ�. ���� �õ��� �̵��մϴ�.\n");
				break;
			}			
		}
		correct = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr1[i] == arr2[j])
				{
					printf("o ");
					correct++;
					break;
				}
				else {
					if (j == N - 1) printf("x ");
				}
			}
		}
		n++;
		printf("\n####################################\n");

		if (n >= CHANCE) break;
	}

	
	switch (correct) {
	case 0:
		printf("�ƽ����� �ζ� ��÷�� �����߽��ϴ�.\n");
		break;
	case 1:
		printf("�ζ� 6� ��÷�ż̽��ϴ�!\n2������ ���� �� �ֽ��ϴ�.\n");
		break;
	case 2:
		printf("�ζ� 5� ��÷�ż̽��ϴ�!\n30������ ���� �� �ֽ��ϴ�.\n");
		break;
	case 3:
		printf("�ζ� 4� ��÷�ż̽��ϴ�!\n2�鸸���� ���� �� �ֽ��ϴ�.\n");
		break;
	case 4:
		printf("�ζ� 3� ��÷�ż̽��ϴ�!\n6õ������ ���� �� �ֽ��ϴ�.\n");
		break;
	case 5:
		printf("�ζ� 2� ��÷�ż̽��ϴ�!\n3���� ���� ���� �� �ֽ��ϴ�.\n");
		break;
	case 6:
		printf("�ζ� 1� ��÷�ż̽��ϴ�!\n18���� ���� ���� �� �ֽ��ϴ�.\n");
		break;
	}
}