#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int BinaryData;

typedef struct __node{
    BinaryData data;
    struct __node* rigth;
    struct __node* left;   
}BinaryTree;

BinaryTree* InitBinarytree(){
    BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));
    node->data = NULL;
    node->left = NULL;
    node->rigth = NULL;
    return node;
}

BinaryData GetData(BinaryTree* bt){
    return bt->data;
}

void SetData(BinaryTree* bt, BinaryData data){
    bt->data = data;
}

BinaryTree* GetLeftSubTree(BinaryTree* bt){
    return bt->left;
}

BinaryTree* GetRightSubTree(BinaryTree* bt){
    return bt->rigth;
}

void MakeLeftSubTree(BinaryTree* main, BinaryTree* sub){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = sub;
}

void MakeRigthSubTree(BinaryTree* main, BinaryTree* sub){
    if(main->rigth != NULL){
        free(main->rigth);
    }
    main->rigth = sub;
}

void InorderTraverse(BinaryTree* bt){
    if(bt == NULL)  return;
    InorderTraverse(bt->left);
    printf("%d \n", bt->data);
    InorderTraverse(bt->rigth);
}

void PreorderTraverse(BinaryTree* bt){
    if(bt == NULL)  return;
    printf("%d \n", bt->data);
    InorderTraverse(bt->left);
    InorderTraverse(bt->rigth);
}

void PostorderTraverse(BinaryTree* bt){
    if(bt == NULL)  return;
    InorderTraverse(bt->rigth);
    InorderTraverse(bt->left);
    printf("%d \n", bt->data);
}

void LevelorderTravere(BinaryTree* bt){
    if(bt == NULL)  return;
    Queue* q;
    InitQueue(q);
    Enqueue(q, bt->data);
    while(!QueueIsEmpty(q)){
        printf("%d\n", Dequeue(q));
        if(bt->left)
            LevelorderTravere(bt->left);
        else
            LevelorderTravere(bt->rigth);
    }
}

int GetMaxData(BinaryTree* bt){
    if(bt == NULL)  return;
    InorderTraverse(bt->rigth);
    InorderTraverse(bt->left);
    
}


// Not finish function
int GetLevelNode(BinaryTree* bt, int destination, int count, int level_node_count){
    if(bt != NULL && destination != count){
        GetLevelNode(bt->left, destination, ++count, level_node_count);
    }
}

// 1.이진트리를 레벨 순서로 순회하는 함수.
// 2.이진트리의 레벨 x에 몇 개의 노드가 있는지 계산하는 함수.   
// 3.이진트리의 모든 노드에서 왼쪽 서브트리와 오른쪽 서브트리의 높이가 최대 1차이가 나는 트리를
// "균형트리"라고 한다. 주어진 트리가 균형트리인지 확인하는 함수
// 4.이진트리를 좌우로 대칭시키는 함수.
// (결과를 확인하는 방법은 대칭 전후로 레벨 단위로 순회한 결과를 출력)

int main(){

}