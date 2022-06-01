/*
(파일 입출력 처리가 난이도가 높아서 어려운 경우, 키보드 입력으로 대신할 수 있습니다)

자신이 작성하는 c언어 소스코드 파일에 각 예약어가 얼마나 자주 등장하는지를 계산하는 프로그램을 이진탐색트리를 사용하여 구현하시오.

(1) 입력: 자신이 작성한 임의의 c 프로그램 소스파일을 "bst_in.txt"라고 파일명을 지정한다.
    출력: 출현한 예약어들과 출현빈도(예약어들의 오름차순) 화면 출력한다.
          또는 출력파일을 "bst_out.txt"로 생성한다.
(2) c언어의 예약어들 중에서 다음 예약어들의 출현 빈도를 계산한다.
    {"break", "case", "do", "else", "for", "if", "int", "return", "switch", "while", "else if"}
    이 외에도 자신이 자주 사용하는 다른 예약어들을 추가할 것을 권장함.
(3) 이진탐색트리 각 노드의 데이터 필드는 예약어(문자열)과 출현빈도(정수)이다.
(4) 입력파일을 차례로 읽으면서
    - 처음 출현하는 예약어는 이진탐색트리에 삽입하고 출현빈도를 1로 초기화한다.
    - 검색 중 이미 트리에 존재하는 예약어는 출현빈도를 1만큼 증가시킨다.
(5) 완성된 이진탐색트리를 중위순회하면서 예약어들과 출현빈도를 함께 출력한다.
(6) 가장 자주 출현한 예약어(빈도수 최대값)가 무엇인지 찾아서 출력한다.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#define MAX 1000 


typedef struct TreeNode {
    char key[MAX];
    int fre;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode* root = NULL;
TreeNode* maximum;

//노드검색
TreeNode* search(TreeNode* node, char *key) {
    if (node == NULL) return NULL;
    
    if (strcmp(key, node->key) == 0) {
        node->fre++;
        return 0;
    }

    else if (strcmp(key, node->key) == -1) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

//노드생성
TreeNode* new_node(char *item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->key,item);
    temp->fre = 1;//빈도 1로 초기화
    temp->left = temp->right = NULL;
    return temp;
}

//노드삽입
TreeNode* insert_node(TreeNode* node, char *key) {
    //트리가 공백이면 새로운 노드를 반환
    if (node == NULL) return new_node(key);
    //그렇지 않으면 순환적으로 트리 내려가면서 자리 찾기
    if (strcmp(key, node->key) == -1)   node->left = insert_node(node->left, key);
    else if (strcmp(key, node->key) == 1)  node->right = insert_node(node->right, key);
    //변경된 루트 포인터 반환
    return node;
}

//중위순회
void inorder(TreeNode* root,FILE* fp2) {
    if (root) {
        inorder(root->left,fp2); //왼쪽서브트리 순회
        fprintf(fp2, "**[%s]: %d\n", root->key, root->fre);
        inorder(root->right,fp2); //오른쪽서브트리 순회
    }
}

//빈도 최대값
TreeNode* findmax(TreeNode* node) {
    if (node != NULL) {
        findmax(node->left);//왼쪽순회
        findmax(node->right);//오른쪽순회
        if (maximum->fre <= node->fre) {
            strcpy(maximum->key, node->key);
            maximum->fre = node->fre;
        }
    }
    return 0;
}

int main(void) {
    FILE* fp1 = fopen("bst_in.txt", "r");
    FILE* fp2 = fopen("bst_out.txt", "w+");
    if (fp1 == NULL) {
        printf("파일이 존재하지 않습니다.\n");
        exit(1);
    }

    char *p = malloc(sizeof(char) * MAX);
    char *arr[] = { "void","fprintf","printf","break","case","do", "else", "for", "if", "int", "return", "switch", "while" };

    while (!feof(fp1)) {
        fscanf(fp1, "%s", p);//공백단위로 받아옴
        for (int i = 0; i < 13; i++) {
            if (strstr(p, arr[i])) {
                if (search(root, arr[i]) == NULL) {
                    root = insert_node(root, arr[i]);
                    break;//다음 단어 받아오기
                }
                else continue;
            }
        }
    }

    inorder(root,fp2);//중위순회로 출력

    maximum = root;
    findmax(root);

    fprintf(fp2, "***************************\n");
    fprintf(fp2,"**빈도 최대 값-> %s: %d\n", maximum->key,maximum->fre);

    free(p);
    fclose(fp2);
    fclose(fp1);

    printf("완료\n");
    return 0;
}