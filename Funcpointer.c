#include <stdio.h>
#include <stdlib.h>

//Person2 ** makeROW1(int size1, int size2) {
//	int i;
//	Person2 *p = (Person2 **)malloc(sizeof(Person2)*size1);
//	for (i = 0; i < size1; i++) {
//		Person2 *p = (Person2 *)malloc(sizeof(Person2)*size2);
//	}
//}

typedef struct person1 {
	char name[20];
	int age;
	char phone[14];
} Person1; //�ּ� 38bytes

typedef struct person2 {
	char *name;
	int age;
	char *phone;
} Person2; //12bytes, ������ ����.

void makeROW2(Person2 ***p_addr, int size1) {
	int i;
	Person2 *p = *p_addr;
	*p_addr = (Person2 **)malloc(sizeof(Person2*)*size1);

	printf("�࿡ �Ҵ�� ũ��: %d bytes \n", _msize(*p_addr));
} //Person **q �� �ּҸ� �޾ƾ� �ϹǷ� Person ***p�� �Ķ���ͷ�. 

void makeCOL2(Person2 ***p_addr, int size2) {
	int i;
	Person2 *p = *p_addr;

	for (i = 0; i < size2; i++) {
		**p_addr = (Person2 **)malloc(sizeof(Person2)*size2);
	}

	printf("���� �Ҵ�� ũ��: %d bytes \n", _msize(**p_addr));


	//for (i = 0; i < size2; i++) {
	//printf("%d��° �л��� ���� �Է�.\n", i+1);

	//printf("�̸�: "); scanf("%s", (**(p_addr + i)->name);
	//printf("����: "); scanf("%d", (**(p_addr+i))->age);
	//printf("��ȭ��ȣ: "); scanf("%s", (**(p_addr+i))->phone);
	//}

	//for (i = 0; i < size2; i++) {
	//printf("%d��° �л��� ����:\n", i+1);
	//printf("�̸�: %s\n", (**(p_addr + i))->name);
	//printf("����: %d\n", (***(p_addr + i)).age);
	//printf("��ȭ��ȣ: %s\n", (**(p_addr + i))->phone);
	//printf("\n");
	//}
}

int main1234() {
	int size1 = 0, size2 = 0;
	//char **p;
	//char *q[10];
	//char r[5][10];

	/*Person1 *p;
	Person1 q[10];*/

	Person2 *p = NULL;; // 1�� n�� => n��.
	Person2 **q = NULL; // n�� n�� => n���� n�� ���´�. �ּҸ� �� �� �����ؾ� Person2.

	printf("��? "); scanf("%d", &size1);
	printf("��? "); scanf("%d", &size2);
	printf("\n");
	makeROW2(&q, size1);
	makeCOL2(&q, size2);
}