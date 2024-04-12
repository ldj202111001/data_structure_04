/*
프로그램 내용: c언어의 구조체를 이용한 원형 큐 프로그램
실습날짜: 2024 - 04 - 12
학번: 202111001
이름: 이동재
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int Element;
typedef struct	CircularQueue 
{
	Element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void error(const char* str) // 에러출력
{
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue* q) { q->front = q->rear = 0; ; } // 큐 초기화
int is_empty(Queue* q) { return q->front == q->rear; }
int is_full(Queue* q) { return q->front == (q->rear + 1) % MAX_QUEUE_SIZE; }
int size(Queue* q) { return(q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Queue* q, Element val)
{
	if(is_full(q))
		error("큐 포화 에러");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = val;
}

Element dequeue(Queue* q)
{
	if (is_empty(q))
		error("큐 rhdqor 에러");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

Element peek(Queue* q)
{
	if (is_empty(q))
		error("큐 공백 에러");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(Queue* q, const char msg[])
{
	int i, maxi = q->rear;
	if (q->front >= q->rear)
		maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]=", msg, size(q));
	for (i = q->front + 1; i <= maxi; i++)
		printf("%2d", q->data[i % MAX_QUEUE_SIZE]);
	printf("\n");
}

void main() 
{
	int i;
	Queue q;
	init_queue(&q);
	for (i = 1; i < 10; i++)
		enqueue(&q, i);
	print_queue(&q, "선형큐 enqueue 9회");
	printf("\tdequeue() --> %d\n", dequeue(&q));
	printf("\tdequeue() --> %d\n", dequeue(&q));
	printf("\tdequeue() --> %d\n", dequeue(&q));
	print_queue(&q, "선형큐 dequeue 3회");
}
//4.1원형 큐, 4.2원형 덱, 4.4미로탐색 프로그램(dfs, bfs), 4.6c언어의 구조체를 이용해 구현한 원형 큐 프로그램
//은행 시뮬레이션 테스트 프로그램x 안해도됨