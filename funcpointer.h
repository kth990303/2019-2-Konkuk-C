#pragma once
typedef struct player {
	char name[100];
	int power;
	int hp;
	int(*pf)(void *, void *);//����ü ���� �Լ� ������
} Player;
