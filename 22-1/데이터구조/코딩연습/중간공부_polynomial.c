//���׽� ǥ�� 2��° ���
//� X�� ���� ���׽��� ���� ����ϴ� �Լ��� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�
// A ���׽İ� B ���׽��� ��Ģ���� 

#define MAX_SIZE 100
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    double coef; // ���
    int expon; // ����
}polynomial;

void SortPolynomial(polynomial *p, int count_term_a, int count_term_b){
    polynomial temp;
    polynomial max = p[0];
    int temp_idx;
    for(int i = 0; i < count_term_a + count_term_b; i++){
        if(i < count_term_a){
            for(int k = i; k < count_term_a; k++){
                if(max.expon < p[k].expon){
                    max = p[k];
                    temp_idx = k;
                }
            }
        }
        else{
            for(int k = count_term_a; k < count_term_a + count_term_b; k++){
                if(max.expon < p[k].expon){
                    max = p[k];
                    temp_idx = k;
                }
            }
        }
        temp = p[i];
        p[i] = max;
        p[temp_idx] = temp;
    }
}

void PrintPolynomial(polynomial *p, int count_term_a, int count_term_b){
    printf("A ���׽�\n");
    for(int i = 0; i < count_term_a; i++){
        if(i + 1 == count_term_a){
            printf("%lfx^%d\n", p[i].coef, p[i].expon);
        }
        else{
            printf("%lfx^%d + ", p[i].coef, p[i].expon);
        }
    }
    for(int i = count_term_a; i <count_term_a + count_term_b; i++){
        if(i + 1 == count_term_a + count_term_b){
            printf("%lfx^%d\n", p[i].coef, p[i].expon);
        }
        else{
            printf("%lfx^%d + ", p[i].coef, p[i].expon);
        }
    }
}

int InsertUnkwon(polynomial *p, int count_term_a, int count_term_b, int x){
    int result = 0;
    for(int i = 0; i < count_term_a; i++){
        int temp = p[i].coef;
        for(int k = 0; k < p[i].expon; k++){
            temp *= x;
        }
        result += temp;
    }
    for(int i = count_term_a; i < count_term_a + count_term_b; i++){
        int temp = p[i].coef;
        for(int k = 0; k < p[i].expon; k++){
            temp *= x;
        }
        result += temp;
    }
    return result;
}

polynomial MinusPolynomial(polynomial *p, int *count_term_a, int *count_term_b){
    polynomial temp[MAX_SIZE];
    int As = 0;
    int Ae = *count_term_a - 1;
    int Bs = *count_term_a;
    int Be = *count_term_b;

    for(int i =0; As <= Ae && Bs <= Be; i++){
        if(p[As].expon > p[Bs].expon){
            temp[i] = p[As++];
        }
        else if(p[As].expon < p[Bs].expon){
            temp[i] = p[Bs++];
        } 
        else{
            if(p[As].coef - p[Bs].coef == 0){
                As++;
                Bs++;
                if(i < *count_term_a){
                    *count_term_a--;
                }
                else{
                    *count_term_b--;
                }
            }
            else{
                temp[i].coef = p[As].coef - p[Bs].coef;
                As++;
                Bs++;
            }
        }
    }
}

int main(){
    polynomial p[MAX_SIZE];
    int count_term_a = 0;
    int count_term_b = 0;

    printf("A ���׽��� ���� ������ ��ΰ���?\n");
    scanf("%d", &count_term_a);
    printf("B ���׽��� ���� ������ ��ΰ���?\n");
    scanf("%d", &count_term_b);
    printf("����� ������ ������� �Է����ּ���\n");
    
    for(int i = 0; i < count_term_a + count_term_b; i++){
        scanf("%lf %d", p[i].coef, p[i].expon);
    }
}