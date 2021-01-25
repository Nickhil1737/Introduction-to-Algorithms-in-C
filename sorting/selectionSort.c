#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;*x = *y;*y = temp;
}

void selectionSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i){
        int min = i;
        for(int j = i+1; j < n; ++j){
            if(arr[min] > arr[j])
                min = j;
        }
        swap(&arr[min],&arr[i]);
    }
}

int main()
{
    int arr[] = {1,3,2,1,4,5,6,3};
    selectionSort(arr,8);
}
