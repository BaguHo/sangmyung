//평면 상의 좌표(x,y) 표현하는 구조체 정의
//1번함수: 좌표입력시, 원점으로부터 거리 계산하고 반환
//x,y입력시 1번함수 호출해서 반환되는 값 출력(거리출력)
//2번함수: 배열에 저장된 5개 좌표 중 원점에서부터 제일 먼 좌표 구하기

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

	printf("x좌표 입력: ");
	scanf("%d", &keyboard.x);
	printf("y좌표 입력: ");
	scanf("%d", &keyboard.y);
	printf("\n<배열 속 좌표>\n\n");

	for (int i = 0; i < 5; i++) {
		printf("(%d, %d)\n", ptr[i].x, ptr[i].y);
	}

	printf("입력한 좌표의 원점으로부터 거리: %f\n", distance(&keyboard.x,&keyboard.y));
	printf("가장 거리가 먼 좌표: (%d, %d)", farthest(ptr));
	return 0;
}