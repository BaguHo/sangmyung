#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_EXPONENT 101

//다항식 표현 2번째 방법
//어떤 X에 대한 다항식의 값을 계산하는 함수를 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력

//A, B다항식에서 항의 개수를 입력받고, 그 항들의 계수와 차수를 입력받는다.
//여기서 두 가지 경우가 있을 수 있다.
// 1. A 다항식과 B 다항식의 합을 나타내라.
// 2. A 다항식과 B 다항식을 하나의 배열에 저장하고 출력하라.

typedef struct __polynomial{
    int exponent;
    double coef;
} polynomial;

void insert_poly(polynomial *p, int count_term_A, int count_term_B){
    //A, B 다항식의 계수와 차수를 입력받을 때 
    printf("A 다항식의 계수와 차수를 순서대로 입력하라.\n");
    for(int i = 0; i < count_term_A; i++)
        scanf("%lf %d", &p[i].coef, &(p[i].exponent));
    printf("B 다항식의 계수와 차수를 순서대로 입력하라.\n");
    for(int i = count_term_A; i < count_term_A + count_term_B; i++)
        scanf("%lf %d", &p[i].coef, &p[i].exponent);
}

void print_poly(polynomial *p, int A, int B){
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

//내림차순
void sort_poly(polynomial *p, int count_term_A, int count_term_B){
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

void minus_poly(polynomial *p, int *count_term_A, int *count_term_B){
    int Ae = (*count_term_A) - 1;
    int Be = (*count_term_A) + (*count_term_B);
    int As = 0;
    int Bs = *count_term_A;

    polynomial temp[MAX_EXPONENT] = {0, };

    for(int i = 0; As <= Ae && Bs <= Be; i++){
        // A의 지수 > B의 지수
        // A의 지수가 B지수 인덱스까지 넘어가는 경우를 처리해야 함
        if(p[As].exponent > p[Bs].exponent){
            temp[i] = p[As];
            As++;
        }
        else if (p[As].exponent < p[Bs].exponent){
            //A 지수 < B 지수
            temp[i] = p[Bs];
            Bs++;
        }
        else{
            // A지수 == B지수
            if(p[As].coef - p[Bs].coef != 0){
                temp[i].coef = p[As].coef - p[Bs].coef;
                As++;
                Bs++;
            }
            else{// 뺀 값이 0일 때
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
    //계수가 0인 값 제거
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

double eval_poly(polynomial *p, int count_term_A, int count_term_B){
    int x;
    double result = 0;
    printf("x값을 넣어주세요\n");
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
    printf("결과값: %.2lf\n", result);
}

int main(){
    polynomial x[MAX_EXPONENT] = {0,};
    int count_term_A;
    int count_term_B;
    while(1){
        int n;
        printf("0. 프로그램종료\n");
        printf("1. 다항식 입력\n");
        scanf("%d", &n);    
        if(n == 0) 
            return 0;
        else{    
            printf("A 다항식의 항의 개수는? \n");
            scanf("%d", &count_term_A);
            printf("B 다항식의 항의 개수는? \n");
            scanf("%d", &count_term_B);
            insert_poly(&x[0], count_term_A, count_term_B);
            sort_poly(&x[0], count_term_A, count_term_B);
            minus_poly(&x[0], &count_term_A, &count_term_B);
            print_poly(&x[0], count_term_A, count_term_B);
            printf("x 대입값: %lf\n", eval_poly(&x[0], count_term_A, count_term_B));
        }
    }//minus에서 에러
}