#include<stdio.h>
#define MAX_LIST_SIZE 100
#define TRUE 1
#define FALSE 0

// ADT 정리
// pos를 이용한 지정 insert, delete 등이 가능 -> 배열 기반의 연결리스트라서 가능
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
        printf("이미 값이 있습니다.\n");
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
        printf("data가 없습니다\n");
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
        printf("data가 없습니다\n");
        // -1값을 반환하면 만약에 p->data[pos]의 값이 -1이면 어떡하지...?
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