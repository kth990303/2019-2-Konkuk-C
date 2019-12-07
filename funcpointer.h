#pragma once
typedef struct player {
	char name[100];
	int power;
	int hp;
	int(*pf)(void *, void *);//구조체 내의 함수 포인터
} Player;
