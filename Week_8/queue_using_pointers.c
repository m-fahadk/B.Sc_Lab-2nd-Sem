#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

struct Queue
{
    Node *front;
    Node *rear;
};
typedef struct Queue Queue;

int is_queue_empty(Queue *queue)
{
    if ((queue->front == NULL))
    {
        return 1;
    }
    return 0;
}

Node *get_node()
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
    return n;
}

Queue *get_queue(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void enqueue(Queue *q, int data)
{
    Node *n = get_node();
    Node *temp = q->front;

    n->data = data;

    if (is_queue_empty(q))
    {
        q->front = n;
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    q->rear = n;
}

int dequeue(Queue *q)
{

    int del = q->front->data;
    Node *temp = q->front;
    if (q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = temp->next; // q->front-next
    }
    free(temp);
    return del;
}

void traversal(Queue *q)
{
    if (is_queue_empty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("[ ");
        Node *temp = q->front;
        while (temp->next != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d  ", temp->data);
        printf("]");
    }
}

int main()
{
    int choice, data;
    Queue *q = get_queue();
    printf("\n==== Queue ====\n");

    do
    {
        printf("\nChoose an option\n");
        printf("1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value :");
            scanf("%d", &data);
            enqueue(q, data);
            break;

        case 2:
            if (is_queue_empty(q))
            {
                printf("Queue is already empty");
            }
            else
            {
                int deleted = dequeue(q);
                printf("Node dequeued = %d", deleted);
            }
            break;
        case 3:
            traversal(q);
        }
    } while (choice != 4);
}