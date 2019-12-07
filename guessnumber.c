#include <stdio.h>

int mainguess() {
	int num = 280;
	int input;
	char c;

	while (1) {
		printf("input: ");
		scanf("%d", &input);
		scanf("%c", &c);
		if (c >= 65)
			printf("숫자만 입력하세요~\n");
		else if (input == num) {
			printf("Correct!\n");
			break;
		}
		else if (input > num)
			printf("Answer is smaller than input!\n");
		else if (input < num)
			printf("Answer is bigger than input!\n");
	}
}