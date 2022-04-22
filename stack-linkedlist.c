#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* top = NULL;

void push(int data);
void display() ;
void pop();

void main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    pop();
    display();
}



void push(int data) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = top;
    top = temp;
}

void display() {

    struct node* temp;
    temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
        
}

void pop(){
   
   if(top!=NULL){
        struct node* temp;
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
   }

}