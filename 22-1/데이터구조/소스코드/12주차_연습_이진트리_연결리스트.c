#define max(a,b)  (((a) > (b)) ? (a) : (b))

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//===============================QUEUE======================================

typedef int Element;

typedef struct queue_node{
    Element data;
    struct queue_node* next;
}QueueNode;

typedef struct __queue{
    QueueNode* front;
    QueueNode* rear;
    int length;
}Queue;

void InitQueue(Queue* pq){
    pq->front = NULL;
    pq->rear = NULL;
}

void Enqueue(Queue* pq, Element data){
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->data = data;
    if(pq->front == NULL){
        pq->front = new_node;
        pq->rear = new_node;
    }
    else{
        pq->rear->next = new_node;
        pq->rear = new_node;
    }
}

Element Dequeue(Queue* pq){
    if(pq->length == 0){
        printf("Queue가 비어있습니다\n");
        return 0;
    }
    Element rdata = pq->front->data;
    QueueNode* remove_node = pq->front;
    pq->front = pq->front->next;
    free(remove_node);
    return rdata;    
}

int QueueIsEmpty(Queue* pq){
    if(pq->length == 0) return 1;
    else return 0;
}

//===============================QUEUE======================================

typedef int BinaryData;

typedef struct __node{
    BinaryData data;
    struct __node* left;   
    struct __node* right;
}BinaryNode;

