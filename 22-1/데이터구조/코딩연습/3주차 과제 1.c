//다항식 표현 첫 번째 방법
//어떤 x에 대한 다항식의 값을 계산하는 함수 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력
//두 다항식의 최고차항 절대값이 같고 부호는 다른 경우를 처리하지 못한다.

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
			C.coef[Cpos++] = A.coef[Apos++];//A항이 B항보다 차수가 높으니 현재 C항에 A항의 값 넣기
			degree_A--;//차수줄이기
		}
		else if (degree_A == degree_B) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];//A항과 B항의 차수가 같으니 C항에 A+B 값 넣기
			degree_A--, degree_B--;//차수줄이기
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];//B항이 A항보다 차수가 높으니 현재 C항에 B항의 값 넣기
			degree_B--;//차수줄이기
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
	printf("다항식의 차수를 입력하세요: ");
	scanf("%d", &p.degree);
	printf("각 항의 계수를 입력하세요: ");
	for (int i = 0; i <= p.degree; i++) {
		scanf("%f", &p.coef[i]);
	}
	return p;
}

void root_x(polynomial p) {
   while (1) {
	  int x;
	  float sum = 0;

	  printf("대입할 X값을 입력하세요: (ex.a을 입력하면 종료합니다.)");
	  scanf("%d", &x);

	  if (x == 97)
		  return 0;

	  int degree_P = p.degree;//C의 차수
	  for (int i = 0; i <= p.degree; i++)
		 sum += p.coef[i] * pow(x, degree_P--);

	  printf("대입한 X값에 대한 다항식 결과: %3.1f\n", sum);

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