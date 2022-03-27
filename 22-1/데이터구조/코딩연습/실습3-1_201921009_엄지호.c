#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101
//���׽� ǥ�� ù ��° ���
//� x�� ���� ���׽��� ���� ����ϴ� �Լ� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�
//�� ���׽��� �ְ����� ���밪�� ���� ��ȣ�� �ٸ� ��츦 ó������ ���Ѵ�.

typedef struct __polynomial {
    int degree;
    double coef[MAX_DEGREE];
} polynomial;

// p1 - p2
polynomial minus_poly(polynomial p1, polynomial  p2){
    polynomial result = {0, {0, }};
    result.degree = max(p1.degree, p2.degree);
    int idx = 0;
    //�� �ְ������� ó���� �������� �ڿ� �ԷµǾ��ִ� ���� ��� �� ĭ�� ���ܵ� ���� 0�̴�.
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
    printf("���׽��� �ְ������� �Է����ּ���\n");
    scanf("%d", &p->degree);
    printf("�� ���� ����� �Է����ּ���\n");
    for (int i = 0; i <= p->degree; i++) {
        scanf("%lf", &p->coef[i]);
    }
}

//result�� ����Ͽ��� �� 0���� ����Ǵ� ����
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
        printf("0. �ڷΰ���\n");
        printf("1. x ����\n");
        scanf("%d", &temp);
        if (temp == 0) {
            token = 0;
            return -1;
        }
        else if (temp == 1) {
            int temp = 0;
            printf("x�� �Է��ϼ���\n");
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
        printf("0. ���α׷� ����\n");
        printf("1. ���׽� �Է�\n");
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
            printf("���׽� 1 - ���׽� 2\n");
            print_poly(x);
            print_poly(y);
            printf("================================================\n");
            print_poly(minus_poly(x,y));
            printf("================================================\n");
            double num = eval_poly(minus_poly(x,y));
            if (num == -1)
                break;
            else{
                printf("x�� �Է��� ��: %.2lf\n",num);
            }
            break;
        default:
            printf("0. ���α׷� ����\n");
            printf("1. ���׽� �Է�\n");
            scanf("%d", &token);
            break;
        }
    }
}