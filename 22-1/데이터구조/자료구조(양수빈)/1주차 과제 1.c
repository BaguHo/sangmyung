//m���� n���� ���� ����ϱ�(m<=n Ű���� �Է�)
//�ݺ����� �Լ�(for.while)
//��ȯȣ�� �Լ�
//main���� Ű���� �Է� ��, �Լ� ȣ��
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
	printf("m �Է�: ");
	scanf_s("%d", &m);
	printf("n �Է�: ");
	scanf_s("%d", &n);
	printf("�ݺ��Լ�: %d\n��ȯ�Լ�: %d\n", repeat(m, n), rotation(m, n));
	return 0;
}