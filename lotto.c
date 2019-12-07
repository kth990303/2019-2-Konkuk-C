#include <stdio.h>
#include <stdlib.h>

#define N 6
#define RANGE 45
#define CHANCE 8
//로또 숫자 정하기
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
		printf("%d번째 시도\n", n+1);
		for (int i = 0; i < N; i++) {
			printf("%d번째 수를 입력해주세요: ", i + 1);
			scanf("%d", &arr2[i]);

			if (arr2[i] > RANGE || arr2[i] < 0) {
				printf("범위를 초과하였습니다. 다음 시도로 이동합니다.\n");
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
		printf("아쉽지만 로또 당첨에 실패했습니다.\n");
		break;
	case 1:
		printf("로또 6등에 당첨돼셨습니다!\n2만원을 받을 수 있습니다.\n");
		break;
	case 2:
		printf("로또 5등에 당첨돼셨습니다!\n30만원을 받을 수 있습니다.\n");
		break;
	case 3:
		printf("로또 4등에 당첨돼셨습니다!\n2백만원을 받을 수 있습니다.\n");
		break;
	case 4:
		printf("로또 3등에 당첨돼셨습니다!\n6천만원을 받을 수 있습니다.\n");
		break;
	case 5:
		printf("로또 2등에 당첨돼셨습니다!\n3억의 돈을 받을 수 있습니다.\n");
		break;
	case 6:
		printf("로또 1등에 당첨돼셨습니다!\n18억의 돈을 받을 수 있습니다.\n");
		break;
	}
}