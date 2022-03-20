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
    for(int i = count_term_A; i < count_term_A + count_term_B; i++)
        scanf("%lf %d", &p[i].coef, &p[i].degree);
}

void print_poly(polynomial *p, int A, int B){
    int count_term_A = A;
    int count_term_B = B;

    for(int i = 0; i < count_term_A; i++){
        if(i + 1 == count_term_A)
            printf("%.2lfx^%d\n", p[i].coef, p[i].degree);
        else
            printf("%.2lfx^%d + ", p[i].coef, p[i].degree);
    }
    for(int i = count_term_A; i < count_term_A + count_term_B; i++){
        if(i + 1 == count_term_A + count_term_B)
            printf("%.2lfx^%d\n", p[i].coef, p[i].degree);
        else
            printf("%.2lfx^%d + ", p[i].coef, p[i].degree);
    }
    printf("============================================\n");
}

void sort_poly(polynomial *p, int count_term_A, int count_term_B){
    polynomial temp;
    int idx;
    for(int i = 0; i < count_term_A + count_term_B; i++){
        idx = 0;
        polynomial max = p[i];
        idx = i;
        for(int k = i; k < count_term_A + count_term_B; k++){
            if(max.degree < p[k].degree){
                max = p[k];
                idx = k;   
            }
        }
        temp = p[i];
        p[i] = max;
        p[idx] = temp;
    }
}

//A ���׽İ� B ���׽��� ���� ���׽��� �����ְ� X���� �Է¹޴´�.
double sum_poly(polynomial *p, int count_term_A, int count_term_B){
    int x;
    double result = 0;
    for(int i = 0; i < count_term_A + count_term_B; i++){
        if(i + 1 == count_term_A + count_term_B)
            printf("%.2lfx^%d\n", p[i].coef, p[i].degree);
        else
            printf("%.2lfx^%d + ", p[i].coef, p[i].degree);
    }

    printf("x���� �־��ּ���\n");
    scanf("%d", &x);
    
    for(int i = 0; i < count_term_A + count_term_B; i++){
        double temp = 0;
        for(int k = 0; k < p[i].degree; k++){
            if(k == 0)
                temp += p[i].coef;
            else
                temp *= x;
        }
        result += temp;
    }
    printf("�����: %.2lf\n", result);
}

int main(){
    polynomial x[MAX_DEGREE] = {{0, }};
    int count_term_A;
    int count_term_B;
    printf("A ���׽��� ���� ������? \n");
    scanf("%d", &count_term_A);
    printf("B ���׽��� ���� ������? \n");
    scanf("%d", &count_term_B);
    insert_poly(&x[0], count_term_A, count_term_B);
    print_poly(&x[0], count_term_A, count_term_B);
    sort_poly(&x[0], count_term_A, count_term_B);
    printf("==========================\n");
    sum_poly(&x[0], count_term_A, count_term_B);
}