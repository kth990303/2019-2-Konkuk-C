#include <stdio.h>
#define N 100
//2-3
int mainfr() {
	char str[N];
	int cnt[52] = { 0 };
	int len = 0;
	printf("문자열을 입력하세요: ");
	gets(str);
	puts(str);
	while (str[len]) len++;

	for (int i = 0; i < len; i++) {
		for (int j = 97; j < 123; j++) {
			if (str[i] == j) cnt[str[i] - 'a']++;
			else continue;
		}
	}

	printf("\n");
	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", i + 97, cnt[i]);
	}
	printf("\n");
}