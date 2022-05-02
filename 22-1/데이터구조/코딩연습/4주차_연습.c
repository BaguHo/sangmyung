#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USER_LENGTH 9

// id[11] pw[7] 구조체로 입력받고 
// 입력된 id가 있는 아이디인지 찾는 함수 재귀로(이진탐색)
// 로그인이 되면 비밀번호 바꿀지 물어보고 비밀번호 변경하는  함수 
// 입력된 유저 정보 출력 후 
// 그 유저를 오름차순으로 정렬
// 사용자 id를 입력받음
// id 가 맞으면 비밀번호 입력
// 비밀번호 다를 시 다시 입력
// 비밀번호 3회 틀리면 프로그램 종료

typedef struct {
    char id[11];
    char password[7];
}User;

int BinarySearchId(User *p, int top, int bottom, User user){
    if(top > bottom){
        return -1;
    }
    int mid = (top + bottom) / 2;
    int temp = strcmp(user.id, p[mid].id);
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
    BinarySearchId(p, top, bottom, user); 
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
        printf("0.프로그램종료\n");
        printf("1.비밀번호 변경\n");
        scanf("%d", &qurter);

        if(qurter == 0){
            printf("프로그램이 종료됩니다.\n");
            printf("====================================\n");
            return -1;
        }
        else if(qurter == 1){
            printf("현재 비밀번호를 입력해주세요\n");
            scanf("%s", cur.password);

            if(strcmp(user.password, cur.password) == 0){
                printf("비밀번호가 일치합니다.\n");
                printf("============================================\n");
                printf("변경할 비밀번호를 입력해주세요.\n");
                scanf("%s", temp.password);
                for(int i = 0; i < 11; i++){
                    p[user_idx].password[i] = temp.password[i];
                }
                printf("변경한 비밀번호입니다.\n");
                PrintPassword(p, user_idx);
            }
            else{
                printf("비밀번호가 일치하지 않습니다.\n");
                return -1;
            }
        }
    }
}

int Login(User *p, User user){
    int user_idx;
    user_idx = BinarySearchId(p, 0, USER_LENGTH - 1, user);
    if(user_idx == -1){
        printf("id, password를 잘못입력하셨습니다.\n");
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
        printf("0. 프로그램 종료\n");
        printf("1. 로그인\n");
        scanf("%d", &temp);
        
        switch (temp){
        case 0:
            printf("프로그램을 종료합니다\n");
            return 0;
            break;
        case 1:
            for(i = 0; i < 3; i++){    
                printf("id를 입력해주세요\n");
                scanf("%s", user.id);
                printf("password를 입력해주세요\n");
                scanf("%s", user.password);
                //login이 성공하면 user_idx를 return하고 실패하면 -1을 return한다.
                if(user_idx = Login(p, user) == -1){
                    printf("%d번 틀리셨습니다. %d번 남앗습니다.\n", i, 3 - i);
                }
                else{
                    printf("로그인 되었습니다\n");
                    break;
                }
            }
            if(i == 3){
                printf("3번 틀리셨습니다. 프로그램을 종료합니다\n");
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
            printf("0. 프로그램 종료\n");
            printf("1. 로그인\n");
            scanf("%d", &temp);    
            break;
        }
    }
}