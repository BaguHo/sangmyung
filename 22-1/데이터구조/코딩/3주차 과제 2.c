//���׽� ǥ�� 2��° ���
//� X�� ���� ���׽��� ���� ����ϴ� �Լ��� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_TERMS 101
typedef struct {
	float coef;//���//����
	int expon;//����//��
}polynomial;

polynomial terms[MAX_TERMS] = { {0,}, };
int avail;

//A�� B���� ����� ���� �Է�
polynomial input_poly(int Ae, int Be) {
	printf("A���� ����� ������ �Է��ϼ���: ");
	for (int i = 0; i <= Ae; i++) {
		scanf("%f,%d", &terms[i].coef, &terms[i].expon);
	}
	printf("B���� ����� ������ �Է��ϼ���: ");
	for (int i = Ae+1; i <= Be; i++) {
		scanf("%f,%d", &terms[i].coef, &terms[i].expon);
	}
}

char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

//C ���� �ִ� �Լ�
void attach(float coef, int expon) {
	if (avail>MAX_TERMS){
		fprintf(stderr,"���� ������ �ʹ� ����");
		exit(1);
	}
	terms[avail].coef = coef;//���� �������� case�� �ִ� coef�� Cs���� ���� �ε��� avail.coef�� ����
	terms[avail].expon = expon;//���� �������� case�� �ִ� expon�� Cs���� ���� �ε��� avail.expon�� ����
	avail++;//Be�� ������ �������� Cs�� �����ϴ� �������� �÷����鼭 �Ѿ�� attach
}

//C ���׽��� ���ϴ� �Լ�
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>'://A�� ���� > B�� ����
			attach(terms[As].coef, terms[As].expon);
			As++; break;
		case '='://A�� ���� = B�� ����
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++, Bs++; break;
		case '<'://A�� ���� < B�� ����
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++; break;
		}

	//B�� �� ���̰� A�� ������ �ʾ��� �� ������ A�׵��� ����
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) 
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void) {
	int As = 0;
	int Ae, Bs, Be, Cs, Ce;

	printf("A���� �� �� �Դϱ�?: ");
	scanf("%d", &Ae);
	printf("B���� �� �� �Դϱ�?: ");
	scanf("%d", &Be);
	Ae = Ae - 1;
	Be = Ae + Be;

	input_poly(Ae, Be);
	Bs = Ae+1;
	avail = Be+1;
	printf("---------------------------------------------------------\n");
	
	//�ϳ��� �迭�� �Էµ� ���� ���� ���׽��� ǥ��
	printf("< coef  >");
	for (int i = 0; i <= Be; i++) 
		printf("[%3.1f]", terms[i].coef);//coef(���)
	printf("\n");
	printf("< expon >");
	for (int i = 0; i <= Be; i++)
		printf("[%3d]", terms[i].expon);//expon(����)
	printf("\n");
	printf("---------------------------------------------------------\n");


	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("---------------------------------------------------------\n");	
	print_poly(Cs, Ce);

	return 0;
}