#include <stdio.h>
#include <Windows.h>
#include <math.h>

int add(int i, int j)
{
	int result = i+j;
	return result;
}

int minus(int i, int j)
{
	int Result = i - j;
	return Result;
}

void Mult(int i, int j)
{
	printf("%d x %d = %d\n", i, j, i*j);
}

void Nanu(int i, int j)
{
	printf("%d / %d = %lf\n", i, j, (double) i/j);

	if (i == 0)
		printf("0�� � ������ ���� �� �����ϴ�.\n");
}

void �޴����̱�()
{
	printf("####################################\n");
	printf("1. ���ϱ� \n");
	printf("2. ���� \n");
	printf("3. ���ϱ� \n");
	printf("4. ������ \n");
	printf("0. �׸��ϱ� \n");
	printf("####################################\n\n");
}

int main_���()
{
	int i, j, menu;
	char c;

	�޴����̱�();

	while (1) {
		printf("�޴��� �Է��ϼ���: ");
		scanf("%d", &menu);

		if (menu == 0)
			break;

		printf("�� ���� ������ �Է��ϼ���: ");
		scanf("%d %d", &i, &j);

		//printf("������ +, -, *, / �� �ϳ��� �Է��ϼ���: ");
		//scanf(" %c", &c);

		switch (menu)
		{
		case 1:
			printf("%d + %d = %d\n", i, j, add(i, j));
			break;
		case 2:
			printf("%d - %d = %d\n", i, j, minus(i, j));
			break;
		case 3:
			Mult(i, j);
			break;
		case 4:
			Nanu(i, j);
			break;
		case 0:
			return -1;
			break;
		default:
			printf("�ùٸ��� ���� �����ڸ� �Է��ϼ̽��ϴ�.\n");
			break;
		}
		printf("\n####################################\n\n");
	}
}


/*
int main() {
	int i = 0;
	int �����ڸ�, �����ڸ� = 0;

	while (1) {
		printf("%d: ", i);

		�����ڸ� = i % 10;
		�����ڸ� = i / 10;

		if (�����ڸ� != 0 && �����ڸ� % 3 == 0) {
			if (�����ڸ� != 0 && �����ڸ� % 3 == 0)
				printf("¦");
			printf("¦!\n");
		}

		if (�����ڸ� != 0 && �����ڸ� % 3 == 0 && �����ڸ� % 3 != 0)
			printf("¦! ");
			
		i++;

		Sleep(200);
	}
}
*/

/*
int main()
{
	char c;
	int j;

	printf("���ڿ��� �Է��ϼ���: ");
	scanf(" %c", &c);

	if (c == 'a')
		j = 1;
	else
		j = 0;

	printf("c: %c, a= %d", c, j);
}
*/