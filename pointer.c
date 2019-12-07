#include <stdio.h>
#include <Windows.h>
#include <time.h>

void homework(int *stress, int *happy, int *hp) {
	*stress += 20; //homework ���� ��, stress 20 ����.
	*happy += 10; //������ ������ �ѵ��ϹǷ� happy 10 ����.
	*hp -= 10; //������ �ϴ� ���� ü�� 10 ����.
	printf("������ �����մϴ�.\n");
	Sleep(1500);
	printf("������ ¥������, �ѵ��մϴ�. �׸��� ��������ϴ�..\n");
	printf("��Ʈ������ �����ϳ� �ູ���� �����մϴ�. ��, ü���� �����մϴ�.\n");
}
void play(int *stress, int *hp, int *money) {
	*stress -= 30; // ģ���� �� �� ��Ʈ���� 30 ����.
	*hp -= 30; //ü�� 30 ����
	*money -= 30000; //30000�� �Һ�
	printf("�ų��� ģ����� ���� ���ʴϴ�.\n");
	Sleep(1500);
	printf("��Ʈ������ Ȯ �پ�����, ���� ü���� �Ҿ����ϴ�.\n");
}
void eat(int *happy, int *hp, int *money) {
	*happy += 15; // �� ������ �ູ�ϴϱ� �ູ 15 ����.
	*hp += 20; // �������� �����Ǵϱ� ü�� 20 ����.
	*money -= 8000; //�ĺ�� �ڱⰡ �δ��ϹǷ� 8000�� ����.
	printf("���� �ѱ����� ���. ���� ������ �Խ��ϴ�.\n");
	Sleep(1500);
	printf("�ĺ� ��� �� �ƽ�����, ü�µ�, �ູ�� ������ϴ�.\n");
}
void sleep(int *stress, int *hp, int time) {
	if (time >= 6) {
		printf("������ ���մϴ�. ����ð��� �� ���� ���ð��� ������ϴ�.\n");
		Sleep(500 * time);
		*stress -= 20; // sleep ���� ��, 6�ð� �̻��̸� stress 20 ����
		*hp += 30; // ü�� 30 ����.
		printf("����� ���� �ڼ� ������ �� �մϴ�.\n");
	}
		
	else if (time > 0 && time < 6) {
		printf("������ ���մϴ�. ����ð��� �� ���� ���ð��� ������ϴ�.\n");
		Sleep(500 * time);
		*stress -= 10; // 6�ð� �̸��̸� stress 10 ����.
		*hp += 15; // ü�� 15 ����
		printf("���� ������.. ��Ʈ������ ü�¸鿡�� ������ �̵�ۿ� �� ������ϴ�.\n");
	}
	else
		printf("�ùٸ� �ð��� �Է��ϼ���.\n");
}
void alba(int *stress, int *hp, int *money, int time) {
	printf("���������� �˹ٸ� ������ �ϰڽ��ϴ�.\n");
	Sleep(500*time);
	*stress += 5 * time; //�˹��ϴ� �͸�ŭ ���� �� ����. ��Ʈ���� �ð� �� 5 ����.
	*hp -= 10 * time;; //�˹��ϴ� �͸�ŭ ���� �͵� ����. ü�� �ð� �� 10 ����.
	*money += 8350 * time; //�����ñ޵� ��������.
	printf("��Ʈ����, ü�� �� �Ҿ����� ���� �ð� �� �����ñ޸�ŭ �������.\n");
}
void show_menu(int stress, int happy, int hp, int money, int date) {
	printf("=========================================================================\n");
	printf("%d�� °\n", date);
	printf("���� ��Ʈ����: %d, �ູ��: %d, ü��: %d, ��: %d��\n", stress, happy, hp, money);
	if (date > 30) printf("**30�� �Ѱ� �б��� �ٳ�µ� ������ ���� �ʾ� ���������մϴ�.**\n");
	printf("���� ��� ��! ���� �Ϸ�� ��� �����ðڽ��ϱ�?\n");
	if (happy >= 100 || stress <= -150) printf("**���� �ູ�ؼ� �����鼭 ������ ��ñ���?**\n");
	if (happy <= -50 || stress >= 50) printf("**�ƹ��� ���� �߿��ص� �ູ�� �߿����� �������?**\n");
	if (money > 250000) printf("**�� ���� ���̸� �� ��� �Ծ �ǰڴ°ɿ�?**\n");
	if (hp <= 0) printf("**ü���� ���Ƶ� �ൿ�� �����ϳ�, �ǰ��� �������ּ���!**\n");
	if (money <= 10000) printf("**���� ��� �ൿ�� �����ϳ�, �ſ����� �������ּ���!**\n");
	printf("����(1), �Ļ�(2), �˹�(3), ģ���� ���(4), ����(5), ����(0): ");
}

int main() {
	int stress = 0, happy = 0, hp = 100, money = 100000, date = 1;
	int menu, time;

	while (1) {
		show_menu(stress, happy, hp, money, date);
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			homework(&stress, &happy, &hp);
			date++;
			break;
		case 2:
			eat(&happy, &hp, &money);
			date++;
			break;
		case 3:
			printf("�ð��� �Է��ϼ���: ");
			scanf("%d", &time);
			alba(&stress, &hp, &money, time);
			date++;
			break;
		case 4:
			play(&stress, &hp, &money);
			date++;
			break;
		case 5:
			printf("�ð��� �Է��ϼ���: ");
			scanf("%d", &time);
			sleep(&stress, &hp, time);
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