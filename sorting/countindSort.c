#include<stdio.h>

void countingSort(int arr[], int B[], int n, int k)
{
    int C[1000];    //array of size whose max index can be k
    for(int i = 0; i < k+1; ++i)
        C[i] = 0;
    for(int j = 0; j < n; ++j)
        C[arr[j]]++;
        // C[i] contains no. of occurences of element i
    for(int i = 1; i < k+1; ++i){
        C[i] += C[i-1];
    }
    for(int i = n-1; i >= 0; --i){
        B[C[arr[i]]] = arr[i];
        C[arr[i]]--;
    }
}

int main()
{
    int arr[] = {1,4,2,2,3,6,9,3,6};
    int B[1000];
    countingSort(arr,B,9,9);
    // array B consists of the sorted array
    
    return 0;
}
