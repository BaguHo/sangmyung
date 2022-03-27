#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USER_LENGTH 9

// id[11] pw[7] ����ü�� �Է¹ް� 
// �Էµ� id�� �ִ� ���̵����� ã�� �Լ� ��ͷ�(����Ž��)
// �α����� �Ǹ� ��й�ȣ �ٲ��� ����� ��й�ȣ �����ϴ�  �Լ� 
// �Էµ� ���� ���� ��� �� 
// �� ������ ������������ ����
// ����� id�� �Է¹���
// id �� ������ ��й�ȣ �Է�
// ��й�ȣ �ٸ� �� �ٽ� �Է�
// ��й�ȣ 3ȸ Ʋ���� ���α׷� ����

typedef struct {
    char id[11];
    char password[7];
}User;

int BinarySearchId(User *p, int top, int bottom, User test){
    if(top > bottom){
        return -1;
    }
    int mid = top * bottom / 2;
    int temp = strcmp(test.id, p[mid].id);
    if(temp == 0){
        return mid;
    }
    else{
        if(temp == 1){
            top = mid;
        }
        else{
            bottom = mid;
        }
    }
    BinarySearchId(p, top, bottom, test); 
}

void PrintPassword(User *p, int user_idx){
    printf("%s\n", p[user_idx].password);
}

void Ascending(User *p){
    User min;
    User temp;
    int idx;
    for(int i = 0; i < USER_LENGTH - 1; i++){
       if(strcmp(p[i].id, p[i + 1].id) == -1){
            for(int k = i; k < USER_LENGTH - 1; k++){
                if(strcmp(p[k].id, p[k + 1].id) == -1){
                    min = p[k];
                    idx = k;
                }
            }
            temp = p[i];
            p[i] = min;
            p[idx] = temp;
        }
    }
}

int ChangePassword(User *p, User user, int user_idx){
    User cur;
    User temp;
    int qurter;

    while(1){
        printf("0.���α׷�����\n");
        printf("1.��й�ȣ ����\n");
        scanf("%d", &qurter);

        if(qurter == 0){
            printf("���α׷��� ����˴ϴ�.\n");
            printf("====================================\n");
            return -1;
        }
        else if(qurter == 1){
            printf("���� ��й�ȣ�� �Է����ּ���\n");
            scanf("%s", cur.password);

            if(strcmp(user.password, cur.password) == 0){
                printf("��й�ȣ�� ��ġ�մϴ�.\n");
                printf("============================================\n");
                printf("������ ��й�ȣ�� �Է����ּ���.\n");
                scanf("%s", temp.password);
                for(int i = 0; i < 11; i++){
                    p[user_idx].password[i] = temp.password[i];
                }
                printf("������ ��й�ȣ�Դϴ�.\n");
                PrintPassword(p, user_idx);
            }
            else{
                printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n");
                return -1;
            }
        }
    }
}

int Login(User *p, User user){
    int user_idx;
    user_idx = BinarySearchId(p, 0, USER_LENGTH - 1, user);
    if(user_idx == -1){
        printf("id, password�� �߸��Է��ϼ̽��ϴ�.\n");
        return -1;
    }
    return user_idx;
}

int main(){
    User p[USER_LENGTH] ={
		{"apple", "123411"},
		{"banana", "234599"},
		{"orange", "345688"},
		{"peach","456777"},
		{"tomato", "567866"},
		{"lemon","678955"},
		{"melon","135744"},
		{"watermelon","357333"},
		{"strawberry", "246222"}    
    };
    // Ascending(p);
    while(1){
        int temp;
        User user;
        int i;
        int user_idx;
        printf("0. ���α׷� ����\n");
        printf("1. �α���\n");
        scanf("%d", &temp);
        
        switch (temp){
        case 0:
            printf("���α׷��� �����մϴ�\n");
            return 0;
            break;
        case 1:
            for(i = 0; i < 3; i++){    
                printf("id�� �Է����ּ���\n");
                scanf("%s", user.id);
                printf("password�� �Է����ּ���\n");
                scanf("%s", user.password);
                //login�� �����ϸ� user_idx�� return�ϰ� �����ϸ� -1�� return�Ѵ�.
                if(user_idx = Login(p, user) == -1){
                    printf("%d�� Ʋ���̽��ϴ�. %d�� ���ѽ��ϴ�.\n", i, 3 - i);
                }
                else{
                    printf("�α��� �Ǿ����ϴ�\n");
                    break;
                }
            }
            if(i == 3){
                printf("3�� Ʋ���̽��ϴ�. ���α׷��� �����մϴ�\n");
                return 0;
            }
            printf("=====================================================\n");
            int num = ChangePassword(p, user, user_idx);
            if(num == -1){
                return 0;
                break;
            }
            break;
        default:
            printf("0. ���α׷� ����\n");
            printf("1. �α���\n");
            scanf("%d", &temp);    
            break;
        }
    }
}