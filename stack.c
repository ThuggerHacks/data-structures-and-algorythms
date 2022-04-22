#include<stdio.h>
#include<stdlib.h>

#define LEN 5


int stack[LEN];
int top = -1;
int top_val;
int cond = 1;

void push(int data);
void pop(void);
void stack_top();
int isEmpty();
int isFull();
void display();

void main() {
    while(cond == 1) {
        printf("\n1-append\n2-remove\n3-top\n4-all\n5-quit\n");
        int choice;

        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("enter the number\n");
                int num;
                scanf("%d",&num);
                push(num);
            break;
            case 2:  
                pop();
            break;    
            case 3:
                stack_top();
            break;
            case 4:
                display();
            break;
            case 5:
                cond = 2;
            break;
            default:
                printf("invalid option!");
            break;        

        }
    }
}

void push(int data ) {
    if(isFull() == 0) {
        top++;
        stack[top] = data;
        printf("%d was inserted! ",data);
    }else{
        printf("the stack is full!");
    }
}

void pop() {
    if(isEmpty() == 0) {
        top--;
        printf("top element was removed!");
    }else{
        printf("there are no elements to remove!");
    }
}

void stack_top() {
    if(isEmpty() == 0) {
        printf("top element %d ", stack[top]);
    }else{
       printf("there are no elements in the stack!");
    }
}

int isFull() {
    if(top == LEN-1) {
        return 1;
    }else{
        return 0;
    }
}

int isEmpty() {
    if(top == -1 ) {
        return 1;
    }else{
        return 0;
    }
}

void display() {
    int i;
    if( isEmpty() == 0){
        for(i = 0; i<=top; i++ ) {
            printf("%d ",stack[i]);
        }
    }else{
        printf("no elements available");
    }
}