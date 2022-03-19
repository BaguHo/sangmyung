//���׽� ǥ�� ù ��° ���
//� x�� ���� ���׽��� ���� ����ϴ� �Լ� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�
//�� ���׽��� �ְ����� ���밪�� ���� ��ȣ�� �ٸ� ��츦 ó������ ���Ѵ�.

#include<stdio.h>
#include <math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_A = A.degree;
	int degree_B = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_A > degree_B) {
			C.coef[Cpos++] = A.coef[Apos++];//A���� B�׺��� ������ ������ ���� C�׿� A���� �� �ֱ�
			degree_A--;//�������̱�
		}
		else if (degree_A == degree_B) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];//A�װ� B���� ������ ������ C�׿� A+B �� �ֱ�
			degree_A--, degree_B--;//�������̱�
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];//B���� A�׺��� ������ ������ ���� C�׿� B���� �� �ֱ�
			degree_B--;//�������̱�
		}
	}
	return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}

polynomial input_poly(polynomial p){
	printf("���׽��� ������ �Է��ϼ���: ");
	scanf("%d", &p.degree);
	printf("�� ���� ����� �Է��ϼ���: ");
	for (int i = 0; i <= p.degree; i++) {
		scanf("%f", &p.coef[i]);
	}
	return p;
}

void root_x(polynomial p) {
   while (1) {
	  int x;
	  float sum = 0;

	  printf("������ X���� �Է��ϼ���: (ex.a�� �Է��ϸ� �����մϴ�.)");
	  scanf("%d", &x);

	  if (x == 97)
		  return 0;

	  int degree_P = p.degree;//C�� ����
	  for (int i = 0; i <= p.degree; i++)
		 sum += p.coef[i] * pow(x, degree_P--);

	  printf("������ X���� ���� ���׽� ���: %3.1f\n", sum);

   }
}

int main(void) {
	polynomial a = { 0,{0,} };
	polynomial b = { 0,{0,} };
	polynomial c;

	a = input_poly(a);
	b = input_poly(b);
	print_poly(a);
	print_poly(b);
	c = poly_add(a, b);
	printf("----------------------------------------------------------------\n");
	print_poly(c);
	printf("\n");
	root_x(c);
	return 0;
}