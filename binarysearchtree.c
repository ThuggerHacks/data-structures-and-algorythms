#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
void push(int data );
void inorder(struct node* t);
void preorder(struct node* t);
void postorder(struct node* t);
void reverse(struct node* t);
int size = 0;

void main() {
    push(10);
    push(5);
    push(30);
    push(7);
    push(40);
    push(4);
    reverse(root);
    inorder(root);
}

void push(int data ) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL ) {
        root = temp;
        size++;
    }else{
        struct node* current,*parent;
        current = parent = root;
        while(current) {
            parent = current;
            if(current->data>temp->data) {
                current = current->left;
            }else{
                current = current->right;
            } 
        }

        if(parent->data>temp->data) {
            parent->left = temp;
        }else{
             parent->right = temp;
        }

        size++;
    }
}

void inorder(struct node* t) {
    if(t->left)
        inorder(t->left);
    printf("%d ",t->data);
    if(t->right)
        inorder(t->right);
        
}

void preorder(struct node* t) {
    
    printf("%d ",t->data);
    if(t->left)
        preorder(t->left);
     if(t->right)
        preorder(t->right);
        
}

void postorder(struct node* t) {
    
    if(t->left)
        preorder(t->left);
     if(t->right)
        preorder(t->right);
    printf("%d ",t->data);
        
}

void reverse(struct node* t) {
    struct node* temp = t->left;
    t->left = t->right;
    t->right = temp;

    if(root->left!=NULL)
        reverse(t->left);
    if(root->right!=NULL)    
        reverse(t->right);
}

void pop( ) {

}