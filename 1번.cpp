#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int randomNumber(int max)
{
	double num;
	num = 1.00 + (rand() % max);
	return num;
}

void interpolation(double(*arr)[3], int, int);


int main()
{
	double arr[3][3];

	srand(time(NULL));

	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arr[i][j] = randomNumber(100);
			printf("%.2lf\t", arr[i][j]);
		}
		printf("\n");
	}

	printf("\nThe Array After Interpolation1\n");
	interpolation(arr, 5, 5);

	return 0;
}

void interpolation(double (*arr)[3], int, int)
{
	double ary[5][5];
	int i, j;
	

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j % 2 == 0 && i % 2 == 0) {
				printf("%.2lf\t", arr[i/2][j/2]);
				if (j % 5 == 4) printf("\n");
			}


			else if (i % 2 == 0 && j % 2 == 1)
				printf("%.2lf\t", (arr[i/2][j/2] + arr[i/2][j/2 + 1]) / 2);

			else if (i % 2 == 1 && j % 2 == 0) {
				printf("%.2lf\t", (arr[i / 2][j / 2] + arr[i / 2 + 1][j / 2]) / 2);
				if (j % 5 == 4) printf("\n");
			}

			else if (i % 2 == 1 && j % 2 == 1)
				printf("%.2lf\t", (arr[i / 2][j / 2] + arr[i / 2][j / 2 + 1] + arr[i / 2 + 1][j / 2 + 1] + arr[i / 2 + 1][j / 2]) / 4);
		}
		printf("\n");
	}
}
