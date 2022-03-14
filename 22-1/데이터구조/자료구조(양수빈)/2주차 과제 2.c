//입력된 임의의 정수값들이 정렬된 상태의 정수 배열에서, 특정 값을 이진탐색하기
//1. 이진탐색 알고리즘은 반복문장으로
//2. 정수 배열에서 이진탐색하는 함수를 순환호출 방법으로 작성
//1. 2. 에서 모두 탐색 과정을 추적할 수 있게 출력문장을 적절히 삽입하기.
//EX. 현재 탐색 범위와 킷값을 비교하는 가운데 요소의 위치와 및 값 등
//탐색하는 킷값이 배열에 존재하지 않는 경우 없음을 판단해야 한다.

#include<stdio.h>
#include<stdlib.h>

int Bsearch1(int* arr, int target,int top, int bottom) {
	int mid;
	int num = 1;
	int time = 1;
	while (top <= bottom) {
		mid = (top + bottom) / 2;

		printf("%d. mid[%d]: %d\n", num, mid, arr[mid]);
		printf("\n");

		if (target == arr[mid]) {
			return printf("target's index: arr[%d]\nnumber of times: %d\n", mid, time);
		}
		else {
			if (target > arr[mid]) {
				top = mid + 1;
			}
			else {
				bottom = mid - 1;
			}
		}
		num++;
		time++;
	}

	return printf("Not Found\n");
}

int Bsearch2(int* arr, int target,int top, int bottom,int num, int time) {
	int mid;
	
	if (top > bottom)
		return printf("Not Found\n");

	mid = (top + bottom) / 2;

	num++;
	time++;
	
	printf("%d. mid[%d]: %d\n", num, mid, arr[mid]);
	printf("\n");

	if (target == arr[mid])
		return printf("target's index: arr[%d]\nnumber of times: %d\n", mid, time);
	else if (target > arr[mid])
		return Bsearch2(arr, target, mid + 1, bottom, num, time);
	else
		return Bsearch2(arr, target, top, mid - 1, num, time);
}

int main(void) {
	int no = 0;
	int num = 0;
	int time = 0;

	printf("how many numbers will you enter?: ");
	scanf("%d", &no);

	int* arr = malloc(sizeof(int) * no);
	int len = _msize(arr) / sizeof(int);//arr size

	printf("enter numbers(%d): ",no);
	for (int i = 0; i < no; i++) {
		scanf("%d", &arr[i]);
	}

	int temp = 0;

	for (int i = 0; i < no; i++){
		for (int j = 0; j < no-1; j++){
			if (arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}//for(j)
	}//for(i)

	for (int i = 0; i < no; i++) {
		printf("{%d}", arr[i]);
	}
	
	printf("\n");

	int target = 0;
	printf("target?: ");
	scanf("%d", &target);

	int top = 0;
	int bottom = len - 1;

	printf("--1st Binary Search result--\n");
	printf("\n");
	Bsearch1(arr, target, top, bottom);
	
	printf("\n");

	printf("--2nd Binary Search result--\n");
	printf("\n");
	Bsearch2(arr, target, top, bottom, num, time);

	free(arr);

	return 0;
}