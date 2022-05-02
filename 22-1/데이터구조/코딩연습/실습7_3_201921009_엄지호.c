#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUEUE_SIZE 100

typedef int Data;

typedef struct {
    Data data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void InitQueue(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int IsEmpty(Queue *q){
    return (q->front == q->rear);
}

int IsFull(Queue *q){
    return ((q->front + 1) % MAX_QUEUE_SIZE == q->front);
}

void Error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void PrintQueue(Queue *q){
    printf("QUEUE (front=%d rear=%d) = ", q->front, q->rear);
    if(!IsEmpty(q)){
        int i = q->front;
        do{
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if(i == q->rear){
                break;
            }
        }
        while(i != q->front);
    }
    printf("\n");
}

void Enqueue(Queue *q, Data data){
    if(IsFull(q)){
        Error("ť�� ��ȭ�����Դϴ�");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

Data Dequeue(Queue *q){
    if(IsEmpty(q)){
        Error("ť�� ��������Դϴ�");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

Data Peek(Queue *q){
    if(IsEmpty(q)){
        Error("ť�� ��������Դϴ�");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE] ;
}

int main(){
    // �̸����� �ϱ�
    Queue man;
    Queue woman;
    int man_idx = 0;
    int woman_idx = 0;
    InitQueue(&man);
    InitQueue(&woman);
    int length = 0;
    while(length < 100){
        int num = rand() % 2;
        // �ϴ� ���� ��Ű�� �� ������ ���, ��Ī �Ǵ�
        if(num == 1){
            Enqueue(&man, man_idx);
            printf("��%d ���� - ", man_idx++);
            if(!IsEmpty(&man) && !IsEmpty(&woman)){
                printf("��%d/��%d ��Ī\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("���\n");
            }
        }
        else{
            Enqueue(&woman, woman_idx);
            printf("��%d ���� - ", woman_idx++);
            if(!IsEmpty(&man) && !IsEmpty(&woman)){
                printf("��%d/��%d ��Ī\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("���\n");
            }
        }
        length++;
    }
    while(!IsEmpty(&man)){
        printf("��Ī���� ���� ����%d\n", Dequeue(&man));
    }
    while(!IsEmpty(&woman)){
        printf("��Ī���� ���� ����%d\n", Dequeue(&woman));
    }
}