#include<stdio.h>
#define MAX_LIST_SIZE 100
#define TRUE 1
#define FALSE 0

// ADT ����
// pos�� �̿��� ���� insert, delete ���� ���� -> �迭 ����� ���Ḯ��Ʈ�� ����
// insert, delete, get_data, is_empty, init, insert_first, insert_last 
typedef int element;

typedef struct{
    element data[MAX_LIST_SIZE];
    int size;
}ArrayList;

void InitList(ArrayList* p){
    p->size = 0;
}

void Insert(ArrayList *p, int data, int pos){
    if(p->data[pos] != NULL){
        printf("�̹� ���� �ֽ��ϴ�.\n");
        return 0;
    }
    else{
        p->data[pos] = data;
        p->size++;
    }
}

int Delete(ArrayList *p, int pos){
    element temp;
    if(p->data[pos] == NULL){
        printf("data�� �����ϴ�\n");
    }
    else{
        temp = p->data[pos];
        p->data[pos] = NULL;
        p->size--;
        return temp;
    }
}

int GetData(ArrayList *p, int pos){
    if(p->data[pos] == NULL){
        printf("data�� �����ϴ�\n");
        // -1���� ��ȯ�ϸ� ���࿡ p->data[pos]�� ���� -1�̸� �����...?
        return -1;
    }
    else{
        return p->data[pos];
    }
}

int IsEmpty(ArrayList *p){
    if(p->size == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int main(){

}