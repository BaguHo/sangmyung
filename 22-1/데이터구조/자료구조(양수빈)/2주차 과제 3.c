//���п����� ���Ҽ� (�Ǽ��ο� ����θ� ���� x+yi)�� ǥ���ϱ� ���� ����ü ����
//���Ҽ� 10�� �����ϴ� �迭
//�迭�� ���Ҽ����� ��� ���� ����� ���ϴ� �Լ��� �ۼ��ϰ� main()�Լ��� �̿��ؼ� ȣ���ϰ� , ����� Ȯ���Ͻÿ�.
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	double x;
	double y;
}number;

void numadd(number *ptr) {
	number add;
	add.x = 0;
	add.y = 0;

	for (int i = 0; i < 10; i++) {
		printf("%d��° �Է��� ���Ҽ����� �Ǽ��κ�: %lf, ����κ�: %lfi\n",i+1,ptr[i].x,ptr[i].y);
	}

	for (int i = 0; i < 10; i++) {
		add.x += ptr[i].x;
		add.y += ptr[i].y;
	}
	printf("���Ҽ����� �Ǽ��κ�: %lf, ����κ�: %lfi",add.x,add.y);
}

int main(void) {
	number* ptr = malloc(sizeof(number) * 10);
	
	printf("���Ҽ� 10���� �Է��ϼ���\n");
	for (int i = 0; i < 10; i++) {
		scanf("%lf %lf", &ptr[i].x, &ptr[i].y);
	}

	numadd(ptr);

	free(ptr);
	return 0;
}
/*
1.2 2.4
1.1 2.2
1.3 2.5
2.1 3.4
3.4 2.3
4.5 1.1
0.2 1.3
1.2 3.3
2.0 1.1
1.9 5.1
*/