#include <stdio.h>
#include <Windows.h>
#include <time.h>

void homework(int status[]) {
	status[0] += 20; //homework ���� ��, stress 20 ����.
	status[1] += 10; //������ ������ �ѵ��ϹǷ� happy 10 ����.
	status[2] -= 10; //������ �ϴ� ���� ü�� 10 ����.
	printf("������ �����մϴ�.\n");
	Sleep(1500);
	printf("������ ¥������, �ѵ��մϴ�. �׸��� ��������ϴ�..\n");
	printf("��Ʈ������ �����ϳ� �ູ���� �����մϴ�. ��, ü���� �����մϴ�.\n");
}
void play(int status[]) {
	status[0] -= 30; // ģ���� �� �� ��Ʈ���� 30 ����.
	status[2] -= 30; //ü�� 30 ����
	status[3] -= 30000; //30000�� �Һ�
	printf("�ų��� ģ����� ���� ���ʴϴ�.\n");
	Sleep(1500);
	printf("��Ʈ������ Ȯ �پ�����, ���� ü���� �Ҿ����ϴ�.\n");
}
void eat(int status[]) {
	status[1] += 15; // �� ������ �ູ�ϴϱ� �ູ 15 ����.
	status[2] += 20; // �������� �����Ǵϱ� ü�� 20 ����.
	status[3] -= 8000; //�ĺ�� �ڱⰡ �δ��ϹǷ� 8000�� ����.
	printf("���� �ѱ����� ���. ���� ������ �Խ��ϴ�.\n");
	Sleep(1500);
	printf("�ĺ� ��� �� �ƽ�����, ü�µ�, �ູ�� ������ϴ�.\n");
}
void sleep(int status[], int time) {
	if (time >= 6) {
		printf("������ ���մϴ�. ����ð��� �� ���� ���ð��� ������ϴ�.\n");
		Sleep(500 * time);
		status[0] -= 20; // sleep ���� ��, 6�ð� �̻��̸� stress 20 ����
		status[2] += 30; // ü�� 30 ����.
		printf("����� ���� �ڼ� ������ �� �մϴ�.\n");
	}

	else if (time > 0 && time < 6) {
		printf("������ ���մϴ�. ����ð��� �� ���� ���ð��� ������ϴ�.\n");
		Sleep(500 * time);
		status[0] -= 10; // 6�ð� �̸��̸� stress 10 ����.
		status[2] += 15; // ü�� 15 ����
		printf("���� ������.. ��Ʈ������ ü�¸鿡�� ������ �̵�ۿ� �� ������ϴ�.\n");
	}
	else
		printf("�ùٸ� �ð��� �Է��ϼ���.\n");
}
void alba(int status[], int time) {
	printf("���������� �˹ٸ� ������ �ϰڽ��ϴ�.\n");
	Sleep(500 * time);
	status[0] += 5 * time; //�˹��ϴ� �͸�ŭ ���� �� ����. ��Ʈ���� �ð� �� 5 ����.
	status[2] -= 10 * time;; //�˹��ϴ� �͸�ŭ ���� �͵� ����. ü�� �ð� �� 10 ����.
	status[3] += 8350 * time; //�����ñ޵� ��������.
	printf("��Ʈ����, ü�� �� �Ҿ����� ���� �ð� �� �����ñ޸�ŭ �������.\n");
}
void show_menu(int status[], int date) {
	printf("=========================================================================\n");
	printf("%d�� °\n", date);
	printf("���� ��Ʈ����: %d, �ູ��: %d, ü��: %d, ��: %d��\n", status[0], status[1], status[2], status[3]);
	if (date > 30) printf("**30�� �Ѱ� �б��� �ٳ�µ� ������ ���� �ʾ� ���������մϴ�.**\n");
	printf("���� ��� ��! ���� �Ϸ�� ��� �����ðڽ��ϱ�?\n");
	if (status[1] >= 100 || status[0] <= -150) printf("**���� �ູ�ؼ� �����鼭 ������ ��ñ���?**\n");
	if (status[1] <= -50 || status[0] >= 50) printf("**�ƹ��� ���� �߿��ص� �ູ�� �߿����� �������?**\n");
	if (status[3] > 250000) printf("**�� ���� ���̸� �� ��� �Ծ �ǰڴ°ɿ�?**\n");
	if (status[2] <= 0) printf("**ü���� ���Ƶ� �ൿ�� �����ϳ�, �ǰ��� �������ּ���!**\n");
	if (status[3] <= 10000) printf("**���� ��� �ൿ�� �����ϳ�, �ſ����� �������ּ���!**\n");
	printf("����(1), �Ļ�(2), �˹�(3), ģ���� ���(4), ����(5), ����(0): ");
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
			printf("�ð��� �Է��ϼ���: ");
			scanf("%d", &time);
			alba(status, time);
			date++;
			break;
		case 4:
			play(status);
			date++;
			break;
		case 5:
			printf("�ð��� �Է��ϼ���: ");
			scanf("%d", &time);
			sleep(status, time);
			date++;
			break;
		case 0:
			break;
		default:
			printf("�ùٸ� ���� �Է��ϼ���.");
			break;
		}
		if (menu == 0) break; //while������ ����� �����ŵ�ϴ�.
	}
}