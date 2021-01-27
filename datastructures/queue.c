#include<stdio.h>

#define max 10009
int head = 0;
int tail = -1;
int Q[max];

void enqueue(int x)
{
    if(head == -1)
        head++;
    Q[++tail] = x;
}
int dequeue()
{
    if(head == -1)
        return -1;
        //underflow

    int x = Q[head];
    if(head == tail)
        head = tail = -1;
    else    head++;
    return x;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    int x = dequeue();
    x = dequeue();
    x = dequeue();
    x = dequeue();

    return 0;
}
