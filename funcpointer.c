#include <stdio.h>
#include "funcpointer.h"

//�Լ� ������
//int plus(int x, int y);
//int(*fp)(int, int) = plus; fp ������ ������ plus �Լ��� ����Ű�� int�� ���� 2���� ������.
//����, �ؿ��� ���� �� �ʱ�ȭ fp = plus �̷��� ������ε� ����.
//int show();
//int(*fp2)() = show;

//main�Լ�����
//int(*fp[4])(int, int) = { plus, minus, multl, divv };
//���� �� �Լ� ��� ������ ����

//���� ����Ʈ(linked array): �ڱ����� ����ü: 27�ϱ���: ������� x.

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
	Player attacker = { "ų��", 20, 100, attack };
	Player defender = { "����", 20, 100, heal };
	Player p1 = { "p1", 20, 100, attack };
	Player p2 = { "p2", 20, 100, attack };
	int i;

	printf("���ݹޱ� �� %s�� ����\n", p1.name);
	show(p1);
	while (1) {
		printf("1. ���� 2. ��: "); scanf("%d", &i);

		if (i == 1) {
			attacker.pf(&attacker, &p1);
			printf("���ݹ��� �� %s�� ����\n", p1.name);
			show(p1);
		}
		if (i == 2) {
			defender.pf(&defender, &p1);
			printf("������ �� %s�� ����\n", p1.name);
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
//	int(*pf[4])(int, int) = { plus, minus, multi, divv }; //��ġ �ּ� �˷��ִ� ����(?)
//	int(*f)(int, int) = plus;
//
//	int x, y, i;
//	printf("���� �Է�: "); scanf("%d", &x);
//	printf("���� �Է�: "); scanf("%d", &y);
//
//	for (i = 0; i < 4; i++)
//		printf("%d\n", pf[i](x, y)); //�Լ� ������ �迭�� �̿�.
//	
//
//	/*printf("���� �Է�: "); scanf("%d", &x);
//	printf("���� �Է�: "); scanf("%d", &y);
//
//	printf("%d\n", f(x, y));*/
//}
