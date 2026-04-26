#include <stdio.h>
#define MAX 10

struct circular_queue
{
    int arr[MAX];
    int rear;
    int front;
};
typedef struct circular_queue Queue;

int is_queue_empty(Queue *queue)
{
    if (-1 == queue->rear)
    {
        return 1;
    }
    return 0;
}

int is_queue_full(Queue *queue)
{
    return ((queue->rear + 1) % MAX == queue->front);
}

void enqueue(Queue *queue, int data)
{
    if (is_queue_empty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else if (!(is_queue_full(queue)))
    {
        queue->rear = (queue->rear + 1) % MAX;
    }
    queue->arr[queue->rear] = data;
}

int dequeue(Queue *queue)
{
    int data = queue->arr[queue->front];
    if (is_queue_empty(queue))
    {
    }
    else if (queue->rear == queue->front)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX;
    }
    return data;
}

void traversal(Queue *queue)
{
    int index = queue->front;
    while (index != queue->rear)
    {
        printf("%d <- ", queue->arr[index]);
        index = (index + 1) % MAX;
    }
    printf("%d ", queue->arr[index]);
}

Queue get_queue()
{
    Queue queue;
    queue.front = -1;
    queue.rear = -1;

    return queue;
}

int main()
{
    Queue queue1 = get_queue();
    Queue *queue_pt = &queue1;
    int choice, data;
    printf("\n=== Queue ===");

    do
    {
        printf("\nChoose an option\n");
        printf("1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (is_queue_full(queue_pt))
            {
                printf("\nQueue is full");
            }
            else
            {
                printf("Enter a value :");
                scanf("%d", &data);
                enqueue(queue_pt, data);
            }
            break;

        case 2:
            if (is_queue_empty(queue_pt))
            {
                printf("Queue is already empty");
            }
            else
            {
                int deleted = dequeue(queue_pt);
                printf("Node dequeued = %d", deleted);
            }
            break;
        case 3:
            traversal(queue_pt);
            break;

        default:
            printf("Invalid input");
        }
    } while (choice != 4);
}