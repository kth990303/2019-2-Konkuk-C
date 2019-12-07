#include <stdio.h>
#include <Windows.h>
#include <time.h>

void homework(int status[]) {
	status[0] += 20; //homework 수행 시, stress 20 증가.
	status[1] += 10; //과제를 끝내서 뿌듯하므로 happy 10 증가.
	status[2] -= 10; //과제를 하는 동안 체력 10 감소.
	printf("과제를 진행합니다.\n");
	Sleep(1500);
	printf("과제는 짜증나나, 뿌듯합니다. 그리고 힘들었습니다..\n");
	printf("스트레스는 증가하나 행복도가 증가합니다. 단, 체력은 감소합니다.\n");
}
void play(int status[]) {
	status[0] -= 30; // 친구와 놀 때 스트레스 30 감소.
	status[2] -= 30; //체력 30 감소
	status[3] -= 30000; //30000원 소비
	printf("신나게 친구들과 술을 마십니다.\n");
	Sleep(1500);
	printf("스트레스는 확 줄었으나, 돈과 체력을 잃었습니다.\n");
}
void eat(int status[]) {
	status[1] += 15; // 밥 먹으면 행복하니까 행복 15 증가.
	status[2] += 20; // 에너지도 충전되니까 체력 20 증가.
	status[3] -= 8000; //식비는 자기가 부담하므로 8000원 감소.
	printf("역시 한국인은 밥심. 밥을 맛나게 먹습니다.\n");
	Sleep(1500);
	printf("식비가 비싼 게 아쉽지만, 체력도, 행복도 얻었습니다.\n");
}
void sleep(int status[], int time) {
	if (time >= 6) {
		printf("숙면을 취합니다. 수면시간이 길 수록 대기시간도 길어집니다.\n");
		Sleep(500 * time);
		status[0] -= 20; // sleep 수행 시, 6시간 이상이면 stress 20 감소
		status[2] += 30; // 체력 30 증가.
		printf("충분한 잠을 자서 개운한 듯 합니다.\n");
	}

	else if (time > 0 && time < 6) {
		printf("숙면을 취합니다. 수면시간이 길 수록 대기시간도 길어집니다.\n");
		Sleep(500 * time);
		status[0] -= 10; // 6시간 미만이면 stress 10 감소.
		status[2] += 15; // 체력 15 증가
		printf("잠이 부족해.. 스트레스와 체력면에서 조금의 이득밖에 못 얻었습니다.\n");
	}
	else
		printf("올바른 시간을 입력하세요.\n");
}
void alba(int status[], int time) {
	printf("지긋지긋한 알바를 열심히 하겠습니다.\n");
	Sleep(500 * time);
	status[0] += 5 * time; //알바하는 것만큼 싫은 게 없다. 스트레스 시간 당 5 증가.
	status[2] -= 10 * time;; //알바하는 것만큼 힘든 것도 없다. 체력 시간 당 10 감소.
	status[3] += 8350 * time; //최저시급도 감지덕지.
	printf("스트레스, 체력 다 잃었지만 돈은 시간 당 최저시급만큼 얻었군요.\n");
}
void show_menu(int status[], int date) {
	printf("=========================================================================\n");
	printf("%d일 째\n", date);
	printf("현재 스트레스: %d, 행복도: %d, 체력: %d, 돈: %d원\n", status[0], status[1], status[2], status[3]);
	if (date > 30) printf("**30일 넘게 학교를 다녔는데 종강을 하지 않아 지긋지긋합니다.**\n");
	printf("수업 모두 끝! 오늘 하루는 어떻게 보내시겠습니까?\n");
	if (status[1] >= 100 || status[0] <= -150) printf("**요즘 행복해서 웃으면서 지내고 계시군요?**\n");
	if (status[1] <= -50 || status[0] >= 50) printf("**아무리 일이 중요해도 행복이 중요하지 않을까요?**\n");
	if (status[3] > 250000) printf("**이 정도 돈이면 좀 놀고 먹어도 되겠는걸요?**\n");
	if (status[2] <= 0) printf("**체력이 낮아도 행동은 가능하나, 건강을 생각해주세요!**\n");
	if (status[3] <= 10000) printf("**돈이 적어도 행동은 가능하나, 신용등급을 생각해주세요!**\n");
	printf("과제(1), 식사(2), 알바(3), 친구와 놀기(4), 숙면(5), 종료(0): ");
}

int main() {
	int status[4] = { 0,0,100,100000 }, date = 1;
	//int stress = 0, happy = 0, hp = 100, money = 100000, date = 1;
	int menu, time, i;

	while (1) {
		show_menu(status, date);
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			homework(status);
			date++;
			break;
		case 2:
			eat(status);
			date++;
			break;
		case 3:
			printf("시간을 입력하세요: ");
			scanf("%d", &time);
			alba(status, time);
			date++;
			break;
		case 4:
			play(status);
			date++;
			break;
		case 5:
			printf("시간을 입력하세요: ");
			scanf("%d", &time);
			sleep(status, time);
			date++;
			break;
		case 0:
			break;
		default:
			printf("올바른 값을 입력하세요.");
			break;
		}
		if (menu == 0) break; //while문에서 벗어나서 종료시킵니다.
	}
}