#include<stdio.h>

#define max 10009
#define true 1
#define false 0
int top = -1;
int S[max];

int stackEmpty()
{
    if(top == -1)
        return true;
    return false;
}
void push(int x)
{
    S[++top] = x;
}
int pop()
{
    if(stackEmpty())
        return -1;
        //underflow 
    else
        return S[top--];
}

int main()
{
    push(1);
    push(2);
    push(3);
    int x = pop();
    x = pop();
    x = pop();
    x = pop();

    return 0;
}
