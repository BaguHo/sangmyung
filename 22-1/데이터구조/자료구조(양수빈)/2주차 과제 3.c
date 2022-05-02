//수학에서의 복소수 (실수부와 허수부를 갖는 x+yi)를 표현하기 위한 구조체 정의
//복소수 10개 저장하는 배열
//배열의 복소수들을 모두 합한 결과를 구하는 함수를 작성하고 main()함수를 이용해서 호출하고 , 결과를 확인하시오.
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
		printf("%d번째 입력한 복소수에서 실수부분: %lf, 허수부분: %lfi\n",i+1,ptr[i].x,ptr[i].y);
	}

	for (int i = 0; i < 10; i++) {
		add.x += ptr[i].x;
		add.y += ptr[i].y;
	}
	printf("복소수에서 실수부분: %lf, 허수부분: %lfi",add.x,add.y);
}

int main(void) {
	number* ptr = malloc(sizeof(number) * 10);
	
	printf("복소수 10개를 입력하세요\n");
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