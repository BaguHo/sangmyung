//문자열의 길이 계산하기(문자열 키보드입력)
//strlen() 사용x
//1번 함수- 반복문장(for,while) 배열의 인덱스[]사용
//2번 함수- 반복문장(for,while) 포인터연산, s[i](X) *(s+i)(O)
//3번 함수- 순환호출

#include<stdio.h>
int repeat1(char *str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int repeat2(char *str) {
	int i = 0;
	while (*(str + i) != '\0')
		i++;
	return i;
}


int rotation(char *str) {
	if (*str== '\0')	return 0;
	else return 1 + rotation(str+1);
}

int main(void) {
	char* str = malloc(sizeof(char) * 10);
	printf("문자열 입력: ");
	scanf("%s", str);

	printf("반복문장1: %d\n", repeat1(str));
	printf("반복문장2: %d\n", repeat2(str));
	printf("순환호출: %d\n", rotation(str));
	free(str);
	return 0;
}