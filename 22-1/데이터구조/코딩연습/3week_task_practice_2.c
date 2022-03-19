#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DEGREE 101

//���׽� ǥ�� 2��° ���
//� X�� ���� ���׽��� ���� ����ϴ� �Լ��� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�

//A, B���׽Ŀ��� ���� ������ �Է¹ް�, �� �׵��� ����� ������ �Է¹޴´�.
//���⼭ �� ���� ��찡 ���� �� �ִ�.
// 1. A ���׽İ� B ���׽��� ���� ��Ÿ����.
// 2. A ���׽İ� B ���׽��� �ϳ��� �迭�� �����ϰ� ����϶�.


typedef struct __polynomial{
    int degree;
    double coef;
} polynomial;


void insert_poly(polynomial *p, int A, int B){
    int count_term_A = A;
    int count_term_B = B;


    //A, B ���׽��� ����� ������ �Է¹��� �� 
    printf("A ���׽��� ����� ������ ������� �Է��϶�.\n");
    for(int i = 0; i < count_term_A; i++)
        scanf("%lf %d", &p[i].coef, &(p[i].degree));
    printf("B ���׽��� ����� ������ ������� �Է��϶�.\n");
    for(int i = count_term_A + 1; i < count_term_A + count_term_B; i++)
        scanf("%lf %d", &p[i].coef, &p[i].degree);
}

void print_poly(polynomial *p, int A, int B){
    int count_term_A = A;
    int count_term_B = B;

    for(int i = 0; i < count_term_A; i++){
        if(i + 1 == count_term_A)
            printf("%lfx^%d\n", p[i].coef, p[i].degree);
        else
            printf("%lfx^%d + ", p[i].coef, p[i].degree);
    }
    for(int i = count_term_A; i <count_term_A + count_term_B; i++){
        if(i + 1 == count_term_A + count_term_B)
            printf("%lfx^%d\n", p[i].coef, p[i].degree);
        else
            printf("%lfx^%d + ", p[i].coef, p[i].degree);
    }
    printf("============================================\n");
}

//�������� sort�� ��� �ؾ����� �𸣰ڴ�.
int sort_poly(polynomial *p, int count_term_A, int count_term_B){
    polynomial temp;
    int max = p[0].degree;
    for(int i = 0; i < count_term_A + count_term_B; i++){
        for(int k = i; k < count_term_A + count_term_B; k++){
            if(max < p[i].degree){
                max = p[i].degree;
            }
        }
    }
}

int compare(int a, int b){
    if(a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

//A ���׽İ� B ���׽��� ���� ���׽��� �����ְ� X���� �Է¹޴´�.
double sum_poly(polynomial *p, int count_term_A, int count_term_B){
    int x;
    polynomial result[MAX_DEGREE] = {0, {0, }};
    polynomial max;
    int idx;
    for(int i = 0; i < count_term_A + count_term_B; i++){
        max.degree = p[i].degree;
        idx = 0;
        for(int k = i; k <count_term_A + count_term_B; k++){
            if(max.degree < p[k].degree){
                max = p[k];
                idx = k;
            }
        }        
        p[i] = max;
    }
    //���׽��� ���ϰ� p�迭�� �����ϴ� �ͱ��� �Ϸ�
    //p�迭 print�ϰ� x�� �޾Ƽ� �� ��ȯ�ϴ� �ͱ����� �ؾ��ϴ� �۾�
}

int main(){
    polynomial x[MAX_DEGREE] = {0, {0, }};
    int token;
    int count_term_A;
    int count_term_B;
    printf("A ���׽��� ���� ������? \n");
    scanf("%d", &count_term_A);
    printf("B ���׽��� ���� ������? \n");
    scanf("%d", &count_term_B);
}