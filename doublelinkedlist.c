#include<stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void push(int data);
void display();
int length() ;
void pop();
void shift(int data);
void unshift();
void insert(int pos,int data);
void splice(int pos);
void swap(int pos1, int pos2);

void main() {
    push(10);
    push(11);
    push(18);
    push(14);
    push(114);
    push(1);
    swap(1,2);

    display();
}

void push(int data) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL) {
        root = temp;
    }else{
        struct node* p;
        p = root;

        while(p->right!=NULL){
            p = p->right;
        }

        p->right = temp;
        temp->left = p;

    }
}


int length() {
    if(root == NULL) {
        printf("empty list\n");
    }else{
        struct node* p = root;
        int c = 0;
        while(p != NULL ) {
            c++;
            p = p->right;
        }

        return c;
    }
}

void pop() {
    if(root == NULL ) {
        printf("empty list\n");
    }else{
        struct node* p,*q;
        p = root;
        int i;
        for(i = 0; i<length()-2; i++) {
            p = p->right;
        }
        q = p->right;
        p->right = NULL;
        q->left = NULL;
        free(q);

    }
}

void shift(int data) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;

    if(root == NULL){
        root = temp;
    }else{

        temp->right = root;
        root->left = temp;
        root = temp;
    }
}

void unshift() {
    if(root == NULL ) {
        printf("empty list\n");
    }else{
        struct node* temp;
        temp = root;

        root = root->right;
        temp->right->left = NULL;
        temp->right = NULL;
    }
}

void insert(int pos,int data){
    if(pos<length()){
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->right = NULL;
        temp->left = NULL;

        if(root == NULL){
            root = temp;
        }else{
            struct node* p;
            p = root;

            int i;

            for(i = 0; i<pos-1; i++ ) {
                p = p->right;
            }
            temp->right = p->right;
            p->right->left = temp;
            p->right = temp;
            temp->left = p;

        }
    }
}

void splice(int pos) {
    if(pos<length()){
        struct node* temp,*q;
        temp = root;
        int i;
        for(i = 0; i<pos-1; i++ ) {
            temp = temp->right;
        }
        q = temp->right;
        temp->right = q->right;
        q->right->left = temp;
        q->left = NULL;
        q->right = NULL;
        free(q);



    }
}

//need to re-do
void swap(int pos1, int pos2) {
        struct node* temp,*q,*r;
        temp = root;
        int i;
        for(i = 0; i<pos1-1; i++ ) {
            temp = temp->right;
        }
        q = temp->right;
        r = q->right;
        temp->right = r;
        r->left = temp;
        q->right = r->right;
        r->right->left= q;
        r->right = q;
        q->left = r;


}

void display() {
    struct node* temp;
    temp = root;

    if(root == NULL) {
        printf("empty list\n");
    }else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->right;
        }
    }
}