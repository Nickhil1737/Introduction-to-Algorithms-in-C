#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int N = 0; //heap size
int heapMinimum(int pq[])
{
    return pq[1];
}
void heapDecreaseKey(int *pq, int k, int key)
{
    if(pq[k] < key)  return;
    pq[k] = key;
    while(k > 1 && pq[k/2] > pq[k]){
        swap(&pq[k/2],&pq[k]);
        k = k/2;
    }

}
void minHeapify(int *pq, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest;
    if( l <= N && pq[l] < pq[i])
        smallest = l;
    else    smallest = i;
    if( r <= N && pq[r] < pq[smallest])
        smallest = r;
    if(smallest != i){
        swap(&pq[smallest],&pq[i]);
        minHeapify(pq,smallest);
    }
}
int extractMin(int pq[])
{
    if(N == 0)  return -1;//heap underflow
    int nax = pq[1];
    pq[1] = pq[N--];
    minHeapify(pq,1);
    return nax;
}
void minHeapInsert(int pq[], int key)
{
    pq[++N] = 1e9;
    heapDecreaseKey(pq,N,key);
}

int main()
{
    int pq[100009];
    N = 0;

    minHeapInsert(pq,2);
    minHeapInsert(pq,4);
    int x = extractMin(pq);
    minHeapInsert(pq,3);
    minHeapInsert(pq,6);
    int y = extractMin(pq);
    minHeapInsert(pq,1);
    int z = extractMin(pq);
    return 0;
}
