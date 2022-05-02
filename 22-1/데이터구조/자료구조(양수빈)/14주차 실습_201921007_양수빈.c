//문제
/*
이진트리 연산 프로그래밍
아래와 같이 정의된 이진트리에 대해 아래 1~5의 함수를 작성하고 테스트하시오.

typedef struct TreeNode{
   int data;
   struct TreeNode *left,*right;
}TreeNode;

1.이진트리를 레벨 순서로 순회하는 함수.
2.이진트리의 레벨 x에 몇 개의 노드가 있는지 계산하는 함수.
3.이진트리의 모든 노드에서 왼쪽 서브트리와 오른쪽 서브트리의 높이가 최대 1차이가 나는 트리를
"균형트리"라고 한다. 주어진 트리가 균형트리인지 확인하는 함수
4.이진트리를 좌우로 대칭시키는 함수.
(결과를 확인하는 방법은 대칭 전후로 레벨 단위로 순회한 결과를 출력)

main()에서는 위1~5에서 작성한 함수를 각각 호출하여 결과를 확인한다.
테스트를 위한 서로 다른 세 개의 이진트리(노드 10개)를 초기화해서 사용하시오.
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
}TreeNode;


//============= 원형큐 코드 시작 ================

#define MAX_QUEUE_SIZE 100
#define true 1
#define false 0

typedef TreeNode* element;
typedef struct {
    element data[MAX_QUEUE_SIZE];//큐 타입
    int front, rear;
}QueueType;

int result = 0;

//오류함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입 함수
void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

//============= 원형큐 코드 끝 ================

void level_order(TreeNode* ptr) {
    QueueType q;
    init_queue(&q);
    if (ptr == NULL)   return;
    enqueue(&q, ptr);
    while (!is_empty(&q)) {
        ptr = dequeue(&q);
        printf("[%d] ", ptr->data);
        if (ptr->left) {
            enqueue(&q, ptr->left);
        }

        if (ptr->right) {
            enqueue(&q, ptr->right);
        }
    }
}

int get_height(TreeNode* node) {
    int height = 0;
    if (node != NULL)
        height = 1 + max(get_height(node->left), get_height(node->right));
    return height;
}

int isBalanced(TreeNode* node) {
    int leftHeight = 0;
    int rightHeight = 0;
    if (node != NULL) {
        leftHeight = get_height(node->left);
        rightHeight = get_height(node->right);
        //왼쪽 서브트리와 오른쪽서브트리의 높이차가 1을 넘길 때
        if (abs(leftHeight - rightHeight) > 1)
            return false;
        else {
            isBalanced(node->left);
            isBalanced(node->right);
            if (node == NULL) return true;
        }
    }
}

void reverse(TreeNode* node) {
    if (node == NULL)
        return;
    else {
        reverse(node->left);
        reverse(node->right);//후위순회
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int getLevel(TreeNode* node) {
    if (node == NULL) return 0;

    int lLevel = getLevel(node->left);
    int rLevel = getLevel(node->right);

    if (lLevel > rLevel) return lLevel + 1;
    else return rLevel + 1;
}

int count_node(TreeNode* root, int x, int cnt) {
    if (root != NULL) {
        if (x == cnt) {
            result++;
            return;
        }
        count_node(root->left, x, cnt + 1);
        count_node(root->right, x, cnt + 1);
    }
}

//균형트리[1]
/*
TreeNode n1 = { 3,NULL,NULL };
TreeNode n2 = { 8,NULL,NULL };
TreeNode n3 = { 1,&n1,&n2 };
TreeNode n4 = { 9,NULL,NULL };
TreeNode n5 = { 6,&n4,NULL };
TreeNode n6 = { 4,&n3,&n5 };
TreeNode n7 = { 2,NULL,NULL };
TreeNode n8 = { 7,NULL,NULL };
TreeNode n9 = { 10,&n7,&n8 };
TreeNode n10 = { 5,&n6,&n9 };
TreeNode* root = &n10;
*/
/*
              5
            /    ＼
            4      10
          /  ＼   /  ＼
         1    6  2    7
         / ＼ /
         3   8 9
*/

