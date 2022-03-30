// (1) 2차원 행렬을 SparseMatrix 구조로 자동 변환하여 저장하는 함수만들기
// (2) SparseMatrix 구조의 변수 내용을 2차원 배열구조로 보이도록 출력하는 함수 만들기
// (3) SparseMatrix 타입의 두 희소행렬을 덧셈 또는 뺄셈하는 함수만들기(하나의 함수)

// main() 에서는
// 1. 함수를 호출해서, 배열 A,B,C,D를 각각 SparseMatrix 타입 변수 SA, SB, SC, SD에 저장하기
// 2. 메뉴 1,2,3,4에 따라서 아래의 연산 결과로  SparseMatrix 타입의 결과 구하기
// 3.  (3) 함수 호출로 A+B 구하고, A, B와 결과 희소행렬을 (2)의 함수를 이용해서 출력하기
// 4.  (3) 함수 호출로 A-B 구하고, A, B와 결과 희소행렬을 (2)의 함수를 이용해서 출력하기
// 5.  (3) 함수 호출로 C+D 구하고, A, B와 결과 희소행렬을 (2)의 함수를 이용해서 출력하기
// 6. (3) 함수 호출로 C-D 구하고, A, B와 결과 희소행렬을 (2)의 함수를 이용해서 출력하기
// 위 3~6 사이에는 임의 키 입력을 기다려서, 결과를 확인하는 시간 갖기
#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
} element;
typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	// 행의 개수
	int cols;	// 열의 개수
	int terms; 	// 항의 개수
} SparseMatrix;

SparseMatrix int_matrix(int ar, int ac, int* a, SparseMatrix* b) {//변환 함수

	int cnt = 0;
	int index = 0;
	for (int i = 0; i < ar; i++) {//행
		for (int j = 0; j < ac; j++) {//열
			if (*a != 0) {
				b->data[index].row = i;
				b->data[index].col = j;
				b->data[index].value = *a;
				cnt++;
				index++;
			}
			a++;
		}
	}

	b->rows = ar;
	b->cols = ac;
	b->terms = cnt;

	return *b;
}



SparseMatrix print_matrix(SparseMatrix a) {//프린트 함수
	int index = 0;
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.data[index].row == i) {
				if (a.data[index].col == j)
					printf("[%d]", a.data[index++].value);
				else
					printf("[0]");
			}
			else
				printf("[0]");
		}
		printf("\n");
	}
}



