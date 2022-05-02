/*
����带 ���� �ܼ����Ḯ��Ʈ�� �̿��ؼ� ���׽� �����ϱ�
-���׽��� �� �׵��� {���,����}�� ���ʷ� Ű���� �Է��ؼ�, �ܼ����Ḯ��Ʈ�� �����Ͻÿ�
-�Է� X�� ���� ���׽��� ���� ����ϴ� �Լ��� ����� �׽�Ʈ�Ͻÿ�.
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
	if (temp == NULL)	error("�޸� �Ҵ� ����");
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

		printf("������ X���� �Է��ϼ���: (ex.0�� �Է��ϸ� �����մϴ�.)");
		scanf("%lf", &x);

		for (; p!=NULL; p=p->link)
			sum += p->coef * pow(x, p->expon);

		printf("������ X���� ���� ���׽� ���: %3.1lf\n", sum);

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

	printf("<���׽�>\n");
	printf("�Է��� ���� ����: ");
	scanf("%d", &num);
	printf("���׽��� ���,������ ���ʷ� �Է��ϼ���: ");
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