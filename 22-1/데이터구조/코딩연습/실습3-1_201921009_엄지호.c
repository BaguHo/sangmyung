#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101
//다항식 표현 첫 번째 방법
//어떤 x에 대한 다항식의 값을 계산하는 함수 만들기
//다항식을 키보드로 입력하는 함수 만들기
//main 순서 1. 다항식 입력함수 호출 2. 입력된 다항식 출력 3. 특정 x값 입력 4. 다항식 계산 결과 출력
//반복문장이용 x값 여러번 입력 또 다른 다항식 입력
//두 다항식의 최고차항 절대값이 같고 부호는 다른 경우를 처리하지 못한다.

typedef struct __polynomial {
    int degree;
    double coef[MAX_DEGREE];
} polynomial;

// p1 - p2
polynomial minus_poly(polynomial p1, polynomial  p2){
    polynomial result = {0, {0, }};
    result.degree = max(p1.degree, p2.degree);
    int idx = 0;
    //각 최고차항이 처음에 없어지면 뒤에 입력되어있는 값이 없어서 한 칸씩 땡겨도 값은 0이다.
    while(p1.degree + p2.degree > 0){
        if(p1.degree > p2.degree){// p1 > p2
            for(; p1.degree != p2.degree; idx++){
                result.coef[idx] = p1.coef[idx];
                p1.degree--;
            }
        }
        else if(p1.degree < p2.degree){ // p1 < p2
            for(; p1.degree != p2.degree; idx++){
                result.coef[idx] = p2.coef[idx];
                p2.degree--;
            }
        }
        else{ // p1 == p2
            for(; p1.degree + p2.degree >= 0; idx++){
                result.coef[idx] = p1.coef[idx] - p2.coef[idx];
                p1.degree--;
                p2.degree--;
            }
        }
    }
    for(int i = 0; i < result.degree; i++){
        if(result.coef[i] == 0){
            for(int k = i; k <= result.degree; k++){
                result.coef[k] = result.coef[k + 1];
            }
            result.degree--;
        }
    }
    return result;
}

void insert_poly(polynomial* p) {
    printf("다항식의 최고차수를 입력해주세요\n");
    scanf("%d", &p->degree);
    printf("각 항의 계수를 입력해주세요\n");
    for (int i = 0; i <= p->degree; i++) {
        scanf("%lf", &p->coef[i]);
    }
}

//result를 출력하였을 때 0부터 출려되는 문제
void print_poly(polynomial p) {
    for (int i = 0; i <= p.degree; i++) {
        if (i == p.degree) {
            printf("%.2lfx^%d \n", p.coef[i], p.degree - i);
        }
        else {
            printf("%.2lfx^%d + ", p.coef[i], p.degree - i);
        }
    }
}

double eval_poly(polynomial p) {
    double result = 0;
    double x;
    int token = 1;
    while (token == 1) {
        int temp;
        printf("0. 뒤로가기\n");
        printf("1. x 대입\n");
        scanf("%d", &temp);
        if (temp == 0) {
            token = 0;
            return -1;
        }
        else if (temp == 1) {
            int temp = 0;
            printf("x를 입력하세요\n");
            scanf("%lf", &x);
            for (int i = 0; i <= p.degree; i++) {
                result = p.coef[i];
                for (int k = 0; k <= p.degree - i; k++) {
                    result *= x;
                }
                temp += (int)result;
            }
            return temp;
        }
        else
            break;
    }
    return printf("ERROR\n");
}

int main() {
    polynomial x = { 0, {0, } };
    polynomial y = { 0, {0, }};
    int token;
    int n;
    while (1) {
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
            insert_poly(&y);
            printf("================================================\n");
            printf("다항식 1 - 다항식 2\n");
            print_poly(x);
            print_poly(y);
            printf("================================================\n");
            print_poly(minus_poly(x,y));
            printf("================================================\n");
            double num = eval_poly(minus_poly(x,y));
            if (num == -1)
                break;
            else{
                printf("x를 입력한 값: %.2lf\n",num);
            }
            break;
        default:
            printf("0. 프로그램 종료\n");
            printf("1. 다항식 입력\n");
            scanf("%d", &token);
            break;
        }
    }
}