#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//1�� ��ҹ��� �Ǻ��Լ� ��밡��
//2�� ���Ҽ��� ��ȯ�Լ��� 
//3�� �����Լ��� length ���ϴ� 
//4�� ���ĵ� �����迭 ����Ž�� ��ȯ�Լ�

void IsFull(char* str) {
    int temp = 0;
    if (strchr(str, '!') != '\0' && strchr(str, '?') != '\0' && strchr(str, '*') != '\0' &&
     strchr(str, '#') != '\0' && strchr(str, '$') != '\0') {
        printf("Ư�����ڰ� �����ϴ�.\n");
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]) != 0) {
            temp += 1;
        }
    }
    if (temp == 0)
        printf("�빮�ڰ� �����ϴ�.\n");
    temp = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i]) != 0) {
            temp += 1;
        }
    }
    if (temp == 0)
        printf("�ҹ��ڰ� �����ϴ�.\n");
    if(strlen(str) < 10) {
        printf("10�� �����Դϴ�.\n");
    }
}

void first() {
    char str[100];
    printf("���ڿ��� �Է����ּ���\n");
    scanf("%s", str);
    IsFull(&str[0]);
}

typedef struct __complex {
    double x;
    double y;
}complex_num;

// ����Լ��� ������ ����
void sum(int n, complex_num* temp, double x, double y) {
    if (n < 1) {
        printf("���: %lf + %lf\n", x, y);
        return 0;
    }
    printf("��������� ��: %lf + %lf\n", x, y);
    sum(n - 1, temp + 1, x += temp->x , y += temp->y);
}

void second() {
    int n;
    printf("�� ���� ���Ҽ��� �Է��Ͻðڽ��ϱ�?\n");
    scanf("%d", &n);
    complex_num* arr = malloc(sizeof(complex_num) * n);
    printf("���Ҽ� �Ǽ��κ�, ����κ��� �Է����ּ���\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &arr[i].x, &arr[i].y);
        printf("%lf %lf\n", arr[i].x, arr[i].y);
    }
    sum(n, arr, 0, 0);
    free(arr);
}

// ����Լ�
int length(char* str, int i) {
    if (*str == '\0') {
        return 0;
    }
    else {
        printf("���ڿ��� ���̸� ���ϴ� ����: %d\n", i + 1);
        return 1 + length(str + 1, i + 1);
    }
}

void Thrid() {
    char str[100];
    printf("���ڿ��� �Է����ּ���\n");
    scanf("%s", str);
    printf("%d\n", length(str, 0));
}

int RecursionBinarySearch(int* input, int target, int low, int high) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (input[mid] == target) {
        for (int i = low; i <= high; i++)
            printf("%d ", input[i]);
        printf("\n");
        return mid;
    }
    else if (input[mid] > target) {
        for (int i = low; i <= high; i++)
            printf("%d ", input[i]);
        printf("\n");
        return RecursionBinarySearch(&input[0], target, low, mid - 1);
    }
    else {
        for (int i = low; i <= high; i++)
            printf("%d ", input[i]);
        printf("\n");
        return RecursionBinarySearch(&input[0], target, mid + 1, high);
    }
}

// ã�� ���� ���� ����Ž���� �̿��� ����Լ��� ����
void Qurd() {
    int target;
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("���� �� �� ã����� ���� �Է��ϼ���\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    scanf("%d", &target);
    printf("%d \n", arr[RecursionBinarySearch(&arr[0], target, 0, 9)]);
}

int main() {
    int temp;
    while (1) {
        printf("-------------------------------------\n");
        printf("�� �� ������ Ǫ�ðڽ��ϱ�?\n");
        printf("0.EXIT\n");
        printf("1.���ڿ� ���Ǹ���\n");
        printf("2.���Ҽ� ��(��ȯȣ��)\n");
        printf("3.�Է¹��ڿ� ���̰��(��ȯȣ��)\n");
        printf("4.����Ž��(��ȯȣ��)\n");
        printf("-------------------------------------\n");

        scanf_s("%d", &temp);
        switch (temp) {
        case 0:
            return 0;
        case 1:
            first();
            break;
        case 2:
            second();
            break;
        case 3:
            Thrid();
            break;
        case 4:
            Qurd();
            break;
        default:
            break;
        }
    }
}
