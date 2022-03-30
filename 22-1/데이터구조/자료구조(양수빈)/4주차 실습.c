#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char id[11];
	char password[7];
}users;

int search(users *str, int top, int bottom, users test) {
	if (top > bottom) {
		return -1;
	}

	int mid = (top + bottom) / 2;

	if (strcmp(test.id, str[mid].id)==0) {
		return mid;
	}
	else {
		if (strcmp(test.id, str[mid].id)== 1)
			top = mid + 1;
		else {
			bottom = mid - 1;
		}
	}
	search(str, top, bottom, test);
}

int change_password(users* str, users* test,int result) {
	int choice;
	char test2_password[7];

	if (strcmp(str[result].password, test->password) == 0) {
		printf("�α����� �Ǿ����ϴ�.");
		printf("password�� �����Ͻðڽ��ϱ� ? 1.���� 2.����\n");
		scanf("%d", &choice);
		if (choice == 2) {
			printf("����Ǿ����ϴ�.\n");
			return 0;
		}
		else {
			printf("������ ��й�ȣ�� �Է��ϼ���: ");
			scanf("%s", test2_password);//������� �ȵȴ縣�ξ�; ���Ƥä�; ����
			printf("%s", test2_password);
			strcpy(str[result].password, test2_password);

			printf("\n");

			printf("������ �� ��й�ȣ ��ġ �˻��Դϴ�. ��й�ȣ�� �Է��ϼ���: ");
			scanf("%s", &str[result].password);
		}
	}
	if (strcmp(str[result].password, test2_password) == 0) {
		printf("��й�ȣ�� ���������� ����Ǿ����ϴ�.\n");
		return 0;
	}
	else{
		printf("������ ���� �����մϴ�.");
		return 0;
	}
}

int main(void) {
	users str[9] = {
		{"apple","123411"},
		{"banana", "234599"},
		{"orange","345688"},
		{"peach","456777"},
		{"tomato", "567866"},
		{"lemon","678955"},
		{"melon","135744"},
		{"watermelon","357333"},
		{"strawberry", "246222"},
	};

	printf("<users infomation>\n");
	for (int i = 0; i < 9; i++) {
		printf("%d. [%s] [%s]\n", i + 1, str[i].id, str[i].password);
	}


	printf("\n");

	users  temp = { 0,0 };
	for (int i = 0; i < 8; i++){
		for (int j = i+1; j < 9; j++){
			if (strcmp(str[i].id, str[j].id)>0){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	printf("<asending>\n");
	for (int i = 0; i < 9; i++) {
		printf("%d. [%s][%s]\n", i+1, str[i].id, str[i].password);
	}

	printf("\n");

	users test;
	printf("������� id�� �Է��ϼ���: ");
	scanf("%s",&test.id);
	
	int len = sizeof(test.id) / sizeof(char);//id size
	int top = 0;
	int bottom = len - 1;
	int result;
	result= search(str, top, bottom, test);
	
	if (result == -1) {
		printf("id�� �����ϴ�\n");
		return 0;
	}
	
	printf("��й�ȣ�� �Է��ϼ���: ");
	scanf("%s", &test.password);

	//printf("id: %s password:%s\n", test.id, test.password);

	char test2_password = { 0 };
	int num = 1;

	if (strcmp(str[result].password, test.password) != 0) {
		while (num < 4) {
			printf("��й�ȣ�� �ٸ��ϴ�. �ٽ� �Է��ϼ���.(%dȸ ����)\n", num);
			num++;
			scanf("%s", &test.password);

			if (strcmp(str[result].password, test.password) == 0) {
				return change_password(str, &test, result);
			}

			if (num == 3) {
				printf("3ȸ Ʋ���̽��ϴ�. �����մϴ�\n");
				return 0;
			}
		}
	}
	else
		return change_password(str, &test, result);
	
	return 0;
}