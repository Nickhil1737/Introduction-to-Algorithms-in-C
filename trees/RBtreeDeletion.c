#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define BLACK 1
struct node{
    int key;
    int color;
    struct node *parent , *left , *right;
}*root;
struct node * newMalloc(int key){
    struct node *x = (struct node *) malloc(sizeof(struct node));
    x-> key = key;
    x->parent = NULL;
    x->left = NULL;
    x->right = NULL;
    return x;
}

struct node * treeMinimum(struct node *x)
{
    while(x->left != NULL)
        x = x->left;
    return x;
}
struct node * treeSearch(int k){
    struct node *x = root;
    while(x != NULL && x->key != k){
        if(k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}
void leftrotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;

    if(x->parent == NULL)
        root = y;
    else if(x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    x->parent = y;
    y->left = x;
}

void rightrotate(struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if(x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;

    if(y->parent == NULL)
        root = x;
    else if(y->parent->left == y)
        y->parent->left = x;
    else
        y->parent->right = x;
    y->parent = x;
    x->right = y;
}

void RBtransplant(struct node *u, struct node *v)
{
    if(u->parent == NULL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v != NULL)
        v->parent = u->parent;
}

void RBdeleteFixup(struct node *x)
{
    while(x != root && x->color == BLACK)
    {
        if(x == x->parent->left){
            struct node *w = x->parent->right;
            if(w->color == RED){                    //case1
                w->color  = BLACK;
                x->parent->color = RED;
                leftrotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color == BLACK){   //case2
                w->color = RED;
                x = x->parent;
            }
            else{
                if(w->right->color == BLACK){       //case3
                    w->left->color = BLACK;
                    w->color = RED;
                    rightrotate(w);
                }
                w->color = x->parent->color;        //case4
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftrotate(x->parent);
                x = root;
            }
        }
        else{
            struct node *w = x->parent->left;
            if(w->color == RED){
                w->color  = BLACK;
                x->parent->color = RED;
                rightrotate(x->parent);
                w = x->parent->left;
            }
            if(w->right->color == BLACK && w->left->color == BLACK){
                w->color = RED;
                x = x->parent;
            }
            else{
                if(w->left->color == BLACK){
                    w->right->color = BLACK;
                    w->color = RED;
                    leftrotate(w);
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rightrotate(x->parent);
                x = root;
            }

        }
    }
    x->color = BLACK;
}

void RBdelete(struct node *z)
{
    struct node *y = z;
    struct node *x;
    int y_original_color = y->color;
    if(z->left == NULL){
        x = z->right;
        RBtransplant(z,z->right);
    }
    else if(z->right == NULL){
        x = z->left;
        RBtransplant(z,z->left);
    }
    else{
        y = treeMinimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z)
            z->parent = y;
        else{
            RBtransplant(y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        RBtransplant(z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_original_color == BLACK)
        RBdeleteFixup(T,x);
}
void deleteNode(int key)
{
    struct node *x = treeSearch(key);
    if(x == NULL)
        return;
    RBdelete(x);
}

void rbfixup(struct node *z)
{
    
    while(z->parent != NULL && z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            struct node *y = z->parent->parent->right;            //uncle

            if(y->color == RED){                           //case 1
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{ 
                if(z == z->parent->right){                //case 2
                    z = z->parent;
                    leftrotate(z);
                }
                                                      //case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightrotate(z->parent->parent);
            }
        }
        else{
            struct node *y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    rightrotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftrotate(z->parent->parent);
            }
        }

    }
    root->color = BLACK;
}

void RBinsert(int key)
{
    struct node *x = root;
    struct node *z = newMalloc(key);
    struct node *y = NULL;
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
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
    z->left = NULL;
    z->right = NULL;
    z->color = RED;
    rbfixup(z);
}

void inorder(struct node *x)
{
    if( x == NULL)  return ;
    inorder(x->left);
    printf("%d\t",x->key);
    x->color == 1 ?printf("BLACK\n"):printf("RED\n");
    inorder(x->right);
}

int main()
{
    int n = 9;
    int arr[] = {11,2,14,1,7,15,5,8,4};
    for(int i = 0; i < 9; ++i){
        int k = arr[i];
        RBinsert(k);
    }
    printf("Root -> %d\n",root->key);
    printf("Inorder Traversal\nNode    Color\n");
    inorder(root);  

    return  0;
}


