#include <stdio.h>
#include<malloc.h>
struct node
{
    int data ;
    struct node* left;
    struct node* right;
};

struct node* creatNode(int data){
    struct node*n;
    n=(struct node*)malloc(sizeof (struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}


void preorder(struct node*root)
{
    if (root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}

void inorder(struct node*root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void postorder(struct node*root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

int main (){
    struct node*p=creatNode(4);
    struct node*p1=creatNode(1);
    struct node*p2=creatNode(6);
    struct node*p3=creatNode(5);
    struct node*p4=creatNode(2);

    //now linking the node:

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

  preorder(p);
  printf("\n");
  inorder(p);
   printf("\n");
   postorder(p);



    return 0;
}



