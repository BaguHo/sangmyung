//��� ���� ��ǥ(x,y) ǥ���ϴ� ����ü ����
//1���Լ�: ��ǥ�Է½�, �������κ��� �Ÿ� ����ϰ� ��ȯ
//x,y�Է½� 1���Լ� ȣ���ؼ� ��ȯ�Ǵ� �� ���(�Ÿ����)
//2���Լ�: �迭�� ����� 5�� ��ǥ �� ������������ ���� �� ��ǥ ���ϱ�

#include<stdio.h>
#include<math.h>
typedef struct {
	int x;
	int y;
}location;

double distance(location *keyboard) {
	return sqrt((keyboard->x * keyboard->x) + (keyboard->y * keyboard->y));
}

location farthest(location *ptr) {
	location *max = &ptr[0];
	for (int i = 0; i < 5; i++) {
		if (distance(&ptr[i]) > distance(max)) {
			max = &ptr[i];
		}
	}
	return *max;
}

int main(void) {
	location ptr[5]=
	{
		{0.3},
		{4,3},
		{2,1},
		{5,5},
		{4,0} 
	};
	location keyboard;

	printf("x��ǥ �Է�: ");
	scanf("%d", &keyboard.x);
	printf("y��ǥ �Է�: ");
	scanf("%d", &keyboard.y);
	printf("\n<�迭 �� ��ǥ>\n\n");

	for (int i = 0; i < 5; i++) {
		printf("(%d, %d)\n", ptr[i].x, ptr[i].y);
	}

	printf("�Է��� ��ǥ�� �������κ��� �Ÿ�: %f\n", distance(&keyboard.x,&keyboard.y));
	printf("���� �Ÿ��� �� ��ǥ: (%d, %d)", farthest(ptr));
	return 0;
}