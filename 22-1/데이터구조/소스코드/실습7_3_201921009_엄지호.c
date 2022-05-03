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
        Error("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

Data Dequeue(Queue *q){
    if(IsEmpty(q)){
        Error("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

Data Peek(Queue *q){
    if(IsEmpty(q)){
        Error("큐가 공백상태입니다");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE] ;
}

int main(){
    // 이름저장 하기
    Queue man;
    Queue woman;
    int man_idx = 0;
    int woman_idx = 0;
    InitQueue(&man);
    InitQueue(&woman);
    int length = 0;
    while(length < 100){
        int num = rand() % 2;
        // 일단 입장 시키고 그 다음에 대기, 매칭 판단
        if(num == 1){
            Enqueue(&man, man_idx);
            printf("남%d 입장 - ", man_idx++);
            if(!IsEmpty(&man) && !IsEmpty(&woman)){
                printf("여%d/남%d 매칭\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("대기\n");
            }
        }
        else{
            Enqueue(&woman, woman_idx);
            printf("여%d 입장 - ", woman_idx++);
            if(!IsEmpty(&man) && !IsEmpty(&woman)){
                printf("여%d/남%d 매칭\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("대기\n");
            }
        }
        length++;
    }
    while(!IsEmpty(&man)){
        printf("매칭되지 못한 남자%d\n", Dequeue(&man));
    }
    while(!IsEmpty(&woman)){
        printf("매칭되지 못한 여자%d\n", Dequeue(&woman));
    }
}