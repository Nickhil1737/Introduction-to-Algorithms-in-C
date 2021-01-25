#include<stdio.h>

void swap(int * x, int *y)
{
    int temp = *x;*x = *y;*y = temp;
}
int partition(int *arr, int p, int r)
{
    int i = p-1;
    int x = arr[r];
    for(int j = p; j < r; ++j){
        if(arr[j] <= x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quickSort(int *arr, int p, int r)
{
    if(p < r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main()
{
    int arr[] = {1,4,2,8,5,7,6,3};
    quickSort(arr,0,7);

    return 0;
}
