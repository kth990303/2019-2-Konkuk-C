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
} Person1; //최소 38bytes

typedef struct person2 {
	char *name;
	int age;
	char *phone;
} Person2; //12bytes, 공간상 유리.

void makeROW2(Person2 ***p_addr, int size1) {
	int i;
	Person2 *p = *p_addr;
	*p_addr = (Person2 **)malloc(sizeof(Person2*)*size1);

	printf("행에 할당된 크기: %d bytes \n", _msize(*p_addr));
} //Person **q 의 주소를 받아야 하므로 Person ***p를 파라미터로. 

void makeCOL2(Person2 ***p_addr, int size2) {
	int i;
	Person2 *p = *p_addr;

	for (i = 0; i < size2; i++) {
		**p_addr = (Person2 **)malloc(sizeof(Person2)*size2);
	}

	printf("열에 할당된 크기: %d bytes \n", _msize(**p_addr));


	//for (i = 0; i < size2; i++) {
	//printf("%d번째 학생의 정보 입력.\n", i+1);

	//printf("이름: "); scanf("%s", (**(p_addr + i)->name);
	//printf("나이: "); scanf("%d", (**(p_addr+i))->age);
	//printf("전화번호: "); scanf("%s", (**(p_addr+i))->phone);
	//}

	//for (i = 0; i < size2; i++) {
	//printf("%d번째 학생의 정보:\n", i+1);
	//printf("이름: %s\n", (**(p_addr + i))->name);
	//printf("나이: %d\n", (***(p_addr + i)).age);
	//printf("전화번호: %s\n", (**(p_addr + i))->phone);
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

	Person2 *p = NULL;; // 1행 n열 => n명.
	Person2 **q = NULL; // n행 n열 => n명이 n줄 들어온다. 주소를 두 번 참조해야 Person2.

	printf("행? "); scanf("%d", &size1);
	printf("열? "); scanf("%d", &size2);
	printf("\n");
	makeROW2(&q, size1);
	makeCOL2(&q, size2);
}