// Time Complexity
// Best case: O(n) (already sorted)
// Worst case: O(n²)
// Average case: O(n²)

#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter the elements of array:\n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=1; i<n; i++){
        int tepm = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > tepm){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tepm;
    }
    
    printf("The sorted array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}