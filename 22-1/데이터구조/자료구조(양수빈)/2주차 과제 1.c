//��ȯ
//������ ���� 10���� �迭�� �����ϰ�, �ִ밪�� ã�� ������ ���α׷��� ��ȯȣ���� �̿��ؼ� �ۼ��Ͻÿ�.

#include<stdio.h>
int rotation(int* ptr, int n, int max)
{
	if (n<10){
		if (ptr[n] > max)
			max = ptr[n];
		max = rotation(ptr, n + 1, max);
	}
	return max;
}
	
int main(void) {
	int ptr[10] = { 3, 5, 14, 1, 23, 45, 7, 10, 33, 57};
	
	printf("<ptr>\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", ptr[i]);
	}
	
	printf("\n");

	int n = 1;
	int max = ptr[0];

	max = rotation(ptr, n, max);
	printf("ptr max: %d", max);
	return 0;
}