#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 15
typedef int element;
typedef struct { // 큐 타입
    element  data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
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

// 삽입 함수
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

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
            printf("여%d 입장 - ", woman);
        }
        else {
            man++;
            enqueue(&queue_man, man);
            printf("남%d 입장 - ", man);
        }
        if (!is_empty(&queue_woman) && !is_empty(&queue_man) && queue_woman.front == queue_man.front) {
            printf("여%d/남%d 매칭\n", dequeue(&queue_woman), dequeue(&queue_man));
            couple++;
        }
        else
            printf("대기\n");
        printf("현재 여성 큐 | front:%d  ||  rear:%d\n", queue_woman.front, queue_woman.rear);
        printf("현재 남성 큐 | front:%d  ||  rear:%d\n", queue_man.front, queue_man.rear);
        printf("-----------------------------------------------------------\n");
        Sleep(1000);
    }
}