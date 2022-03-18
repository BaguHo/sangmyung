#include<stdio.h>
#define MAX_DEGREE 101
//다항식 표현 첫 번째 방법
//어떤 x에 대한 다항식의 값을 계산하는 함수 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력
//두 다항식의 최고차항 절대값이 같고 부호는 다른 경우를 처리하지 못한다.

//다항식 표현 2번째 방법
//어떤 X에 대한 다항식의 값을 계산하는 함수를 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력

typedef struct __polynomial{
    int degree;
    double coef[MAX_DEGREE];
} polynomial;

void insert_poly(polynomial *p){
    printf("다항식의 최고차수를 입력해주세요\n");
    scanf("%d", &p->degree);
    printf("각 항의 계수를 입력해주세요\n");
    //계수에서 에러
    for(int i = 0; i <= (*p).degree; i++){
        scanf("%lf", &p->coef[i]);
    }
}

void print_poly(polynomial *p){
    for(int i = 0; i <= (*p).degree; i++){
        if(i == (*p).degree){
            printf("%.2lf * x ^ %d ", p->coef[i], p->degree - i);
            printf("\n");
        }
        else{
            printf("%.2lf * x ^ %d + ", p->coef[i], p->degree - i);
        }
    }
}

double insert_x(polynomial p){
    double result = 0;
    double x;
    int token = 1;
    while(token == 1){
        int temp;
        printf("0. 뒤로가기\n");
        printf("1. x 대입\n");
        scanf("%d", &temp);
        if(temp == 0){
            token = 0;
            return -1;
        }
        else if(temp == 1){
            int temp;
            printf("x를 입력하세요\n");
            scanf("%lf", &x);
            for(int i = 0; i < p.degree; i++){
                result = p.coef[i];    
                for(int k = 0; k < p.degree - i; k++){
                    result *= x;
                }
                temp += result;
            }
            return temp;
        }
        else
            break;
    }
    return printf("ERROR\n");
}

int main(){
    polynomial x = {0, {0, }};
    int token;
    while(1){
        printf("0. 프로그램 종료\n");
        printf("1. 다항식 입력\n");
        scanf("%d", &token);
        switch (token)
        {
        case 0:
            return 0;
            break;
        case 1:
            insert_poly(&x);
            print_poly(&x);
            if(insert_x(x) == -1)
                break;
            else
                printf("x를 입력한 값: %.2lf\n", insert_x(x));
            break;
        default:
            printf("0. 프로그램 종료\n");
            printf("1. 다항식 입력\n");
            scanf("%d", token);
            break;
        }
    }
}