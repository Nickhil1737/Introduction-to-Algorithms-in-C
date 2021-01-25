#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;*x = *y;*y = temp;
}

void bubbleSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i){
        for(int j = n-1; j > i; --j){
            if(arr[j] < arr[j-1])
                swap(&arr[j],&arr[j-1]);
        }
    }
}

int main()
{
    int n = 8;
    int arr[] = {1,3,2,1,4,5,6,3};
    bubbleSort(arr,n);
}
