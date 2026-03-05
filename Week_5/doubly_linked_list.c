#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
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
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

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
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    printf("Inserted at end.\n");
}

void insert_middle()
{
    struct node *newnode, *temp;
    int pos, i, value;

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
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Inserted at position %d\n", pos);
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
    
    if(head != NULL)
        head->prev = NULL;
    

    free(temp);

    printf("First node deleted.\n");
}

void delete_end()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    printf("Last node deleted.\n");
}

void delete_middle()
{
    struct node *temp;
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
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted at position %d\n", pos);
}

void traversal()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, subchoice;

    do
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n1.Beginning\n2.Middle\n3.End\n");
            scanf("%d", &subchoice);

            if (subchoice == 1)
                insert_begin();
            else if (subchoice == 2)
                insert_middle();
            else if (subchoice == 3)
                insert_end();
            else
                printf("Invalid option\n");
            break;

        case 2:
            printf("\n1.Beginning\n2.Middle\n3.End\n");
            scanf("%d", &subchoice);

            if (subchoice == 1)
                delete_begin();
            else if (subchoice == 2)
                delete_middle();
            else if (subchoice == 3)
                delete_end();
            else
                printf("Invalid option\n");
            break;

        case 3:
            traversal();
            break;

        case 4:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
