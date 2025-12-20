#include<stdio.h>
int main(){
    int n, i;
   printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
   printf("Enter the elements of array:\n");
    for( i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int count = 1;
    while(count <= n)
    {
        for( i=0;i<=n-count;i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        count ++;
    }
    printf("The sorted array is:\n");
    for( i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
