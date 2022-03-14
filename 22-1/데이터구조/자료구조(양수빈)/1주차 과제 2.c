//���ڿ��� ���� ����ϱ�(���ڿ� Ű�����Է�)
//strlen() ���x
//1�� �Լ�- �ݺ�����(for,while) �迭�� �ε���[]���
//2�� �Լ�- �ݺ�����(for,while) �����Ϳ���, s[i](X) *(s+i)(O)
//3�� �Լ�- ��ȯȣ��

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
	printf("���ڿ� �Է�: ");
	scanf("%s", str);

	printf("�ݺ�����1: %d\n", repeat1(str));
	printf("�ݺ�����2: %d\n", repeat2(str));
	printf("��ȯȣ��: %d\n", rotation(str));
	free(str);
	return 0;
}