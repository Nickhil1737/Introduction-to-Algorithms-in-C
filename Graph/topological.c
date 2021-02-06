#include<stdio.h>
#include<stdlib.h>

int V, E, dfstime;
int finished[1000],discover[1000], marked[1000];

struct node {
    int info;
    struct node * next;
}*adj[100], *head;
void addEdge (int x , int y)
{
    struct node* edge = (struct node *) malloc(sizeof(struct node));
    edge->info = y;
    edge->next = adj[x];
    adj[x] = edge;
}
void insertnode (int k)
{
    struct node *x = (struct node*)malloc(sizeof(struct node));
    x->info = k;
    x->next = head;
    head = x;
}

void dfsvisit (int s)
{
    discover[s] = ++dfstime;
    marked[s] = 1;
    struct node *x = adj[s];
    while (x != NULL) {
        if (!marked[x->info])
            dfsvisit(x->info);
        x = x->next;
    }
    insertnode(s);
    finished[s] = ++dfstime;
}
void dfs ()
{
    for (int i = 1; i < V+1; ++i)
        marked[i] = 0;
    dfstime = 0;
    for (int i = 1; i < V+1; ++i)
        if (!marked[i])  dfsvisit(i);
}

void printTopSort (struct node *x) {
    while (x!= NULL) {
        printf("%d ",x->info);
        x = x->next;
    }
}


int main()
{
    V = 6, E = 8;
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(4,2);
    addEdge(1,4);
    addEdge(5,4);
    addEdge(5,6);
    addEdge(6,6);

    for (int i = 1; i < V+1; ++i) {
        struct node *x = adj[i];
        printf("\n%d  - ",i);
        while (x != NULL) {
            printf("%d ",x->info);
            x = x->next;
        }
        printf("\n");
        
    }
    dfs();
    for (int i = 1; i < V+1; ++i)   printf("%d ",discover[i]);
    printf("\n");
    for (int i = 1; i < V+1; ++i)   printf("%d ",finished[i]);
    printf("\n Topological sort : ");
    printTopSort(head);
    
    

    return 0;
}


