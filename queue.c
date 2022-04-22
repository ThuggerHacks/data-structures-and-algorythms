#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

void push(int data);
void display();
void pop();

int front = 0;
int back = 0;
int queue[CAPACITY];

void main() {
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();
}


void push(int data) {
    if(back != CAPACITY){
        queue[back] = data;
        back++;
    }else{
        printf("queue is full\n");
    }
}

void display() {
    if(back != front) {
        int i;
        for(i = front; i<back; i++ ) {
            printf("%d ",queue[i]);
        }
    }else{
        printf("queue is empty\n");
    }
}

void pop(){
    if(back !=front){
        int i;
        for(i = front; i<back-1; i++ ) {
            queue[i] = queue[i+1];
        }
        back--;
    }else{
        printf("empty queue\n");
    }
}