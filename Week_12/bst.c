#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("  [!] %d already exists in the BST. Duplicates not allowed.\n", value);

    return root;
}

struct Node *findMin(struct Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("  [!] %d not found in the BST.\n", value);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    struct Node *root = NULL;
    int choice, value;

    printf("========================================\n");
    printf("   Binary Search Tree (BST) Operations  \n");
    printf("========================================\n");

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for a key\n");
        printf("4. Display (In-order - sorted)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("  [✓] %d inserted.\n", value);
            break;

        case 2:
            if (root == NULL)
            {
                printf("  [!] BST is empty.\n");
                break;
            }
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("  [✓] Delete operation completed for %d.\n", value);
            break;

        case 3:
            if (root == NULL)
            {
                printf("  [!] BST is empty.\n");
                break;
            }
            printf("Enter key to search: ");
            scanf("%d", &value);
            {
                struct Node *result = search(root, value);
                if (result != NULL)
                    printf("  [✓] Key %d FOUND in the BST.\n", value);
                else
                    printf("  [✗] Key %d NOT FOUND in the BST.\n", value);
            }
            break;

        case 4:
            printf("In-order   : ");
            inorder(root);
            printf("\n");
            break;

        case 0:
            printf("Freeing memory and exiting...\n");
            freeTree(root);
            root = NULL;
            break;

        default:
            printf("  [!] Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    printf("Goodbye!\n");
    return 0;
}
