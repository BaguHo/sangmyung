//����
/*
����Ʈ�� ���� ���α׷���
�Ʒ��� ���� ���ǵ� ����Ʈ���� ���� �Ʒ� 1~5�� �Լ��� �ۼ��ϰ� �׽�Ʈ�Ͻÿ�.

typedef struct TreeNode{
   int data;
   struct TreeNode *left,*right;
}TreeNode;

1.����Ʈ���� ���� ������ ��ȸ�ϴ� �Լ�.
2.����Ʈ���� ���� x�� �� ���� ��尡 �ִ��� ����ϴ� �Լ�.
3.����Ʈ���� ��� ��忡�� ���� ����Ʈ���� ������ ����Ʈ���� ���̰� �ִ� 1���̰� ���� Ʈ����
"����Ʈ��"��� �Ѵ�. �־��� Ʈ���� ����Ʈ������ Ȯ���ϴ� �Լ�
4.����Ʈ���� �¿�� ��Ī��Ű�� �Լ�.
(����� Ȯ���ϴ� ����� ��Ī ���ķ� ���� ������ ��ȸ�� ����� ���)

main()������ ��1~5���� �ۼ��� �Լ��� ���� ȣ���Ͽ� ����� Ȯ���Ѵ�.
�׽�Ʈ�� ���� ���� �ٸ� �� ���� ����Ʈ��(��� 10��)�� �ʱ�ȭ�ؼ� ����Ͻÿ�.
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
}TreeNode;


//============= ����ť �ڵ� ���� ================

#define MAX_QUEUE_SIZE 100
#define true 1
#define false 0

typedef TreeNode* element;
typedef struct {
    element data[MAX_QUEUE_SIZE];//ť Ÿ��
    int front, rear;
}QueueType;

int result = 0;

//�����Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//���� ���� ���� �Լ�
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//���� �Լ�
element dequeue(QueueType* q) {
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

//============= ����ť �ڵ� �� ================

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
        //���� ����Ʈ���� �����ʼ���Ʈ���� �������� 1�� �ѱ� ��
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
        reverse(node->right);//������ȸ
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

//����Ʈ��[1]
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
            /    ��
            4      10
          /  ��   /  ��
         1    6  2    7
         / �� /
         3   8 9
*/

//������ �ƴ� Ʈ�� [2]
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
            /    ��
            4      10
          /  ��   /  ��
         1    6  2    7
         / �� /
         3  8 9
         /
        11
*/

//����Ʈ�� [3]
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
            /    ��
            4      10
          /  ��   /  ��
         1    6  2    7
        / �� /  / �� /
       3   8 9 13 12 11
*/

//������ �ƴ� Ʈ�� [4]
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
            /    ��
            4      10
          /  ��   /  ��
         1    6  2    7
         / �� /
         3  8 9
         /
        11
        /
       13
*/

//������ �ƴ� Ʈ�� [5]

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
            /    ��
           11      12
          /  ��       ��
          6     8        9
              /          ��
             4              7
            / ��
            3    5
*/


void menu() {
    printf("==============================\n");
    printf("1. ������ȸ ���\n");
    printf("2. ���� ��� ����\n");
    printf("3. ����Ʈ�� �˻�\n");
    printf("4. Ʈ�� �¿����\n");
    printf("0. ����\n");
    printf("==============================\n");
    printf("����: ");
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
            printf("���� ��ȸ= ");
            level_order(root);
            printf("\n");
            break;
        case 2:
            printf("�˻��� ����: ");
            scanf("%d", &x);
            count_node(root, x, cnt);
            printf("������ ��� ����: %d\n", result);
            printf("\n");
            result = 0;
            break;
        case 3:
            if (isBalanced(root) == false) printf("����Ʈ���� �ƴմϴ�.\n");
            else
                printf("����Ʈ���Դϴ�.\n");
            break;
        case 4:
            reverse(root);
            printf("����\n");
            printf("\n");
            break;
        case 0:
            break;
        default:
            printf("�߸��� �Է�\n");
            printf("�ٽ� �Է��ϼ���.\n");
        }
        if (ch == 0)   break;
    }
    printf("�����մϴ�.\n");
    return 0;
}