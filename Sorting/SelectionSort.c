// Time Complexity
// Best case: O(n²)
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

    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("The sorted array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}