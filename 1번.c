#include <stdio.h>
#define N 10

int main1() {
	int i, j, k = 0;
	int num[N] = { 0 };

	while (1) {
		printf(" %d-input: ", k); scanf("%d", &i);

		if (i % 10 == 0) continue;

		num[k] = i;
		for (j = 0; j < i; j++) {
			if (j % 2 == 0) break;
			else printf("*");
		}
		k++;

		for (j = 0; j < 10; j++)
			printf("%d ", num[j]);
		printf("\n######################\n");
	}
}