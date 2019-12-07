#include <stdio.h>
#define ROW 3
#define COL 5
//2-1
int mainar() {
	int ar[ROW][COL];
	int k = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			ar[i][j] = k;
			k++;
		}
			
	}
	
	printf("===========================================\n");
	printf("     이름   주소\t값    type   size  \n");
	printf("===========================================\n");
	
	printf("      ar: %8p %d  int[3][5] %d\n", &ar, ar, sizeof(ar));
	printf("   ar[0]: %p %7d  int[5]    %d\n", &ar[0], ar[0], sizeof(ar[0]));
	for (int i = 0; i < COL;i++)
		printf("ar[0][%d]: %p %7d   int       %d\n", i,&ar[0][i], ar[0][i], sizeof(ar[0][i]));
	printf("   ar[1]: %p %7d  int[5]    %d\n", &ar[1], ar[1], sizeof(ar[1]));
	for (int i = 0; i < COL; i++)
		printf("ar[1][%d]: %p %7d   int       %d\n", i, &ar[1][i], ar[1][i], sizeof(ar[1][i]));
	printf("   ar[2]: %p %7d  int[5]    %d\n", &ar[2], ar[2], sizeof(ar[2]));
	for (int i = 0; i < COL; i++)
		printf("ar[2][%d]: %p %7d   int       %d\n", i, &ar[2][i], ar[2][i], sizeof(ar[2][i]));
}