//균형이 아닌 트리 [2]
/*
TreeNode n0 = { 11,NULL,NULL };
TreeNode n1 = { 3,&n0,NULL };
TreeNode n2 = { 8,NULL,NULL };
TreeNode n3 = { 1,&n1,&n2 };
TreeNode n4 = { 9,NULL,NULL };
TreeNode n5 = { 6,&n4,NULL };
TreeNode n6 = { 4,&n3,&n5 };
TreeNode n7 = { 2,NULL,NULL };
TreeNode n8 = { 7,NULL,NULL };
TreeNode n9 = { 10,&n7,&n8 };
TreeNode n10 = { 5,&n6,&n9 };
TreeNode* root = &n10;
*/
/*
              5
            /    ＼
            4      10
          /  ＼   /  ＼
         1    6  2    7
         / ＼ /
         3  8 9
         /
        11
*/

//균형트리 [3]
/*
TreeNode n1 = { 11,NULL,NULL };
TreeNode n2 = { 7,&n1,NULL };
TreeNode n3 = { 13,NULL,NULL };
TreeNode n4 = { 12,NULL,NULL };
TreeNode n5 = { 2,&n3,&n4 };
TreeNode n6 = { 10,&n5,&n2 };
TreeNode n7 = { 9,NULL,NULL };
TreeNode n8 = { 6,&n7,NULL };
TreeNode n9 = { 3,NULL,NULL };
TreeNode n10 = { 8,NULL,NULL };
TreeNode n11 = { 1,&n9,&n10 };
TreeNode n12 = { 4,&n11,&n8 };
TreeNode n13 = { 5,&n12,&n6 };
TreeNode* root = &n13;
*/

/*
              5
            /    ＼
            4      10
          /  ＼   /  ＼
         1    6  2    7
        / ＼ /  / ＼ /
       3   8 9 13 12 11
*/

//균형이 아닌 트리 [4]
/*
TreeNode zero = {13,NULL,NULL};
TreeNode n0 = { 11,&zero,NULL };
TreeNode n1 = { 3,&n0,NULL };
TreeNode n2 = { 8,NULL,NULL };
TreeNode n3 = { 1,&n1,&n2 };
TreeNode n4 = { 9,NULL,NULL };
TreeNode n5 = { 6,&n4,NULL };
TreeNode n6 = { 4,&n3,&n5 };
TreeNode n7 = { 2,NULL,NULL };
TreeNode n8 = { 7,NULL,NULL };
TreeNode n9 = { 10,&n7,&n8 };
TreeNode n10 = { 5,&n6,&n9 };
TreeNode* root = &n10;

*/
/*
              5
            /    ＼
            4      10
          /  ＼   /  ＼
         1    6  2    7
         / ＼ /
         3  8 9
         /
        11
        /
       13
*/

//균형이 아닌 트리 [5]

TreeNode e1 = { 3, NULL, NULL };
TreeNode e2 = { 5, NULL, NULL };
TreeNode e3 = { 4, &e1, &e2 };
TreeNode e4 = { 6, NULL, NULL };
TreeNode e5 = { 8, &e3, NULL };
TreeNode e6 = { 7, NULL, NULL };
TreeNode e7 = { 9, NULL, &e6 };
TreeNode e8 = { 11, &e4, &e5 };
TreeNode e9 = { 12, NULL, &e7 };
TreeNode e10 = { 10, &e8, &e9 };
TreeNode* root = &e10;

/*
             10
            /    ＼
           11      12
          /  ＼       ＼
          6     8        9
              /          ＼
             4              7
            / ＼
            3    5
*/


void menu() {
    printf("==============================\n");
    printf("1. 레벨순회 출력\n");
    printf("2. 레벨 노드 개수\n");
    printf("3. 균형트리 검사\n");
    printf("4. 트리 좌우반전\n");
    printf("0. 종료\n");
    printf("==============================\n");
    printf("선택: ");
}

int main(void) {
    int ch;
    int x;
    int cnt = 1;
    while (1) {
        menu();
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("레벨 순회= ");
            level_order(root);
            printf("\n");
            break;
        case 2:
            printf("검색할 레벨: ");
            scanf("%d", &x);
            count_node(root, x, cnt);
            printf("레벨의 노드 개수: %d\n", result);
            printf("\n");
            result = 0;
            break;
        case 3:
            if (isBalanced(root) == false) printf("균형트리가 아닙니다.\n");
            else
                printf("균형트리입니다.\n");
            break;
        case 4:
            reverse(root);
            printf("성공\n");
            printf("\n");
            break;
        case 0:
            break;
        default:
            printf("잘못된 입력\n");
            printf("다시 입력하세요.\n");
        }
        if (ch == 0)   break;
    }
    printf("종료합니다.\n");
    return 0;
}