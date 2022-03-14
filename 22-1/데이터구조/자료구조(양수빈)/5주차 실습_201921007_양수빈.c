// (1) 2���� ����� SparseMatrix ������ �ڵ� ��ȯ�Ͽ� �����ϴ� �Լ������
// (2) SparseMatrix ������ ���� ������ 2���� �迭������ ���̵��� ����ϴ� �Լ� �����
// (3) SparseMatrix Ÿ���� �� �������� ���� �Ǵ� �����ϴ� �Լ������(�ϳ��� �Լ�)


// main() ������
// 1. �Լ��� ȣ���ؼ�, �迭 A,B,C,D�� ���� SparseMatrix Ÿ�� ���� SA, SB, SC, SD�� �����ϱ�
// 2. �޴� 1,2,3,4�� ���� �Ʒ��� ���� �����  SparseMatrix Ÿ���� ��� ���ϱ�
// 3.  (3) �Լ� ȣ��� A+B ���ϰ�, A, B�� ��� �������� (2)�� �Լ��� �̿��ؼ� ����ϱ�
// 4.  (3) �Լ� ȣ��� A-B ���ϰ�, A, B�� ��� �������� (2)�� �Լ��� �̿��ؼ� ����ϱ�
// 5.  (3) �Լ� ȣ��� C+D ���ϰ�, A, B�� ��� �������� (2)�� �Լ��� �̿��ؼ� ����ϱ�
// 6. (3) �Լ� ȣ��� C-D ���ϰ�, A, B�� ��� �������� (2)�� �Լ��� �̿��ؼ� ����ϱ�
// �� 3~6 ���̿��� ���� Ű �Է��� ��ٷ���, ����� Ȯ���ϴ� �ð� ����
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
	int rows;	// ���� ����
	int cols;	// ���� ����
	int terms; 	// ���� ����
} SparseMatrix;

SparseMatrix int_matrix(int ar, int ac, int* a, SparseMatrix* b) {//��ȯ �Լ�

	int cnt = 0;
	int index = 0;
	for (int i = 0; i < ar; i++) {//��
		for (int j = 0; j < ac; j++) {//��
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



SparseMatrix print_matrix(SparseMatrix a) {//����Ʈ �Լ�
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



SparseMatrix cal_matrix(SparseMatrix a, SparseMatrix b) {//��� �Լ�
	SparseMatrix c;
	SparseMatrix d;

	//��� a�� b�� ũ�Ⱑ ������ Ȯ���ϰ� Ʋ���� ����
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "������ ũ�� ����\n");
		exit(1);
	}

	//����
	printf("==================plus======================\n");
	c.rows = a.rows;//a�� b�� ũ�Ⱑ ����
	c.cols = a.cols;
	c.terms = 0;//ä��� �ֱ����� 0���� �ʱ�ȭ
	int ca = 0, cb = 0, cc = 0;//�� �࿭�� data �迭�� index


	while (ca < a.terms && cb < b.terms) {
		//�� ��Ŀ����� �������� ������� ������ ���������� ����� ��ȣ�� ��
		int incca = a.data[ca].row * a.cols + a.data[ca].col;//���� a���� ��ġ
		int inccb = b.data[cb].row * b.cols + b.data[cb].col;//���� b���� ��ġ
		if (incca < inccb)//b�� �� ũ�� a��� ���� �տ� ���� ��
			c.data[cc++] = a.data[ca++];//a�׸� ���� ���̱�
		else if (incca == inccb) {//������
			if ((a.data[ca].value + b.data[cb].value) != 0) {
				//���� �ε��� ��ȣ�� ���� 0�� ���� ���� �ε����� �ѱ�� �����Ŀ� �������� ����
				c.data[cc].row = a.data[ca].row;//��¥�� a.row b.row ����
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else {
				ca++;
				cb++;
			}
		}
		else//a�� �� ũ�� b��� ���� �տ� ���� ��
			c.data[cc++] = b.data[cb++];//b�׸� ���� ���̱�
	}

	for (; ca < a.terms; ca++) {//�ϳ��� �迭�� ������ ��, ���� ������ �迭 ���̱�
		c.data[cc++] = a.data[ca++];
	}
	for (; cb < b.terms; cb++) {
		c.data[cc++] = b.data[cb++];
	}
	c.terms = cc;


	print_matrix(c);

	printf("�������� �Ѿ���� �ƹ� Ű �Է�........\n");
	getchar();

	printf("==================minus=====================\n");
	d.rows = a.rows;//a�� b�� ũ�Ⱑ ����
	d.cols = a.cols;
	d.terms = 0;//ä��� �ֱ����� 0���� �ʱ�ȭ
	int da = 0, db = 0, dc = 0;//�� �迭�� �׸� index

	while (da < a.terms && db < b.terms) {
		//�� ��Ŀ����� �������� ������� ������ ���������� ����� ��ȣ�� ��
		int indda = a.data[da].row * a.cols + a.data[da].col;//���� a���� ��ġ
		int inddb = b.data[db].row * b.cols + b.data[db].col;//���� b���� ��ġ
		if (indda < inddb)//b�� �� ũ�� a��� ���� �տ� ���� ��
			d.data[dc++] = a.data[da++];//a�׸� ���� ���̱�
		else if (indda == inddb) {//������
			//���� �ε��� ��ȣ�� ���� 0�� ���� ���� �ε����� �ѱ�� �����Ŀ� �������� ����
			if ((a.data[da].value - b.data[db].value) != 0) {
				d.data[dc].row = a.data[da].row;//��¥�� a.row b.row ����
				d.data[dc].col = a.data[da].col;
				d.data[dc++].value = a.data[da++].value - b.data[db++].value;
			}
			else {
				da++;
				db++;
			}
		}
		else {///a�� �� ũ�� b��� ���� �տ� ���� ��
			d.data[dc].row = b.data[db].row;//b�׸� ���� ���̱�
			d.data[dc].col = b.data[db].col;
			d.data[dc].value = (-1) * b.data[db].value;//�ڿ� ���� �� Ŀ�� ���̳ʽ� �ϰ�� -1�� ���������
			dc++;
			db++;
		}
	}

	for (; da < a.terms; da++) {//�ϳ��� �迭�� ������ ��, ���� ������ �迭 ���̱�
		d.data[dc++] = a.data[da++];
	}
	for (; db < b.terms; db++) {
		d.data[dc].row = b.data[db].row;//b�׸� ���� ���̱�
		d.data[dc].col = b.data[db].col;
		d.data[dc].value = (-1) * b.data[db].value;//�ڿ� ���� �� Ŀ�� ���̳ʽ� �ϰ�� -1�� ���������
		dc++;
		db++;
	}
	d.terms = dc;


	print_matrix(d);

	printf("�������� �Ѿ���� �ƹ� Ű �Է�........\n");
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

	printf("�������� �Ѿ���� �ƹ� Ű �Է�........\n");
	getchar();

	cal_matrix(SA, SB);


	SC = int_matrix(Cr, Cc, &C, &SC);
	SD = int_matrix(Dr, Dc, &D, &SD);


	printf("================C====================\n");
	print_matrix(SC);
	printf("================D====================\n");
	print_matrix(SD);

	printf("�������� �Ѿ���� �ƹ� Ű �Է�........\n");
	getchar();

	cal_matrix(SC, SD);
	return 0;
}