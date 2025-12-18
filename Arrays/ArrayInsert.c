#include<stdio.h>
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
    printf("Enter the position where you want to isert an item\n");
    int p;//position where you want to insert an element
    scanf("%d",&p);
    printf("Enter the item which you want to insert\n");
    int item;//which item do you to insert
    scanf("%d",&item);
    //for inserting we run a loop backward
    for(int i=n;i>=p;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[p]=item;
    n=n+1;
    printf("After the inserting %d into the array.The array are:\n",item);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}