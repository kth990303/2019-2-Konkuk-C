#include <stdio.h>

int make�Ƹ޸�ī��(int ��, int Ŀ��, int ���߰�)
{
	int num;
	printf("���ִ� Ŀ�Ǹ� ����ϴ�. �� �߰� �Ͻðڽ��ϱ�?(yes: 1 No:2)");
	scanf("%d", &num);

	if (num == 1)
		return Ŀ�� + �� + ���߰�;
	else if (num == 2)
		return Ŀ�� +��;
	else
		return 0;
}

int make����������(int Ŀ��, int ���߰�)
{
	int num;
	printf("���� Ŀ�Ǹ� ����ϴ�. �� �߰� �Ͻðڽ��ϱ�?(yes: 1 No:2)");
	scanf("%d", &num);

	if (num == 1)
		return Ŀ�� + ���߰�;
	else if (num == 2)
		return Ŀ��;
	else
		return 0;
	
}

int make�ٴҶ��(int Ŀ��, int �ٴҶ�, int ��)
{
	printf("������ �ٴҶ�󶼸� ����ڽ��ϴ�.");
	return Ŀ�� + �� + �ٴҶ�;
}

int main_order() {
	int Ŀ�� = 1000;
	int �� = 500;
	int ���� = 1000;
	int �ٴҶ� = 500;
	int ���߰� = 300;
	int choice;
	int ������;
	int how1;
	int how2;
	int how3;

	printf("���Ͻô� �޴��� ���ÿ�: \n");
	printf("1.�Ƹ޸�ī��\n");
	printf("2.����������\n");
	printf("3.�ٴҶ��\n");
	scanf("%d", &choice);

	printf("######################################\n\n");

	switch (choice)
	{
	case 1:
		how1 = make�Ƹ޸�ī��(��, Ŀ��, ���߰�);
		printf("%d���Դϴ�.\n", how1);
		printf("�󸶸� ���ðڽ��ϱ�?");
		scanf("%d", &������);

		if (������ >= how1)
		{
			printf("\n�Ž����� %d�� �帮�ڽ��ϴ�~\n", ������ -how1);
			printf("õ��¥�� %d��\n", (������ - how1) / 1000);
			printf("���¥�� %d��\n", ((������ - how1) % 1000) / 100);
			printf("�ʿ�¥�� %d��\n", (((������ - how1) % 1000) % 100) / 10);
		}
		else
			printf("���� �����Ͽ� ������ �� �����ϴ�.\n");
		break;
	case 2:
		how2 = make����������(Ŀ��, ���߰�);
		printf("%d���Դϴ�.\n", how2);
		printf("�󸶸� ���ðڽ��ϱ�?");
		scanf("%d", &������);
		if (������ >= how2)
		{
			printf("\n�Ž����� %d�� �帮�ڽ��ϴ�~\n", ������ - how2);
			printf("õ��¥�� %d��\n", (������ - how2) / 1000);
			printf("���¥�� %d��\n", ((������ - how2) % 1000) / 100);
			printf("�ʿ�¥�� %d��\n", (((������ - how2) % 1000) % 100) / 10);
		}
		else
			printf("���� �����Ͽ� ������ �� �����ϴ�.\n");
		break;
	case 3:
		how3 = make�ٴҶ��(Ŀ��, �ٴҶ�, ��);
		printf("%d���Դϴ�.\n", how3);
		
		printf("�󸶸� ���ðڽ��ϱ�?");
		scanf("%d", &������);
		if (������ >= how3)
		{
			printf("\n�Ž����� %d�� �帮�ڽ��ϴ�~\n", ������ -how3);
			printf("õ��¥�� %d��\n", (������ - how3) / 1000);
			printf("���¥�� %d��\n", ((������ - how3) % 1000) / 100);
			printf("�ʿ�¥�� %d��\n", (((������ - how3) % 1000) % 100) / 10);
		}
		else
			printf("���� �����Ͽ� ������ �� �����ϴ�.\n");
		break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
}