#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *prev;
    struct node *next;
}*head;

void listInsert(struct node *x)
{
    x->next = head;
    if(head != NULL){
        head->prev = x;
    }
    head = x;
    head->prev = NULL;
}
void insert(int k)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->key = k;
    x->prev = x->next = NULL;
    listInsert(x);
}
struct node * listSearch(int k)
{
    struct node *x = head;
    while( x != NULL && x->key != k)
        x = x->next;
    return x;
}
void listDelete(struct node *x)
{
    if(x->prev != NULL)
        x->prev->next = x->next;
    else    head= x->next;
    if(x->next != NULL)
        x->next->prev = x->prev;

}

int main()
{

    insert(1);
    insert(2);
    insert(3);

    struct node *x = listSearch(3);
    listDelete(x);

    return 0;
}
