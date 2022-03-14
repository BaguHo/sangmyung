/*
헤드노드를 갖는 단순연결리스트를 이용해서 다항식 연산하기
-다항식의 각 항들의 {계수,지수}를 차례로 키보드 입력해서, 단순연결리스트로 연결하시오
-입력 X에 대한 다항식의 값을 계산하는 함수를 만들고 테스트하시오.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)	error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial= ");
	for (; p; p = p->link) {
		printf("%d^%d +", p->coef, p->expon);
	}
	printf("%d^%d", p->coef, p->expon);

	printf("\n");
}

void calculate(ListType* plist) {
	while (1) {
		ListNode* p = plist->head;
		double x;
		double sum = 0;

		printf("대입할 X값을 입력하세요: (ex.0을 입력하면 종료합니다.)");
		scanf("%lf", &x);

		for (; p!=NULL; p=p->link)
			sum += p->coef * pow(x, p->expon);

		printf("대입한 X값에 대한 다항식 결과: %3.1lf\n", sum);

		if (x == 0)
			return 0;
	}
}

int main(void) {
	ListType* list1;
	int num;
	int insert_c;
	int insert_e;
	int x;

	list1 = create();

	printf("<다항식>\n");
	printf("입력할 항의 개수: ");
	scanf("%d", &num);
	printf("다항식의 계수,지수를 차례로 입력하세요: ");
	for (int i = 0; i < num; i++) {
		scanf("%d,%d", &insert_c, &insert_e);
		insert_last(list1, insert_c, insert_e);
	}

	printf("\n");

	poly_print(list1);

	calculate(list1);

	free(list1);
	return 0;
}