#include <stdio.h>

double Calc(int 월저축액, double 월이자)
{
	int 금액 = 월저축액 + 월저축액*월이자 / 100;
	return 금액;
}


int main_plus()
{
	int 목표금액 = 0;
	int 월저축액 = 0;
	double 누적금액 = 0;
	double 연이자 = 0;
	double 월이자 = 0;

	printf("목표금액을 입력하세요: ");
	scanf("%d", &목표금액);
	
	printf("월 저축액을 입력하세요: ");
	scanf("%d", &월저축액);

	printf("이자(퍼센트율)를 입력하세요: ");
	scanf("%lf", &연이자);

	월이자 = 연이자 / 12;
	printf("\n###############################################\n\n");
	

	while (누적금액 < 목표금액)
	{
		누적금액 += Calc(월저축액, 월이자);
		printf("이번 달 %d원 저축(이자: %.5lf퍼센트)\n금액: %.2lf원, 누적금액: %.2lf원입니다.\n\n",
			월저축액, 월이자, Calc(월저축액, 월이자), 누적금액);
	}
	if (누적금액 >= 목표금액)
		printf("축하드립니다. 목표 금액에 달성했습니다.\n");
}