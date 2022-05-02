#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_EXPONENT 101

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
    int exponent;
    double coef;
} polynomial;

void InsertPolyNomial(polynomial *p, int count_term_A, int count_term_B){
    //A, B ���׽��� ����� ������ �Է¹��� �� 
    printf("A ���׽��� ����� ������ ������� �Է��϶�.\n");
    for(int i = 0; i < count_term_A; i++)
        scanf("%lf %d", &p[i].coef, &(p[i].exponent));
    printf("B ���׽��� ����� ������ ������� �Է��϶�.\n");
    for(int i = count_term_A; i < count_term_A + count_term_B; i++)
        scanf("%lf %d", &p[i].coef, &p[i].exponent);
}

void PrintPolynomial(polynomial *p, int A, int B){
    int count_term_A = A;
    int count_term_B = B;

    for(int i = 0; i < count_term_A; i++){
        if(i + 1 == count_term_A)
            printf("%.2lfx^%d\n", p[i].coef, p[i].exponent);
        else
            printf("%.2lfx^%d + ", p[i].coef, p[i].exponent);
    }
    for(int i = count_term_A; i < count_term_A + count_term_B; i++){
        if(i + 1 == count_term_A + count_term_B)
            printf("%.2lfx^%d\n", p[i].coef, p[i].exponent);
        else
            printf("%.2lfx^%d + ", p[i].coef, p[i].exponent);
    }
    printf("============================================\n");
}

//��������
void SortPolynomial(polynomial *p, int count_term_A, int count_term_B){
    polynomial temp;
    int idx;
    for(int i = 0; i < count_term_A + count_term_B; i++){
        polynomial max = p[i];
        idx = i;
        if(i < count_term_A){
            for(int k = i; k < count_term_A; k++){
                if(max.exponent < p[k].exponent){
                    max = p[k];
                    idx = k;   
                }
            }
        }
        else{
            for(int k = i; k <= count_term_B; k++){
                if(max.exponent < p[k].exponent){
                    max = p[k];
                    idx = k;   
                }
            }
        }
        temp = p[i];
        p[i] = max;
        p[idx] = temp;
    }
}

void MinusPolynomial(polynomial *p, int *count_term_A, int *count_term_B){
    int Ae = (*count_term_A) - 1;
    int Be = (*count_term_A) + (*count_term_B);
    int As = 0;
    int Bs = *count_term_A;

    polynomial temp[MAX_EXPONENT] = {0, };

    for(int i = 0; As <= Ae && Bs <= Be; i++){
        // A�� ���� > B�� ����
        // A�� ������ B���� �ε������� �Ѿ�� ��츦 ó���ؾ� ��
        if(p[As].exponent > p[Bs].exponent){
            temp[i] = p[As];
            As++;
        }
        else if (p[As].exponent < p[Bs].exponent){
            //A ���� < B ����
            temp[i] = p[Bs];
            Bs++;
        }
        else{
            // A���� == B����
            if(p[As].coef - p[Bs].coef != 0){
                temp[i].coef = p[As].coef - p[Bs].coef;
                As++;
                Bs++;
            }
            else{// �� ���� 0�� ��
                    As++;
                    Bs++;
                    i--;
                    if(i < *count_term_A){
                        (*count_term_A) -= 1;
                    }
                    else{
                        (*count_term_B) -= 1;
                    }
            }
        }
    }
    //����� 0�� �� ����
    for(int i = 0; i <= Ae + Be; i++){
        if(temp[i].coef == 0){
            if(i < *count_term_A){
                for(int k = i; k < As + Bs; k++){
                    temp[i] = temp[i + 1];
                    (*count_term_A) -= 1; 
                }
            }
            else{    
                for(int k = i; k < As + Bs; k++){
                    temp[i] = temp[i + 1];
                    (*count_term_B) -= 1; 
                }
            }
        }
    }
    for(int i = 0; i < *count_term_A + *count_term_B; i++){
        p[i] = temp[i];
        printf("%lf %d %lf %d\n", p[i].coef,p[i].exponent, temp[i].coef, temp[i].exponent);
    }
}

double EvaluatePolynomial(polynomial *p, int count_term_A, int count_term_B){
    int x;
    double result = 0;
    printf("x���� �־��ּ���\n");
    scanf("%d", &x);
    for(int i = 0; i < count_term_A + count_term_B; i++){
        double temp = 0;
        for(int k = 0; k < p[i].exponent; k++){
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
    polynomial x[MAX_EXPONENT] = {0,};
    int count_term_A;
    int count_term_B;
    while(1){
        int n;
        printf("0. ���α׷�����\n");
        printf("1. ���׽� �Է�\n");
        scanf("%d", &n);    
        if(n == 0) 
            return 0;
        else{    
            printf("A ���׽��� ���� ������? \n");
            scanf("%d", &count_term_A);
            printf("B ���׽��� ���� ������? \n");
            scanf("%d", &count_term_B);
            InsertPolyNomial(&x[0], count_term_A, count_term_B);
            SortPolynomial(&x[0], count_term_A, count_term_B);
            MinusPolynomial(&x[0], &count_term_A, &count_term_B);
            PrintPolynomial(&x[0], count_term_A, count_term_B);
            printf("x ���԰�: %lf\n", EvaluatePolynomial(&x[0], count_term_A, count_term_B));
        }
    }//minus���� ����
}