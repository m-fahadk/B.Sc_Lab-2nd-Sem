#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    printf("Inserted at beginning.\n");
}

void insert_end()
{
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;

    printf("Inserted at end.\n");
}

void insert_middle()
{
    struct node *newnode, *temp;
    int value, pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insert_begin();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted at position %d.\n", pos);
}

void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Deleted first node.\n");
}

void delete_end()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Deleted last node.\n");
}

void delete_middle()
{
    struct node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delete_begin();
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Deleted node at position %d.\n", pos);
}

void traversal()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, subchoice;

    do
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInsertion at:\n");
            printf("1. Beginning\n");
            printf("2. Middle (position)\n");
            printf("3. End\n");
            printf("Enter option: ");
            scanf("%d", &subchoice);

            if (subchoice == 1)
                insert_begin();
            else if (subchoice == 2)
                insert_middle();
            else if (subchoice == 3)
                insert_end();
            else
                printf("Invalid insertion option.\n");
            break;

        case 2:
            printf("\nDeletion at:\n");
            printf("1. Beginning\n");
            printf("2. Middle (position)\n");
            printf("3. End\n");
            printf("Enter option: ");
            scanf("%d", &subchoice);

            if (subchoice == 1)
                delete_begin();
            else if (subchoice == 2)
                delete_middle();
            else if (subchoice == 3)
                delete_end();
            else
                printf("Invalid deletion option.\n");
            break;

        case 3:
            traversal();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
