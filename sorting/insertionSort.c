#include<stdio.h>


void insertionSort(int *arr, int n)
{
    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {1,3,2,1,4,5,6,3};
    insertionSort(arr,8);
}
