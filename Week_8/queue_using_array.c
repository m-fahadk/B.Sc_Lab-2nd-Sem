#include <stdio.h>

#define MAX 1000

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} Queue;

int is_empty(Queue q)
{
    if ((q.front == -1 && q.rear == -1) || (q.front > q.rear))
        return 1;

    else
        return 0;
}

int is_full(Queue q)
{
    if (q.rear == MAX - 1)
        return 1;

    else
        return 0;
}

void enqueue(Queue *q)
{
    if (is_full(*q))
    {
        printf("\nQueue full");
    }

    else if (is_empty(*q))
    {
        q->front = 0;
        q->rear = 0;
        printf("\nEnter a value: ");
        scanf("%d", &(q->arr[q->rear]));
    }

    else
    {
        q->rear += 1;
        printf("\nEnter a value: ");
        scanf("%d", &(q->arr[q->rear]));
    }
}

void dequeue(Queue *q)
{
    if (is_empty(*q))
    {
        printf("Cannot remove (Queue already empty)");
    }

    else
    {
        printf("Value dequeued is - %d", q->arr[q->front]);
        q->front += 1;
    }
}

void traversal(Queue q)
{
    if (is_empty(q))
    {
        printf("Queue is empty");
    }

    else
    {
        int i;
        for (i = q.front; i <= q.rear; i++)
        {
            printf("%d ", q.arr[i]);
        }
    }
}

int main()
{
    Queue q1;
    q1.front = -1;
    q1.rear = -1;
    int choice;

    printf("\n==== Queue ====\n");

    do
    {
        printf("\nChoose an option: ");
        printf("\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&q1);
            break;

        case 2:
            dequeue(&q1);
            break;

        case 3:
            traversal(q1);
            break;
        }
    } while (choice != 4);
}