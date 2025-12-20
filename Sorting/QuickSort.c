#include<stdio.h>

int pratition(int arr[],int low,int high){
    int p = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<p){
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    i++;
    int t = arr[i];
    arr[i] = arr[high]; 
    arr[high] = t;
    return i;
}
void quickS(int arr[],int low,int high){
    if(low < high){
        int p = pratition(arr,low,high);
        quickS(arr,low,p-1);
        quickS(arr,p+1,high);
    }
}

int main(){
    int n;
    printf("Enter the size of array::\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }

    quickS(arr,0,n-1);
    
    printf("The sorted array is :\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}