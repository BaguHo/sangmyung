//다항식 표현 2번째 방법
//어떤 X에 대한 다항식의 값을 계산하는 함수를 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_TERMS 101
typedef struct {
	float coef;//계수//숫자
	int expon;//차수//승
}polynomial;

polynomial terms[MAX_TERMS] = { {0,}, };
int avail;

//A항 B항의 계수와 차수 입력
polynomial input_poly(int Ae, int Be) {
	printf("A항의 계수와 차수를 입력하세요: ");
	for (int i = 0; i <= Ae; i++) {
		scanf("%f,%d", &terms[i].coef, &terms[i].expon);
	}
	printf("B항의 계수와 차수를 입력하세요: ");
	for (int i = Ae+1; i <= Be; i++) {
		scanf("%f,%d", &terms[i].coef, &terms[i].expon);
	}
}

char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

//C 항을 넣는 함수
void attach(float coef, int expon) {
	if (avail>MAX_TERMS){
		fprintf(stderr,"항의 개수가 너무 많음");
		exit(1);
	}
	terms[avail].coef = coef;//현재 진행중인 case에 있는 coef값 Cs에서 부터 인덱스 avail.coef에 붙임
	terms[avail].expon = expon;//현재 진행중인 case에 있는 expon값 Cs에서 부터 인덱스 avail.expon에 붙임
	avail++;//Be가 끝나는 지점이자 Cs가 시작하는 지점에서 늘려가면서 넘어가서 attach
}

//C 다항식을 구하는 함수
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>'://A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++; break;
		case '='://A의 차수 = B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++, Bs++; break;
		case '<'://A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++; break;
		}

	//B를 다 붙이고 A가 끝나지 않았을 때 나머지 A항들을 붙임
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

	printf("A항은 몇 개 입니까?: ");
	scanf("%d", &Ae);
	printf("B항은 몇 개 입니까?: ");
	scanf("%d", &Be);
	Ae = Ae - 1;
	Be = Ae + Be;

	input_poly(Ae, Be);
	Bs = Ae+1;
	avail = Be+1;
	printf("---------------------------------------------------------\n");
	
	//하나의 배열로 입력된 여러 개의 다항식을 표현
	printf("< coef  >");
	for (int i = 0; i <= Be; i++) 
		printf("[%3.1f]", terms[i].coef);//coef(계수)
	printf("\n");
	printf("< expon >");
	for (int i = 0; i <= Be; i++)
		printf("[%3d]", terms[i].expon);//expon(차수)
	printf("\n");
	printf("---------------------------------------------------------\n");


	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("---------------------------------------------------------\n");	
	print_poly(Cs, Ce);

	return 0;
}