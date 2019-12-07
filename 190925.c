#include <stdio.h>

int make아메리카노(int 물, int 커피, int 샷추가)
{
	int num;
	printf("맛있는 커피를 만듭니다. 샷 추가 하시겠습니까?(yes: 1 No:2)");
	scanf("%d", &num);

	if (num == 1)
		return 커피 + 물 + 샷추가;
	else if (num == 2)
		return 커피 +물;
	else
		return 0;
}

int make에스프레소(int 커피, int 샷추가)
{
	int num;
	printf("진한 커피를 만듭니다. 샷 추가 하시겠습니까?(yes: 1 No:2)");
	scanf("%d", &num);

	if (num == 1)
		return 커피 + 샷추가;
	else if (num == 2)
		return 커피;
	else
		return 0;
	
}

int make바닐라라떼(int 커피, int 바닐라, int 물)
{
	printf("달콤한 바닐라라떼를 만들겠습니다.");
	return 커피 + 물 + 바닐라;
}

int main_order() {
	int 커피 = 1000;
	int 물 = 500;
	int 우유 = 1000;
	int 바닐라 = 500;
	int 샷추가 = 300;
	int choice;
	int 가진돈;
	int how1;
	int how2;
	int how3;

	printf("원하시는 메뉴를 고르시오: \n");
	printf("1.아메리카노\n");
	printf("2.에스프레소\n");
	printf("3.바닐라라떼\n");
	scanf("%d", &choice);

	printf("######################################\n\n");

	switch (choice)
	{
	case 1:
		how1 = make아메리카노(물, 커피, 샷추가);
		printf("%d원입니다.\n", how1);
		printf("얼마를 내시겠습니까?");
		scanf("%d", &가진돈);

		if (가진돈 >= how1)
		{
			printf("\n거스름돈 %d원 드리겠습니다~\n", 가진돈 -how1);
			printf("천원짜리 %d개\n", (가진돈 - how1) / 1000);
			printf("백원짜리 %d개\n", ((가진돈 - how1) % 1000) / 100);
			printf("십원짜리 %d개\n", (((가진돈 - how1) % 1000) % 100) / 10);
		}
		else
			printf("돈이 부족하여 구매할 수 없습니다.\n");
		break;
	case 2:
		how2 = make에스프레소(커피, 샷추가);
		printf("%d원입니다.\n", how2);
		printf("얼마를 내시겠습니까?");
		scanf("%d", &가진돈);
		if (가진돈 >= how2)
		{
			printf("\n거스름돈 %d원 드리겠습니다~\n", 가진돈 - how2);
			printf("천원짜리 %d개\n", (가진돈 - how2) / 1000);
			printf("백원짜리 %d개\n", ((가진돈 - how2) % 1000) / 100);
			printf("십원짜리 %d개\n", (((가진돈 - how2) % 1000) % 100) / 10);
		}
		else
			printf("돈이 부족하여 구매할 수 없습니다.\n");
		break;
	case 3:
		how3 = make바닐라라떼(커피, 바닐라, 물);
		printf("%d원입니다.\n", how3);
		
		printf("얼마를 내시겠습니까?");
		scanf("%d", &가진돈);
		if (가진돈 >= how3)
		{
			printf("\n거스름돈 %d원 드리겠습니다~\n", 가진돈 -how3);
			printf("천원짜리 %d개\n", (가진돈 - how3) / 1000);
			printf("백원짜리 %d개\n", ((가진돈 - how3) % 1000) / 100);
			printf("십원짜리 %d개\n", (((가진돈 - how3) % 1000) % 100) / 10);
		}
		else
			printf("돈이 부족하여 구매할 수 없습니다.\n");
		break;
	default:
		printf("잘못 입력하셨습니다.\n");
	}
}