#include<stdio.h>

int ufrank[1000],parent[10000];
void make_set(int x)
{
    parent[x] = x;
    ufrank[x] = 0;
}
int find_set(int x)
{
    while(x != parent[x])
        x = parent[x];
    return x;
}
void link(int x,int y)
{
    if(ufrank[x] > ufrank[y])
        parent[y] = x;
    else{
        parent[x] = y;
        if(ufrank[x] == ufrank[y])
            ufrank[y] = 1+ ufrank[y];
    }
}
void unionf(int x, int y)
{
    link(find_set(x),find_set(y));
}

int same_components(int x, int y)
{
    if(find_set(x) == find_set(y))
        return 1;
    return 0;
}

int main()
{
    for(int i = 1; i < 6; ++i)  make_set(i);
    for(int i = 1; i < 6; ++i)  printf("%d ",parent[i]);
    printf("\n");
    unionf(1,2);
    unionf(2,3);
    unionf(5,4);
    unionf(2,5);
    for(int i = 1; i < 6; ++i)  printf("%d ",parent[i]);
    printf("\n");
    for(int i = 1; i < 6; ++i)  printf("%d ",ufrank[i]);
    printf("\n");
    return 0;
}
