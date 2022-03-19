#include<stdio.h>
#define MAX_DEGREE 101
//���׽� ǥ�� ù ��° ���
//� x�� ���� ���׽��� ���� ����ϴ� �Լ� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�
//�� ���׽��� �ְ����� ���밪�� ���� ��ȣ�� �ٸ� ��츦 ó������ ���Ѵ�.

//���׽� ǥ�� 2��° ���
//� X�� ���� ���׽��� ���� ����ϴ� �Լ��� �����
//���׽��� Ű����� �Է��ϴ� �Լ� �����
//main ���� 1. ���׽� �Է��Լ� ȣ�� 2. �Էµ� ���׽� ��� 3. Ư�� x�� �Է� 4. ���׽� ��� ��� ���
//�ݺ������̿� x�� ������ �Է� �� �ٸ� ���׽� �Է�

typedef struct __polynomial {
    int degree;
    double coef[MAX_DEGREE];
} polynomial;

void insert_poly(polynomial* p) {
    printf("���׽��� �ְ������� �Է����ּ���\n");
    scanf("%d", &p->degree);
    printf("�� ���� ����� �Է����ּ���\n");
    //������� ����
    for (int i = 0; i <= (*p).degree; i++) {
        scanf("%lf", &p->coef[i]);
    }
}

void print_poly(polynomial* p) {
    for (int i = 0; i <= (*p).degree; i++) {
        if (i == (*p).degree) {
            printf("%.2lf * x ^ %d ", p->coef[i], p->degree - i);
            printf("\n");
        }
        else {
            printf("%.2lf * x ^ %d + ", p->coef[i], p->degree - i);
        }
    }
}

double insert_x(polynomial p) {
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
            for (int i = 0; i < p.degree; i++) {
                result = p.coef[i];
                for (int k = 0; k < p.degree - i; k++) {
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
    int token;
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
            print_poly(&x);
            if (insert_x(x) == -1)
                break;
            else
                printf("x�� �Է��� ��: %.2lf\n", insert_x(x));
            break;
        default:
            printf("0. ���α׷� ����\n");
            printf("1. ���׽� �Է�\n");
            scanf("%d", &token);
            break;
        }
    }
}