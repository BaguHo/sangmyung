//m부터 n까지 합을 계산하기(m<=n 키보드 입력)
//반복문장 함수(for.while)
//순환호출 함수
//main에서 키보드 입력 후, 함수 호출
#include<stdio.h>
int repeat(int m, int n) {
	int sum = 0;
	int i = 0;
	while (i <= n - m) {
		sum += m;
		m++;
	}
	return sum;
}


int rotation(int m, int n) {
	if (m > n)   return 0;
	else return m + rotation(m + 1, n);
}


int main(void) {
	int m = 0;
	int n = 0;
	printf("m 입력: ");
	scanf_s("%d", &m);
	printf("n 입력: ");
	scanf_s("%d", &n);
	printf("반복함수: %d\n순환함수: %d\n", repeat(m, n), rotation(m, n));
	return 0;
}