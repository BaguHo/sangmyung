//다항식 표현 2번째 방법
//어떤 X에 대한 다항식의 값을 계산하는 함수를 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력
// A 다항식과 B 다항식의 사칙연산 

#define MAX_SIZE 100
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    double coef; // 계수
    int expon; // 차수
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
    printf("A 다항식\n");
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

    printf("A 다항식의 항의 개수는 몇개인가요?\n");
    scanf("%d", &count_term_a);
    printf("B 다항식의 항의 개수는 몇개인가요?\n");
    scanf("%d", &count_term_b);
    printf("계수와 차수를 순서대로 입력해주세요\n");
    
    for(int i = 0; i < count_term_a + count_term_b; i++){
        scanf("%lf %d", p[i].coef, p[i].expon);
    }
}