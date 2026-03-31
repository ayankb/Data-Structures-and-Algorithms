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
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<n-1; i++){
        int flag = 0;
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }

    printf("The sorted array is :\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}