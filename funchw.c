#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastruct.h"

void makeROW(Person2 ***p_addr, int size1) {
	int i;
	Person2 *p = *p_addr;
	*p_addr = (Person2 **)malloc(sizeof(Person2*)*size1);
	if (p_addr == NULL) {
		printf("건물의 층 공사(공간 할당)에 실패했어요\n");
		exit(1);
	}
	else
		printf("이 건물은 %d층: (%d bytes) \n",size1, _msize(*p_addr));
}

void makeCOL(Person2 ***p_addr, int size1) {
	int i,j=0;
	int *q = (int *)malloc(sizeof(int)*size1);
	Person2 *p = *p_addr;

	for (i = 0; i < size1; i++) {
		printf("%d층에 몇 호실을 오픈하시겠습니까? ", i + 1); scanf("%d", q + i);
		*(*(p_addr)+i) = (Person2 **)malloc(sizeof(Person2)*(*(q + i)));

		if (p_addr + i == NULL) {
			printf("건물의 호실 공사(공간 할당)에 실패했어요\n");
			exit(1);
		}
		else
			printf("%d층에 할당된 칸: %d bytes \n", i + 1, _msize(*(*(p_addr)+i)));
			//printf("%d\n", _msize(*(*(p_addr)+i))/sizeof(Person2));
	}
	free(q);
	q = NULL;
}

//Person2 **makeRow2(int size1) {
//	Person2 **p = (Person2 **)malloc(sizeof(Person2*)*size1);
//	return p;
//} 
// 이중 포인터의 주소를 넘겨받지 않으면 함수 내에서만 복사된 값의 변화가 일어나고 실제 값은 변하지 않음.
// Call-by-value
// 따라서 이중 포인터의 주소(Call-by-reference)를 넘겨받아야 돼서 ***p를 전달 (p_address: p_addr)

void ShowRoom(Person2 ***p_addr, int size1) {
	printf("==========================================\n");
	int i, j;
	
	for (i = 0; i < size1; i++) {
		printf("%d층: ", i + 1);
		for (j = 0; j < _msize(*(*(p_addr)+i)) / sizeof(Person2); j++) {
			printf("□");
		}
		printf("\n");
	}
}

//void inputinfo(Person2 **p, Person2 ***p_addr, int size1) {
//	int i, j, len1, len2 = 0;
//	char *name = (char *)calloc("", sizeof(char)*50);
//	char *phone = (char *)calloc("", sizeof(char)*50);
//
//	printf("==========================================\n");
//	printf("몇 층에 예약하시겠습니까? "); scanf("%d", &i);
//	printf("몇 호에 예약하시겠습니까? "); scanf("%d", &j);
//	if (i > size1 || j>_msize(*(*(p_addr)+(i-1))) / sizeof(Person2) || i <= 0 || j <= 0) {
//		printf("올바른 정보를 입력해야 예약 가능합니다.\n");
//		exit(1);
//	}
//
//	printf("정보 입력을 시작합니다.\n");
//	printf("이름: "); scanf("%s", name);
//	if (strlen(name) > 50) {
//		realloc(name, strlen(name)-50+1);
//	}
//	p[i-1][j-1].name = name;
//	printf("나이: "); scanf("%d", &(p[i-1][j-1].age));
//	printf("전화번호: "); scanf("%s", phone);
//	if (strlen(phone) > 50) {
//		realloc(phone, strlen(phone) - 50 + 1); 
//	}
//	p[i-1][j-1].phone = phone;
//
//	if (name == NULL || phone == NULL) {
//		printf("예약 실패! (할당 오류)\n");
//		exit(1);
//	}
//	else printf("예약 완료!\n");
//	printf("==========================================\n");
//	printf("%d0%d호 정보: \n", i, j);
//	printf("이름 : %s\n나이: %d살\n전화번호: %s \n ", p[i-1][j-1].name, p[i-1][j-1].age, p[i-1][j-1].phone);
//
//	free(name);
//	free(phone);
//}

int main() {
	int size1 = 0, size2 = 0, i;
	int row, col;
	int k = 0;
	//Person2 *p = NULL;; // 1행 n열 => n명.
	
	Person2 **p = NULL; // n행 n열 => n명이 n줄 들어온다. 주소를 두 번 참조해야 Person2.
	printf("==========================================\n");
	printf("변수명    주소  \t값     타입\n");
	printf("  p    %p    %p   Person2 **\n", &p, p);
	printf("==========================================\n");

	printf("몇 층입니까? "); scanf("%d", &size1);

	
	printf("\n");
	makeROW(&p, size1);
	printf("==========================================\n");
	printf("변수명    주소  \t값     타입\n");
	printf("  p    %p    %p   Person2 **\n", &p, p);
	printf("==========================================\n");
	makeCOL(&p, size1);
	ShowRoom(&p, size1);
	/*inputinfo(p, &p, size1);*/
	free(p);
	p = NULL;
}