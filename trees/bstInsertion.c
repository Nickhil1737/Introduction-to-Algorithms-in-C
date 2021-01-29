#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *parent;
    struct node *left, *right;
}*root;

struct node * newMalloc(int key){
    struct node *x = (struct node *) malloc(sizeof(struct node));
    x-> key = key;
    x->parent = NULL;
    x->left = NULL;
    x->right = NULL;
    return x;
}
void insert(int k)
{
    struct node *x = root;
    struct node *y = NULL;

    struct node *z = newMalloc(k);

    while(x != NULL){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y == NULL)
        root = z;
    else if(z->key < y->key){
        y->left = z;
    }
    else{
        y->right = z;
    }
}

struct node * treeSearch(struct node *root, int key)
{
    struct node *x = root;
    while(x != NULL && key != x->key){
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

void inordertraversal(struct node *x)
{
    if(x == NULL)
        return;
    inordertraversal(x->left);
    printf("%d ", x->key);
    inordertraversal(x->right);
}

int main()
{
    int arr[] = {1,4,2,8,5,7,6,9,3};
    int n = 9;  
    for(int i = 0; i < n ; ++i){
        int k = arr[i];  
        insert(k);
    }
    struct node*x = treeSearch(root,5);

    inordertraversal(root);

    return 0;
}

/*
Mon 21 Sep 2020 02:33:56 PM IST
 *     astrainL3gi0N
 */
