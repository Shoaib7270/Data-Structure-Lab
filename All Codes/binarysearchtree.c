#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *search(struct node *root, int x)
{
    if (root == NULL)
    {
        printf("Not Found\n");
    }
    else if (root->data == x)
    {
        printf("%d Founded!\n", x);
    }
    else if (root->data > x)
    {
        search(root->left, x);
    }
    else if (root->data > x)
    {
        search(root->right, x);
    }
};
struct node *newnode(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
};

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return newnode(data);
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    return root;
};
void display()
{
    int c;
    printf("\n1.Inorder\n2.Preorder\n3.Postorder\n");
    printf("Enter your choice:");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        inorder(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        postorder(root);
        break;
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d \n", root->data);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    int c, data;
    do
    {
        printf("\n");
        printf("1.Add elements\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Delete\n");
        printf("enter you choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the value:");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the data you want to Found");
            scanf("%d", &data);
            search(root, data);
            break;
            // case 4:
            //  printf("Enter the data you want to Delete");
            //  scanf("%d",&data);
            //  deleteNode(root,data);
            //  break;
        }
    } while (1);
}

/*
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
        }
    return root;
}
*/
