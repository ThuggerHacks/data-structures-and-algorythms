#include <stdio.h>
#include <stdlib.h>
//pendent
#define CAPACITY 5

int cqueue[CAPACITY];
int front = -1;
int rear = -1;

void push(int data);
void pop();
void display();

void main() {
    push(10);
    push(20);
    push(30);
    push(100);
    push(200);
    pop();
    pop();
    push(300);
    push(400);
    display();
}

void push(int data) {
    if((front == rear+1) || rear == CAPACITY-1) {
        printf("cqueue is full!");
    }else if(front == -1 && rear == -1 ) {
        front = rear = 0;
        cqueue[rear] = data;
    }else if(rear == CAPACITY-1) {
        rear = 0;
        cqueue[rear] = data;
    }else{
        rear++;
        cqueue[rear] = data;
    }
}

void pop() {
    if(front == -1 && rear == -1 ) {
        printf("cqueue is empty!");
    }else if( front == rear ) {
        front = -1;
        rear = -1;
    }else if(front == CAPACITY-1) {
        front = 0;
    }else{
        front++;
    }
}

void display() {
    if(rear == -1 && front == -1 ) {
        printf("cqueue is empty!");
    }else{
        int i,j;
        for( i = front; i<rear; i++ ) {
            printf("%d ",cqueue[i]);
        }

        for(j = 0; j<rear; j++ ) {
            printf("%d ",cqueue[j]);
        }
    }
}