SparseMatrix cal_matrix(SparseMatrix a, SparseMatrix b) {//계산 함수
	SparseMatrix c;
	SparseMatrix d;

	//행렬 a와 b의 크기가 같은지 확인하고 틀리면 종료
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "희소행렬 크기 에러\n");
		exit(1);
	}

	//덧셈
	printf("==================plus======================\n");
	c.rows = a.rows
	;//a와 b가 크기가 같음
	c.cols = a.cols;
	c.terms = 0;//채우고 넣기위해 0으로 초기화
	int ca = 0, cb = 0, cc = 0;//각 행열의 data 배열의 index


	while (ca < a.terms && cb < b.terms) {
		//각 행렬에서의 현재항의 상대적인 순서를 순차적으로 계산한 번호를 비교
		int incca = a.data[ca].row * a.cols + a.data[ca].col;//현재 a값의 위치
		int inccb = b.data[cb].row * b.cols + b.data[cb].col;//현재 b값의 위치
		if (incca < inccb)//b가 더 크며 a행렬 항이 앞에 있을 때
			c.data[cc++] = a.data[ca++];//a항목 먼저 붙이기
		else if (incca == inccb) {//같을때
			if ((a.data[ca].value + b.data[cb].value) != 0) {
				//같은 인덱스 번호가 합이 0일 때는 다음 인덱스로 넘기고 희소행렬에 저장하지 않음
				c.data[cc].row = a.data[ca].row;//어짜피 a.row b.row 같음
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else {
				ca++;
				cb++;
			}
		}
		else//a가 더 크며 b행렬 항이 앞에 있을 때
			c.data[cc++] = b.data[cb++];//b항목 먼저 붙이기
	}

	for (; ca < a.terms; ca++) {//하나의 배열이 끝났을 때, 남은 나머지 배열 붙이기
		c.data[cc++] = a.data[ca++];
	}
	for (; cb < b.terms; cb++) {
		c.data[cc++] = b.data[cb++];
	}
	c.terms = cc;


	print_matrix(c);

	printf("다음으로 넘어갈려면 아무 키 입력........\n");
	getchar();

	printf("==================minus=====================\n");
	d.rows = a.rows;//a와 b가 크기가 같음
	d.cols = a.cols;
	d.terms = 0;//채우고 넣기위해 0으로 초기화
	int da = 0, db = 0, dc = 0;//각 배열의 항목 index

	while (da < a.terms && db < b.terms) {
		//각 행렬에서의 현재항의 상대적인 순서를 순차적으로 계산한 번호를 비교
		int indda = a.data[da].row * a.cols + a.data[da].col;//현재 a값의 위치
		int inddb = b.data[db].row * b.cols + b.data[db].col;//현재 b값의 위치
		if (indda < inddb)//b가 더 크며 a행렬 항이 앞에 있을 때
			d.data[dc++] = a.data[da++];//a항목 먼저 붙이기
		else if (indda == inddb) {//같을때
			//같은 인덱스 번호가 합이 0일 때는 다음 인덱스로 넘기고 희소행렬에 저장하지 않음
			if ((a.data[da].value - b.data[db].value) != 0) {
				d.data[dc].row = a.data[da].row;//어짜피 a.row b.row 같음
				d.data[dc].col = a.data[da].col;
				d.data[dc++].value = a.data[da++].value - b.data[db++].value;
			}
			else {
				da++;
				db++;
			}
		}
		else {///a가 더 크며 b행렬 항이 앞에 있을 때
			d.data[dc].row = b.data[db].row;//b항목 먼저 붙이기
			d.data[dc].col = b.data[db].col;
			d.data[dc].value = (-1) * b.data[db].value;//뒤에 항이 더 커서 마이너스 일경우 -1을 곱해줘야함
			dc++;
			db++;
		}
	}

	for (; da < a.terms; da++) {//하나의 배열이 끝났을 때, 남은 나머지 배열 붙이기
		d.data[dc++] = a.data[da++];
	}
	for (; db < b.terms; db++) {
		d.data[dc].row = b.data[db].row;//b항목 먼저 붙이기
		d.data[dc].col = b.data[db].col;
		d.data[dc].value = (-1) * b.data[db].value;//뒤에 항이 더 커서 마이너스 일경우 -1을 곱해줘야함
		dc++;
		db++;
	}
	d.terms = dc;


	print_matrix(d);

	printf("다음으로 넘어갈려면 아무 키 입력........\n");
	getchar();
}


int main(void) {
	int A[7][5] = { { 0, 0, 0, 0, 2 },
				  { 0, 0,-1, 0, 0 },
				  { 0, 0, 0, 0, 0 },
				  { 5, 0, 0, 0, 0 },
				  { 0, 0, 0, 0, 0 },
				  { 0, 0, 0, 0, 3 },
				  { 0, 0, 1, 0, 0 } };
	int Ar = 7; int Ac = 5;

	int B[7][5] = { { 0, 0, 0, 0, 0 },
					   { 0, 0, 1, 0, 0 },
					   { 0,-2, 0, 0, 0 },
					   { 0, 0, 0, 0, 0 },
					   { 0, 0, 0, 0, 0 },
					   { 0, 0, 0, 0, 0 },
					   { 0, 0, 5, 0, 0 } };
	int Br = 7; int Bc = 5;

	int C[5][6] = { { 0, 0, 0, 0, 0, 2 },
					   { 0, 0, 0,-1, 0, 0 },
					   { 0, 0, 0, 0, 0, 0 },
					   { 0, 5, 0, 0, 0, 0 },
					   { 0, 0, 0, 0, 3, 0 } };
	int Cr = 5; int Cc = 6;

	int D[5][6] = { { 0, 2, 0, 0, 0, 0 },
						  { 0, 0, 0, 1, 0, 0 },
						  { 0, 3, 0, 0, 0, 0 },
						  { 0, 5, 0, 0, 0, 0 },
						  { 0, 0, 0, 0,-1, 0 } };
	int Dr = 5; int Dc = 6;

	SparseMatrix SA, SB, SC, SD;

	SA = int_matrix(Ar, Ac, &A, &SA);
	SB = int_matrix(Br, Bc, &B, &SB);

	printf("================A====================\n");
	print_matrix(SA);
	printf("================B====================\n");
	print_matrix(SB);

	printf("다음으로 넘어갈려면 아무 키 입력........\n");
	getchar();

	cal_matrix(SA, SB);


	SC = int_matrix(Cr, Cc, &C, &SC);
	SD = int_matrix(Dr, Dc, &D, &SD);


	printf("================C====================\n");
	print_matrix(SC);
	printf("================D====================\n");
	print_matrix(SD);

	printf("다음으로 넘어갈려면 아무 키 입력........\n");
	getchar();

	cal_matrix(SC, SD);
	return 0;
}