#include <stdio.h>
#include "funcpointer.h"

//함수 포인터
//int plus(int x, int y);
//int(*fp)(int, int) = plus; fp 포인터 변수는 plus 함수를 가르키고 int형 인자 2개를 가진다.
//이후, 밑에서 선언 후 초기화 fp = plus 이러한 방식으로도 가능.
//int show();
//int(*fp2)() = show;

//main함수에서
//int(*fp[4])(int, int) = { plus, minus, multl, divv };
//여러 개 함수 묶어서 포인터 가능

//연결 리스트(linked array): 자기참조 구조체: 27일까지: 시험범위 x.

void attack(Player *attacker_addr, Player *defender_addr) {
	printf("==== attack ==== \n");
	defender_addr->hp -= attacker_addr->power;
}

void heal(Player *attacker_addr, Player *defender_addr) {
	printf("===== heal ===== \n");
	defender_addr->hp += attacker_addr->power;
}

void show(Player p) {
	printf("name: %s\npower: %d\nhp: %d\n", p.name, p.power, p.hp);
}

int main() {
	void(*pf[2]) = { attack, heal };
	Player attacker = { "킬러", 20, 100, attack };
	Player defender = { "힐러", 20, 100, heal };
	Player p1 = { "p1", 20, 100, attack };
	Player p2 = { "p2", 20, 100, attack };
	int i;

	printf("공격받기 전 %s의 상태\n", p1.name);
	show(p1);
	while (1) {
		printf("1. 공격 2. 힐: "); scanf("%d", &i);

		if (i == 1) {
			attacker.pf(&attacker, &p1);
			printf("공격받은 후 %s의 상태\n", p1.name);
			show(p1);
		}
		if (i == 2) {
			defender.pf(&defender, &p1);
			printf("힐받은 후 %s의 상태\n", p1.name);
			show(p1);
		}
	}
}


//int plus(int x, int y) {
//	printf("%d + %d = ", x,y);
//	return x + y;
//}
//
//int minus(int x, int y) {
//	printf("%d - %d = ", x,y);
//	return x - y;
//}
//
//int multi(int x, int y) {
//	printf("%d x %d = ", x, y);
//	return x * y;
//}
//
//int divv(int x, int y) {
//	printf("%d / %d = ", x,y);
//	if (y == 0) return 0;
//	else return x / y;
//}
//
//int main() {
//	int(*pf[4])(int, int) = { plus, minus, multi, divv }; //위치 주소 알려주는 개념(?)
//	int(*f)(int, int) = plus;
//
//	int x, y, i;
//	printf("숫자 입력: "); scanf("%d", &x);
//	printf("숫자 입력: "); scanf("%d", &y);
//
//	for (i = 0; i < 4; i++)
//		printf("%d\n", pf[i](x, y)); //함수 포인터 배열을 이용.
//	
//
//	/*printf("숫자 입력: "); scanf("%d", &x);
//	printf("숫자 입력: "); scanf("%d", &y);
//
//	printf("%d\n", f(x, y));*/
//}
