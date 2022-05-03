#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUEUE_SIZE 100

typedef struct {
    int id;
    int arrival_time;
    int service_time;
}QueueElement;

typedef struct {
    QueueElement node[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void InitQueue2(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int IsEmpty2(Queue *q){
    return (q->front == q->rear);
}

int IsFull2(Queue *q){
    return ((q->front + 1) % MAX_QUEUE_SIZE == q->front);
}

void Error2(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void PrintQueue2(Queue *q){
    printf("QUEUE (front=%d rear=%d) = ", q->front, q->rear);
    if(!IsEmpty2(q)){
        int i = q->front;
        do{
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->node[i]);
            if(i == q->rear){
                break;
            }
        }
        while(i != q->front);
    }
    printf("\n");
}

void Enqueue2(Queue *q, QueueElement node){
    if(IsFull2(q)){
        Error2("ť�� ��ȭ�����Դϴ�");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->node[q->rear] = node;
}

QueueElement Dequeue2(Queue *q){
    if(IsEmpty2(q)){
        Error2("ť�� ��������Դϴ�");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->node[q->front];
}

QueueElement Peek2(Queue *q){
    if(IsEmpty2(q)){
        Error2("ť�� ��������Դϴ�");
    }
    return q->node[(q->front + 1) % MAX_QUEUE_SIZE] ;
}



int main(){
    Queue q;
    InitQueue2(&q);
    int minutes = 60;
    int total_wait = 0;
    int total_customer = 0;
    int service_time = 0;
    int service_time_q2 = 0;
    int service_customer;
    int service_customer_q2;
    for(int clock = 0; clock < minutes; clock++){
        printf("===========================================================\n");
        printf("����ð�: %d\n", clock);
        if(rand() % 10 < 7){
            QueueElement customer;
            customer.id = total_customer++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3+1;
                Enqueue2(&q, customer);
                printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�: %d��\n", customer.id, customer.arrival_time, customer.service_time);
        }
        if(service_time > 0){
            printf("����� 1 ��%d ������ ó�����Դϴ�.\n", service_customer);
            service_time--;
        }
        if(service_time_q2 > 0){
            printf("����� 2 ��%d ������ ó�����Դϴ�.\n", service_customer_q2);
            service_time_q2--;
        }
        if(!IsEmpty2(&q)){
            if(service_time == 0){
                QueueElement customer = Dequeue2(&q);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("�� %d�� ������ %d�п� �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
                    customer.id, clock, clock-customer.arrival_time);
                
                total_wait += clock - customer.arrival_time;
            }
            else if(service_time_q2 == 0){
                QueueElement customer = Dequeue2(&q);
                service_customer_q2 = customer.id;
                service_time_q2 = customer.service_time;
                printf("�� %d�� ������ %d�п� �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
                    customer.id, clock, clock-customer.arrival_time);
                
                total_wait += clock - customer.arrival_time;
            }
            
        }
    }
    printf("��ü ��� �ð�: %d��\n", total_wait);
}