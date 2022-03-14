#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 15
typedef int element;
typedef struct { // ť Ÿ��
    element  data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// ���� �Լ�
element peek(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== ����ť �ڵ� �� ======

int main(void) {
    QueueType queue_man;
    QueueType queue_woman;
    init_queue(&queue_man);
    init_queue(&queue_woman);

    int man = 0;
    int woman = 0;
    int couple = 0;

    for (int i = 0; i < 100; i++) {
        int random = (rand() % 100) + 1;
        int matching = random % 2;
        if (matching == 1) {
            woman++;
            enqueue(&queue_woman, woman);
            printf("��%d ���� - ", woman);
        }
        else {
            man++;
            enqueue(&queue_man, man);
            printf("��%d ���� - ", man);
        }
        if (!is_empty(&queue_woman) && !is_empty(&queue_man) && queue_woman.front == queue_man.front) {
            printf("��%d/��%d ��Ī\n", dequeue(&queue_woman), dequeue(&queue_man));
            couple++;
        }
        else
            printf("���\n");
        printf("���� ���� ť | front:%d  ||  rear:%d\n", queue_woman.front, queue_woman.rear);
        printf("���� ���� ť | front:%d  ||  rear:%d\n", queue_man.front, queue_man.rear);
        printf("-----------------------------------------------------------\n");
        Sleep(1000);
    }
}