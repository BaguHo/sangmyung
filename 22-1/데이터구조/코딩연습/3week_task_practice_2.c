#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DEGREE 101

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
    int degree;
    double coef;
} polynomial;


void insert_poly(polynomial *p, int A, int B){
    int count_term_A = A;
    int count_term_B = B;

    //A, B 다항식의 계수와 차수를 입력받을 때 
    printf("A 다항식의 계수와 차수를 순서대로 입력하라.\n");
    for(int i = 0; i < count_term_A; i++)
        scanf("%lf %d", &p[i].coef, &(p[i].degree));
    printf("B 다항식의 계수와 차수를 순서대로 입력하라.\n");
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

//A 다항식과 B 다항식을 더한 다항식을 보여주고 X값을 입력받는다.
double sum_poly(polynomial *p, int count_term_A, int count_term_B){
    int x;
    double result = 0;
    for(int i = 0; i < count_term_A + count_term_B; i++){
        if(i + 1 == count_term_A + count_term_B)
            printf("%.2lfx^%d\n", p[i].coef, p[i].degree);
        else
            printf("%.2lfx^%d + ", p[i].coef, p[i].degree);
    }

    printf("x값을 넣어주세요\n");
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
    printf("결과값: %.2lf\n", result);
}

int main(){
    polynomial x[MAX_DEGREE] = {{0, }};
    int count_term_A;
    int count_term_B;
    printf("A 다항식의 항의 개수는? \n");
    scanf("%d", &count_term_A);
    printf("B 다항식의 항의 개수는? \n");
    scanf("%d", &count_term_B);
    insert_poly(&x[0], count_term_A, count_term_B);
    print_poly(&x[0], count_term_A, count_term_B);
    sort_poly(&x[0], count_term_A, count_term_B);
    printf("==========================\n");
    sum_poly(&x[0], count_term_A, count_term_B);
}