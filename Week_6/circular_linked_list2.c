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

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
        head = newnode;
    }

    printf("Inserted at beginning.\n");
}

void insert_end()
{

    if (head == NULL)
    {
        insert_begin();
        return;
    }
    else
    {
        struct node *newnode, *temp;
        int value;
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &value);
        newnode->data = value;

        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Inserted at end.\n");
}

void insert_middle()
{
    if (head == NULL)
    {
        insert_begin();
        return;
    }

    struct node *newnode, *temp;
    int length = 1, i, value;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);
    newnode->data = value;
    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
        length += 1;
    }

    temp = head;
    for (i = 1; i < length / 2; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    printf("Inserted in the middle");
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
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
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
    if (head->next == head)
    {
        head = NULL;
    }

    else
    {

        temp = head->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Last node deleted.\n");
}

void delete_middle()
{
    if (head == NULL)
    {
        printf("List empty.\n");
        return;
    }

    struct node *temp;
    int length = 1, i;
    temp = head;
    if (head->next == head)
    {
        head = NULL;
    }

    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
            length += 1;
        }

        temp = head;
        for (i = 0; i < (length + 1) / 2; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);

    printf("Node deleted at mid");
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
    printf("Head<-> ");
    while (temp->next != head)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("<-> %d <-> Head\n", temp->data);
}

int main()
{
    int choice, subchoice;

    do
    {
        printf("\n===== CIRCULAR LINKED LIST =====\n");
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
