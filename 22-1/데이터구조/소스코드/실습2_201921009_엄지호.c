#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//1번 대소문자 판별함수 사용가능
//2번 복소수합 순환함수로 
//3번 순한함수로 length 구하는 
//4번 정렬된 정수배열 이진탐색 순환함수

void IsFull(char* str) {
    int temp = 0;
    if (strchr(str, '!') != '\0' && strchr(str, '?') != '\0' && strchr(str, '*') != '\0' &&
     strchr(str, '#') != '\0' && strchr(str, '$') != '\0') {
        printf("특수문자가 없습니다.\n");
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]) != 0) {
            temp += 1;
        }
    }
    if (temp == 0)
        printf("대문자가 없습니다.\n");
    temp = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i]) != 0) {
            temp += 1;
        }
    }
    if (temp == 0)
        printf("소문자가 없습니다.\n");
    if(strlen(str) < 10) {
        printf("10자 이하입니다.\n");
    }
}

void first() {
    char str[100];
    printf("문자열을 입력해주세요\n");
    scanf("%s", str);
    IsFull(&str[0]);
}

typedef struct __complex {
    double x;
    double y;
}complex_num;

// 재귀함수로 구현한 덧셈
void sum(int n, complex_num* temp, double x, double y) {
    if (n < 1) {
        printf("결과: %lf + %lf\n", x, y);
        return 0;
    }
    printf("현재까지의 합: %lf + %lf\n", x, y);
    sum(n - 1, temp + 1, x += temp->x , y += temp->y);
}

void second() {
    int n;
    printf("몇 개의 복소수를 입력하시겠습니까?\n");
    scanf("%d", &n);
    complex_num* arr = malloc(sizeof(complex_num) * n);
    printf("복소수 실수부분, 허수부분을 입력해주세요\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &arr[i].x, &arr[i].y);
        printf("%lf %lf\n", arr[i].x, arr[i].y);
    }
    sum(n, arr, 0, 0);
    free(arr);
}

// 재귀함수
int length(char* str, int i) {
    if (*str == '\0') {
        return 0;
    }
    else {
        printf("문자열의 길이를 구하는 과정: %d\n", i + 1);
        return 1 + length(str + 1, i + 1);
    }
}

void Thrid() {
    char str[100];
    printf("문자열을 입력해주세요\n");
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

// 찾고 싶은 수를 이진탐색을 이용한 재귀함수로 구현
void Qurd() {
    int target;
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("다음 수 중 찾고싶은 수를 입력하세요\n");
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
        printf("몇 번 문제를 푸시겠습니까?\n");
        printf("0.EXIT\n");
        printf("1.문자열 조건만족\n");
        printf("2.복소수 합(순환호출)\n");
        printf("3.입력문자열 길이계산(순환호출)\n");
        printf("4.이진탐색(순환호출)\n");
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
