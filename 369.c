#include <stdio.h>

int main369() {
	for (int i = 1; i <= 100; i++)
	{
		if (i / 10 == 3 || i / 10 == 6 || i / 10 == 9)
		{
			if ((i % 10) == 3 || (i % 10) == 6 || (i % 10) == 9)
				printf(" ��¦!");
			else
				printf(" ¦!");
		}

		else if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9)
			printf(" ¦!");
		else
			printf("%4d ", i);

		if (i % 10 == 0)
			printf("\n");
	}
}