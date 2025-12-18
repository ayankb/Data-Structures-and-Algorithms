#include<stdio.h>

int lsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[100];//array declear
    printf("Enter the number of elements of array\n");
    int n;//number of element
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);//input elements of array
    }
    printf("Enter the item which you want to delete from array\n");
    int item;//position where you want to insert an element
    scanf("%d",&item);
   
    int p = lsearch(arr,n,item);
    for(int i=p;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    printf("After the deletion %d from the array.The array are:\n",item);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;

}