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

// 1.����Ʈ���� ���� ������ ��ȸ�ϴ� �Լ�.
// 2.����Ʈ���� ���� x�� �� ���� ��尡 �ִ��� ����ϴ� �Լ�.   
// 3.����Ʈ���� ��� ��忡�� ���� ����Ʈ���� ������ ����Ʈ���� ���̰� �ִ� 1���̰� ���� Ʈ����
// "����Ʈ��"��� �Ѵ�. �־��� Ʈ���� ����Ʈ������ Ȯ���ϴ� �Լ�
// 4.����Ʈ���� �¿�� ��Ī��Ű�� �Լ�.
// (����� Ȯ���ϴ� ����� ��Ī ���ķ� ���� ������ ��ȸ�� ����� ���)

int main(){

}