BinaryNode* InitBinaryNode(){
    BinaryNode* node = (BinaryNode*)malloc(sizeof(BinaryNode));
    node->data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryData GetData(BinaryNode* bt){
    return bt->data;
}

void SetData(BinaryNode* bt, BinaryData data){
    bt->data = data;
}

BinaryNode* GetLeftSubTree(BinaryNode* bt){
    return bt->left;
}

BinaryNode* GetRightSubTree(BinaryNode* bt){
    return bt->right;
}

void MakeLeftSubTree(BinaryNode* main, BinaryNode* sub){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = sub;
}

void MakerightSubTree(BinaryNode* main, BinaryNode* sub){
    if(main->right != NULL){
        free(main->right);
    }
    main->right = sub;
}

// ======================================Travere==============================================

void InorderTraverse(BinaryNode* bt){
    if(bt == NULL)  return;
    InorderTraverse(bt->left);
    printf("%d \n", bt->data);
    InorderTraverse(bt->right);
}

void PreorderTraverse(BinaryNode* bt){
    if(bt == NULL)  return;
    printf("%d \n", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void PostorderTraverse(BinaryNode* bt){
    if(bt == NULL)  return;
    PostorderTraverse(bt->right);
    PostorderTraverse(bt->left);
    printf("%d \n", bt->data);
}

void LevelorderTravere(BinaryNode* bt){
    if(bt == NULL)  return;
    Queue* q;
    InitQueue(q);
    Enqueue(q, bt->data);
    while(!QueueIsEmpty(q)){
        printf("%d\n", Dequeue(q));
        if(bt->left)
            LevelorderTravere(bt->left);
        else
            LevelorderTravere(bt->right);
    }
}

void PlusOne(BinaryNode* bt){
    if(bt == NULL)  return;
    bt->data += 1;
    printf("%d \n", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

BinaryNode* SearchMaxNode(BinaryNode* bt){
    BinaryNode* cur = bt;
    BinaryNode* left_node;
    BinaryNode* right_node;

    if(cur->left != NULL || cur->right != NULL){
        // 양쪽 다 존재
        if(cur->left != NULL && cur->right != NULL){
            left_node = SearchMaxNode(cur->left);
            right_node = SearchMaxNode(cur->right);
            if(left_node->data > right_node->data){
                if(cur->data > left_node->data){
                    return cur;
                }
                else{
                    return left_node;
                }
            }     
            else{
                if(cur->data > right_node->data){
                    return cur;
                }
                else{
                    return right_node;
                }
            }
        } // 왼쪽만 존재
        else if(cur->left != NULL && cur->right == NULL){
            left_node = SearchMaxNode(bt->left);        
            if(cur->data > left_node->data){
                return cur;
            }
            else{
                return left_node;
            }
        } // 오른쪽만 존재
        else if(cur->left == NULL && cur->right != NULL){
            right_node = SearchMaxNode(bt->right);        
            if(cur->data > right_node->data){
                return cur;
            }
            else{
                return right_node;
            }
        }
    }
    return cur;
}

int GetOneChild(BinaryNode *node){
    int count = 0;
    if(!node)
        return count;
    else if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)){
        count = 1 + GetOneChild(node->left) + GetOneChild(node->right);
    }
    else
        count = GetOneChild(node->left) + GetOneChild(node->right);
    return count;
}

int IsEqual(BinaryNode* bt1, BinaryNode* bt2){
    if(bt1 == NULL && bt2 == NULL)  return 1;
    if(bt1 == NULL || bt2 == NULL)  return 0;
    if(bt1->data != bt2->data)  return 0;
    return IsEqual(bt1->left, bt2->left) && IsEqual(bt1->right, bt2->right);
}
// ======================================Travere==============================================

int CountNode(BinaryNode* bt){
    int count = 0;
    if(bt != NULL){
        count =  1 + CountNode(bt->left) + CountNode(bt->right);
    }
    return count;
}

// Error <- Segmentation fault
int CountLeafNode(BinaryNode* bt){
    int count;
    if(bt->left == NULL && bt->right == NULL){
        count = 1;
    }
    else{
        count = CountLeafNode(bt->left) + CountLeafNode(bt->right);
    }
    return count;
}

int GetHeight(BinaryNode* bt){
    int count = 1;
    if(bt != NULL){
        count = max(GetHeight(bt->left), GetHeight(bt->right));
    }
    return count;
}

// Postorder
int GetSumOfData(BinaryNode* bt){
    int count = 0;
    if(bt->left == NULL && bt->right == NULL){
        return bt->data;
    }
    else{
        if(bt->left != NULL && bt->right !=NULL){
            return bt->data + GetSumOfData(bt->right) + GetSumOfData(bt->left);
        }
        else if(bt->left != NULL && bt->right == NULL){
            return bt->data + GetSumOfData(bt->left);
        }
        else if(bt->left == NULL && bt->right != NULL){
            return bt->data + GetSumOfData(bt->right);
        }
    }
    return bt->data;
}

BinaryNode* CopyTree(BinaryNode* bt){
    BinaryNode* temp = (BinaryNode*)malloc(sizeof(BinaryNode*));
    if(bt){
        temp->left = CopyTree(bt->left);
        temp->right = CopyTree(bt->right);
        temp->data = bt->data;
        return temp;
    }
    return NULL;
}

// Inorder
// **이름 변경 필요**
void PrintNumberLessThenX(BinaryNode* bt, int x){
    if(bt == NULL)  return;
    if(bt->data < x){
        printf("%d\n", bt->data);
    }
    PrintNumberLessThenX(bt->left, x);
    PrintNumberLessThenX(bt->right, x);
}

// // Not finish function
// int GetLevelNode(BinaryNode* bt, int destination){
//     int count = 0;
//     if(bt != NULL){
//         return count = 1 + max(GetLevelNode(bt->left, destination), GetLeftSubTree(bt->right, destination));
//     }
//     return count;
// }


int main(){
    // BinaryTree1 높이 
    BinaryNode n10 = {14,NULL,NULL};
    BinaryNode n9 = {19,NULL,&n10};
    BinaryNode n8 = {12,NULL,&n9};
    BinaryNode n7 = {10,NULL,NULL};
    BinaryNode n1 = {1,&n7,NULL};
    BinaryNode n2 = {4,&n1,NULL};
    BinaryNode n3 = {16,&n8,NULL};
    BinaryNode n4 = {8,NULL,NULL};
    BinaryNode n5 = {20,&n3,&n4};
    BinaryNode n6 = {15,&n2,&n5};
    BinaryNode* root1 = &n6;
    
    // BinaryTree2 높이 7
    BinaryNode n27 = {10,NULL,NULL};
    BinaryNode n24 = {25,NULL,NULL};
    BinaryNode n210 = {30,NULL,&n24};
    BinaryNode n29 = {23,NULL,&n210};
    BinaryNode n28 = {12,NULL,&n29};
    BinaryNode n23 = {16,&n28,NULL};
    BinaryNode n25 = {20,&n23,NULL};
    BinaryNode n21 = {1,&n27,NULL};
    BinaryNode n22 = {4,&n21,NULL};
    BinaryNode n26 = {15,&n22,&n25};
    BinaryNode* root2 = &n26;

    // BinaryTree3 높이 8
    BinaryNode n37 = {10,NULL,NULL};
    BinaryNode n34 = {25,&n37,NULL};
    BinaryNode n310 = {30,NULL,&n34};
    BinaryNode n39 = {23,NULL,&n310};
    BinaryNode n38 = {12,NULL,&n39};
    BinaryNode n33 = {16,&n38,NULL};
    BinaryNode n35 = {40,&n33,NULL};
    BinaryNode n31 = {1,NULL,NULL};
    BinaryNode n32 = {4,&n31,NULL};
    BinaryNode n36 = {15,&n32,&n35};
    BinaryNode* root3 = &n36;
    int intersection;
    BinaryNode* temp;
    int n;

    while(1){
        printf("1.SumOfData\n2.CountLeafNode\n3.GetHeight\n4.LevelorderTravere\n");
        printf("5.InorderTraverse\n6.PreorderTraverse\n7.PostorderTraverse\n8.SearchMaxNode\n9.PrintNumberLessThenX\n");
        printf("10.CopyTree\n11.IsEqual\n12.PlusOne\n13.GetOneChild\n0.EXIT\n");
        scanf("%d", &intersection);
        switch (intersection)
        {
        case 0:
            return 0;
        case 1:
            printf("Sum of data = %d\n", GetSumOfData(root1));
            printf("===================================================\n");
            break;
        case 2:
            printf("Count leaf node = %d", CountLeafNode(root1));
            printf("===================================================\n");
            break;
        case 3:
            printf("Height = %d\n", GetHeight(root1));
            printf("===================================================\n");
            break;
        case 4:
            printf("============Levelorder============\n");
            LevelorderTravere(root1);
            printf("===================================================\n");
            break;
        case 5:
            printf("============Inorder============\n");
            InorderTraverse(root1);
            printf("===================================================\n");
            break;
        case 6:
            printf("============Preorder============\n");
            PreorderTraverse(root1);
            printf("===================================================\n");
            break;
        case 7:
            printf("============Postorder============\n");
            PostorderTraverse(root1);
            printf("===================================================\n");
            break;
        case 8:
            printf("============SearchMaxNode============\n");
            printf("Search max number 1 = %d\n", SearchMaxNode(root1)->data);
            printf("Search max number 2 = %d\n", SearchMaxNode(root2)->data);
            printf("Search max number 3 = %d\n", SearchMaxNode(root3)->data);
            printf("===================================================\n");
            break;
        case 9:
        {
            int x;
            printf("============PrintNumberLessThenX============\n");
            printf("X를 입력해주세요\n");
            scanf("%d", &x);
            printf("===================================================\n");    
            PrintNumberLessThenX(root1, x);
            printf("===================================================\n");    
            break;
        }
        case 10:
        {
            printf("============CopyTree============\n");
            printf("몇 번 이진트리를 복사할 건가요?\n");
            printf("1.root1\n2.root2\n3.root3\n");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                temp = CopyTree(root1);
                InorderTraverse(temp);
                break;
            case 2:
                temp = CopyTree(root2);
                InorderTraverse(temp);
                break;
            case 3:
                temp = CopyTree(root3);
                InorderTraverse(temp);
                break;
            default:
                break;
            }
            printf("===================================================\n");    
            break;
        }
        case 11:
            printf("복사한 Tree와 복사된 Tree가 같은지 확인하는 프로그램\n");
            switch (n)
            {
            case 1:
                if(IsEqual(temp, root1)){
                    InorderTraverse(temp);
                    printf("복사한 트리가 동일합니다\n");
                }
                break;
            case 2:
                if(IsEqual(temp, root2)){
                    InorderTraverse(temp);
                    printf("복사한 트리가 동일합니다\n");
                }
                break;
            case 3:
                if(IsEqual(temp, root3)){
                    InorderTraverse(temp);
                    printf("복사한 트리가 동일합니다\n");
                }
                break;
            default:
                break;
            }
            printf("===================================================\n");
            break;
        case 12:
            printf("============PlusOne============\n");
            PlusOne(root1);
            InorderTraverse(root1);
            printf("===================================================\n");
            break;
        case 13:
            printf("============GetOneChild============\n");
            printf("Get one child = %d\n", GetOneChild(root1));
            printf("===================================================\n");
            break;
        }
    }
}