#include<stdio.h>

#define INF 1e9

void merge(int *arr, int p,int mid, int r)
{
    int a[1000],b[1000];
    int l = 0;
    for(int i = p; i < mid+1; ++i)
        a[l++] = arr[i];
    a[l] = INF;
    l = 0;
    for(int i = mid+1; i < r+1; ++i)
        b[l++] = arr[i];
    b[l] = INF;
    for(int k = p,i = 0, j = 0; k < r+1; ++k){
        if(a[i] < b[j])
            arr[k] = a[i++];
        else
            arr[k] = b[j++];
    }
}
void mergeSort(int *arr, int p, int r)
{
    if(p < r){
        int mid = (p+r)/2;
        mergeSort(arr,p,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,p,mid,r);
    }
}

int main()
{
    int arr[] = {1,4,2,8,5,7,6,3};
    mergeSort(arr,0,7);

    return 0;
}
