#include <stdio.h>
#include <stdlib.h>

int cond = 1;
struct node
{

    int data;
    struct node *link;
};

struct node *root = NULL;

void push(int data);
void display();
void shift(int data);
int length();
void insert(int pos, int data);
void unshift();
void pop();
void splice(int pos);
void swap(int pos1, int pos2);
void reverse();

void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    reverse();
    display();
    printf("size: %d ", length());
}

void push(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;

        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void shift(int data)
{

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link = root;
        root = temp;
    }
}

int length()
{
    struct node *temp;
    temp = root;
    int c = 0;

    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }

    return c;
}

void insert(int pos, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (pos < length() && pos > 0)
    {
        struct node *p;
        p = root;

        int i;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
    else
    {
        printf("posicao invalida!");
    }
}

void unshift()
{
    if (root != NULL)
    {
        struct node *temp;
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        printf("empty list");
    }
}

void pop()
{
    struct node *temp, *q;
    temp = root;
    int i;
    for (i = 0; i < length() - 2; i++)
    {
        temp = temp->link;
    }
    q = temp->link;
    temp->link = NULL;
    free(q);
}

void display()
{
    struct node *temp;
    temp = root;
    if (root == NULL)
    {
        printf("no elemnts!");
    }
    else
    {

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}

void splice(int pos)
{
    if (pos < length() && pos >= 0)
    {
        struct node *temp, *q;
        temp = root;
        int i;
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->link;
        }
        q = temp->link;
        temp->link = q->link;
        q->link = NULL;
        free(q);
    }
    else
    {
        printf("invalid position!");
    }
}
//need to re-do
void swap(int pos1, int pos2)
{
    struct node *temp, *q, *r;
    temp = root;
    int i;

    for (i = 0; i < pos1 - 1; i++)
    {
        temp = temp->link;
    }
    q = temp->link;
    r = q->link;
    temp->link = r;
    q->link = r->link;
    r->link = q;
}

void reverse()
{
    struct node *temp, *q;
    temp = root;
    q = root;
    int i = 0;
    int j = length() - 1;

    while (i < j)
    {
        int k = 0;
        while (k < j)
        {
            temp = temp->link;
            k++;
        }
        int p = temp->data;
        temp->data = q->data;
        q->data = p;
        i++;
        j--;
        temp = root;
        q = q->link;
    }
}
