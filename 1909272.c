#include <stdio.h>

double Calcu(int �������, double ������)
{
	int �ݾ� = ������� + �������*������ / 100;
	return �ݾ�;
}

double Mplus(double ������)
{
	������ += 0.5;
	return ������;
}


int main_����()
{
	int �� = 0;
	int ����ݾ� = 0;
	int ������� = 0;
	double �����ݾ� = 0;
	double ������ = 0;
	double ������ = 0;

	printf("����ݾ��� �Է��ϼ���: ");
	scanf("%d", &����ݾ�);
	�����ݾ� = ����ݾ�;

	printf("�� ������� �Է��ϼ���: ");
	scanf("%d", &�������);

	printf("����(�ۼ�Ʈ��)�� �Է��ϼ���: ");
	scanf("%lf", &������);

	������ = ������ / 12;
	printf("\n###############################################\n\n");


	while (�����ݾ�>-2000000)
	{
		�����ݾ� -= Calcu(�������, ������);
		if (�����ݾ� < 0) {
			������ = Mplus(������);
			printf("%d��° �� %d�� ����(����: %.5lf�ۼ�Ʈ)\n�ݾ�: %.2lf��, �����ݾ�: %.2lf���Դϴ�.\n\n",
				��, �������, Mplus(������), Calcu(�������, ������), �����ݾ�);
			printf("***���̳ʽ� �����Դϴ�. ���ڰ� 0.5�ۼ�Ʈ �����մϴ�.***.\n\n");
			��++;
		}
		else {
			printf("%d��° �� %d�� ����(����: %.5lf�ۼ�Ʈ)\n�ݾ�: %.2lf��, �����ݾ�: %.2lf���Դϴ�.\n\n",
				��, �������, ������, Calcu(�������, ������), �����ݾ�);
			��++;
		}
	}	
	if (�����ݾ� < -2000000)
		printf("\n####���� ��ġ �� ���� ���ϴ�.####\n\n");
}